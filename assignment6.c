#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int a, int b)
{
	if(a>b)
		return b;
	else 
		return a;
}
int minimum(int *arr,int n , int sum)
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
        	temp[i][j]=999999;
		}
	}
		for ( i = 0; i <= n; ++i)
	{
		for ( j = 0; j <= sum; ++j)
		{
			printf("%d ",temp[i][j] );
		}
	  printf("\n");
	}
	printf("okk\n");
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
				if(min(temp[i-1][j],temp[i-1][j-arr[i-1]])!=999999)
				{
					if(temp[i-1][j-arr[i-1]]!=999999)
					{
						temp[i][j]=temp[i-1][j-arr[i-1]]+1;
					}
					else
						temp[i][j]=temp[i-1][j];
				}
			}
		}
	}
	for ( i = 0; i <= n; ++i)
	{
		for ( j = 0; j <= sum; ++j)
		{
			printf("%d ",temp[i][j] );
		}
	  printf("\n");
	}


	int sumpos[sum+1],temp1=0,sumsub[sum+1];
	for (int  i = 1	; i <= sum; ++i)
	{
	  if(temp[n][i]!=999999)
		{
		sumpos[temp1]=temp[n][i];
		sumsub[temp1]=i;
		 ++temp1;
	     }
	}

	printf("temp1=%d\n",temp1 );
	for ( i = 0; i < temp1; ++i)
	{
		printf("%d  %d\n ",sumpos[i],sumsub[i] );
	}
	printf("\n");
	printf("totalsum-%d\n", sum);
	int mindiff=999999,second=0,position;
	// for (int i = 0; i < temp1-1; ++i)
	// {
	// 	if(mindiff>=abs(sumsub[i]-sum))
	// 	{	
	// 		mindiff=abs(sumsub[i]-sum);
	// 	   second=sumsub[i];
	// 	   position=sumpos[i];
	// 	}
	// }
	 for (int i=0; i<temp1-1; i++)
      for (int j=i+1; j<temp1; j++)
          if (abs(sumsub[i] - sumsub[j]) < mindiff &&sumsub[i]+sumsub[j]==sum)
                mindiff = abs(sumsub[i] - sumsub[j]);
	int number2=second;
	int number1=n;
	printf("diff-%d\nsecond-%d \nposition%d\n",mindiff,second,position);
	// while(number1>=0&&number2>=0)
	//  {
 //          printf("%d %d\n",number1,number2 );
 //        //   if(number2-arr[number1-1]<=0)
 //        //   {
 //        //   	if(temp[number1][number2]==temp[number1-1][number2-arr[number1-1]])
 //        //   	{
 //        //   		printf("%d\n",arr[number1-1] );
 //        //   		number2=number2-arr[number1-1];
	//  		    // number1=number1-1;

 //        //   	}
 //        //   }
	//  	 if(temp[number1][number2]==temp[number1-1][number2-arr[number1-1]]+1)
	//  	{
	//  		printf("t1-%d t2-%d \n",temp[number1][number2],temp[number1-1][number2-arr[number1-1]]+1 );
	//  		printf("%d\n",arr[number1-1] );
	//  		number2=number2-arr[number1-1];
	//  		number1=number1-1;
	//  		printf("num1-%d num-2-%d\n", number1,number2);

	//  	}
	//  	else
	//  	{
	//  		number1--;
	//  	}

	//  }
	return temp[n-1][sum];
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
	printf("%d\n", sum);
	printf("%d\n",minimum(arr,n,sum) );
}