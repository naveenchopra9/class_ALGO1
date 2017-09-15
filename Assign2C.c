x//Name-Naveen Roll no -1601cs28
//find the given integer
#include <stdlib.h>
#include <stdio.h>
//globle variable
int count=0;
//function call
 void function(int number){
 	if(number<1){
 		printf("Error\n");
     return;
 	}
 	else{
 		if(number==1){     //terminate condition
 			printf("final value %d \n",number );
 			return;
 		}
     else if (number%2!=0&&number!=1)
     {
     	printf("Next value :%d\n",number);
     	number=number*3+1;
     	
     	function(number);
     	count++;
     }
     else if(number!=1)
     {
     	printf("Next value :%d\n",number);
     	number=number/2;
    
     	function(number);
     	count++;
     }
 }
}
//main function
int main(){
	int n;
	printf("Read a integer-");
	scanf("%d",&n); //input integer
	function(n);// call function
	printf("number of steps-%d\n",count );//step printing
	return 0;
}