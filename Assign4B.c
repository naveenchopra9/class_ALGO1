// Please use -lm I'm using pow() function in program
// NAME-NAVEEN ROLLNO-1601CS28
//DATE - 27/08/17
//  Multiplying two N-bit numbers by an efficient
//HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//FUNCTION CALL FOR EQUAL BINARY NUMBER IN STOREE IN ARRAY
int makeequal(int binary1[],int binary2[],int number1,int number2,int fullmake[])
  {
     int l1=number1-number2; //diff between two unequal binary
     int l2=number2-number1;   
      if(l1>0)//if first number is large then second
      {
        for(int i =number1; i>=l1 ; )
        {
            fullmake[i]=binary2[i-l1];
            i--;
        }
        for (int i = 0; i <l1 ; ++i)
        {
           fullmake[i]=0;
        }
      return number1;//largest length
     }
      if(l2>0) //second number is large then first
      {
        for(int i =number2; i>=l2 ; )
        {
         fullmake[i]=binary1[i-l2];
         i--;
        }
        for (int i = 0; i <l2 ; ++i)
        {
         fullmake[i]=0;
        }          
      }
      return number2; //largest length
  }
  //sum of two binary nuumber 
int binarysum(int binaryofnumber1[],int binaryofnumber2[],int numberofbits1,
  int numberofbits2,int binary[],int temp)
{
   int remainder=0,sum[50];  
   int number4=numberofbits1,number3=numberofbits2;
   int i=0;
    while(number4>0||number3>0)//terminate condition
    {
      //storing number array
    sum[i] =  (binaryofnumber1[numberofbits2-1-i] + binaryofnumber2[numberofbits2-1-i]+ remainder ) % 2;
    remainder = (binaryofnumber1[numberofbits2-1-i] + binaryofnumber2[numberofbits2-1-i]+ remainder ) / 2;
    i++;
    number3--;
    number4--;
    }
    if(remainder!=0)
    {
      sum[i++] = remainder;
    }
     i--;
     //binary storing array 
    for (int j = i; j>=0; --j)
   {
       binary[i-j]=sum[j];
   }
    temp=i+1;
  return temp;//length of binary sum length
}
  //multiply two number using binary two number
 long long multiply(int arr1[],int arr2[],int end1,int end2)
  {
      int sub=0;
      int array2[end1];// store first number
      int array1[end2];// store second number
     if(end1<end2)
       {
 
       sub=makeequal(arr1,arr2,end1,end2,array1);//make equal length both number of binary
       for (int i = 0; i < end2; ++i)
       {
            array2[i]=arr2[i];
       }
       }

      else if(end1>end2)
      {
       sub=makeequal(arr1,arr2,end1,end2,array2); //make equal length both number of binary
      for (int i = 0; i < end1; ++i)
      {
           array1[i]=arr1[i];
      }
      }

      else//if equal length
      {
        sub=end1;
        for (int i = 0; i < end1; ++i)
        {
         array1[i]=arr1[i];//store directly
         array2[i]=arr2[i];
        }
      }
       if(sub==0)//length is equal terminate
        return 0;
       //terminate condition
      if (sub==1)
      { 
       return arr1[0]*arr2[0];
      }
      int first=sub/2,second=sub-sub/2;
      int subarr1[first],subarr2[second],subarr3[first],subarr4[second];//storing left and right binary part
      for (int i = 0; i <first ; ++i)
      {
        subarr1[i]=array1[i];
        subarr3[i]=array2[i];
      }
      int j = 0;
      for (int i = sub/2; i <sub/2+second; ++i)
      {
          subarr2[j]=array1[i];
          subarr4[j]=array2[i];
          j++;
      }
      long long int sum1= multiply(subarr1,subarr3,first,first);//recursion 
      long long int sum2= multiply(subarr2,subarr4,second,second);//recursion
       int binarysum1[50];
       int binarysum2[50];
       int array3[second];
       int array4[first],sub1=0;
       int array5[second];
       int array6[first],sub2=0;
        if(first<second)
       {
         sub1=makeequal(subarr1,subarr2,first,second,array3);//make equal and store in array3 and array5
         sub2=makeequal(subarr3,subarr4,first,second,array5);
         for (int i = 0; i < second; ++i)
         {
            array4[i]=subarr2[i];
            array6[i]=subarr4[i];
         }
       }
       else if(first>second)
       {
         sub1=makeequal(subarr1,subarr2,first,second,array4);
         sub2=makeequal(subarr3,subarr4,first,second,array6);
         for (int i = 0; i <first; ++i)
         {
           array3[i]=subarr1[i];
           array5[i]=subarr3[i];

         }
       }
       else{
        sub1=first;
        sub2=second;
        for (int i = 0; i <first; ++i)
        {
         array3[i]=subarr1[i];
         array4[i]=subarr2[i];
         array5[i]=subarr3[i];
         array6[i]=subarr4[i];
        }
       }
       //binary sum of two number  and output length of longest
     int temp1=  binarysum(array3,array4,sub1,sub1,binarysum1,sub1);
     int temp2=  binarysum(array5,array6,sub2,sub2,binarysum2,sub2);
     long long int sum3=multiply(binarysum1,binarysum2,temp1,temp2);
      return (sum1*pow(2,2*(sub-sub/2))+(sum3-sum1-sum2)*pow(2,(sub-sub/2))+sum2);//store sum1,sum2,sum3 and return in main function
 }

int main()
{
      int array1[50],array2[50];
      for (int i = 0; i < 50; ++i)
      {
        array1[i]=0;
        array2[i]=0;
      }
      int number1,i=0;
      int number2;

      printf("Enter two number(Input is interger (space separate))::");
      scanf("%d %d",&number1,&number2);
      int arrstore1[50],arrstore2[50],numberofbits1=0,numberofbits2=0;
    //convert in binary and store in array
       int number11=number1;
      while(number11!=0)
      {
               if(number11%2==0)
               {
                     arrstore1[i]=0;
               }
                else
                {
                  arrstore1[i]=1;
                }
                   number11=number11/2;

                   i++;
                   numberofbits1++;           
      }
      for (int i = 0; i < numberofbits1; ++i)
      {
            array1[numberofbits1-1-i]=arrstore1[i];
      }
      //convert number two in binary and store in array
      int j=0,number22=number2;
      while(number22!=0)
      {
              if(number22%2==0)
              {
               arrstore2[j]=0;
              }
              else
              {
               arrstore2[j]=1;
              }
              number22=number22/2;
               j++;
               numberofbits2++;
      }
      for (int i = 0; i < numberofbits2; ++i)
      {

         array2[numberofbits2-1-i]=arrstore2[i];
      }
     long long p= multiply(array1,array2,numberofbits1,numberofbits2);//call multiplay function
     printf("Multiplyof number-1:%d and number-2:%d equal to::%lld\n",number1,number2,p);
}