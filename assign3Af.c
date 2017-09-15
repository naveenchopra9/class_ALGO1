//NAME-NAVEEN ROLLNO-1601CS28
// find the median of n positive integers.
#include <stdio.h>
#include <stdlib.h>
//GLOBLE ARRAY AND SIZE OF  ARRAY
int n;
int arr[10001];
// SWAP TWO INTEGER 
      void swap(int *a,int *b){
        int temp = *a;
              *a=*b;
            *b=temp;
      }
  //CHOOSE ACORRDING TO RENDOM VALUE IN ARRAY USING RENDOMPOSTION AND SWAP ACORREDING DESENDING ORDER
      int partition(int arr[],int left ,int right){

          int rendom=arr[right];   //PIVOT OF CHOOSE LAST ELEMENT OR ARRAY
          int i,temp=left-1;  
          for(i =left ; i<=right; i++){ //SEACHONG POSITION OF PIVOT
           if(arr[i]<rendom){
             temp++;
             swap(&arr[temp],&arr[i]);
            }
        }
//SET PIVIT POSITION
   swap(&arr[temp+1],&arr[right]);
  return temp+1; //RETURN POSTION
}
//TAKE REANDOM ELEMENT AND TRANSFER IT TO ENDING ELEMENT AND MAKE LAST ELEMENT AS A PIVOT
int rendomposition(int left,int right){
      int temp=left+rand()%(right-left+1);//RENDOM INDEX OF ANY ELEMENT
       swap(&arr[right],&arr[temp]);
       return partition(arr,left,right); //CALL PARTITION TO SORT

}
//rendom select element  and find the median of  srorted array
int rendomselect(int arr[] ,int left,int right ){
     if(left<=right){
         int number1=rendomposition(left,right); //find the rendom position and set it right position
           if(rendomselect(arr ,left,number1-1)==(n-1)/2)
            return (n-1)/2;
          else
            return rendomselect(arr,number1+1,right);

         }
     }
int main(){
 printf("Enter a number::");
 scanf("%d",&n);
 int i;
 for(i =0 ; i < n ; i++){
   scanf("%d",&arr[i]);
 }
 //divideconq(arr,0,n-1);//CALL FUNCTION
 int q=rendomselect(arr,0,n-1);
 printf("Median::%d\n",arr[q] );
}
