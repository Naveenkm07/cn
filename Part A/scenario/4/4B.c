#include<stdio.h>  
#include<string.h>  
#include<stdlib.h> 
#include<conio.h>

void main()   
{   
    int copy[20][20], dist[20][20], via[20][20];   
    int n=5, i=0, j=0, k=0, count=0;   
    int input[6][6] = {
        {0, 0,   0,   0,   0,   0},
        {0, 0,   3,   999, 7,   999},  
        {0, 3,   0,   4,   999, 6},    
        {0, 999, 4,   0,   999, 2},    
        {0, 7,   999, 999, 0,   5},    
        {0, 999, 6,   2,   5,   0}     
    };
    
    clrscr();
    printf("--- SCENARIO 4B: Distance Vector Routing ---\n");
    printf("Nodes A-E mapped to 1-5\n\n");
    
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
    
    printf("\nShortest paths from Node A (1): \n");   
    for(j=1; j<=n; j++)   
    {   
        if (copy[1][j] == 999) {
            printf("\t To %d is Unreachable\n", j);
        } else {
            printf("\t To %d Via %d Cost Is %d\n", j, via[1][j], copy[1][j]);   
        }
    }   
    
    getch();
}
