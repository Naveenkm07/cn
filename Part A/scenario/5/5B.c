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
    int n=5, v=1, i, j, cost[10][10], dist[10];  
    int input[6][6] = {
        {0, 0,   0,   0,   0,   0},
        {0, 0,   4,   6,   999, 999},
        {0, 4,   0,   2,   5,   999},
        {0, 6,   2,   0,   999, 7},
        {0, 999, 5,   999, 0,   3},
        {0, 999, 999, 7,   3,   0}
    };
    
    clrscr();
    printf("\n--- SCENARIO 5B: Link State Routing ---\n");
    printf("Nodes T1-T5 mapped to 1-5\n");
    
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
    
    printf("\n Shortest path from T1(1) to T5(5):\n");  
    printf("1 -> 5, minimum cost = %d\n", dist[5]);  
    
    getch();  
}
