// Please use -lm I'm using pow() function in program
// NAME-NAVEEN ROLLNO-1601CS28
//DATE - 27/08/17
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//add two matrix in n*n time  and store in C matrix 
void addmatrix(int number,int A[][number],int B[][number],int C[][number]){
	 int i,j;
	for ( i = 0; i <number ; ++i)
	{
		for ( j = 0; j <number ; ++j)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
}
// merge four A1,A2,A3,A4 in C[][] matrix and size of this matrix is two times
void Merge(int n,int A1[][n],int A2[][n],int A3[][n],int A4[][n],int C[][2*n]){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j]=A1[i][j];
			C[i][j+n]=A2[i][j];
			C[i+n][j]=A3[i][j];
			C[i+n][j+n]=A4[i][j];	
		}
	}

}
//divide D matrix in four matrix size of this matrix is half of it's
void Divide (int n ,int D[][2*n],int D1[][n],int D2[][n],int D3[][n],int D4[][n])
{
	for (int i = 0; i < n; ++i)
	       {
	       	 for (int j = 0; j < n ; ++j)
	       	 {
		       	 	D1[i][j]=D[i][j];
		       	 	D2[i][j]=D[i][j+n];
		       	 	D3[i][j]=D[i+n][j];
		       	    D4[i][j]=D[i+n][j+n];
	       	 }
	       }       
}
//maltipliy two matrix 
void multipliy(int n,int A[][n],int B[][n],int C[][n]){
	//divide A,B in four-four matrix using divide and conquer method 
	     int A11[n/2][n/2],A12[n/2][n/2],A21[n/2][n/2],A22[n/2][n/2];
		 int B11[n/2][n/2],B12[n/2][n/2],B21[n/2][n/2],B22[n/2][n/2];
		 int C1[n/2][n/2],C2[n/2][n/2],C3[n/2][n/2],C4[n/2][n/2];
		 //call divide function
		 Divide(n/2,A,A11,A12,A21,A22);
		 //call divide function
		 Divide(n/2,B,B11,B12,B21,B22);
		 //terminate condition
	if(n==2)
		{	
         
          C1[0][0]=(A11[0][0]*B11[0][0])+(A12[0][0]*B21[0][0]); 
          C2[0][0]=(A11[0][0]*B12[0][0])+(A12[0][0]*B22[0][0]); 
          C3[0][0]=(A21[0][0]*B11[0][0])+(A22[0][0]*B21[0][0]); 
          C4[0][0]=(A21[0][0]*B12[0][0])+(A22[0][0]*B22[0][0]);
		}
	else
	{
		//store two matrix first divide part storing
		 int M1[n/2][n/2],M2[n/2][n/2];
		 multipliy(n/2,A11,B11,M1);
		 multipliy(n/2,A12,B21,M2);
	     addmatrix(n/2,M1,M2,C1);
	    //store two matrix second divide part storing
         int M3[n/2][n/2],M4[n/2][n/2];
		 multipliy(n/2,A11,B12,M3);
		 multipliy(n/2,A12,B22,M4);
	     addmatrix(n/2,M3,M4,C2);
	     //store two matrix thred divide part storing
	     int M5[n/2][n/2],M6[n/2][n/2];
		 multipliy(n/2,A21,B11,M5);
		 multipliy(n/2,A22,B21,M6);
	     addmatrix(n/2,M5,M6,C3);
	     //store two matrix forth divide part storing
	     int M7[n/2][n/2],M8[n/2][n/2];
		 multipliy(n/2,A21,B12,M7);
		 multipliy(n/2,A22,B22,M8);
	     addmatrix(n/2,M7,M8,C4);
	}
	//merge all four matrix in C
	Merge(n/2,C1,C2,C3,C4,C);
}
int main(){
	int number;
	printf("Enter a number::");
	scanf("%d",&number);
	int A[number][number],B[number][number];
	printf("Enter matrix just like n*n matrix:\n");
	printf("Enter first matrix:\n");
	for (int i = 0; i < number; ++i)
	{
  		for (int j = 0; j < number; ++j)
  		{
  			scanf("%d",&A[i][j]);
  		}
	}
	printf("Enter second matrix:\n");
	for (int i = 0; i < number; ++i)
	{
  		for (int j = 0; j < number; ++j)
  		{
  			scanf("%d",&B[i][j] );
  		}
	}
	int C[number][number];
	//call matrix multipliy
	multipliy(number,A,B,C);
	for(int i =0 ; i< number ; i++)	{
  		for (int j = 0; j < number; ++j)
  		{
  			printf("%d ",C[i][j] );
  		}
  		printf("\n");
	}

}