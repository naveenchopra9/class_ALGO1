//name-Naveen rollno-1601CS28
//Date-31/07/2016
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stucture of linked list
struct node
 {
  char name[10];
  struct node* next;
  };
 //print array
 void print(struct node *head) 
 {
  struct node* newnode=head;
  while(newnode!=NULL)
  {
    if(newnode==head)
   printf(" %s",newnode->name);
     else
    printf("==> %s",newnode->name);
   newnode=newnode->next;
  }  
 }
 //main function
int main()
 {
  
  struct node *head1=NULL,*head2=NULL,*newnode=NULL,*prevnode=NULL;
  
int n,i,j,k;
 printf("Enter size--");
 scanf("%d",&n);
 char *name1[n];
 char *name2[n];
 //modification of two linked list 
 for(i=0 ; i< n ; i++)
 {
  struct node* new=(struct node*)malloc(sizeof(struct node));
     scanf("%s",new->name);
     name1[i]=(char*)malloc(strlen((new->name)+1)*sizeof(char));
     strcpy(name1[i],new->name);
//to separate to linked lists
if(i<n/2)
{  
if(i==0)
   {
    head1=new;
   }
  else
   {
  new->next=head1;
    head1=new;
    }
}
if(i>=n/2)
{  
if(i==n/2)
   {
    head2=new;
   }
  else
   {
  new->next=head2;
    head2=new;  }
}

 }
 struct node* newhead1,*newhead2;
for (i = n; i >=0; i--)
{
  name2[i]=(char*)malloc(2*sizeof(char));
 name2[i][0]=name1[i][0];
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
  strcpy(newnode->name,name2[i]);
 if(i<n/2)
{  
if(i==(n/2)-1)
   {
    newhead1=newnode;
   }
  else
   {
  newnode->next=newhead1;
    newhead1=newnode;
    }
}
if(i>=n/2)
{  
if(i==n-1)
   {
    newhead2=newnode;
   }
  else
   {
  newnode->next=newhead2;
    newhead2=newnode;
    
   }
}
}
//print both linked list
printf("\n");
  printf("Linked lists :");
print(newhead1);
printf(" ");
printf("and ");
print(newhead2);
//sorting of linked list
 char name[10];
 int num=0;
  for(j =0 ; j <(n/2) ; j++)
     {
       if(name2[j][0]==97||name2[j][0]==101||name2[j][0]==105||name2[j][0]==111||name2[j][0]==117||name2[j][0]==65||name2[j][0]==69||name2[j][0]==73||name2[j][0]==85||name2[j][0]==79)
       {
        strcpy(name,name2[j]);
        for(k=j ; k>num; k --)
         {
           strcpy(name2[k],name2[k-1]);
         }
         strcpy(name2[num],name);
         num++; 
         }
        
       }
char nam[10];
 int number=n/2;
  for(j =n/2 ; j <n ; j++)
     {
       if(name2[j][0]==97||name2[j][0]==101||name2[j][0]==105||name2[j][0]==111||name2[j][0]==117||name2[j][0]==65||name2[j][0]==69||name2[j][0]==73||name2[j][0]==85||name2[j][0]==79)
       {
         strcpy(nam,name2[j]);
        for(k=j ; k>number; k --)
         {
           strcpy(name2[k],name2[k-1]);
         }
         strcpy(name2[number],nam);
        number++;
       }
    
    }
 struct node* newhead11,*newhead22;
 for (i = n; i >=0; i--)
 {
 struct node* newnode1=(struct node*)malloc(sizeof(struct node));
  strcpy(newnode1->name,name2[i]);
 if(i<n/2)
{  
if(i==(n/2)-1)
   {
    newhead11=newnode1;
   }
  else
   {
  newnode1->next=newhead11;
    newhead11=newnode1;
    }
}
if(i>=n/2)
{  
if(i==n-1)
   {
    newhead22=newnode1;
   }
  else
   {
  newnode1->next=newhead22;
    newhead22=newnode1;
    
   }
}
}
//print sorted array
printf("\n");
printf("Arranged linked list--");
print(newhead11);
printf(" ");
printf("and ");
print(newhead22);

int number1[99],numb=0;
int numbercount[99];


//to fine palindrome 
for (i = 1; i < n/2; ++i)
{

   if((name2[i-1][0]==name2[i+1][0])&&(i-1)>=0&&(i+1)<n/2)
   {
    number1[numb]=i;
    numb++;
   }
}
 for(i =0 ; i <numb ; i++)
   {
     int number3=number1[i]+1;
      int count=0 ,count1=0,number2=number1[i]-1;
   do
     {
      count1=0;
       if(name2[number2][0]==name2[number3][0]&&number3<n/2)
       {
        count++;
        count1++;
        number2--;
        number3++;
       }
     } while (count1);
     numbercount[i]=count;
   }
   printf("\n");
   for(i= 0 ; i< numb; i++)
     {
      int number4=number1[i]-numbercount[i];
      int number5=number1[i]+numbercount[i];
     for (j = number4; j <=number5; ++j)
      {
        if(j==number4)
        printf("%s",name2[j] );
        else
        printf("==>%s",name2[j] ); 
      }
      printf("\n");
     }
 int numb1=0,number11[99],numbercount1[99];
 
     for (i = n/2+1; i < n; ++i)
{

   if((name2[i-1][0]==name2[i+1][0])&&(i-1)>=n/2&&(i+1)<n)
   {
    number11[numb1]=i;
    numb1++;
   }
}
 for(i =0 ; i <numb1 ; i++)
   {
     int number33=number11[i]+1;
      int counta=0 ,count11=0,number22=number11[i]-1;
   do
     {
      count11=0;
       if(name2[number22][0]==name2[number33][0]&&number22>=n/2)
       {
        counta++;
        count11++;
        number22--;
        number33++;
       }
     } while (count11);
     numbercount1[i]=counta;
   }
   for(i= 0 ; i< numb1; i++)
     {
      int number44=number11[i]-numbercount1[i];
      int number55=number11[i]+numbercount1[i];
     for (j = number44; j <=number55; ++j)
      {
        if(j==number44)
        printf("%s",name2[j] ); 
        else
          printf("==> %s",name2[j] );
      }
     }
if(numb>0)
  printf(" is a palindrome");
printf("\n");
int aa=0;
 for(i= 0 ; i < n/2-1 ;i++){
  int a1,a2;
    if(name2[i][0]==name2[i+1][0]){
      a1=i;a2=i+1;
      while(a1>=0&&a2<n/2){
        for ( j = a1;  j<= a2; ++j)
        {
          if(aa==0)
          printf("%s",name2[j]);
        else
          printf("==> %s",name2[j]);
        aa++;
        }
        printf(" is a palindrome\n");
        a1=a1-1;
          a2=a2+1;
          aa=0;
          if(name2[a1][0]!=name2[a2][0]){
                 //   printf(" is a palindrome\n");
            break;
          }
       }

   }
 } 
  aa=0;
 for(i= n/2 ; i < n-1 ;i++){
  int a11,a21;
    if(name2[i][0]==name2[i+1][0]){
      a11=i;a21=i+1;
      while(a11>=n/2&&a21<n){
        for ( j = a11;  j<= a21; ++j)
        {
            if(aa==0)
          printf("%s",name2[j]);
        else
          printf("==> %s ",name2[j]);
         aa++;
        }
        printf(" is a palindrome\n");
          a11=a11-1;
          a21=a21+1;
          aa=0;
          if(name2[a11][0]!=name2[a21][0]){
                    //printf(" is a palindrome\n");
                    
            break;
          }
    }
   }
 }
 return 0;
 }

