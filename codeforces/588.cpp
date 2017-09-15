#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,t;
  cin>>n>>k>>t;
  if(t<=k)
    cout<<t;
  else if(t>k&&t<=n)
    cout<<k;
  else if(t>n||t<=n+k)
    cout<<n+k-t;
  else
    cout<<"0"<<endl;
  return 0;
}