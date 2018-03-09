%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Component.h"
using namespace std;
%}
%option noyywrap

%{

	Component comp[100];
	int c_index=0;
	int r=0,l=0,c=0;
	int inductor[100][4];
	int capacitor[100][4];


	void diffNet(string s)
	{

	}
	void show()
	{
		cout<<"Component Count: "<<c_index<<endl;
		for(int i=0;i<c_index;i++)
		{
			cout<<comp[i].getType()<<" "<<comp[i].getNum()<<" "<<comp[i].getInitialNet()<<" "<<comp[i].getFinalNet()<<" "<<comp[i].getVal()<<endl;
		}
	}	
	typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse();
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
%} 

Component [R|L|C][1-9][0-9]*
Registor R[1-9][0-9]*
Inductor L[1-9][0-9]*
Capacitor C[1-9][0-9]*
whitespace [ |\n]
factor [N|U|M|K]?
unit [F|H]?

net Net

%%

{Component}{whitespace}*(({net}[0-9]*)|0){whitespace}*(({net}[0-9]*)|0){whitespace}*[1-9][0-9]*{factor}{unit}[ ]*[\n]    {

									string temp=yytext;
									istringstream ss(temp);
									temp="";
									float magnitude;
									
									for(int i=0;i<4;i++)
									{	
										string t;
										switch(i)
										{
											case 0:
											ss>>t;
											comp[c_index].setType(t[0]);
											comp[c_index].setNum(stoi(t.substr(1)));
											temp+=(t+" ");
											break;
											
											case 1:
											ss>>t;
											temp+=(t+" ");
											if(t=="0"){
												comp[c_index].setInitialNet(0);
											}
											else{
												comp[c_index].setInitialNet(stoi(t.substr(3))+1);
											}
											break;
											
											case 2:
											ss>>t;
											temp+=(t+" ");
											if(t=="0"){
												comp[c_index].setFinalNet(0);
											}
											else{
												comp[c_index].setFinalNet(stoi(t.substr(3))+1);
											}
											break;
											
											case 3:
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
												// if(t[t.length()-1])
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
												
											break;
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

int main(int argc, char* argv[]) {
    FILE *fh;

    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    // cout<<yyin;
    yylex();
    // char string[] = "C1 Net1 0 10NF";
    // YY_BUFFER_STATE buffer = yy_scan_string(string);
    // yyparse();
    // yy_delete_buffer(buffer);
    return 0;

  
    
} 