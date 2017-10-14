//NAME-NAVEEN ROLLNO-1601CS28
//PROBLEM finds ith order statistics of n elements in linear time
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//SWAP TWO NUMBER IN ARRAY
void swap(int *a,int *b)
{
	int temp = *a;
        *a=*b;
        *b=temp;
}
//PARTITION AROUND CHOOSE RANDOM ELEMENT IN ARRAY 
int partition(int arr[],int l,int r,int pi)
{
  int j;
  //FIND ELEMENT POSITION IN ARRAY AND SWAP IT WITH LAST ELEMENT 
  for ( j = l; j <r; ++j)
  {
   if(arr[j]==pi) 
    break;
  }
  swap(&arr[j],&arr[r]);
  int temp=l;
  for (int i = l; i <=r-1; ++i)
  {
    if(arr[i]<pi)
      {
        swap(&arr[i],&arr[temp]);
        temp++;
      }
  }
  swap(&arr[temp],&arr[r]);
  return temp; //RIGHT POSITION IN ARRAY OF PIVOT
}
//INSERTION SORTING OF ELEMENT IN ARRAY GROP OF 5-5
int Sort(int arr[],int l, int n)
{
   int i, key, j;
   for (i = l+1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= l && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
      return arr[l+(n-l)/2];  //RETURN MEDIAN OF 5 ELEMENT GROUP 
}
//TO FIND THE KTH ELEMENT IN ARRAY IN O(N) TIME
int Kthsmallestelement(int arr[],int left,int right,int k )
{

  if(k>0&&k<=(right-left+1))//K MUST BE IN LESSTHAN ARRAY ELEMENT
  {
	//number of element in array
 int numelement=right-left+1;
 int n1=numelement/5;
  if((numelement+4)/5==(n1+1))
  	  n1=n1+1;
  int m[n1];//STORE ARRAY 5-5 GROUP ELEMENT MEDIAN
  int i;
  for ( i = 0; i < numelement/5; ++i)
  {
      	m[i]=Sort(arr,left+i*5,left+(i*5)+5);
  }
  //IF GROUP ARE NOT 5 GROUP THAN STORE IN ARRAY
  if(i*5<numelement)
  {
    m[i]=Sort(arr,left+i*5,numelement-1);
    i++;
  }
  int midofmid;
  //MEDIAN OF MEDIAN
  if(i==1)
  {
    midofmid=m[i-1];//IF ONLY 1 ELEMENT LEFT
  }
  else
    midofmid=Kthsmallestelement(m,0,i-1,i/2);//RECR CALL OF MEDIAN OF MEDIAN
   int p=partition(arr,left,right,midofmid);   //PARTITION AROUND MEDIAN OF MEDIAN  
   if(p-left==k-1) //IF KtH POSITION ARE EQUAL JUST RETURN 
   {
    return arr[p];
   }
   else if(p-left>k-1) //SEARCH LEFT SIDE IN ARRAY
    return Kthsmallestelement(arr,left,p-1,k);
   else
    return Kthsmallestelement(arr,p+1,right,k-p+left-1);//RIGHT SIDE
  }
  return -1;
}
int main()
{
	int n;
  printf("Enter array size :: ");
	scanf("%d",&n);
	int arr[n];
  printf("Enter array elements (space separeted:: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int k;
  printf("Enter searching position ::");
	scanf("%d",&k);
	int p=Kthsmallestelement(arr,0,n-1,k);
  if(p!=-1)
	printf("%d\n", p);
  else
  {
    printf("Element are out of range of array size\n");
  }

}