//name -Naveen Roll-1601cs28
//finding max and min digit number
//calling recursion
#include <stdio.h>
#include <stdlib.h>
//globle variable
int mindigitnum=15,maxdigitnum=-1,temp=0,temp1=0;
// finding max digit
int max_digit(int number){
	if(number==0)
		return maxdigitnum;//terminate condition
	if(number!=0)
	{
     temp=number%10;
     number=number/10;
     if(maxdigitnum<temp)
     	maxdigitnum=temp;
     max_digit(number);//calling
	}
}
//finding min digit
int min_digit(int number1){
	if(number1==0)
		return mindigitnum;//terminate condition
	if(number1!=0)
	{
     temp1=number1%10;
     number1=number1/10;
     if(mindigitnum>temp1)
     	mindigitnum=temp1;
     min_digit(number1);//recursion calling 
	}
}
int main(){
     int n;
     printf("Enter a number::");
     scanf("%d",&n);//input number
     printf("Max digit::");
     int maxdigit=max_digit(n);//call finding max number
     printf("%d\n",maxdigit );//print
      printf("Min digit::");
     int mindigit=min_digit(n);//call findingg min number
     printf("%d\n",mindigit );
	return 0;
}