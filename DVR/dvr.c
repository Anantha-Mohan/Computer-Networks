#include<stdio.h>
#include<limits.h>
typedef struct
{
	int source,destination,weight;
}Link;
Link link[100];
int distance[100];
void main()
{
	int src,numnodes,numlinks,source,destination,weight,cycle=0;
	printf("Enter the source vertex:");
	scanf("%d",&src);
	printf("Enter the number of nodes:");
	scanf("%d",&numnodes);
	printf("Enter the number of links:");
	scanf("%d",&numlinks);
	printf("Src\tDest\tWeight\n");
	for(int i=0;i<numlinks;i++)
	{	
		scanf("%d %d %d",&link[i].source,&link[i].destination,&link[i].weight);
	}
	for(int i=0;i<numnodes;i++)
	{
		distance[i]=INT_MAX;
	}
	distance[src]=0;
	for(int i=0;i<numnodes;i++)
	{
		for(int j=0;j<numlinks;j++)
		{
			source=link[j].source;
			destination=link[j].destination;
			weight=link[j].weight;
			if(distance[source]!=INT_MAX&&(distance[destination]>distance[source]+weight))
			{
				distance[destination]=distance[source]+weight;
			}
		}
	}
		for(int j=0;j<numlinks;j++)
		{
			source=link[j].source;
			destination=link[j].destination;
			weight=link[j].weight;
			if(distance[source]!=INT_MAX&&(distance[destination]>distance[source]+weight))
			{
				cycle=1;break;
			}
		}
	if(cycle==1)printf("Negative weight cycle detected");
	printf("Distance from source vertex to every other vertex:\nNode\tDisance\n");
	for(int i=0;i<numnodes;i++)
	{
		printf("%d\t%d\n",i,distance[i]);
	}
}
