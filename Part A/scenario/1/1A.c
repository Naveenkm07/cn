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
    
    
    strcpy(input, "1011001110001010");
    strcpy(gp, "10001");
    
    printf("\n--- SCENARIO 1A ---");
    printf("\n Input message: %s", input);
    printf("\n Generator polynomial: %s\n", gp);
    
    strcpy(output, input);
    
    
    for(i=1; i<strlen(gp); i++) {
        strcat(output, "0");
    }
    
    
    crc(input, output, gp);
    printf("\n The transmitted message is %s%s\n", input, output + strlen(input));
    
    
    printf("\n Enter the received message in binary to verify error: \n");
    scanf("%s", recv);
    
    if(crc(input, recv, gp)) {
        printf("\n Error in data transmission has occurred \n");
    } else {
        printf("\n No error in data \n");
    }
    getch();
}
