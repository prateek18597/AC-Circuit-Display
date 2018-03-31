#include <iostream>
#include <Eigen>
using namespace std;
using namespace Eigen;
int main()
{
   // Matrix2f A, b;
   // A << 2, -1, -1, 3;
   // b << 1, 2, 3, 1;
   // cout << "Here is the matrix A:\n" << A << endl;
   // cout << "Here is the right hand side b:\n" << b << endl;
   // Matrix2f x = A.ldlt().solve(b);
   // cout << "The solution is:\n" << x << endl;

   std::complex<double> iota(0,1);


   Matrix<std::complex<double>,3,3> A ;

   A<<                
   										          
                                            0.1 , -0.1 , 1	,					
   										          
                                            -0.1 ,  0.1 + (iota)*(-0.101) , 0,
                                           
                                           1 , 0 , 0
   cin>>n;                                                      ;
   Matrix<std::complex<double>,n,1>  B ;

   B<<   0 ,0 , 10 ;

        cout<<(A.inverse()*B);                                   
}