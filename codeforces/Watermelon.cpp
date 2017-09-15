#include  <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int w;
  cin>>w;
  int count=0;
  for (size_t i = 1; i < w; i++)
   {
       if((w-i)%2==0)
       {
         if(i%2==0)
           {
             count++;
           }
       }
  }
  if(count>0)
  cout<<"YES"<<endl;
  else
  cout<<"NO"<<endl;
}
