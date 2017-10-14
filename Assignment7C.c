//NAME-NAVEEN ROLL-NUMBER -1601CS28
//PROBLEM dynamic programming algorithm to find out the minimum steps 
#include <stdio.h>
#include <stdlib.h>
int arr[4];//GLOBLE
//FIND MINIMUM
int min(int a,int b)
 {
   return (a>b)?b:a;
 }
 //FIND STEPS
int dp(int n)
{
int i , j ;

int temp[n+1];
for( i=0 ; i <= n ; i++)
    temp[i]=999999; //ASSIGN LARGE VALUES IN ARRAY 
 temp[0]=0;
 temp[1]=0;

 for ( i = 2; i <= n; ++i)
 {
   for (int j = 0; j < 4; ++j)
   {
     if(i%arr[j]==0)
     {
        if(temp[i/arr[j]]!=999999)
        temp[i]=min(temp[i/arr[j]]+1,temp[i]);
     }

   }
    temp[i]=min(temp[i-1]+1,temp[i]);
 }
   return temp[n];
}
int main()
{
 int n;
 printf("Enter a number:");
 scanf("%d",&n);
 arr[0]=2;
 arr[1]=3;
 arr[2]=5;
 arr[3]=7;
 if(n==0)
  printf("Impossible\n");
else
 printf("Minimum-%d",dp(n));
 
return 0;
}
