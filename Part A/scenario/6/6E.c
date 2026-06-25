#include<stdio.h>  
#include<stdlib.h> 
#include<conio.h>

long phi, M, n, e, d, C;  

void encrypt()  
{  
    int i;  
    C = 1;  
    for(i=0; i<e; i++)  
        C = (C * M) % n;  
    printf("\n\tEncrypted File Metadata (Ciphertext) : %ld", C);  
}  

void decrypt()  
{  
    int i;  
    long plain = 1;  
    for(i=0; i<d; i++)  
        plain = (plain * C) % n;  
    printf("\n\tDecrypted File Metadata (Plaintext)  : %ld", plain);  
}  

void main()  
{   
    int i, p, q, rem, gcd;  
    
    clrscr();
    printf("--- SCENARIO 6E: RSA Encryption (Cloud Storage) ---\n\n");
    
    p = 17;
    q = 19;
    M = 12;
    
    printf("Given values:\n");
    printf("p = %d, q = %d, Message = %ld\n", p, q, M);
    
    n = p * q;  
    phi = (p - 1) * (q - 1);  
    
    e = 2;
    while(e < phi) {
        gcd = 1;
        for(i=1; i<=e && i<=phi; ++i) {
            if(e%i==0 && phi%i==0) gcd = i;
        }
        if(gcd == 1) break;
        e++;
    }
    
    d = 0;  
    do  
    {  
        d++;  
        rem = (d * e) % phi;  
    } while(rem != 1);  
    
    printf("\n\tCalculated n\t= %ld", n);  
    printf("\n\tCalculated Phi\t= %ld", phi);  
    printf("\n\tPublic Key (e)\t= %ld", e);  
    printf("\n\tPrivate Key (d)\t= %ld\n", d);  
    
    if(M < n)  
    {  
        encrypt();  
        decrypt();  
    }  
    else {
        printf("\nInvalid Plain text (M must be less than n)\n") ;  
    }
    
    getch();
}
