//Name -Naveen Roll- 1601CS28
//Date- 31/07/2016
#include <stdio.h>
#include <stdlib.h>
//largest digit of answer of first part
int max=0;
int LargeDigit(int number)
    {
      int num=0,num1=0;//initilizing variable
      if(number!=0)
        {
          num=number%10; //finding divider of number
          number=number/10;
          if(num>max)
             max=num;      //mxinum digit   
          LargeDigit(number); //recursion calling 
          num1++;
        }  
        if(num1!=0) 
          return max;   //output maxinum
        else
        return 0;   
    }
//main function
int main()
{
	int i, j,n;
	printf("Enter the number::");
	scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; ++i)
    {
    	scanf(" %d",&arr[i]);
    }
    int max,include=arr[0],exclude=0;
    //she will get maximum number of chocolates
  for(i=1 ; i < n ; i++)
  {
      int oldinclude=include;  
      include=exclude+arr[i];
      if(oldinclude>exclude)
      exclude=oldinclude;
  }
  if(include>exclude)
     max=include;
  else
    max=exclude;
    printf("maximum number of chocolates:%d\n",max );//maximam chocolates
  printf("\nmaximam digit::%d",LargeDigit(max));//output maximum digit
}