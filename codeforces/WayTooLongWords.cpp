#include  <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int w;
  cin>>w;
  string str;
  for (size_t i = 0; i < w; i++)
   {
     cin>>str;
    int len=str.length();
    if(len<=10)
    cout<<str<<endl;
    else if(len>10)
    cout<<str[0]<<len-2<<str[len-1]<<endl;
   }
}
