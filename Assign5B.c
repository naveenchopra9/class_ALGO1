//NAME-NAVEEN ROLL.NO-1601CS28
//DATE-28/09/2017
//PROBLEM IS SORT THE LIST OF SCORE AND NAME IN LINEAR TIME
//HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//STRUCT OF NAME AND SCORE IN ARRAY STRUCTURE
struct node
{
  char names[1000];
  int score;
};
struct node array[10001],array3[10001];
//FIND THE MAXIMUM SCORE OF GIVE LIST OF SCORE
int maximum( int number)
{
 int i ;
 int max=array[0].score;
  for(i =0 ; i < number ; i++)
    {
     if(array[i].score>max)
        max=array[i].score;
    }
    return max;
}
//FIN THE MUXIMUM LENGTH OF STRING IN GIVEN NAMES OF PLAYERS
int maxlength(int number)
{
  int i, maxle=strlen(array[0].names);
  for(i =0 ; i < number ; i++)
    {
     if(strlen(array[i].names)>maxle)
        maxle=strlen(array[i].names);
    }
    return maxle;
}
//SORTING OF NAME USING REDIX SORT IN LINEAR TIME
void linearsortstring( int number1 ,int number2,int number3)
{
  //MAKE 26 LENGTH ARRAY TO STORE EVERY CHARACTER OF EQUAL LENGTH IN STRING
  int array2[26];
  //MAKE ALL VALUE ZERO
  for( int i = 0 ; i< 26 ; i++)
  {
    array2[i]=0;
  }
  //STORE POSITION OF CHARACTER IN ARRAY
  for( int i = 0 ; i<number1 ; i++)
  {
    array2[array[i].names[number2]-'a']++;
    if(array[i].names[number2]-'a'<0)
            array2[0]++;
  }
  //MAKE SERIES FOR SORTED ARRAY POSITION
      for(int  i = 1 ; i < 26 ; i++)
      {
          array2[i]+=array2[i-1];
       }
          char arr[number1][100];
          //STORE AT POSITION IN STRUCT
           for( int  i =number1-1 ; i>=0 ; i--)
           {
             if(array2[array[i].names[number2]-'a']-1<0)
             {
                strcpy(array3[array2[0]-1].names,array[i].names);
                       array3[array2[0]-1].score=array[i].score;
                      --array2[0];
             }
            else
              {
             strcpy(array3[array2[array[i].names[number2]-'a']-1].names,array[i].names);
              array3[array2[array[i].names[number2]-'a']-1].score=array[i].score;
              --array2[array[i].names[number2]-'a'];
               }
            }
            //COPY OF STRING IN ARRAY STRUCTURE
           for( int i = 0 ; i<number1 ; i++)
           {
             strcpy(array[i].names,array3[i].names);
             array[i].score=array3[i].score;
           }
}
//SORTING OF EVERY DIGIT AND IN ALL NUMBERS AND TAKE IT SORTED POSITION
 void linearsort( int number1, int number2)
  {
    //MAKE ARRAY 10 FOR STORING ALL DIGIT OF NUMBERS
   int i =0,array1[10];
   for(i =0 ; i < 10 ; i++)
        array1[i]=0;
        //SORTING DIGIT IT POSITION
    for( i = 0 ; i < number1 ; i++)
    {
        array1[((array[i].score)/number2)%10]++;
    }
    //MAKE SERIES AND FOR STORING DIGIT AT REAL POSITION
     int arr[number1];
    for( i = 1 ; i < 10 ; i++)
    {
        array1[i]+=array1[i-1];
     }
     //STORE IN STRUCTURE IN REAL POSITION
    for( i =number1-1 ; i>=0 ; i--)
    {
      //swap(&array[array1[((array[i].score)/number2)%10]-1],&array[i]);
        array3[array1[((array[i].score)/number2)%10]-1].score=array[i].score;
        strcpy(array3[array1[((array[i].score)/number2)%10]-1].names,array[i].names);
        --array1[((array[i].score)/number2)%10];
    }
    for( i = 0 ; i < number1 ; i++)
    {
           array[i].score=array3[i].score;
           strcpy(array[i].names,array3[i].names);
    }
  }
//CALL READIX SORT AND SORTIG IN LINEAR TIME
void radixsort(int number)
{
  int k=0,len1=maxlength(number);
  //CALL SORTIG FUNCTION OF LIST STRINGWISE
    for( k =len1-1 ; k>=0 ; k--)
    {
      linearsortstring(number,k,len1);
    }
   int i, maxnumber=maximum(number);
 //CALL SORTING LINEAR FUNCTION DIGITWISE NUMBER SORTING
    for( i =1 ; (maxnumber/i)>0 ; i *= 10)
             linearsort(number,i);
}
int main()
{
 int number,i;
  printf("Enter a number(Length of players)::\n");
  scanf(" %d",&number);
  printf("Space separate between name and score\n" );
  for( i =0 ; i< number ; i++)
  {
    char arr1[100];
    scanf("%s\n",arr1 );
    int len=strlen(arr1);
    for (int j = 0; j < len; j++)
    {
      arr1[j]=tolower(arr1[j]);
    }
  strcpy(array[i].names,arr1);
  scanf("%d",&array[i].score);
  }
  radixsort(number);
  printf("List Of Players And With Score\n");
  printf("\n");
  for ( i = 0; i < number; i++)
  {
     array[i].names[0]=toupper(array[i].names[0]);
  }
  //print of list of names of players
  printf(" PLAYERS         SCORE\n\n");
 for( i =0 ; i< number ; i++)
   {
     int len2=strlen(array[i].names);
   printf(" %s ",array[i].names);
   for (int k = 0; k < 15-len2; k++)
    {
     printf(" ");
   }
   printf("%d",array[i].score);
   printf("\n" );
   }
return 0;
}
