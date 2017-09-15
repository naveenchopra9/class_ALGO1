//Name-Naveen Rollno-1601cs28
//sorting by find max and min
#include <stdio.h>
#include <stdlib.h>
//globle array
 int array[10001];
 //swaping of two number in array
void swapnumber(int * number1 , int *number2){
	int temp=*number1;
	    *number1=*number2;
	    *number2=temp;
}
//sorting according to given qus
void sortarray(int array[], int first ,int last){
     int i ,count1,count2 ,max=-1,min=10000;
     if(first+1>=last){
     	return;
     }
     //finding position of max and minimam
     //and find minimam and maximam eliment
	for(i =first ; i <= last ; i++){
            if(max<array[i]){
            	max=array[i];
            	count1=i;}
             if (min>array[i]){
            	min=array[i];
            	count2=i;
            }
	}
	//if max are not in first position
	if(count1!=first){
		 	swapnumber(&array[count1],&array[first]);//call sort function

		      if(count2==first){	
		               count2=count1;
		  }
	}
	swapnumber(&array[count2],&array[last]);
	sortarray(array,first+1,last-1);//recursion call
}
int main(){
	//define
     int number;
     printf("Enter a number::");
     scanf("%d",&number);
     int i;
     printf("Enter array elements::");
     for ( i = 0; i < number; ++i)
     {
     	scanf("%d",&array[i]);
     }
     sortarray(array,0,number-1);//call sorting fuction
     printf("\nMaximam::%d \nMinimam::%d",array[0] ,array[number-1]);
	return 0;
}