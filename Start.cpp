%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>	
#include "Start.h"

using namespace std;
%}
%option noyywrap

%{

	Component comp[100];
	Source sour[10];
	int c_index=0;
	int s_index=0;
	void genmaim();

	void show()
	{
		cout<<"Component Count: "<<c_index<<endl;
		for(int i=0;i<c_index;i++)
		{
			cout<<comp[i].getType()<<" "<<comp[i].getNum()<<" "<<comp[i].getInitialNet()<<" "<<comp[i].getFinalNet()<<" "<<comp[i].getVal()<<endl;
		}
		cout<<"Source Count: "<<s_index<<endl;
		for(int i=0;i<s_index;i++)
		{
			cout<<sour[i].getType()<<" "<<sour[i].getNum()<<" "<<sour[i].getInitialNet()<<" "<<sour[i].getFinalNet()<<" "<<sour[i].getDCO()<<" "<<sour[i].getAmpli()<<" "<<sour[i].getFreq()<<" "<<sour[i].getDelay()<<" "<<sour[i].getDamp()<<endl;
		}
	}


%} 

Component [R|L|C][1-9][0-9]*
Source [V|I][1-9][0-9]*
NotComponent (^[RLC])[1-9][0-9]*
Registor R[1-9][0-9]*
Inductor L[1-9][0-9]*
Capacitor C[1-9][0-9]*
whitespace [ |\n]
factor [N|U|M|K]?
unit [F|H]?
NotUnit (^[ |F|H])
Position (({net}([0]|([1-9][0-9]*)))|0)
net (Net)|(NET)|(net)
Decimal (([0-9]+(\.)[0-9]+)|([0-9]*))
sine (SINE)[ ]*(\(){whitespace}+{Decimal}{whitespace}*{Decimal}{whitespace}*{Decimal}(Khz){whitespace}*{Decimal}(S)[ ]*{Decimal}{whitespace}*(\)){whitespace}
sine1 (SINE)[ ]*(\(){Decimal}{whitespace}*{Decimal}{whitespace}*{Decimal}(Khz){whitespace}*{Decimal}(S)[ ]*{Decimal}{whitespace}*(\)){whitespace}

%%

{Source}{whitespace}*{Position}{whitespace}{Position}{whitespace}{sine}{whitespace}* {

	string temp=yytext;
	istringstream ss(temp);
	temp="";
	string t;
	ss>>t;
	sour[s_index].setType(t[0]);
	sour[s_index].setNum(stoi(t.substr(1)));
	ss>>t;
	// cout<<t;
	if(t=="0"){
		sour[s_index].setInitialNet(0);
	}
	else{
		int x=stoi(t.substr(3))+1;
		// cout<<x;
		sour[s_index].setInitialNet(x);
	}
	ss>>t;
	// cout<<t;
	if(t=="0"){
		sour[s_index].setFinalNet(0);
	}
	else{
		sour[s_index].setFinalNet(stoi(t.substr(3))+1);
	}
	ss>>t;
	float magnitude;
	ss>>t;
	ss>>t;
	// cout<<t<<endl;	
	magnitude=stof(t);
	sour[s_index].setDCO(magnitude);
	ss>>t;
	// cout<<t<<endl;
	magnitude=stof(t);
	sour[s_index].setAmpli(magnitude);
	ss>>t;
	// cout<<t.substr(0,t.length()-3)<<endl;
	magnitude=stof(t.substr(0,t.length()-3));
	
	switch(t[t.length()-3])
	{
		case 'K':
		magnitude*=1000.0;//stof(t.substr(0,t.length()-2))*1000;
		// comp[c_index].setVal(magnitude);
		break;
		case 'N':
		magnitude/=1000000000.0;
		// comp[c_index].setVal(magnitude);
		break;

		case 'U':
		magnitude/=1000000.0;
		// comp[c_index].setVal(magnitude);
		break;
		case 'M':
		magnitude/=1000.0;
		// comp[c_index].setVal(magnitude);
		break;
		default:
		magnitude=stof(t.substr(0,t.length()-2));
		// comp[c_index].setVal(magnitude);


	}

	sour[s_index].setFreq(magnitude);
	ss>>t;
	// cout<<t.substr(0,t.length()-1)<<endl;
	magnitude=stof(t.substr(0,t.length()-1));
	sour[s_index].setDelay(magnitude);
	ss>>t;
	// cout<<t<<endl;
	magnitude=stof(t);
	sour[s_index].setDamp(magnitude);
	
	if(sour[s_index].getInitialNet()==sour[s_index].getFinalNet())
	{
		sour[s_index].clear();
	}
	else
		s_index++;
	
									
}

{Component}{whitespace}*{Position}{whitespace}*{Position}{whitespace}*[1-9][0-9]*{factor}{unit}[ ]*[\n]    {

									string temp=yytext;
									istringstream ss(temp);
									temp="";
									float magnitude;
									string t;
									ss>>t;
									comp[c_index].setType(t[0]);
									comp[c_index].setNum(stoi(t.substr(1)));
									temp+=(t+" ");
									ss>>t;
									temp+=(t+" ");
									if(t=="0"){
										comp[c_index].setInitialNet(0);
									}
									else{
										comp[c_index].setInitialNet(stoi(t.substr(3))+1);
									}
									ss>>t;
									temp+=(t+" ");
									if(t=="0"){
										comp[c_index].setFinalNet(0);
									}
									else{
										comp[c_index].setFinalNet(stoi(t.substr(3))+1);
									}
									temp+=(t+" ");
									ss>>t;
									if(t[t.length()-1]=='H' || t[t.length()-1]=='F')
									{
										switch(t[t.length()-2])
										{
											case 'K':
											magnitude=stof(t.substr(0,t.length()-2))*1000;
											comp[c_index].setVal(magnitude);
											break;
											case 'N':
											magnitude=stof(t.substr(0,t.length()-2))/1000000000.0;
											comp[c_index].setVal(magnitude);
											break;

											case 'U':
											magnitude=stof(t.substr(0,t.length()-2))/1000000.0;
											comp[c_index].setVal(magnitude);
											break;
											case 'M':
											magnitude=stof(t.substr(0,t.length()-2))/1000.0;
											comp[c_index].setVal(magnitude);
											break;
											default:
											magnitude=stof(t.substr(0,t.length()-1));
											comp[c_index].setVal(magnitude);


										}
									}	
									else
									{
										switch(t[t.length()-1])
										{
											case 'K':
											magnitude=stof(t.substr(0,t.length()-1))*1000;
											comp[c_index].setVal(magnitude);
											break;
											case 'N':
											magnitude=stof(t.substr(0,t.length()-1))/1000000000.0;
											comp[c_index].setVal(magnitude);
											break;

											case 'U':
											magnitude=stof(t.substr(0,t.length()-1))/1000000.0;
											comp[c_index].setVal(magnitude);
											break;
											case 'M':
											magnitude=stof(t.substr(0,t.length()-1))/1000.0;
											comp[c_index].setVal(magnitude);
											break;
											default:
											magnitude=stof(t.substr(0,t.length()));
											comp[c_index].setVal(magnitude);


										}
									}	
												
									if(comp[c_index].getInitialNet()==comp[c_index].getFinalNet())
									{	
										cout<<"Both Net can't be same in "<<yytext;
										comp[c_index].clear();
										
									}
									else
									{
										c_index++;
									}	

									
}

x	{
	show();
}

.	{
		// cout<<yytext<<endl;
}


%%

int main(int argc, char* argv[]) 
{
    
    FILE *fh;

    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;

    yylex();
    genmaim();
    
	return 0;
} 