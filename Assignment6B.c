//NAME-NAVEEN ROLLNO-1601CS28
//PROBLEM OF PATH FOR MNIMIZE THE COST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//GLOBLE VARIABLE
int number1=0,number2=0;
char str[100][100];
int temp=0;
//FIND MINIMUM OF LEFT UPPER AND DIGONAL MINIMUM 
int min(int a, int b , int c)
  { 
   int min1=0;
   if(b>c)
     min1=(a>c)?c:a;
    else 
    min1=(a<b)?a:b;

    return min1;
  }
  //MINIMUM COST OF PATH IN GIVEN MATRIX
int findminimum(int row,int column,int arr[number1][number2])
{
   
   int i,j,arr1[number1+1][number2+1];
   //fist path for first row and column we can find and than find other array arr1 elements
       arr1[0][0]=arr[0][0];
   for( i =1 ;i < number1 ; i++)
      arr1[i][0]=arr[i][0]+arr1[i-1][0];
      
         for( i =1 ;i < number2 ; i++)
          arr1[0][i]=arr[0][i]+arr1[0][i-1];
  
   for(i =1 ; i < number1 ; i++)
     {
     for( j =1 ; j< number2 ; j++)
       {
        arr1[i][j]=arr[i][j]+min(arr1[i-1][j-1],arr1[i-1][j],arr1[i][j-1]);
        }
     }
    
     
     int number3=number1-1,number4=number2-1;
     while(number3>0||number4>0)
     {
      if(number4==0)
      {
      strcpy(str[temp],"downward");
      temp++;
      --number3;
      }
      else if(number3==0)
      {
        --number4;
        strcpy(str[temp],"leftward");
      temp++;
      }
     else  if(arr1[number3-1][number4-1]==min(arr1[number3-1][number4-1],arr1[number3][number4-1],arr1[number3-1][number4]))
      { 
      --number3;
      --number4;
      
      strcpy(str[temp],"diagonal");
      temp++;
      }
      else if((arr1[number3-1][number4]==min(arr1[number3-1][number4-1],arr1[number3][number4-1],arr1[number3-1][number4])))
      {
    
      --number3;
      strcpy(str[temp],"downward");
      temp++;
      }
      else if((arr1[number3][number4-1]==min(arr1[number3-1][number4-1],arr1[number3][number4-1],arr1[number3-1][number4])))
      {
        --number4;
        strcpy(str[temp],"leftward");
        temp++;
      }
     // printf("temp1-%d temp2-%d\n",number3,number4 );
     }
    // printf("temp-%d\n",temp );
     
   return arr1[number1-1][number2-1];
}
int main()
{
  int row,column;
  printf("Enter a row and columns:\n");
  scanf("%d %d",&row,&column);
  int i,j;
  int arr[row][column];
  number1=row;
  number2=column;
  printf("Enter integer of table(space separate):\n");
  for(i=0 ; i < row ;i++)
    {
       for( j =0 ; j< column ; j++)
         {
            scanf("%d",&arr[i][j]);
         }
         
     }
     int min=findminimum(row-1,column-1,arr);
     printf("Min Cost:%d",min);
     for( i =temp-1; i>=0 ; i--)
     {
         printf("\n%s",str[i]);
     }
     printf("\n");
return 0;
}
