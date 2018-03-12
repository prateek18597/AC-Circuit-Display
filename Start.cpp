%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Start.h"
// #include "img.h"
// #include "Component.h"
using namespace std;
%}
%option noyywrap

%{

	Component comp[100];
	int c_index=0;
	int r=0,l=0,c=0;
	int inductor[100][4];
	int capacitor[100][4];

	void show()
	{
		cout<<"Component Count: "<<c_index<<endl;
		for(int i=0;i<c_index;i++)
		{
			cout<<comp[i].getType()<<" "<<comp[i].getNum()<<" "<<comp[i].getInitialNet()<<" "<<comp[i].getFinalNet()<<" "<<comp[i].getVal()<<endl;
		}
	}	
%} 

Component [R|L|C][1-9][0-9]*
Registor R[1-9][0-9]*
Inductor L[1-9][0-9]*
Capacitor C[1-9][0-9]*
whitespace [ |\n]
factor [N|U|M|K]?
unit [F|H]?
Position (({net}([0]|([1-9][0-9]*)))|0)
net Net

%%

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
										cout<<"Wrong Input";
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
		cout<<yytext<<endl;
}


%%

int main(int argc, char* argv[]) 
{
    
    FILE *fh;

    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;

    yylex();
    
    return 0;
} 