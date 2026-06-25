#include<stdio.h>  
#include<string.h>  
#include<stdlib.h> 
#include<conio.h>

void main()   
{   
    int copy[20][20], dist[20][20], via[20][20];   
    int n=4, i=0, j=0, k=0, count=0;   
    int input[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 2, 7, 1},
        {0, 2, 0, 3, 4},
        {0, 7, 3, 0, 2},
        {0, 1, 4, 2, 0}
    };
    
    clrscr();
    printf("--- SCENARIO 4A: Distance Vector Routing ---\n\n");
    
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
    
    for(i=1; i<=n; i++)   
    {   
        printf("\nShortest path from Node %d \n", i);   
        for(j=1; j<=n; j++)   
        {   
            printf("\t To %d Via %d Cost Is %d\n", j, via[i][j], copy[i][j]);   
        }   
    }   
    
    getch();
}
