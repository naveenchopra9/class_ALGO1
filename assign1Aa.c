//Name-Naveen Roll no-1601CS28
//Date-31/07/2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stucture
struct node
  {
  char names[10];
  struct node *next;
  };
  //printing function
 void print(struct node *head)
 {
 struct node *newnode=NULL;
  newnode=head;
  while(newnode!=NULL)
   {
    
   printf("%s",newnode->names);
   if(newnode->next)
   printf(", ");
   newnode=newnode->next;
   }
 }
 //sort the linked list of unique
void sortlist(struct node **head2,char* str)
    {
      struct node *temp=NULL, *previous=NULL,*current=NULL; /*previous stores the node before the insertion point*/
           temp=(struct node*)malloc(sizeof(struct node));
           temp->next=NULL;
            strcpy(temp->names,str);
           if (*head2 == NULL)  /* first node in the list */
           {
               *head2 = temp;
            }
            else if (strcmp((*head2)->names,temp->names)>=0)/* insert at the head */
        {
                temp->next = *head2;
                *head2 = temp;
            }
           else 
          {
                previous = *head2;     
                current = (*head2)->next; 
            while ((current != NULL) && strcmp(current->names,temp->names)<0) 
              {
                    previous = current;
                    current = current->next;
                }
                temp->next=previous->next;
            previous->next=temp;
          }

    }
//main function
int main()
{
 int n,i;
 printf("Enter number of students-");
 scanf("%d",&n);
int lenght;
char *name[n];
 struct node *head=NULL;
 //to make to diffrent type of linked list
 for( i =0 ; i <n ; i++)
   {
   struct node* new_head = (struct node*) malloc(sizeof(struct node));
   scanf(" %s",new_head->names);
   name[i]=(char*)malloc(strlen(new_head->names+1)*sizeof(char));
 strcpy( name[i],new_head->names);
   
     lenght=strlen(name[i]);
  if(i==0)
     head = new_head;
    else
    new_head->next=head;
    
    head=new_head;
   }

int len,j,ii=0,jj=0,k,count=0;
for(i=0 ; i< n ; i++)
 {
  len=strlen(name[i]);

}
//to find unique linked list 
struct node *head3=NULL;
char *array[n];
   for(i=0 ; i< n ; i++)
    {
     len=strlen(name[i]);
     
    
    int maxlen=0;
     for( j=0 ; j<n  ; j++)
       {
     if(j!=i)
        {
         for(k =0 ; k<len ; k++)
         {
         if(name[i][k]==name[j][k])
            {
               count++; 
            } 
         else 
        break;

          }
          if(count>maxlen) 
             { 
                maxlen=count;  
             }
              count=0;
        }
      
       }
     maxlen++;
    array[i]=(char*)malloc((maxlen+1)*sizeof(char));
   
    for(ii=0; ii<maxlen ; ii++)  
     {
     array[i][ii]=name[i][ii];
     }
    }
    //sorting
struct node* newsort=NULL,*head1=NULL;
    for( i =n ; i >=0 ; i--)
   {
   struct node* newsort = (struct node*) malloc(sizeof(struct node));
   strcpy(newsort->names,array[i]);
  if(i==n-1)
     head1 = newsort;
    else
    newsort->next=head1;
    
    head1=newsort;
   }
   printf("Names in array::\n");
   print(head1);
   printf("\n");
   //sorted linked list
  for ( i = 0; i < n; ++i)
  {

    sortlist(&head3,array[i]) ;
   }
  printf("Sorted names in array==>");
  print(head3);
  struct node* newhead3=head3;
  int arr[n],s=0;
  while(newhead3!=NULL)
    {
      for ( i = 0; i < n; ++i)
      {
        if(strcmp(newhead3->names,array[i])==0)
         {

          arr[s]=i;
        }
      }
      s++;
      newhead3=newhead3->next;
    }


  //to print the main full name linked list 
  printf("\nNames to be printe::");
    struct node* newhead4=NULL,*head4=NULL;
    for( i =n-1 ; i >=0 ; i--)
   {
   struct node* newhead4 = (struct node*) malloc(sizeof(struct node));
    int t=arr[i];
   strcpy(newhead4->names,name[t]);
  if(i==n-1)
     head4 = newhead4;
    else
    newhead4->next=head4;
    
    head4=newhead4;
   }
   printf("\n");
print(head4);
  
return 0;
}

 

