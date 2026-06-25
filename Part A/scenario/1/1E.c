#include <stdio.h>
#include <string.h>
#include <conio.h>

int crc(char *input, char *output, char *gp) {
    int i, j;
    for(i=0; i<strlen(input); i++) {
        if(output[i] == '1') {
            for(j=0; j<strlen(gp); j++) {
                if (output[i+j] == gp[j]) {
                    output[i+j] = '0';
                } else {
                    output[i+j] = '1';
                }
            }
        }
    }
    for(i=0; i<strlen(output); i++) {
        if(output[i] == '1') {
            return 1;
        }
    }
    return 0;
}

void main() {
    char input[50], output[50];
    char recv[50], gp[50];
    int i;
    int total = 0, errors = 0, choice = 1;
    
    clrscr();
    
    
    strcpy(input, "1101011010110011");
    strcpy(gp, "10011");
    
    printf("\n--- SCENARIO 1E ---");
    printf("\n Input frame: %s", input);
    printf("\n Generator polynomial: %s\n", gp);
    
    strcpy(output, input);
    
    
    for(i=1; i<strlen(gp); i++) {
        strcat(output, "0");
    }
    
    
    crc(input, output, gp);
    printf("\n The transmitted frame is %s%s\n", input, output + strlen(input));
    
    
    while(choice == 1) {
        total++;
        printf("\n Enter received frame %d: ", total);
        scanf("%s", recv);
        
        if(crc(input, recv, gp)) {
            printf(" -> Frame %d is corrupted.\n", total);
            errors++;
        } else {
            printf(" -> Frame %d is valid.\n", total);
        }
        
        printf("\n Process another frame? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }
    
    printf("\n---------------------------------");
    printf("\n Total frames processed: %d", total);
    printf("\n Total error frames detected: %d\n", errors);
    getch();
}
