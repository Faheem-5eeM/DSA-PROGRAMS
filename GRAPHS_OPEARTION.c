#include<stdio.h>
#include<stdlib.h>
int i,j,m,n,s[10],b[10];
int source, a[10][10],visited[10];
void create()
{
    printf("\nENter the no of vertices of the digraph\n");
    scanf("%d",&n);
    printf("\nEnter the adjacent Matrix of the Graph\n");
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
    }
}

void bfs()
{
    int rear =-1, front =0, q[10],u;
    printf("\nEnter the source vertes to find node reachable or not\n");
    scanf("%d",&source);
    q[++rear] = source;
    visited[source] = 1;
    printf("\nReachable Vertices are :\n");
    while(front <= rear)
    {
       u = q[front++];
       for(i=1;i<=n;i++)
       {
           if(a[u][i]==1 && visited[i]==0)
           {
               q[++rear] = i;
                visited[i] = 1;
                printf("%d\t",i);
           }
       }
    }
}

void dfs(int source)
{
     int top = -1, v;
     s[++top] = 1;
     b[source] = 1;
     for(v=1;v<=n;v++)
     {
        if(a[source][v]==1 && b[v] == 0)
        {
             printf("%d -> %d\n",source,v);
             dfs(v);
        }
     }
}

void main()
{
     int ch;
     while(1)
     {
         printf("\n1 -> Create\n2-> BFS\n3 -> DFS(connected or not)\n4 -> exit\n");
         printf("\nEnter your choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1: create();
                     break;
            case 2 : bfs();
                     for(i=1;i<=n;i++)
                     {
                      if(visited[i]==0)
                      {
                         printf("\nVertices that is not reachable is %d\n",i);
                      }
                     }
                     break;
             case 3: printf("\nEnter the source vertex is connected or not:\n");
                     scanf("%d",&source);
                     dfs(source);
                     m = 0;
                     for(i=1;i<=n;i++)
                     {
                        if(b[i] == 0)
                        {
                            m = 1;
                        }
                     }
                     if(m == 1)
                     {
                        printf("\nGraph is connecte\n");
                     }
                     else
                     {
                        printf("\nGraph not connected\n");
                     }
                     break;
              case 4: exit(1);
              default: printf("\nEnter a valid input\n");
     }
     }
}
