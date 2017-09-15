#include  <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,m,a;
  cin>>n>>m>>a;
  long long int total,p,q,r,s,r1,r2;
  p=n/a;
  q=m/a;
  r=n%a;
  s=m%a;
  r1=(r%n==0)?0:1;
  r2=(s%m==0)?0:1;
  total=p+q+r1+r2;
  cout<<total<<endl;
}
