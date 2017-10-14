//NAME-NAVEEN ROLLNO-1601CS28
//PROBLEM-sum of final pair list is  maximized.
#include <stdio.h>
#include <stdlib.h>
//FIND MAX OF TWO NUMBER
int  max(int a,int b)
  {
  return (a>b)?a:b;
  }
  //SWAP TO ARRAY ELEMENT IN ARRAY
void swap(int *a,int *b)
{
 int temp = *a;
    *a=*b;
    *b=temp;
}
//SORTING OF ARRAY  USING QUICK SORTING
int partition(int arr[],int l,int r)
{
int rend=arr[r];
int j,i = l-1;
for( j = l; j<=r-1 ; j++)
  {
  if(arr[j]<=rend)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }
   }
   swap(&arr[i+1],&arr[r]);
   return i+1; 
}
void sort(int arr[],int l,int r)
{
 if(l<=r)
 {
  int p=partition(arr,l,r);
   sort(arr,l,p-1);
   sort(arr,p+1,r);
 }
}
//MAKE PAIRING IN ARRAY TO FIND THE MAXIMUM OF NUMBER IN ARRAY
int pair(int arr[],int n ,int m)
{
   	int i,temp[n];
   	temp[0]=0;
    int temp1[n+1];
    temp1[n-1]=0;
   	printf("PAIRING OF ALL ELEMENT DIFF OF TWO ELEMENT IS LESS OR EQUAL  %d::",m);
   	for( i = 1 ; i < n ; i++)
   	{
   	  temp[i]=temp[i-1];
   	  if((arr[i]-arr[i-1])<=m)
   	    { 

   	    printf("(%d,%d), ",arr[i-1],arr[i]);
   	    if(i==1)
   	       temp[i]=max(temp[i],arr[i]+arr[i-1]);
   	     else
         {
   	      temp[i]=max(temp[i],temp[i-2]+arr[i]+arr[i-1]);
   	     }
   	    }
   	}
    printf("\n");
    printf("ELEMENT WHICH HAVE MAXIMUM SUM IN ARRAY ::");
    for (int i = n-1; i>=1 ; --i)
    {
      if(arr[i]-arr[i-1]<=m)
      {
        printf("(%d,%d ), ",arr[i-1],arr[i] );
        i--;
      }
    }
   	return temp[n-1]; 

}
int main()
{
int n;
printf("Enter array size::");
scanf("%d",&n);
int a[n];
int i,m;
printf("Enter array element:: ");
for(i =0 ; i < n ; i++)
    scanf("%d",&a[i]);
    sort(a,0,n-1);
    printf("Enter diff of element ::");
   scanf("%d",&m);
    printf("\nMAXIMUM SUM ::%d \n",pair(a,n,m));
return 0;
}
