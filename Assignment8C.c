
//Name-naveen RollNo -1601Cs28
//problem  maximum nummber of edges in any connected component of the graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//represent structure of  adj list node
struct adjlistnode
{
  int data;
  struct adjlistnode* next;
};
//represent struct of adj  list
struct adjlist
{
	struct adjlistnode* head;//pointer  to head node of list
};
struct graph
{
	int size;
	struct adjlist *array;
};

//create undirected graph 
struct graph* creategraph(int n)
{
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->size=n;
	graph->array=(struct adjlist*)malloc(n*sizeof(struct adjlist));
	int i;
	for ( i = 0; i < n; ++i)
	{
	  graph->array[i].head=NULL;
	}
	return graph;
}
//Enter edges in graph
void addedge(struct graph* graph,int u,int v)
{
	//adjancency v to u;
	struct adjlistnode *newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->data=v;
	newnode->next=NULL;
	newnode->next=graph->array[u].head;
	graph->array[u].head=newnode;
	struct adjlistnode *newnode1=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode1->data=u;
	newnode1->next=NULL;
	newnode1->next=graph->array[v].head;
	graph->array[v].head=newnode1;	

}
//dfs untill calling to find the diffrent compontents 
int countnumber=0;
void dfsutil(struct graph* graph ,int v,int visit[])
{
	visit[v]=1;
	++countnumber;
    struct adjlistnode* node=graph->array[v].head;
    while(node!=NULL)
    {
    	int p;
    	p=node->data;
    	if(visit[node->data]==0)
    			{
    				dfsutil(graph,p,visit);
    			}
    	    	node=node->next;
    }
}
//call for every edges if its note visited before
void dfs(struct graph* graph)
{
	int visit[graph->size];
	int count=0;
	  for (int i = 0; i < graph->size; ++i)
	  {
	  	visit[i]=0;
	  }
	int max=-1;
   for (int i = 0; i < graph->size; ++i)
   {
   	if(visit[i]==0)
   	{
   	        countnumber=0;
   		dfsutil(graph,i,visit);
   		if(countnumber>max)
   		     max=countnumber;
   	        count++;
   	}	
   }   
   printf("\n");
   printf("Number of connected component:%d\n",count);
   printf("Maximum number of edges in any connected component of the graph:: %d",max);
}
int main()
{
	int n;
	printf("Enter size of vetex::");
	scanf("%d",&n);
	struct graph* graph=creategraph(n);
	int m;
	printf("Enter number of edges:");
	scanf("%d",&m);
	int p,q;
	printf("Enter v to u(u and v must be 0 to v-1):\n");
    for (int i = 0; i < m; ++i)
    {
      scanf("%d %d", &p,&q);
      addedge(graph,p,q);
    }

    dfs(graph);
}