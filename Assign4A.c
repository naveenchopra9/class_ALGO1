//NAME-NAVEEN ROLL-1601CS28
//DATE-21/08/2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int n;
//STRUCTURE OF LINKED LIST
struct node
{
  char string[40]; //STORING NAME 
  int  numberofmatch; //MATCHING WITH DOCTOR
  int minute;   //ARRIVEL TIMING
  struct node *next;
};

int main()
{
  int i;
  char docter[40];
  printf("Enter docter name::");
  scanf(" %s",docter);
  //find the number of charcter in docter name
   int arrdocter[40];
  for(i =0 ; i< 40 ; i++)
  { 
      arrdocter[i]=0;
  }
  for( i =0 ; i< strlen(docter); i++)
  {     
    char p=tolower(docter[i]);
        arrdocter[p-'a']++;
  }
     printf("Enter a number::");
     scanf("%d",&n);      
     char *ptr[n];
     struct node *head= NULL;
      for(i =0 ; i< n ; i++)
       ptr[i]=(char*)malloc(40*sizeof(char));
       
    for( i =0 ; i< n ; i++){
    int timehour,timeminute,timeminute1;   
    printf("Enter a Name::");
    scanf(" %[^\n]s", ptr[i]);
    printf("Time in hour::");
    scanf("%d",&timehour);
    printf("Time in minute::");
    scanf("%d",&timeminute);
    timeminute1=timehour*60+timeminute;
     //input string searching matching of character
   int j, arr[52];
   int numberofmatch=0;
      for(j =0 ; j< 40 ; j ++)
      {
       arr[j]=0;
      }
    //counting character in matching to docter
    int len=strlen(ptr[i]);
    for(j =0 ; j<len ; j ++)
    {
     char p =tolower(ptr[i][j]);
     if(p>=97)
      arr[p-'a']++;
    }
      // matching of character in docter
    for(j =0 ; j< 40 ; j++)
    {
       if(arr[j]!=0 && arrdocter[j]!=0)
               numberofmatch++;
    }
         //MAKE LINKED LIST OF INPUTE
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
      strcpy(new_node->string,ptr[i]);
      new_node->minute = timeminute1;
      new_node->numberofmatch=numberofmatch;
      if(head==NULL||head->minute>=new_node->minute)
        {
          new_node->next=head;
          head=new_node;
        }
        else
        {
          struct node* current=head;
          while(current->next!=NULL&&current->next->minute<new_node->minute)
          {
            current=current->next;
          }
          new_node->next=current->next;
          current->next=new_node;
        }
   
   }
  printf("\n");
  //SETING TIME ARE 8.00 O'CLOCK
     int timesetminute=480,temp=-1;
     int timesetminute1=0,k=0;
     struct node *newnode =head;
    struct node* newnode1=NULL;
 while(head!=NULL)
 {
   struct node *winner=NULL,*prev,*winprev;
         newnode1 =head;
         if(head==NULL)//HEAD IS NULL THAN BREAK CONDITION
           break;
        while(newnode1!=NULL)
        {
           if(newnode1->minute<=timesetminute)
           {
               if(temp < newnode1->numberofmatch)
                 {
                 winner=newnode1;
                 temp= newnode1->numberofmatch;
                 winprev=prev;
                 }
           }
        prev=newnode1;
        newnode1=newnode1->next;
        }
      int temp1=0;
      if(winner!=NULL)
      {
       printf("%s\n",winner->string );
       if(winner==head)
       {
        head=head->next;
        free(winner);
       }
       else{
        winprev->next=winner->next;
        winner->next=NULL;
        free(winner);
       }
       timesetminute=timesetminute+10;
       temp1++;
      }
    if(temp1==0)
     timesetminute=timesetminute+1;
    temp1==0;
      temp=-1;
    if(timesetminute>1440)
      break;
  }
  return 0;
}