#include <stdio.h> 
#include <stdlib.h> 
#include <dos.h>
#include <conio.h>

int n, r; 
struct frame { char ack; int data; } frm[20]; 

void main() { 
    int i;
    clrscr();
    printf("\n--- SCENARIO 2A: Go-Back-N ARQ ---\n");
    printf("Window Size: 4\nTotal Frames: 8\nLost Frame: 3\n\n");
    
    n = 8;
    r = 3;
    
    
    for (i = 1; i <= n; i++) { 
        frm[i].data = i * 10;
        frm[i].ack = 'y'; 
        printf("Sent packet %d (Data: %d)\n", i, frm[i].data);
    } 
    
    
    frm[r].ack = 'n'; 
    for (i = 1; i <= n; i++) { 
        if (frm[i].ack == 'n') 
            printf("\nPacket %d not received (Timeout detected)\n", i); 
    } 
    
    
    printf("\nResending from packet %d\n", r); 
    for (i = r; i <= n; i++) { 
        delay(1000); 
        frm[i].ack = 'y'; 
        printf("Received packet %d data: %d\n", i, frm[i].data); 
    } 
    
    printf("\nAll packets sent successfully\n"); 
    getch();
}
