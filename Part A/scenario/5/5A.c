#include <stdio.h>  
#include <stdlib.h> 
#include <conio.h>

#define infinity 999  

void dij(int n, int v, int cost[10][10], int dist[])  
{  
    int i, u, count, w, flag[10], min;  
    
    for(i=1; i<=n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];  
    }
    
    count = 2;  
    
    while(count <= n)  
    {  
        min = 999;  
        
        for(w=1; w<=n; w++) {
            if(dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;  
            }
        }
            
        flag[u] = 1;  
        count++;  
        
        for(w=1; w<=n; w++) {
            if((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];  
            }
        }
    }  
}  

void main()  
{  
    int n=4, v=1, i, j, cost[10][10], dist[10];  
    int input[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 4, 2, 999},
        {0, 4, 0, 1, 5},
        {0, 2, 1, 0, 7},
        {0, 999, 5, 7, 0}
    };
    
    clrscr();
    printf("\n--- SCENARIO 5A: Link State Routing ---\n");
    
    for(i=1; i<=n; i++)  
    {
        for(j=1; j<=n; j++)  
        {  
            cost[i][j] = input[i][j];
            if(cost[i][j] == 0 && i != j)  
                cost[i][j] = infinity;  
        }  
    }
    
    dij(n, v, cost, dist);  
    
    printf("\n Shortest path from Node %d:\n", v);  
    for(i=1; i<=n; i++)  
    {
        if(i != v)  
            printf("%d -> %d, cost = %d\n", v, i, dist[i]);  
    }
    
    getch();  
}
