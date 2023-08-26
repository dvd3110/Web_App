#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int dfs(int vertex , int **adj , bool *visited, int n)
{
    printf("%d ",vertex);
    visited[vertex]=true;
     for(int i = 0; i <n ; i++)
     {
         if(adj[vertex][i] && !visited[i])
         {
             dfs(i,adj,visited, n);
         }
     }
return 0;
}

void main()
{
    int n , src;
    printf("enter the no of vetices : ");
    scanf("%d", &n);

    int **adj=((int **)malloc (n * sizeof(int *)));
    for(int i = 0; i <n ; i++)
    {
        adj[i]=((int *)malloc (n * sizeof(int *)));
        for(int j=0; j<n ; j++)
        {
            adj[i][j]=0;
        }
    }

    printf("enter the adj matrix : \n");
     for(int i = 0; i <n ; i++){
         for(int j = 0; j<n ; j++){
            scanf("%d",&adj[i][j]);
         }
     }
    printf("enter the src vertex :");
    scanf("%d",&src);
    bool visited[n];
         for(int i = 0; i <n ; i++){
                visited[i]=false;
         }


    dfs(src, adj , visited , n);
             for(int i = 0; i <n ; i++){
                    free(adj[i]);
             }
             free(adj);


}


