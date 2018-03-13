#ifndef START_H
#define START_H
#include "Component.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>

extern Component comp[100];
extern int c_index;
ofstream ofile;

void header() {
 
ofile<<"<svg height=\"510\" width=\"400\">"<<endl; // height corresponds to vertical and width is horizontal
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
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+length<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
   else
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x<<"\" "<<"y2=\""<<y+length<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl; 		
  
  }
  else
  {
   
   if(c=='h')		 
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+length<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(0,0,255);stroke-width:2\" />"<<endl;
   else
   ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x<<"\" "<<"y2=\""<<y+length<<"\" "<<"style=\"stroke:rgb(0,0,255);stroke-width:2\" />"<<endl;
  
  }	

}

void resistor(int x, int y) {
  

    ofile<<"<path d=\"M"<<x<<" "<<y<<" L"<<x+5<<" "<<y+3<<" L"<<x+10<<" "<<y<<" L"<<x+15<<" "<<y+3<<" L"<<x+20<<" "<<y<<" L"<<x+25<<" "<<y+3<<" L"<<x+30<<" "<<y<<"\" stroke=\"red\" fill=\"none\" stroke-width=\"3\"  /> "<<endl;

}

void capc(int x,int y){

	ofile<<"<line x1=\""<<x<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+10<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+10<<"\" "<<"y1=\""<<y-5<<"\" "<<"x2=\""<<x+10<<"\" "<<"y2=\""<<y+5<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+15<<"\" "<<"y1=\""<<y-5<<"\" "<<"x2=\""<<x+15<<"\" "<<"y2=\""<<y+5<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
	ofile<<"<line x1=\""<<x+15<<"\" "<<"y1=\""<<y<<"\" "<<"x2=\""<<x+25<<"\" "<<"y2=\""<<y<<"\" "<<"style=\"stroke:rgb(255,0,0);stroke-width:2\" />"<<endl;
}


void Indc(int x,int y){


	ofile<<"<path d=\"M"<<x<<","<<y<<" a1,1 0 0,0 10,0\" fill=\"none\" stroke=\"green\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+10<<","<<y<<" a1,1 0 0,0 10,0\" fill=\"none\" stroke=\"green\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+20<<","<<y<<" a1,1 0 0,0 10,0\" fill=\"none\" stroke=\"green\" stroke-width=\"3\" />" ;
	ofile<<"<path d=\"M"<<x+30<<","<<y<<" a1,1 0 0,0 10,0\" fill=\"none\" stroke=\"green\" stroke-width=\"3\" />" ;

}








void drawRes(int net1,int net2,int offset)
{
    int diff=abs(net2-net1);

    
    float l1=(diff-30)/2 ;

    int x=min(net1,net2);
    	
    line(x,250+offset,l1,'h',1);
    resistor(x+l1,250+offset);
    line(x+l1+30,250+offset,l1,'h',1);


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

    
    ofile.open("A.svg");
  for(int i=0;i<100;i++)
  N[i]=false; 

  
  
  int netval[100];

  for(int i=0;i<100;i++)
  netval[i]=-1; 

  

  int num=c_index;

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
  		s+=80;
  	}	

  	if(N[b]==false)
  	{
  		netval[b]=s;
  		N[b]=true;
  		s+=80;
  	}	


  }
		
  
  
  header();
  
  int offset=15;
  for(int i=0;i<num;i++)
  {	
  	int a = comp[i].getInitialNet();
  	int b = comp[i].getFinalNet();

  		
  	if( abs(netval[a] - netval[b]) == 80  &&  number[a][b]==0 ){

  	if(comp[i].getType() == 'R')
	drawRes(netval[a],netval[b],0);
	else if(comp[i].getType() == 'C')
	drawCap(netval[a],netval[b],0);	
	else if(comp[i].getType() == 'L')
    drawInd(netval[a],netval[b],0);

	}
	else{

	if(comp[i].getType() == 'R')
	drawRes(netval[a],netval[b],offset);
	else if(comp[i].getType() == 'C')
	drawCap(netval[a],netval[b],offset);	
	else if(comp[i].getType() == 'L')
    drawInd(netval[a],netval[b],offset);
	offset+= 15;
	
	}

	number[a][b]++;
  	number[b][a]++;


  }	

  
  footer();

  ofile.close();

}


#endif