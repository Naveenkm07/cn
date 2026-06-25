#include <stdio.h> 
#include <conio.h>

int min(int x, int y) { 
    if (x < y) return x; 
    else return y; 
} 

void main() { 
    int drop = 0, mini, nsec = 5, cap = 8, count = 0, i, process = 2; 
    int inp[25] = {0, 3, 6, 5, 7, 4}; 
    
    clrscr();
    printf("\n--- SCENARIO 3C: Leaky Bucket ---\n");
    printf("Bucket Capacity: 8\nOutput Rate: 2\nIncoming Packets: 3, 6, 5, 7, 4\n\n");
    
    printf("\nSecond | Pkt Recv | Pkt Sent | Pkt Left | Pkt Dropped\n"); 
    printf("-------------------------------------------------------\n"); 
 
    for (i = 1; i <= nsec; i++) { 
        count += inp[i]; 
        if (count > cap) { 
            drop = count - cap; 
            count = cap; 
        } 
        mini = min(count, process); 
        count -= mini; 
        printf("  %d\t  %d\t      %d\t       %d\t    %d\n", i, inp[i], mini, count, drop); 
        drop = 0; 
    } 
    for (; count != 0; i++) { 
        if (count > cap) { 
            drop = count - cap; 
            count = cap; 
        } 
        mini = min(count, process); 
        count -= mini; 
        printf("  %d\t  0\t      %d\t       %d\t    %d\n", i, mini, count, drop); 
        drop = 0;
    } 
    getch();
}
