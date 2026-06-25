#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <dos.h>
#include <conio.h>

int n, r; 

struct frame 
{ 
    char ack; 
    int data; 
} frm[10]; 

int sender(void); 
void recvfrm(void); 
void resend(void); 
void resend1(void); 
void goback(void); 
void selective(void); 

void main() 
{ 
    int c; 
    clrscr();
    do 
    { 
        printf("\n1.Selective Repeat ARQ"); 
        printf("\n2.Go Back N ARQ"); 
        printf("\n3.Exit"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &c); 
 
        switch (c) 
        { 
            case 1: 
                selective(); 
                break; 
 
            case 2: 
                goback(); 
                break; 
 
            case 3: 
                exit(0); 
        } 
 
    } while (c != 3); 
    getch();
} 
 
void goback() 
{ 
    sender(); 
    recvfrm(); 
    resend1(); 
    printf("\nAll packets sent successfully\n"); 
} 
 
void selective() 
{ 
    sender(); 
    recvfrm(); 
    resend(); 
    printf("\nAll packets sent successfully\n"); 
} 
 
int sender() 
{ 
    int i; 
 
    printf("\nEnter number of packets: "); 
    scanf("%d", &n); 
 
    for (i = 1; i <= n; i++) 
    { 
        printf("\nEnter data for packet[%d]: ", i); 
        scanf("%d", &frm[i].data); 
        frm[i].ack = 'y'; 
    } 
 
    return 0; 
} 
 
void recvfrm() 
{ 
    int i; 
 
    randomize(); 
    r = rand() % n + 1; 
 
    frm[r].ack = 'n'; 
 
    for (i = 1; i <= n; i++) 
    { 
        if (frm[i].ack == 'n') 
            printf("\nPacket %d not received\n", i); 
    } 
} 
 
void resend() 
{ 
    printf("\nResending packet %d", r); 
    delay(2000); 
 
    frm[r].ack = 'y'; 
 
    printf("\nReceived packet data: %d\n", frm[r].data); 
} 
 
void resend1() 
{ 
    int i; 
 
    printf("\nResending from packet %d\n", r); 
 
    for (i = r; i <= n; i++) 
    { 
        delay(2000); 
        frm[i].ack = 'y'; 
        printf("\nReceived packet %d data: %d", i, frm[i].data); 
    } 
}
