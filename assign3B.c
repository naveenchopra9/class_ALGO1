// NAME-NAVEEN ROLLNO-1601CS28
//FIND STRING IS EVEN OR ODD IF STRING HAVE EVEN CHAR THAN EVEN ELSE ODD
//RECURSION CALLING
//HEADER DEFINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//GLOBLE VARIABLE
int number;
// ARR IS ARRAY TO FIND THE ODD AN EVEN NUMBER
int arr[52],i=0,j=0;
//SEARCH IF STRING HAVE EVEN NUMBER OF CHAR
bool search(int arr[]){
    if(arr[j]%2!=0) //IF STRING IS NOT EVEN
         return false;
       if(j==52)
       return true;
        j++;
     search(arr);
}
//FINDING STRING IS EVEN OR ODD 
bool isEvenword(char a[]){
   if(arr[i]>96){
         arr[a[i]%'a']++;
         i++;
        if(i ==number)
           return search(arr) ;
         isEvenword(a); //RECURSION CALLING
      }
      else if(arr[i]<97){
         arr[a[i]%'A']++;
         i++;
        if(i ==number)
           return search(arr) ;
         isEvenword(a); //RECURSION CALLING
      }
}

int main(){

	char a[1000];
   //STRING INPUT
	printf("Enter string ::");
	scanf("%s",a);
	number=strlen(a);//LENGHT OF STRING 
	 bool p =isEvenword(a);
    if(p==0)
    printf("%s-> is not an even word !" ,a);
    else 
    printf("%s-> is an even word !" ,a);
}