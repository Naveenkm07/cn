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
    
    clrscr();
    
    
    strcpy(input, "1101011100110101");
    strcpy(gp, "100001");
    
    printf("\n--- SCENARIO 1D ---");
    printf("\n File Data Message: %s", input);
    printf("\n Generator polynomial: %s\n", gp);
    
    strcpy(output, input);
    
    
    for(i=1; i<strlen(gp); i++) {
        strcat(output, "0");
    }
    
    
    crc(input, output, gp);
    printf("\n The transmitted frame is %s%s\n", input, output + strlen(input));
    
    
    printf("\n Enter the received frame at data center: \n");
    scanf("%s", recv);
    
    if(crc(input, recv, gp)) {
        printf("\n Bit errors detected in file data! \n");
    } else {
        printf("\n File data received without bit errors \n");
    }
    getch();
}
