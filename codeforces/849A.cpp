#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i =0 ; i< n ; i++)
	{
		cin>>arr[i];
	}
	int count=0;
	if(n%2==1)
	{	++count;
	}

   if((arr[0]%2==1)&&(arr[n-1]%2)==1)
		   ++count;
	if(count==2)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}