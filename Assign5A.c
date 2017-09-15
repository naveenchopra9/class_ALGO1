//NAME-NAVEEN ROLL-NO-1601CS28
//TIMING PROBLEM OF quicksort
//Random INPUT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// SWAP TWO INTEGER
      void swap(long int *a,long int *b)
      {
        long int temp = *a;
              *a=*b;
            *b=temp;
      }

  //CHOOSE ACORRDING TO RENDOM VALUE IN ARRAY USING RENDOMPOSTION AND SWAP ACORREDING DESENDING ORDER
  long int partition(long int arr[],long int left ,long int right,long int first)
    {
          if(first==0)
          {
           swap(&arr[left],&arr[right]);
          }
         else if(first==1)
         {
           long int temp=left+rand()%(right-left+1);//RENDOM INDEX OF ANY ELEMENT
            swap(&arr[right],&arr[temp]);
         }
         else if(first==2)
         {
          long int number11=arr[left],number22=arr[left+(right-left)/2],number33=arr[right];
      //Checking for first is middle number or not
          		if( number22>number11 && number11>number33 || number33>number11 && number11>number22 )
          		{
          			swap(&arr[left],&arr[right]);
          		}
    //Checking for second is middle number or not
          		else if( number11>number22 && number22>number33 || number33>number22 && number22>number11 )
          		{
          			swap(&arr[left+(right-left)/2],&arr[right]);
          		}

    //Checking for thrid is middle number or not
          		else if( number11>number33 && number33>number22 || number22>number33 && number33>number11 )
          		{
          		swap(&arr[right],&arr[right]);
          		}
         }
         else if(first==3)
         {
            long int number1=arr[left+((right-left)/4)],number2=arr[left+((right-left)/2)],number3=arr[left+((3*(right-left))/4)];
                  //Checking for a is middle number or not
           if( number2>number1 && number1>number3 || number3>number1 && number1>number2 )
           {
             swap(&arr[left+((right-left)/4)],&arr[right]);
           }
                //Checking for b is middle number or not
           else if( number1>number2 && number2>number3 || number3>number2 && number2>number1 )
           {
             swap(&arr[left+((right-left)/2)],&arr[right]);
           }

                //Checking for c is middle number or not
           else if( number1>number3 && number3>number2 || number2>number3 && number3>number1 )
           {
           swap(&arr[left+((3*(right-left))/4)],&arr[right]);
           }

         }
          long int rendom=arr[right];   //PIVOT OF CHOOSE LAST ELEMENT OR ARRAY
          long int i,temp=left-1;
          for(i =left ; i<=right-1; i++)
          { //SEACHONG POSITION OF PIVOT
           if(arr[i]<=rendom)
           {
             temp++;
             swap(&arr[temp],&arr[i]);
            }
          }
//SET PIVIT POSITION
   swap(&arr[temp+1],&arr[right]);
  return temp+1; //RETURN POSITION
}
//select element  and find the median of  sorted array
void quicksort(long int arr[] ,long int left,long int right,long int first){
  long int part;
  if(left<right)
  {
        part=partition(arr,left,right,first);
        quicksort(arr,left,part-1,first);
        quicksort(arr,part+1,right,first);
   }
     }
long int main()
{
   long int r;
    srand((unsigned int)time(NULL));
    printf("n        Type_pivot                         Random               Sorted               Almost Sorted\n" );
   for(r =4 ; r<8 ; r++)
   {

     long int n=pow(10,r);

     long int *arr;
    arr=(long int*)malloc(n*sizeof(long int));
     //first element as a pivot
    for(long int q=0; q<=3 ; q++)
    {

      for(long int i = 0 ; i < n ; i++)
      {
         arr[i]=rand()%1000000000;
       }
       printf("%ld    ", n);
       if(q==0)
         printf("FIRST                   " );
       if(q==1)
         printf("RANDOM                    " );
       if(q==2)
       printf("THREE NUMBER MEDIAN 1     ");
       if(q==3)
       printf("THREE NUMBER MEDIAN 2     ");
     for(long int p =0 ; p < 3 ; p++)
     {

      if(p==2)
      {
      //  printf("Almost Sorted-" );
        for (size_t i = 0; i < n/100; i++)
        {
         long int temp, numberrandom=rand()%(n/100);
          temp=arr[numberrandom];
           arr[numberrandom]=arr[n-i-1];
           arr[n-i-1]=arr[numberrandom];
        }
      }

   if(q==0)
   {
     double total_time1;
     clock_t start1, end1;
     start1=clock();
     quicksort(arr ,0,n-1,0);
     end1=clock();
     total_time1= (double)(end1 - start1) / (double)CLOCKS_PER_SEC;
     printf("           %f     ",total_time1);
   }
   if(q==1)
   {
      //rendom as a pivot
      double total_time2;
      clock_t start2, end2;
      start2=clock();
      quicksort(arr ,0,n-1,1);
      end2=clock();
      total_time2= (double)(end2 - start2) / (double)CLOCKS_PER_SEC;
      printf("        %f     ",total_time2);
   }
   if(q==2)
   {
      double total_time3;
      clock_t start3, end3;
      start3=clock();
      quicksort(arr ,0,n-1,2);
      end3=clock();
      total_time3= (double)(end3 - start3) / (double)CLOCKS_PER_SEC;
      printf("        %f     ",total_time3);
   }
   if(q==3)
   {
      double total_time4;
      clock_t start4, end4;
      start4=clock();
      quicksort(arr ,0,n-1,3);
      end4=clock();
      total_time4= (double)(end4 - start4) / (double)CLOCKS_PER_SEC;
      printf("        %f     ",total_time4);
   }
  }
   printf("\n" );
  }
     free(arr);
     printf("\n\n" );
 }

   return 0;
}
