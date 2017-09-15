#include  <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int n;
  cin>>n;
  int len=str.length();
  int k =0,count=0;
  int arr[26]={0};
  for (size_t i = 0; i < len; i++)
   {

     arr[str[i]-'a']++;
   }
   for (size_t i = 0; i <26; i++)
    {
      if(arr[i]>0)
       count++;
    }
  if(len<n)
    cout<<"impossible"<<endl;
  else if(n<=count)
      cout<<"0"<<endl;
  else if(count<n)
        cout<<n-count<<endl;


}
