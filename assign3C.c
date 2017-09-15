//NAME-NAVEEN ROLL-1601CS28
//FIND THE MAXIMUM SUM OF SUBARRAY
#include <stdio.h> //HEADER
#include <stdlib.h>
//FIND THE SUM OF THREE NUMBER
int sumofthree(int a,int b,int c){
  int number=(a>b)?a:b;
  return (number>c)?number:c;
}
//SUM OF RIGHT AND LEFT SUM IN SUM ARRAY
int sumofsubarray(int array[],int left,int mid,int right)
{
 int sumofright=-1000,sumofleft=-1000;
 int i,sum=0;
  //RIGHT SUM OF SUBARRAY  
 for(i=mid+1;i<=right; i ++)
   {
    sum+=array[i];
    if(sum>sumofright)
      sumofright=sum;
   }
 //LEFT SUM OF SUB ARRAY
 sum =0;
  for(i=mid;i>=left; i --)
   {
    sum+=array[i];
    if(sum>sumofleft)
      sumofleft=sum;
   }
//RETURN RIGHT AND LEFT  SUM
  return sumofleft+sumofright;
}
//RECURSION FOR DEVIDING ARRAY IN TWO PART
int maxsubarray(int array[],int left,int right){
  if(left==right)
   return array[left];
  //MID POSITION
   int mid=(left+right)/2;
//LEFT SUM 
   int leftsum=maxsubarray(array,left,mid);
//RIGHT SUM
   int rightsum=maxsubarray(array,mid+1,right); 
//SUM OF SUB ARAY 
   int sumofsub= sumofsubarray(array,left,mid,right);
  return sumofthree(rightsum,leftsum,sumofsub);
//RETURN SUM OF MAX SUBARRAY
}
int main(){
  int n ;
  printf("Enter a number::");
  scanf("%d",&n);
  int i,array[n];
  printf("Enter array ::");
  for(i= 0 ; i< n ; i++)
  scanf("%d",&array[i]);
  int p=maxsubarray(array,0,n-1);
//PRINT MAXIMUM SUBARRAY
  printf("%d",p);
 }

