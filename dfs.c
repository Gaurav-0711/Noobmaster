#include<stdio.h>

// to visit one  components of the graph
void dfs(int a[10][10],int n,int visited[10],int current)
{
	int j;
	
	visited[current]=1;
	printf("%d ",current);     
	for (j=0;j<n;j++)
	{
		if (a[current][j]==1 && visited[j]==0)      //current to j and j is not yet visited
		{
			dfs(a,n,visited,j);
		}
	}
}

// to visit all the components of the graph
void DFS(int a[10][10],int n)
{
  int i,visited[10],comp=0;

      for (i=0;i<n;i++)
      {
	    visited[i]=0;
      }
	
	//To find DFS traversal 
	printf("DFS order:\n");
			
	for (i=0;i<n;i++)
	{
	         if (visited[i]==0)
		 {
				dfs(a,n,visited,i);
				comp++;
		 }
	 
				
	}

        if (comp > 1)
	{
              printf("\nThe graph is disconnected \n");
              printf("\nThe no. of components are:%d\n",comp);
        }
	else
	{
		printf("\nGraph is connected.\n");
	}

}

void bfs(int a[10][10],int n,int visited[10],int current)
{

	int j,q[10],m,r=-1,f=0;

	q[++r]=current; // insert and mark the vertex as visited
	visited[current]=1;
	while (   !(f> r)  )   // while queue not empty
	{
		
		m=q[f++];
		printf("%d ",m);
		for (j=0;j<n;j++)
		{
			if (a[m][j]==1 && visited[j]==0)   
			{
				q[++r]=j;   // insert and mark the vertex as visited
				visited[j]=1;
			}
		}
	}
}


void BFS(int a[10][10],int n)
{
  int i,visited[10],comp=0;

      for (i=0;i<n;i++)
      {
	    visited[i]=0;
      }
	
	//To find DFS traversal 
	printf("BFS order:\n");
			
	for (i=0;i<n;i++)
	{
	         if (visited[i]==0)
		 {
				bfs(a,n,visited,i);
				comp++;
		 }
	 
				
	}

        if (comp > 1)
	{
              printf("\nThe graph is disconnected \n");
              printf("\nThe no. of components are:%d\n",comp);
        }
	else
	{
		printf("\nGraph is connected.\n");
	}

}





int main()
{
	int a[10][10],n,i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	
	//Accepting input matrix   for undirected  & 0,1 matrix
	printf("Enter the adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
    DFS(a,n);
	BFS(a,n);
}