%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>	
#include "Main.h"
#include <cstring>
#include "Net.h"
using namespace std;
%}
%option noyywrap

%{

	int posi=0;
	Net net[1000];
	int neterror[1000]={0};
	Component comp[1000];
	Source sour[1000];
	int c_index=0;
	int s_index=0;
	bool term=false;
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
sine (SINE)[ ]*(\(){whitespace}+{Decimal}{whitespace}+{Decimal}{whitespace}+{Decimal}{factor}(hz){whitespace}+{Decimal}(S)[ ]+{Decimal}{whitespace}+(\)){whitespace}*

%%

{whitespace}*{Source}{whitespace}*{Position}{whitespace}{Position}{whitespace}{sine}{whitespace}* {

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
	// cout<<t<<endl;
	// cout<<t.substr(0,t.length()-3)<<endl;
	// magnitude=stof(t.substr(0,t.length()-3));
	// sour[s_index].setStrFreq((char*)t.c_str());

	switch(t[t.length()-3])
	{
		case 'K':
		magnitude=stof(t.substr(0,t.length()-3));
		magnitude*=1000.0;//stof(t.substr(0,t.length()-2))*1000;
		// comp[c_index].setVal(magnitude);
		break;
		case 'N':
		magnitude=stof(t.substr(0,t.length()-3));
		magnitude/=1000000000.0;
		// comp[c_index].setVal(magnitude);
		break;

		case 'U':
		magnitude=stof(t.substr(0,t.length()-3));
		magnitude/=1000000.0;
		// comp[c_index].setVal(magnitude);
		break;
		case 'M':
		magnitude=stof(t.substr(0,t.length()-3));
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
	sour[s_index].setStrDelay((char*)t.c_str());
	ss>>t;
	// cout<<t<<endl;
	magnitude=stof(t);
	sour[s_index].setDamp(magnitude);
	
	if(sour[s_index].getInitialNet()==sour[s_index].getFinalNet())
	{
		cout<<"Initial and Final net should be different in "<<yytext<<endl;
		sour[s_index].clear();
	}
	else
	{	sour[s_index].setPosition(posi++);
		s_index++;
		sour[s_index-1].setId(s_index-1);
		neterror[sour[s_index-1].getInitialNet()]++;
		neterror[sour[s_index-1].getFinalNet()]++;
		net[sour[s_index-1].getInitialNet()].addSour(sour[s_index-1]);
		net[sour[s_index-1].getFinalNet()].addSour(sour[s_index-1]);
	}								
}

{whitespace}*{Component}{whitespace}*{Position}{whitespace}*{Position}{whitespace}*{Decimal}{factor}{unit}{whitespace}*    {

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
									// cout<<t<<endl;
									// char* xx=(char*)(t.c_str());
									// cout<<xx<<endl;
									comp[c_index].setStrValue((char*)(t.c_str()));	
									
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

									comp[c_index].setStrValue((char*)t.c_str());	
						
									if(comp[c_index].getInitialNet()==comp[c_index].getFinalNet())
									{	
										cout<<"Initial and Final net should be different in "<<yytext<<endl;
										comp[c_index].clear();
										
									}
									else
									{
										comp[c_index].setPosition(posi++);
										c_index++;
										neterror[comp[c_index-1].getInitialNet()]++;
										neterror[comp[c_index-1].getFinalNet()]++;
										net[comp[c_index-1].getInitialNet()].addComp(comp[c_index-1]);
										net[comp[c_index-1].getFinalNet()].addComp(comp[c_index-1]);
									}	

									
}

{whitespace}*[(Netlist:)(NETLIST:)(netlist:)]{whitespace}* {

}

.	{
		term=true;
		// cout<<yytext;
		cout<<"\"Input File has some error.So Circuit might not be complete.\""<<endl;

		
}


%%

int main(int argc, char* argv[]) 
{
    
    FILE *fh;

    if ((fh = fopen(argv[1], "r")))
        yyin = fh;

    string outputfile=argv[2];
    string resultfile=argv[3];

    yylex();
    for(int i=0;i<1000;i++)
    {
    	if(neterror[i]==1)
    	{
    		if(i>0){
    			cout<<"Circuit is Incomplete. Net"<<i-1<<" has only one connection."<<endl;
    			// break;
    		}
    		else{
    			cout<<"Circuit is Incomplete. Ground has only one connection."<<endl;
    			// break;
    		}
    	}
    }
    if(s_index==0)
    {
    	cout<<"There is no Voltage or Current source in the Circuit."<<endl;
    }
    // if(!term){
    	genmaim(outputfile,resultfile);
    	return 0;
    // }
    // return 0;
} 