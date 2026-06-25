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
        {0, 0,   3,   6,   999, 999},  
        {0, 3,   0,   2,   5,   999},    
        {0, 6,   2,   0,   999, 4},    
        {0, 999, 5,   999, 0,   1},    
        {0, 999, 999, 4,   1,   0}     
    };
    
    clrscr();
    printf("--- SCENARIO 4E: Distance Vector Routing ---\n");
    printf("Nodes R1-R5 mapped to 1-5\n\n");
    
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
    
    printf("\nShortest path from Node R1(1) to R5(5): \n");   
    if (copy[1][5] == 999) {
        printf("\t To 5 is Unreachable\n");
    } else {
        printf("\t To 5 Via %d Cost Is %d\n", via[1][5], copy[1][5]);   
    }
    
    getch();
}
