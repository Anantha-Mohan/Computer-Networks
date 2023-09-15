#include<stdio.h>
#include<limits.h>
typedef struct
{
	int source,destination,weight;
}Link;
Link link[100];
int distance[100],visited[100],finished[100];
void main()
{
	int src,numnodes,numlinks,source,destination,weight,cycle=0,min,minindex;
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
		min=INT_MAX;
		for(int j=0;j<numnodes;j++)
		{
			if(min>=distance[j]&&visited[j]==0)
			{
				min=distance[j];
				minindex=j;
			}
		}
		visited[minindex]=1;
		for(int k=0;k<numnodes;k++)
		{
			if(visited[k]==1)
			{
				for(int m=0;m<numlinks;m++)
				{
					if(link[m].source==k)
					{
						if(distance[link[m].destination]>distance[link[m].source]+link[m].weight)
						{
							distance[link[m].destination]=distance[link[m].source]+link[m].weight;
						}
					}
				}
			}
		}
	}
	
	printf("Distance from source vertex to every other vertex:\nNode\tDisance\n");
	for(int i=0;i<numnodes;i++)
	{
		printf("%d\t%d\n",i,distance[i]);
	}
}
