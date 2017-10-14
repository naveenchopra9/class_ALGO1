//Name-Naveen Rollno-1601cs28
// rivalry between any two players
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


//ll node to store  a queue array
struct queuenode
{
	int value;
	struct queuenode* next;
};

//front store the first node of queue and rear store  last node of queue
struct queue
{
	struct queuenode *front,*rear;
};

struct queue* createqueue()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}

 void enqueue(struct queue* q,int key)
{
	//create a new node 
	struct queuenode* qnode=(struct queuenode*)malloc(sizeof(struct queuenode));
	qnode->value=key;	
	qnode->next=NULL;	
	//if queue is empty add front and rear both are same in queue
	if(q->rear==NULL)
	{
		q->front=q->rear=qnode;
		return;
	}
	//add at end of the queue  and  change the rear of the queue
	q->rear->next=qnode;
	q->rear=qnode;
}


//dequeue function  /remove key from queue
struct queuenode* dequeue(struct queue* q)
{
	//if queue is empty 
	if(q->front==NULL)
		return NULL;
	struct queuenode* temp=q->front;
	   q->front=q->front->next;
	 if(q->front==NULL)
	 	q->rear=NULL;
	 return temp;

}
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

int bfs(struct graph* graph ,int s,int colour[])
{
	  struct queue* q=createqueue();
 	         colour[s]=1;
          enqueue(q,s);

      while(q->front!=NULL)
        {
  	 	  struct queuenode* tempnode=dequeue(q);
	  	  int s1=tempnode->value;
	  	  struct adjlistnode* node=graph->array[s1].head;
	  	  while(node!=NULL)
			{
		    if(colour[node->data]==-1)
		    {
		    	colour[node->data]=1-colour[s1];
		    	enqueue(q,node->data);
		    }         
			node=node->next;
		   }
	      }

	  int colour1[graph->size];
	  for (int i = 0; i < graph->size; ++i)
	  {
	  	colour1[i]=2;
	  }
		struct queue* q1=createqueue();
          enqueue(q1,s);
    	
    	colour1[s]=3;
        while(q1->front!=NULL)
        {
		  	  struct queuenode* tempnode1=dequeue(q1);
		  	  int s=tempnode1->value;
		  	  struct adjlistnode* node1=graph->array[s].head;

		  	  while(node1!=NULL)
				{ 
					if(s==node1->data)
						return 0;
	                 if(colour[s]==colour[node1->data])
	                     	return 0;

		   			if(colour1[node1->data]!=3)
		   			{
	          	      enqueue(q1,node1->data);
	          	      colour1[node1->data]=3;
	          	     }
					node1=node1->next;
					}

		}
    return 1;
}

void  bfs1(struct graph* graph ,int s)
{
	int temp1=1;
	 int colour[graph->size];
		for (int i = 0; i < graph->size; ++i)
		  {
	  		colour[i]=-1;
	 	  }

	 	  for (int i = 0; i < graph->size; ++i)
	 	  {
	 	      if(colour[i]==-1)
	 	     if(bfs(graph,i,colour)==0)
	 	               temp1=0;
	 	  }
	   if(temp1==0)
	   	printf("NOT POSSIBLE\n");
	   else
	   {
	     
	   	printf("No rivalry between any two players of a team\n");   
	   }

}
int main()
{
	int n;
	printf("Enter size of vertex::");
	scanf("%d",&n);
	struct graph* graph=creategraph(n);
	int m;
	printf("Enter number of edges:");
	scanf("%d",&m);
	int p,q,s;
	printf("Enter u and v(u and v must be 0 to vertex-1	)\n");
    for (int i = 0; i < m; ++i)
    {

      scanf("%d %d", &p,&q);
      if(i==0)
      	   s=p;
      addedge(graph,p,q);
    }
    
    bfs1(graph,s);
}