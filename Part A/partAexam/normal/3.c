#include <stdio.h> 
#include <stdlib.h> 

int min(int x, int y) 
{ 
    if (x < y) 
        return x; 
    else 
        return y; 
} 

int main() 
{ 
    int drop = 0; 
    int mini; 
    int nsec; 
    int cap; 
    int count = 0; 
    int i; 
    int inp[25]; 
    int process; 
    
    
    
    printf("Enter The Bucket Size\n"); 
    scanf("%d", &cap); 
    printf("Enter The Processing Rate\n"); 
    scanf("%d", &process); 
    printf("Enter The No. Of Seconds Packets are arriving\n"); 
    scanf("%d", &nsec); 
 
    for (i = 1; i <= nsec; i++) 
    { 
        printf("Enter Number of packets entering at %d sec\n", i); 
        scanf("%d", &inp[i]); 
    } 
 
    printf("\nSecond | Packets Received | Packets Sent | Packets Left | Packets Dropped\n"); 
    printf("-------------------------------------------------------------------------\n"); 
 
    
    for (i = 1; i <= nsec; i++) 
    { 
        count = count + inp[i]; 
 
        if (count > cap) 
        { 
            drop = count - cap; 
            count = cap; 
        } 
 
        printf("%d", i); 
        printf("\t%d", inp[i]); 
 
        mini = min(count, process); 
        printf("\t\t%d", mini); 
 
        count = count - mini; 
        printf("\t\t%d", count); 
 
        printf("\t\t%d\n", drop); 
 
        drop = 0; 
    } 
 
    
    for (; count != 0; i++) 
    { 
        if (count > cap) 
        { 
            drop = count - cap; 
            count = cap; 
        } 
 
        printf("%d", i); 
        printf("\t0"); 
 
        mini = min(count, process); 
        printf("\t\t%d", mini); 
 
        count = count - mini; 
        printf("\t\t%d", count); 
 
        printf("\t\t%d\n", drop); 
    } 
 
    return 0; 
}
