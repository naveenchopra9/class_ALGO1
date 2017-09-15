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
  string str1;
  int len=str.length();
  int k =0;
  for (size_t i = 0; i < len; i++)
   {
     char p=tolower(str[i]);
     if(p!='a'&&p!='e'&&p!='i'&&p!='o'&&p!='u'&&p!='y')
        {
          str1.append(1u,'.');
          k++;
          str1.append(1u,p);
          k++;
        }
   }

   cout<<str1<<endl;
}   