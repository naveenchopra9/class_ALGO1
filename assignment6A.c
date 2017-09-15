//NAME-NAVEEN ROLLNO-1601CS28
//PROBLEM FIND THE COINS OF SUM OF COINS
#include <stdio.h>
#include <stdlib.h>
int arr2[10001];
//MINIMUM NUMBER OF TWO NUMBER
int min(int a,int b)
{
  	return (a<b)?a:b;
}
void print(int arr[],int arr2[],int sum)
{
 	int start=sum;
    while(start!=0)
    {
    	printf("%d ",arr[arr2[start]]);
    	start=(start-arr[arr2[start]]);
    }
 }
//TO FIND THE COINS OF SUM ARE EQUALS
int minimum(int arr[],int n,int sum)
{
  //TEMP ARRAY
	int arr1[sum+1];
	arr1[0]=0;
	arr2[0]=-1;
	for (int i = 1; i <= sum; ++i)
	{
		arr1[i]=999999;
		arr2[i]=-1;
	}
  for (int i = 0; i < n ; ++i)
   {
   	 
   	 for (int j = 1; j <= sum; ++j)
   	 {
   	 	if(j >= arr[i])
   	 	{
   	 			if(arr1[j]>1+arr1[j-arr[i]])
   	 			{
   	 		      arr1[j]=min(arr1[j],1+arr1[j-arr[i]]);
   	 		       arr2[j]=i;
   	 		   }
   	 	}
   	 }
   }
   	return arr1[sum-1];
}
// main function 
int main()
{
	int n;
  //input
  printf("Enter number of coins:");
	scanf("%d",&n);
	int arr[n];
  printf("Enter a array  of coins(space separated:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int sum;
  //Enter sum of which we want to sum
  printf("Enter sum of coins :\n");
	scanf("%d",&sum);
  printf("Output minimum number of coins:\n");
	printf("minimum=%d\n",minimum(arr,n,sum));
	printf("Minimum number of coin :");
	print(arr,arr2,sum);
}