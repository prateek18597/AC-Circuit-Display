#ifndef START_H
#define START_H
#include "Component.h"
#include "Source.h"
#include "Net.h"
#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
#include <complex>
#include <cmath>
using namespace std;
#include <vector>
#include<algorithm>
#include <eigen3/Eigen/Dense>

using namespace Eigen;



extern Source sour[10];
extern int s_index;
extern Component comp[100];
extern int c_index;
extern Net net[100];
ofstream ofile;
ofstream outfile;

void html()
{   
    ofile<<"<html>\n";
    ofile<<"<head><title>AC Circuit Solver</title>\n";
    ofile<<"<script type=\"text/javascript\" src=\"svg-pan-zoom.js\">\n";
    
    ofile<<"</script>\n";
    ofile<<"<script type=\"text/javascript\" src=\"script.js\">\n";
    ofile<<"</script>\n";
    
    ofile<<"</head><body>\n";
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
 

// ofile<<"<svg height=\""<<2000<<"\" width=\""<<2000<<"\">"<<endl;
ofile<<"<div id=\"container\" style=\"width: 1400px; height: 700px;\">\n";
ofile<<"<svg id=\"circuit\" xmlns=\"http://www.w3.org/2000/svg\"";
ofile<<"style=\"overflow: hidden; display: inline; width: inherit;";
ofile<<"min-width: inherit; max-width: inherit; height: inherit;";
ofile<<"min-height: inherit; max-height: inherit; \" version=\"1.1\"";
ofile<<"xmlns:xlink=\"http://www.w3.org/1999/xlink\"";
ofile<<"xmlns:ev=\"http://www.w3.org/2001/xml-events\">\n";
 // height corresponds to vertical and width is horizontal

}

// Epilog for the SVG image

