//NAME-NAVEEN ROLL - 1601CS28
//find binary equivent  
#include <stdio.h>
#include <stdlib.h>
//globle array
int arr[10001],i=0;
//call function find binary
void binary_equ(int number){
	if(number==0)
		return; //terminate condition
	else
	{
	 	arr[i]=number%2;
      i++;
	    binary_equ(number/2); //recursion calling
	}
}
int main(){
    int n;
    printf("Enter a number::");
    scanf(	"%d",&n);//input number
    binary_equ(n);
    int j;
    printf("Binary equivent::");
    for ( j= i-1; j >=0; --j)
    {
    	printf("%d", arr[j]);//binary oder
    }
	return 0;
}