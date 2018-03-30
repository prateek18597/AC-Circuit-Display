#include<bits/stdc++.h>
using namespace std;
#include "Start.h"

std::complex<double> x[100];
 
   // Number of unknowns
 
// function to reduce matrix to r.e.f.  Returns a value to 
// indicate whether matrix is singular or not
int forwardElim(std::complex<double>  mat[][7],int N);
 
// function to calculate the values of the unknowns
std::complex<double>* backSub(std::complex<double>  mat[][7],int N);

// function to get matrix content

std::complex<double>* gaussianElimination(std::complex<double> mat[][7],int N)
{
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat,N);
 
    /* if matrix is singular */
    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");
 
        /* if the RHS of equation corresponding to
           zero row  is 0, * system has infinitely
           many solutions, else inconsistent*/
        if (abs(mat[singular_flag][N]))
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");
 
        return x;
    }
 
    /* get solution to system and print it using
       backward substitution */
    return(backSub(mat,N));
}
 
// function for elemntary operation of swapping two rows
void swap_row(std::complex<double> mat[][7], int i, int j,int N)
{
    //printf("Swapped rows %d and %d\n", i, j);
 
    for (int k=0; k<=N; k++)
    {
        std::complex<double> temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}
 
// function to print matrix content at any stage
void print(double mat[][7],int N)
{
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<=N; j++)
            printf("%lf ", mat[i][j]);
 
    printf("\n");
}
 
// function to reduce matrix to r.e.f.
int forwardElim(std::complex<double> mat[][7],int N)
{
    for (int k=0; k<N; k++)
    {
        // Initialize maximum value and index for pivot
        int i_max = k;
        int v_max = abs(mat[i_max][k]);
 
        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = abs(mat[i][k]), i_max = i;
 
        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (! abs(mat[k][i_max]) )
            return k; // Matrix is singular
 
        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap_row(mat, k, i_max,N);
 
 
        for (int i=k+1; i<N; i++)
        {
            /* factor f to set current row kth elemnt to 0,
             * and subsequently remaining kth column to 0 */
            std::complex<double>  f = mat[i][k]/mat[k][k];
 
            /* subtract fth multiple of corresponding kth
               row element*/
            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;
 
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }
 
        //print(mat);        //for matrix state
    }
    //print(mat);            //for matrix state
    return -1;
}
 
int nothing()
{
    return 27;
} 
// function to calculate the values of the unknowns
std::complex<double>* backSub(std::complex<double> mat[][7],int N)
{
      // An array to store solution
 
    /* Start calculating from last equation up to the
       first */
    for (int i = N-1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][N];
 
        /* Initialize j to i+1 since matrix is upper
           triangular*/
        for (int j=i+1; j<N; j++)
        {
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j];
        }
 
        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/mat[i][i];
    }
    
    return(x);
    // printf("\nSolution for the system:\n");
    // for (int i=0; i<N; i++)
    //     cout<<x[i]<<endl;
}
 
