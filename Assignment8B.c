//Name-naveen Roll-No -1601CS28
//problem about path and cyclic or not
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//globle matrix
int mat[1000][1000];
int result[1000][1000];
//to find edges between two names
void findedge(int p,int q,char* name1,char* name2,int l1,int l2)
{
	int arr1[26];
	int arr2[26];
	memset(arr1,0,sizeof(arr1));// set value to zero 
	memset(arr2,0,sizeof(arr2)); // set value  to zero
	for (int i = 1; i <l1; ++i)
	{
		arr1[tolower(name1[i])-'a']++;
	}
	for (int i = 0; i < l2; ++i)
	{
		arr2[tolower(name2[i])-'a']++;
	}
	int temp=0;
	for (int i = 0; i < 26; ++i)
	{
		if(arr1[i]!=arr2[i])
			   ++temp;
	}
	if(temp==1)
		mat[p][q]=1;
}
//to find cycle or not not
int cyclesuntil(int V,int x,int white[],int gray[],int black[])
{
	gray[x]=1;
	white[x]=1;
	for (int i = 0; i <V; ++i)
	{
		if((mat[x][i]!=0)&&(black[i]==1))
		{	
			i++;
			continue;
		}	
		if((mat	[x][i]!=0)&&(gray[i]==1))
		{
		    return 1;
		}
		if((mat[x][i]!=0)&&(white[i]==0))
		{
			if(cyclesuntil(V,i,white,gray,black))
				return 1;
		}
	}
	black[x]=1;
	return 0;
}
//call cyclic  if till know not be visited
void cycles(int V)
{
	int white[V];
	int gray[V];
	int black[V];
	int temp=0;
	memset(white,0,sizeof(white));
	memset(gray,0,sizeof(gray));
	memset(black,0,sizeof(black));
	for (int i = 0; i < V; ++i)
	{
		if(white[i]==0)
		{
		if(cyclesuntil(V,i,white,gray,black))
			{
				++temp;
			}
		}
	}
	printf("\n");
	if(temp>0)
		printf("GRAPH IS CYCLIC\n");
	else
		printf("GRAPH IS ACYCLIC\n");
}
//dfs to finding the path between two elements
 void DFS(int n,int p,int i,int visited[])
    {
        int j;
        visited[i]=1;
        if(p!=i)
         result[p][i]=1;
        for(j=0;j<n;j++)
            {	
            	if(visited[j]==0 && mat[i][j]==1)
                		 DFS(n,p,j,visited);
            }
        
    }
    // call dfs to find the path between two names 
  void path(int V)
   {
    	int visited[V];
    	for (int i = 0; i < V; ++i)
    	{
    		visited[i]=0;
    	}
    	int p =0;
    	 for (int i = 0; i < V; ++i)
    	 {
    			DFS(V,p,i,visited);
    			p++;
    			for (int j = 0; j < V; ++j)
    			{
    				visited[j]=0;
    			}
         }
   }
int main(int argc, char const *argv[])
{
	int V;
	printf("Enter number of vertex:");
	scanf("%d",&V);
	char name[V+1][6];
	for (int i = 0; i <V ; ++i)
	{
		printf("Enter English word number %d :",i );
		scanf(" %s",name[i]);
	}
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			int l1=strlen(name[i]);
			int l2=strlen(name[j]);
			if(i!=j)
			findedge(i,j,name[i],name[j],l1,l2);
		}
	}
	printf("\n");
	printf("Matrix for edges:\n");
	printf("\n");
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			printf("%d  ",mat[i][j] );
		}
		printf("\n");
	}
	cycles(V);
	path(V);
	printf("\n");
	 printf("Matrix for path::\n");
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			printf("%d  ",result[i][j] );
		}
		printf("\n");
	}
	return 0;
}