//prims algorithm
#include<stdio.h>
#include<stdbool.h>
#define max 20
#define infinity 999
int graph[max][max],visited[max],n;
void prims(bool visited[]);
void main()
{
printf("\n enter the number of vertices: ");
scanf("%d",&n);
printf("\n enter the adjacency matrix:");
for(int i=0;i<n;++i)
{
	for(int j=0;j<n;++j)
	{
		printf("\n if an edge exist between %d-%d : ",i,j);
		scanf("%d",&graph[i][j]);
	}
}
bool visited[10];
for(int i=0;i<n;++i)
visited[i]=0;

for(int i=0;i<n;i++)
{
graph[i][i] = 0;
}

printf("\n ***PRIMS ALGORITHM*** ");
prims(visited);
}

void prims(bool visited[])
{
int edgecount = 0,x,y,total = 0,cost = 0;
visited[0]=1;
printf("\n edges are");
printf("\n edge  : minimum weights");
while(edgecount < n-1)
{
	cost = infinity;
	for(int i=0;i<n;++i)
	{
	if(visited[i])
		{
		for(int j=0;j<n;++j)
		{
			if(!visited[j] && graph[i][j])
			{
			if(graph[i][j]<cost)
			{
			cost = graph[i][j];
			x=i;
			y=j;
			}
		}
		}
	}
}

printf("\n %d - %d : %d",x,y,cost);
total+=cost;
visited[y] = 1;
edgecount++;
}
printf("\n the minimum total cost = %d",total);
}

