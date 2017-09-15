//NAME-NAVEEN ROLL NO -1601CS28
//Find the sum of given integer digit according to qus condition
#include <stdio.h>
#include <stdlib.h>
//digit sum according recursion condition
void sumofdigit(int number){
	int sum=0;
	  if((number/10)==0)
	  	return;
	while(number!=0){
	   int temp;
	   	   	temp=number%10;
	        number=number/10;
	        sum+=temp;
	
	}
	printf("->%d",sum );
	sumofdigit(sum);//call function
	    
}
int main(){
     
     int n;
     printf("Enter number::");
     scanf("%d",&n);//Enter a number
     printf("%d", n);
     sumofdigit(n);//calling function
	return 0;
}