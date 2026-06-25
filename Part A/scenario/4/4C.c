#include<stdio.h>  
#include<string.h>  
#include<stdlib.h> 
#include<conio.h>

void main()   
{   
    int copy[20][20], dist[20][20], via[20][20];   
    int n=4, i=0, j=0, k=0, count=0;   
    int input[5][5] = {
        {0, 0,   0,   0,   0},
        {0, 0,   4,   6,   999},
        {0, 4,   0,   999, 5},
        {0, 6,   999, 0,   2},
        {0, 999, 5,   2,   0}
    };
    
    clrscr();
    printf("--- SCENARIO 4C: Distance Vector Routing ---\n");
    printf("Link Failure: B-C link failed (Cost = Infinity)\n");
    printf("Nodes A-D mapped to 1-4\n\n");
    
    for(i=1; i<=n; i++)   
    {
        for(j=1; j<=n; j++)   
        {   
            dist[i][j] = input[i][j];   
            dist[i][i] = 0;   
            copy[i][j] = dist[i][j];   
            via[i][j] = j;   
        }
    }
       
    do  
    {   
        count = 0;   
        for(i=1; i<=n; i++)   
        {
            for(j=1; j<=n; j++)   
            {
                for(k=1; k<=n; k++)   
                {
                    if(copy[i][j] > (dist[i][k] + copy[k][j]))   
                    {   
                        copy[i][j] = dist[i][k] + copy[k][j];   
                        via[i][j] = k;   
                        count++;   
                    }   
                }
            }
        }
    } while (count != 0);   
    
    printf("\nNew shortest path from Node A(1) to D(4): \n");   
    if (copy[1][4] == 999) {
        printf("\t To 4 is Unreachable\n");
    } else {
        printf("\t To 4 Via %d Cost Is %d\n", via[1][4], copy[1][4]);   
    }
    
    getch();
}
