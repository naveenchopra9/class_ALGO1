//Name-1601cs28 Roll No-1601cs28
//serching of element
#include <stdio.h>
#include <stdlib.h>
int p=0;
int min(int num1,int num2){
    if(num2>num1)
        return num1;
    else 
    return num2;
    }
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int search(int arr[], int left, int right,int x)
{
    if(right>=left){  //terminate conditon
    int mid= left+(p+(right-left)*2)/5; //divide into 2/3 and 1/3 part and do recursion
    if(arr[mid]==x)return mid;
    if(arr[mid]>x)
        return search(arr,left,mid-1,x);//call recursion fun
       return search(arr,mid+1,right,x);
   }
    return -1;//if not found in array
}
int main(){
	int n;
        	int i =0 ;
            printf("Enter a Number of size ::");
        	scanf("%d",&n);
        	int x,arr[n];
            //input array
            printf("Enter array elements::");
        	for(i =0 ; i <n ; i++){
		    scanf("%d",&arr[i]);
	}  
         quickSort(arr,0,n-1);//calling quiksorting
         printf("Enter searching integer::");
         scanf("%d",&x); 
         printf("Sorted array ::");
         for(i =0 ; i <n ; i++){
	     printf("%d ",arr[i]);
 
         }
int number1=search(arr,0,n-1,x);
if(number1==-1)
    printf("\nSerching number not exist in arary!");//if not exist
else
printf("\nPosition of serched integer(it's position in Sorted arary)::%d",number1);//position of searched integer  
}