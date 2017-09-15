#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i =0 ; i< n ; i++)
  {
    cin>>arr[i];
  }
  vector<int>::iterator it;
  it=max_element(arr.begin(),arr.end());
  int count=0;
  for(int i =0 ; i< n ; i++)
  {
    count+=abs((*it)-arr[i]);
  }
  cout<<count<<endl;
  return 0;
}