void footer() {
  ofile << "</svg>\n</div>" << endl;
  ofile<<"<div id=\"selenium-highlight\"></div>\n";
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


bool compareFreq(Source a,Source b)
{
    return (a.getFreq()<b.getFreq());
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

   ofile<<"<text x=\""<<x+l1+10<<"\" y=\""<<246+offset<<"\" fill=\"black\">R"<<n<<"="<<val<<"Ohm </text>";
   line(net1,250,offset,'v',0);
   line(net2,250,offset,'v',0);
    
}
  

void drawCap(int net1,int net2,int offset,int n,float val)
{
  int diff=abs(net2-net1);

  float l1=(diff-22)/2 ;

  int x=min(net1,net2);

    line(x,250+offset,l1,'h',1);
    capc(x+l1,250+offset);
    line(x+l1+22,250+offset,l1,'h',1);
  
    ofile<<"<text x=\""<<x+l1+20<<"\" y=\""<<246+offset<<"\" fill=\"black\">C"<<n<<"="<<val<<"F</text>";

    line(net1,250,offset,'v',0);
    line(net2,250,offset,'v',0); 

}

void drawInd(int net1,int net2,int offset,int n,float val)
{

  int diff=abs(net2-net1);

  float l1=(diff-40)/2 ;

  int x=min(net1,net2);
  line(x,250+offset,l1,'h',1);
    Indc(x+l1,250+offset);
    line(x+l1+40,250+offset,l1,'h',1);

  ofile<<"<text x=\""<<x+l1+20<<"\" y=\""<<246+offset<<"\" fill=\"black\">L"<<n<<"="<<val<<"F</text>";

   line(net1,250,offset,'v',0);
   line(net2,250,offset,'v',0); 


}

void genmaim() {
  unsigned x, y;
  
  bool N[100];

  outfile.open("output.txt");  
  ofile.open("top.html");
  html();

  for(int i=0;i<100;i++)
  N[i]=false; 

  
  
  int netval[100];
  int netvarnum[100];
  int xo=0;

  std::vector<int> enunet;

  for(int i=0;i<100;i++)
  { netval[i]=-1; 
    netvarnum[i]=0;
  }

  

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
    {  numnets++;  
        
    }  
  }
  

  header(numnets);

  
  

  
  
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
    drawCap(netval[a],netval[b],0,in,val);  
    else if(comp[i].getType() == 'L')
    drawInd(netval[a],netval[b],0,in,val);

  }
  else{

  if(comp[i].getType() == 'R')
  drawRes(netval[a],netval[b],offset,in,val,c);
  else if(comp[i].getType() == 'C')
  drawCap(netval[a],netval[b],offset,in,val); 
  else if(comp[i].getType() == 'L')
  drawInd(netval[a],netval[b],offset,in,val);
  offset+= 80;
  
  }

  number[a][b]++;
  number[b][a]++;


  }


  for(int i=0;i<scount;i++)
  {
        int a = sour[i].getInitialNet();
        int b = sour[i].getFinalNet();

        
        if(N[a]==false)
        { 
          netval[a]=s-200;
          N[a]=true;
          s+=100;
        } 

        if(N[b]==false)
        {
          netval[b]=s-100;
          N[b]=true;
          s+=100;
        } 
  }


       for(int i=0;i<100;i++){
       
       if(N[i]==true){ 
       netvarnum[i]=xo;
       enunet.push_back(i);
       xo++;
       }
     }
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

  int sourcevarnum[scount];

  int viset=-80;
  for(int i=0;i<scount;i++)
  {
      int a = sour[i].getInitialNet();
      int b = sour[i].getFinalNet();

     sourcevarnum[i]=0;
      
     float dco=sour[i].getDCO();
     float amp=sour[i].getAmpli();
     float delay=sour[i].getDelay();
     float freq=sour[i].getFreq();  
     float damp=sour[i].getDamp();   

    


      if( sour[i].getType() == 'V' )
      { DrawVolt(netval[a],netval[b],viset);  
        sourcevarnum[i]=xo;
        xo++;
      }  
      else if(sour[i].getType() == 'I')
      DrawCurr(netval[a],netval[b],viset);
      
      float d= abs(netval[a]-netval[b]);
      d=d/2;
      d=min(netval[a],netval[b]) + d;
      ofile<<"<text x=\""<<d-2<<"\" y=\""<<225+viset<<"\" fill=\"black\"> SINE("<<dco<<" "<<amp<<" "<<freq<<"Hz "<<delay<<" "<<damp<<") </text>";

      viset-= 80;
  
    //SINE ( < DCOf f set> < Amplitude> < F requency> < Delay> < DampingF actor>)

      number[a][b]++;
      number[b][a]++;

  } 

   

  const int totalvar = xo ;

  int voltnum = totalvar - numnets - 1 ;
   
  // for voltage sources convention is that current will flow from initial net to final net
  
  //cout<<totalvar;

  std::complex<double> iota(0,1);
  
  std::complex<double> zero(0,0);

  std::complex<double> VolComplex[100];

  std::complex<double> CurrComplex[100];

  for(int inn=0;inn<100;inn++)
  VolComplex[inn]=zero;

  for(int inn=0;inn<100;inn++)
  CurrComplex[inn]=zero;  

 // for(int inn=0;inn<enunet.size();inn++)
 // cout<<enunet[inn]<<" ";

  // for(int i=0;i<scount;i++)
  // cout<<sourcevarnum[i]<<endl;   // use krna hune yaad rakhen
    
 
  cout<<endl; 

  Matrix<std::complex<double>,Dynamic,Dynamic> matrix(totalvar,totalvar+1) ;
  std::complex<double> ans[totalvar][1] ;




  for(int i=0;i<scount;i++)
  {   
      
      
  
      for(int p=0;p<totalvar;p++)
       {
          for(int q=0;q<=totalvar;q++)
            matrix(p,q)=zero;

       } 



      

      for(int p=0;p<totalvar;p++)   
       ans[p][0]=zero;  

      int siz = enunet.size() ;
    
      //cout<<siz;
      float freq = sour[i].getFreq() ; 

      //cout<<freq;
      double omega = 2 * 3.14 * freq ;

     for(int j=0;j< siz ;j++)
     {
        int node = enunet[j]  ;
        
        
        int sn = net[node].getSourceCount();
        int cn = net[node].getComponentCount();  

        //cout<<node<<" "<<cn<<" "<<sn<<endl; 
        for(int k=0;k<cn;k++)
        {   

            Component c = net[node].getComponent(k) ;
            
            int a = c.getInitialNet();
            
            int b = c.getFinalNet();

            //cout<<a<<" "<<b<<endl;
           
            char ch = c.getType();
            
            double fl = c.getVal(); 

            if(node == a)
            {
                int pos = netvarnum[a];
                int neg = netvarnum[b];

               if(ch == 'R')
               {  
                  matrix(j,pos) += 1/fl ;
                  matrix(j,neg) -= 1/(fl)  ;
                  
               }
               else if(ch == 'C')
               {
                  matrix(j,pos) += iota*omega*fl ;
                  matrix(j,neg) -= iota*omega*fl ;
               } 
               else
               {  
                  matrix(j,pos) -= iota/(omega*fl)  ;
                  matrix(j,neg) += iota/(omega*fl) ;

               } 
 

            }
            else
            {

                int pos = netvarnum[b];
                int neg = netvarnum[a];
                //cout<<pos<<" a"<<neg<<endl;
               if(ch == 'R')
               {  
                  matrix(j,pos) += 1/fl ;
                  matrix(j,neg) -= 1/(fl)  ;
                  
               }
               else if(ch == 'C')
               {
                  matrix(j,pos) += iota*omega*fl ;
                  matrix(j,neg) -= iota*omega*fl ;
               } 
               else
               {  
                  matrix(j,pos) -= iota/(omega*fl)  ;
                  matrix(j,neg) += iota/(omega*fl) ;

               } 



            }  



        } 


        int activid = sour[i].getId();
        //cout<<activid<<endl;
        for(int k=0;k<sn;k++)
        {
          Source s=net[node].getSource(k);

          char ch =  s.getType();

          int rnid = s.getId();

          //cout<<rnid<<endl;
          double fl = s.getAmpli();

          int matvar = sourcevarnum[rnid];

          int a = s.getInitialNet();

          int b = s.getFinalNet();

          int fnlnet = netvarnum[b];

          if(activid == rnid)
          {   
              if(ch == 'I')
              {   
                  if( node = a)  
                  {  ans[j][0] += -1 * fl;
                     ans[fnlnet][0]+=fl;  
                  }

              }  
              else
              {   
                  if(node == a)
                  { 
                    matrix(j,matvar) += 1 ;
                    matrix(fnlnet,matvar) += -1 ;

                    matrix(matvar,j) += 1;
                    matrix(matvar,fnlnet) += -1;

                    ans[matvar][0] += fl;
                  }  


              }  


          }  
          else
          {

            if(ch = 'V')
            {     
                  if(a = node)
                  {   
                        matrix(j,matvar) += 1 ;
                        matrix(fnlnet,matvar) += -1 ;

                        matrix(matvar,j) += 1;
                        matrix(matvar,fnlnet) += -1;
                  }      


            }              

            // for ch='I' do nothing here  

          }  

        
        } 

     } 

   for(int vx=0;vx<totalvar;vx++)  
   {

      matrix(vx,totalvar) = ans[vx][0];

   }

   //cout<<totalvar;
   //matrix[3][0]=0;
   //gaussianElimination(matrix,4);
   
   Matrix<std::complex<double>,Dynamic,Dynamic> rmat(totalvar-1,totalvar-1);

   for(int m=1;m<totalvar;m++)
   {
         for(int p=1;p<totalvar;p++)
         rmat(m-1,p-1)=matrix(m,p);

        
   } 
    
   // for(int m=0;m<totalvar;m++)
   // {
   //       for(int p=0;p<=totalvar;p++)
   //       cout<<matrix(m,p)<<" ";

   //     cout<<endl;
        
   // }


  Matrix<std::complex<double>,Dynamic,1> B(totalvar-1,1);   
  Matrix<std::complex<double>,Dynamic,1> soln(totalvar-1,1);
  //B << 0,0,10;

  for(int g=1;g<=totalvar-1;g++)
  {
    B(g-1,0)=ans[g][0];
  } 
  
  soln = (rmat.inverse()*B) ;
  

  for(int cn=1;cn<enunet.size();cn++)
  { 
    int var = enunet[cn] ;
    VolComplex[var] = soln(cn-1,0);
  } 

  for(int cn=0;cn<scount;cn++)
  { 
      int var = sourcevarnum[cn] ;

      if( var!=0 )
      {
        CurrComplex[cn] = soln(var-1,0);

      } 

  } 
  // for(int inn=0;inn<10;inn++)
  // cout<<VolComplex[inn]<<" ";  

 // cout<<soln<<endl;
  std::complex<double> Istore[100];

  outfile<<"FREQ "<< freq <<"hz" <<endl;
  cout <<"FREQ "<< freq <<"hz" <<endl;
  
  outfile<<"Voltage\n";  
  cout<<"Voltage\n";

  for(int count=0;count<num;count++)
  {   
      int a = comp[count].getInitialNet();
      int b = comp[count].getFinalNet();
      int number = comp[count].getNum();
      char tp = comp[count].getType() ;
      float fl = comp[count].getVal();

      std::complex<double> flc (fl,0) ; 

      std::complex<double> Vstore = VolComplex[a] - VolComplex[b] ;
      
      if( tp == 'R')
      Istore[count] = (Vstore)/flc  ;
      else if(tp == 'C') 
      { 
        std::complex<double> Z(0,0)  ;

        Z +=  (iota*omega*flc);

        //cout<<"\na"<<Z<<" "<<Vstore<<endl;
        Istore[count] = (Vstore)*Z ; 

        //cout<<endl<<abs(Istore[count])<<endl;
      }   
      else  
      { 
        std::complex<double> Z  (iota*omega*flc) ;
        Istore[count] = (Vstore)/Z ; 
      }

      double mag = abs(Vstore);
      double argu = arg(Vstore)*(180)/3.14;
      comp[count].addVoltage(real(Vstore),imag(Vstore));
      outfile<<tp<<number<<" "<<mag<<" "<<argu;
      
      cout<<tp<<number<<" "<<mag<<" "<<argu;
      
      outfile<<endl;
      cout<<endl;
  }


  for(int count=0;count<scount;count++)
  { 
     char c = sour[count].getType();
     int nu = sour[count].getNum();

     int a = sour[count].getInitialNet();
     int b = sour[count].getFinalNet(); 

     std::complex<double> Vstore = VolComplex[a] - VolComplex[b] ;

     double mag=abs(Vstore);
   double argu = arg(Vstore)*(180)/3.14;
      sour[count].addVoltage(real(Vstore),imag(Vstore));
     cout<<c<<nu<<" "<<mag<<" "<<argu<<endl;
     outfile<<c<<nu<<" "<<mag<<" "<<argu<<endl;


  } 

  outfile<<"\nCurrent"<<endl;
  cout<<"\nCurrent"<<endl;

  for(int count=0;count<num;count++)
  {
    char tp = comp[count].getType() ;
    int number = comp[count].getNum();

    double mag = abs(Istore[count]);
    double argu = arg(Istore[count])*(180)/3.14;
    
    comp[count].addCurrent(real(Istore[count]),imag(Istore[count]));
    outfile<<tp<<number<<" "<<mag<<" "<<argu<<endl;
    cout<<tp<<number<<" "<<mag<<" "<<argu;

    cout<<endl;
  } 
   // below is current

  for(int count=0;count<scount;count++)
  {
     char c = sour[count].getType();
     int nu = sour[count].getNum();

    if(c == 'I') 
    { 
      float val = sour[count].getAmpli();
      sour[count].addCurrent(val,0.0);
      outfile<<c<<nu<<" "<<val<<" 0.0" ;
      cout<<c<<nu<<" "<<val<<" 0.0" ;
    }  
    else
    { std::complex<double> neg (-1,0) ;

      CurrComplex[count] = CurrComplex[count] * neg ; 
      double mag= abs(CurrComplex[count]);
      double argu = arg(CurrComplex[count])*(180)/3.14;
      sour[count].addCurrent(real(CurrComplex[count]),imag(CurrComplex[count])); 
      outfile<<c<<nu<<" "<<mag<<" "<<argu ;
      cout<<c<<nu<<" "<<mag<<" "<<argu ;

    } 

    outfile<<endl;
    cout<<endl;
  } 
  outfile<<endl;
  cout<<endl; 


  }  

 
  
  footer();
  close();
  ofile.close();
  outfile.close();

}


#endif
