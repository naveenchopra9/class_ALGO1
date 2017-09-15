#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int array[999999]={0};
int temp2=0;
int min(int a, int b)
{
	if(a>b)
		return b;
	else 
		return a;
}
void minimum(int *arr,int n , int sum)
{
	int temp[n+1][sum+1];
	int i,j;
	for (i = 0; i <= n; ++i)
	{
		for(j =0 ; j<= sum ; j++)
		{
			 if(j==0)
			 temp[i][0]=1;
			else
        	 temp[i][j]=9999999;
		}
	}
	for ( i = 1; i <= n; ++i)
	{
		for (j =sum; j>=1; --j)
		{
			if(j<arr[i-1])
				temp[i][j]=temp[i-1][j];
			else if(j==arr[i-1])
				temp[i][j]=temp[i-1][j-arr[i-1]];
			else
			{
				if(min(temp[i-1][j],temp[i-1][j-arr[i-1]])!=9999999)
				{
					if(temp[i-1][j-arr[i-1]]!=9999999)
					{
						temp[i][j]=temp[i-1][j-arr[i-1]]+1;
					}
					else
						temp[i][j]=temp[i-1][j];
				}
			}
		}
	}

	int sumpos[sum+1],temp1=0,sumsub[sum+1];
	for (int  i = 1	; i <= sum; ++i)
	{
	  if(temp[n][i]!=9999999)
		{
		sumpos[temp1]=temp[n][i];
		sumsub[temp1]=i;
		 ++temp1;
	     }
	}
	printf("\n");
	int mindiff=9999999,number3=sum/2,second=0,position;		
     	for (int i = 0; i < temp1-1; ++i)
     	{
     		if(mindiff>abs(sum-(2*sumsub[i])))
     		{
     			mindiff=abs(sum-(2*sumsub[i]));
     			second=sumsub[i];
			 	      position=sumpos[i];
     		}
     	}
	int number2=second;
	int number1=n;
	printf("Minimum Difference -%d\n First half sum-%d \nSecond half sum - %d\n",mindiff,second,sum-second);
   printf("First half elements\n");
	while(number1>=0&&number2>=0)
	 {
       	 	  if(temp[number1][number2]==temp[number1-1][number2-arr[number1-1]]+1)
	 	{
	 		printf("%d\n",arr[number1-1] );
	 		array[temp2++]=number1-1;
	 		number2=number2-arr[number1-1];
	 		number1=number1-1;
	 	}
	 	else  if(temp[number1][number2]!=temp[number1-1][number2]&&temp[number1][number2]==temp[number1-1][number2-arr[number1-1]])
          {
          	{
          		printf("%d\n",arr[number1-1] );
          		    array[temp2++]=number1-1;
          			number2=number2-arr[number1-1];
	 		        number1=number1-1;	  
          	}
          }

	 	else
	 	{
	 		--number1;
	 	}

	 }
;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	printf("sum->%d\n", sum);
    minimum(arr,n,sum);
	printf("Second half elements-\n");
	for(int j =0 ; j< n ; j++)
	{
		int temp3=1;
	for (int i = 0; i < temp2; ++i)
	{
		if(j==array[i])
			   temp3=0;
	}
    if(temp3!=0)
	printf("%d\n",arr[j] );
    }
}