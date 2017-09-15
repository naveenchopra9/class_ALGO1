#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,a,b;
  cin>>n>>a>>b;
   int arr[n];
   for (int i = 0; i < n; ++i)
   {
     cin>>arr[i];
   }
   int a1=a,b1=2*b,count=0;
   for (int i = 0; i < n; ++i)
   {
    if(b1==0&&a1==0)
      {
       count+=arr[i];
      }
      
     if(arr[i]==1)
     {
      if(a1!=0)
        --a1;
      else
        --b1;
     }
     else if(arr[i]==2)
     {
        if(b1>2)
          b1=b1-2;
         else
          count=count+2;
     }
   }
   cout<<count<<endl;
  return 0;
}