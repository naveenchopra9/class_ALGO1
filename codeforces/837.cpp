#include <iostream>
#include <bits/stdc++.h>
 using namespace std;
    int main()
    {
     char t[100];
     int n;
     cin>>n;
     cin>>ws;
     int temp= -1;
     cin.getline(t,10001);
      cout << t; //just to confirm the input is read correctly
    
    for (int i = 0; i < n; ++i)
    {
    	int p=t[i];
    	cout<<p<<endl;
    }
     for (int i = 0; i < n; ++i)
     {
     	int temp1=0;
     	int p= t[i];
	     	while(p!=32)
     	{
     		if(t[i]>=65&&t[i]<=96)
     		{
     			temp1++;
     		}
     	}
     	if(temp1>temp)
     		temp=temp1;
     }
     cout<<temp;
    }