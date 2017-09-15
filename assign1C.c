//name-naveen roll-1601CS28
// Date-31/07/2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stucture define
struct node
{
	char serialno[10];
	char title[10];
	char author[10];
	int boolnumber;
  struct node* next;
};
//print linked list and book details
void print(struct node *head)
 {
 struct node *newnode=NULL;
  newnode=head;
  while(newnode!=NULL)
   { 
   printf("%s %s %s",newnode->serialno,newnode->title,newnode->author);
   if(newnode->next)
     printf(", ");
   newnode=newnode->next;
   }
 }
  struct node *head=NULL;// globle define head of linked list
int main()
 {
 	char enter;
  char a,b,c,d,e,f;
  
  do{
    printf("--------------------------------------------------------------------------------------\n");
    printf("a.Make a new entry of book\nb.View Details of a book\nc.how list of available books\nd.Issue a book\ne.Return a book\nf.Exit\n");
  	printf("Enter any options::");
    scanf(" %c",&enter);
    if(enter=='a')//enter details of book name of serial number ,title , and author names
    {
      struct node *newnode=(struct node*)malloc(sizeof(struct node));
       printf("Please enter serial number ,title and author:");
       scanf("%s %s  %[^\t\n]s",newnode->serialno,newnode->title,newnode->author);
       newnode->boolnumber=1;
     if(head==NULL)
       head=newnode;
     else
      newnode->next=head;
    head=newnode;

printf("New Enter Successful\n");
    }
    else if(enter=='b')// view details of books
    {
      struct node* newcheck=head;
      printf("\n");
   struct node *newprint=(struct node*)malloc(sizeof(struct node));
    newprint->next=NULL;
    printf("Choose any option:\n");
    printf("1.By Serial No\n2.By Title\n3.By Author\n");
    int number2;
     scanf("%d",&number2 );
    if(number2==3){
      printf("Enter Author name::\n");
      scanf(" %[^\n]s",newprint->author);
      int number=0;
      while(newcheck!=NULL)
    {
      if(strcmp(newcheck->author,newprint->author)==0)
      {
        printf("%s %s %s",newcheck->serialno,newcheck->title,newcheck->author);
        if(newcheck->boolnumber==0)
          printf(" Issued\n");
        else
          printf("Not Issued\n");
        number++;
      }
      newcheck=newcheck->next;
     }
     if(number==0)
     printf("Author Book Not exit\n");
   }
  else if(number2==1){
      printf("Enter the serial no::\n");
      scanf(" %[^\n]s",newprint->serialno);
      int number=0;
      while(newcheck!=NULL)
    {
      if(strcmp(newcheck->serialno,newprint->serialno)==0)
      {
        printf("%s %s %s",newcheck->serialno,newcheck->title,newcheck->author);
        if(newcheck->boolnumber==0)
          printf(" Issued\n");
        else
          printf(" Not Issued\n");
        number++;
      }
      newcheck=newcheck->next;
     }
     if(number==0)
      printf("Serial Book Not exit\n");
   }
  else if(number2==2){
         printf("Enter Title name::\n");
      scanf(" %[^\n]s",newprint->title);
      int number=0;
      while(newcheck!=NULL)
    {
      if(strcmp(newcheck->title,newprint->title)==0)
      {
        printf("%s %s %s",newcheck->serialno,newcheck->title,newcheck->author);
        if(newcheck->boolnumber==0)
          printf(" Issued\n");
        else
          printf(" Not Issued\n");
        number++;
      }
      newcheck=newcheck->next;
     }
     if(number==0)
      printf("Title Book Not exit\n");
   }
    }

    else if(enter=='c')//show the details of available books
    {
    	printf("List of available books\n");
      struct node* newavail=(struct node*)malloc(sizeof(struct node));
      newavail=head;
      while(newavail!=NULL)
      {
        if(newavail->boolnumber)
         
         {
         printf("%s %s %s ",newavail->serialno,newavail->title,newavail->author);
         printf("  Available\n");
          }
        newavail=newavail->next;
      }
    }

    else if(enter=='d')
    {
      int count1=0,count4=0;
    	printf("Issue a book\n");
      struct node* newissuse=(struct node*)malloc(sizeof(struct node));
      newissuse->next=NULL;
      struct node *newcheck1=head;
      scanf(" %s",newissuse->serialno );
      while(newcheck1!=NULL)
      {
        if(strcmp(newcheck1->serialno,newissuse->serialno)==0)
        {
          if(newcheck1->boolnumber==0)
                   count4++;
                 newcheck1->boolnumber=0;
                   count1++;
        }
         newcheck1=newcheck1->next;
      }
      if(count1==0||count4==1)
        printf("Its a Issued book (not available in libary)\n");
    }

    else if(enter=='e')//return a books
      {
      	printf("Return a book\n");
        int count2=0,count3=0;
        struct node* newissuse1=(struct node*)malloc(sizeof(struct node));
        newissuse1->next=NULL;
      struct node *newcheck11=head;
      scanf(" %s",newissuse1->serialno );
      while(newcheck11!=NULL)
      {
        if(strcmp(newcheck11->serialno,newissuse1->serialno)==0)
        { 
          if(newcheck11->boolnumber==1)
             {
              count3++;
            }
          newcheck11->boolnumber=1;

          count2++;
        }
        newcheck11=newcheck11->next;
      }
       if(count2==0||count3==1)
        printf("Wrong book(again return)\n");
      }
      else if(enter=='f')
      {
      	printf("exit\n");
      }
      else if(enter!='a'&&enter!='b'&&enter!='c'&&enter!='d'&&enter!='e'&&enter!='f')
        printf("Wrong enter please choose in a,b,c,d,e,f\n");

  }while(enter!='f');
  return 0;
 }