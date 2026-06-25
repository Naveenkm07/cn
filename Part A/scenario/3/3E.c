#include <stdio.h> 
#include <conio.h>

int min(int x, int y) { 
    if (x < y) return x; 
    else return y; 
} 

void main() { 
    int drop = 0, mini, nsec = 5, cap = 18, count = 0, i, process = 4; 
    int inp[25] = {0, 7, 11, 9, 6, 10}; 
    
    clrscr();
    printf("\n--- SCENARIO 3E: Leaky Bucket ---\n");
    printf("Bucket Capacity: 18\nOutput Rate: 4\nIncoming Packets: 7, 11, 9, 6, 10\n\n");
    
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
