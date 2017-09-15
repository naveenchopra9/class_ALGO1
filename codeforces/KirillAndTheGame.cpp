#include  <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
  int l,r,x,y;
  float k,p;
  cin>>l>>r>>x>>y>>k;
  int number1=r-l+1;
  int number2=y-x+1;
   int a,b,count=0;
   a=l;
   b=x;
  for (size_t i = 0; i < number1; i++) {
     for (size_t j = 0; j < number2; j++) {
       p=(float)a/b;
         a++;
       if(k==p)
       count++;
     }
     a=l;
     b++;
  }
  if(count>0)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
  return 0;
}
