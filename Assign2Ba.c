//Name-1601cs28 Roll No-1601cs28
//serching of element
#include <stdio.h>
#include <stdlib.h>
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
int min(int num1,int num2){
    if(num2>num1)
        return num1;
    else 
    return num2;
}
int search(int arr[], int left, int right,int x)
{
    if(right>=left){
    int mid= left+(right-left)/3;
    if(arr[mid]==x)return mid;
    if(arr[mid]>x)
        return search(arr,left,mid-1,x);
       return search(arr,mid+1,right,x);
   }
    return -1;
}
int main(){
	int n;
		int i =0 ;
        printf("Enter number::");
        //input array size
	scanf("%d",&n);
	int x,arr[n];
    printf("Enter array element::");
    //array elements
	for(i =0 ; i <n ; i++){
		scanf("%d",&arr[i]);
	}
     quickSort(arr,0,n-1);//call using quick sort
     printf("Enter searching integer::");//serching array
     scanf("%d",&x);
     //array printing (sorted)
     for(i =0 ; i <n ; i++){
	    printf("%d ",arr[i]);
	 
}
int number1=search(arr,0,n-1,x);
if(number1==-1)
    printf("\nSerching number not exist in arary!");
else
printf("\nPosition of serched integer::%d",number1 );//print array positon of serched elements
}