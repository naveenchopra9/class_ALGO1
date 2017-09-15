//Name-naveen roll -1601cs28
//find odd digit number
#include <stdio.h>
#include <stdlib.h>
//globle integer
int odddigit=0;
//recursion calling 
int count_odd_digit(int number){
 int temp=0;//temp variable
    if (number==0)
    	return odddigit;//terminate condition
	if(number!=0){
		temp=number%10;
		number=number/10;
		 if(temp%2!=0)
		 	odddigit++;
		 count_odd_digit(number);//recursion calling
	}
}
int main(){
int n;
printf("Enter a number::");
scanf("%d",&n);//input integer value
int count=count_odd_digit(n); //call and find number
printf("%d\n",count );//number printing
return 0;
}
