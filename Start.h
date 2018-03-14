#ifndef START_H
#define START_H
#include "Component.h"
#include "Source.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>

extern Source sour[10];
extern int s_index;
extern Component comp[100];
extern int c_index;
ofstream ofile;

void html()
{
    ofile<<"<html>\n";
    ofile<<"<body>\n";
    ofile<<"<style>\n";
    ofile<<"body{\n";
    ofile<<"background-color: #93B874;\n";
    ofile<<"}\n";
    ofile<<"</style>\n";
}

void close()
{
  ofile<<"</body>\n";
  ofile<<"</html>\n";

}

void header(int numnets) {
 

ofile<<"<svg height=\""<<1000<<"\" width=\""<<1000<<"\">"<<endl;
 // height corresponds to vertical and width is horizontal

}

// Epilog for the SVG image

void footer() {
  ofile << "</svg>" << endl;
}


// Generation of the two segments

void line(int x,int y,int length,char c,int color)
{ 
  if(color==1){		
   
   if(c=='h')		 
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+length<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
   else
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x<<"\" "<<"y2=\""<<y+length<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl; 		
  
  }
  else
  {
   
   if(c=='h')		 
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+length<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
   else
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x<<"\" "<<"y2=\""<<y+length<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
  
  }	

}

void resistor(int x, int y,float nu,int val) {
  

    ofile<<"<path d=\"M"<<x<<" "<<y<<" L"<<x+5<<" "<<y+10<<" L"<<x+10<<" "<<y<<" L"<<x+15<<" "<<y+10<<" L"<<x+20<<" "<<y<<" L"<<x+25<<" "<<y+10<<" L"<<x+30<<" "<<y<<"\" stroke=\"black\" fill=\"none\" stroke-width=\"3\"  /> "<<endl;
//    ofile<<"<text x=\""<<x+10<<"\" y=\""<<y-4<<"\" fill=\"black\">r"<<nu<<"="<<val<<"Ohm </text>";
}

void capc(int x,int y){

	ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+7.5<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+7.5<<"\" "<<"y1=\""<<y-20<<"\" "<<"x2=\""<<x+7.5<<"\" "<<"y2=\""<<y+20<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+17.5<<"\" "<<"y1=\""<<y-20<<"\" "<<"x2=\""<<x+17.5<<"\" "<<"y2=\""<<y+20<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+17.5<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+25<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(0,0,0);stroke-width:2\" />"<<endl;
}


void Indc(int x,int y){


	ofile<<"<path d=\"M"<<x<<","<<y<<" a0.5,1 0 0,0 10,0\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+10<<","<<y<<" a0.5,1 0 0,0 10,0\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+20<<","<<y<<" a0.5,1 0 0,0 10,0\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+30<<","<<y<<" a0.5,1 0 0,0 10,0\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" ;

}


void Volt(int x,int y,bool side)
{
  //ofile<<"<text x=\""<<x-1<<"\" y=\""<<y-2<<"\" "<<" fill=\"red\">+"<<"</text>"<<endl;
  ofile<<"<circle cx=\""<<x<<"\"  cy=\""<<y<<"\" r=\"20\" "<<"stroke=\"black\" stroke-width=\"3\" fill=\"none\" />";
  ofile<<"<text x=\""<<x-8<<"\" y=\""<<y+5<<"\" "<<" font-size=\"20\" fill=\"black\">~"<<"</text>"<<endl;
  if(side==true)
  {
    ofile<<"<text x=\""<<x-35<<"\" y=\""<<y-3<<"\" "<<" font-size=\"20\" fill=\"black\">+"<<"</text>"<<endl;
    ofile<<"<text x=\""<<x+20<<"\" y=\""<<y-1<<"\" "<<" font-size=\"35\" fill=\"black\">-"<<"</text>"<<endl;
  } 
  else
  {

    ofile<<"<text x=\""<<x-35<<"\" y=\""<<y-1<<"\" "<<" font-size=\"35\" fill=\"black\">-"<<"</text>"<<endl;
    ofile<<"<text x=\""<<x+35<<"\" y=\""<<y-3<<"\" "<<" font-size=\"20\" fill=\"black\">+"<<"</text>"<<endl;

  }

}




void Curr(int x,int y,bool side)
{
  ofile<<"<rect x=\""<<x<<"\" y=\""<<y-10<<"\" width=\"20\" height=\"20\" style=\"fill:none;stroke:black;stroke-width:2;\" />";

  if(side==true)
  { 
    ofile<<"<text x=\""<<x-15<<"\" y=\""<<y<<"\" "<<" font-size=\"20\" fill=\"black\">+"<<"</text>"<<endl;
    ofile<<"<text x=\""<<x+23<<"\" y=\""<<y<<"\" "<<" font-size=\"30\" fill=\"black\">-"<<"</text>"<<endl;
  } 
  else
  { 
    ofile<<"<text x=\""<<x-15<<"\" y=\""<<y<<"\" "<<" font-size=\"30\" fill=\"black\">-"<<"</text>"<<endl;
    ofile<<"<text x=\""<<x+23<<"\" y=\""<<y<<"\" "<<" font-size=\"20\" fill=\"black\">+"<<"</text>"<<endl;
  }

}










void DrawCurr(int net1,int net2,int offset)
{
  int diff=abs(net1-net2);

  float l1=(diff-20)/2 ;

  int x=min(net1,net2);

   bool side;

  if(x==net1)
  side=true;  
  else
  side=false;

  line(x,250+offset,l1,'h',1);
  Curr(x+l1,250+offset,side);
  line(x+l1+20,250+offset,l1,'h',1);

  line(net1,250,offset,'v',0);
  line(net2,250,offset,'v',0); 

}


