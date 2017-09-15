#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
  int r,d, n,c,d1,r1;
  cin>>r>>d;
  cin>>n;
  int count=0;
  for (size_t i = 0; i < n; i++) {
    cin>>c>>d1>>r1;
    int k;
   float l;
   k=( pow(c,2)  +   pow(d1,2)  );
   l=pow(k,0.5);
   if((r-d)<=(l+r1)&&(r-d)<=(l-r1)&&(l+r1)<=r&&(l-r1)<=r)
     count++;
   }
  cout<<count<<endl;
}