void DrawVolt(int net1,int net2,int offset)
{
  int diff=abs(net2-net1);

  float l1=(diff-40)/2 ;

  int x=min(net1,net2);

  bool side;

  if(x==net1)
  side=true;  
  else
  side=false;

  line(x,250+offset,l1,'h',1);
  Volt(x+l1+20,250+offset,side);
  line(x+l1+40,250+offset,l1,'h',1);

  line(net1,250,offset,'v',0);
  line(net2,250,offset,'v',0);  

}



void drawRes(int net1,int net2,int offset,int n,float val,char* c)
{
    int diff=abs(net2-net1);

    
    float l1=(diff-30)/2 ;

    int x=min(net1,net2);
    	
    line(x,250+offset,l1,'h',1);
    resistor(x+l1,250+offset,n,val);
    line(x+l1+30,250+offset,l1,'h',1);

    ofile<<"<text x=\""<<x+l1+10<<"\" y=\""<<246+offset<<"\" fill=\"black\">r"<<n<<"="<<c<<"Ohm </text>";
   line(net1,250,offset,'v',0);
   line(net2,250,offset,'v',0);
    
}
  

void drawCap(int net1,int net2,int offset)
{
	int diff=abs(net2-net1);

	float l1=(diff-22)/2 ;

	int x=min(net1,net2);

 	line(x,250+offset,l1,'h',1);
    capc(x+l1,250+offset);
    line(x+l1+22,250+offset,l1,'h',1);
	

    line(net1,250,offset,'v',0);
    line(net2,250,offset,'v',0); 

}

void drawInd(int net1,int net2,int offset)
{

	int diff=abs(net2-net1);

	float l1=(diff-40)/2 ;

	int x=min(net1,net2);
	line(x,250+offset,l1,'h',1);
    Indc(x+l1,250+offset);
    line(x+l1+40,250+offset,l1,'h',1);

   line(net1,250,offset,'v',0);
   line(net2,250,offset,'v',0); 


}

void genmaim() {
  unsigned x, y;
  
  bool N[100];

    
  ofile.open("top.html");
  html();

  for(int i=0;i<100;i++)
  N[i]=false; 

  
  
  int netval[100];

  for(int i=0;i<100;i++)
  netval[i]=-1; 

  

  int num=c_index;
  int scount=s_index;

  int number[100][100];
  
  for(int i=0;i<100;i++)
  {
  	for(int j=0;j<100;j++)
  	number[i][j]=0;	

  }



  int s=10;

  for(int i=0;i<num;i++)
  {
  	int a = comp[i].getInitialNet();
  	int b = comp[i].getFinalNet();

  	
  	if(N[a]==false)
  	{	
  		netval[a]=s;
  		N[a]=true;
  		s+=300;

  	}	

  	if(N[b]==false)
  	{
  		netval[b]=s;
  		N[b]=true;
  		s+=300;

  	}	


  }
	
  int numnets=0;

  for(int i=0;i<100;i++)
  {
    if(N[i]==true)
    numnets++;  

  }
  

  header(numnets);

  for(int i=0;i<100;i++)
  {
    if(N[i]==true)
    {
      if(i!=0)
      ofile<<"<text x=\""<<netval[i]<<"\" y=\"248\" "<<" fill=\"black\">net"<<i-1<<"</text>"<<endl; 
      else
      ofile<<"<text x=\""<<netval[i]<<"\" y=\"248\" "<<" fill=\"black\">0"<<"</text>"<<endl;  

      ofile<<"<text x=\""<<netval[i]-10<<"\" y=\"250\" "<<" font-size=\"60\" fill=\"blue\">."<<"</text>"<<endl;
    }  

  }
  

  
  
  int offset=80;
  for(int i=0;i<num;i++)
  {	
  	int a = comp[i].getInitialNet();
  	int b = comp[i].getFinalNet();

    char* c=comp[i].getStrValue();
    cout<<comp[i].getStrValue();
  	
    int in=comp[i].getNum();
  	float val =comp[i].getVal();
  		
  	if( abs(netval[a] - netval[b]) == 300  &&  number[a][b]==0 ){

  	if(comp[i].getType() == 'R')
	  drawRes(netval[a],netval[b],0,in,val,c);
	  else if(comp[i].getType() == 'C')
	  drawCap(netval[a],netval[b],0);	
	  else if(comp[i].getType() == 'L')
    drawInd(netval[a],netval[b],0);

	}
	else{

	if(comp[i].getType() == 'R')
	drawRes(netval[a],netval[b],offset,in,val,c);
	else if(comp[i].getType() == 'C')
	drawCap(netval[a],netval[b],offset);	
	else if(comp[i].getType() == 'L')
  drawInd(netval[a],netval[b],offset);
	offset+= 80;
	
	}

	number[a][b]++;
  number[b][a]++;


  }

  int viset=-80;
  for(int i=0;i<scount;i++)
  {
      int a = sour[i].getInitialNet();
      int b = sour[i].getFinalNet();

     // int in = sour[i].getNum();
     // float val = sour[i].getVal();
      
      
      

      if( sour[i].getType() == 'V' )
      DrawVolt(netval[a],netval[b],viset);  
      else if(sour[i].getType() == 'I')
      DrawCurr(netval[a],netval[b],viset);
        
      viset-= 80;
  
  

      number[a][b]++;
      number[b][a]++;

  }	




  
  footer();
  close();
  ofile.close();

}


#endif