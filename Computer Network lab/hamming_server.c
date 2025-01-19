#include <stdio.h> 
#include <math.h> 
#include <arpa/inet.h> 
#include <string.h> 
#include <unistd.h> 
int main() { 
    int sd,cd,cadl,dl, r, i = 0, j = 0, k = 0, z, c, l; 
    struct sockaddr_in sad, cad; 
    char codeword[100],cword[100]; 
    int data1[100], data2[100]; 
 
    sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
    sad.sin_family = AF_INET; 
    sad.sin_port = htons(9995); 
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    bind(sd,(struct sockaddr*)&sad, sizeof(sad)); 
    listen(sd,10); 
 
    printf("Server is listening on port 9995...\n"); 
    cadl = sizeof(cad); 
    cd = accept(sd, (struct sockaddr *)&cad, &cadl); 
 
    recv(cd, cword, sizeof(cword), 0); 
    printf("Received codeword from client: %s\n", cword); 
 
    printf("Enter the codeword: "); 
    scanf("%s", codeword); 
 
    dl = strlen(codeword); 
 
    while (1) { 
        if (pow(2, i) >= dl + i + 1)   
            break; 
        i++; 
    } 
    r = i;  
    j = dl - 1; 
 
     
    for (i = 1; i <= dl; i++) { 
        data1[i] = codeword[j] - '0'; 
        j--; 
    } 
 
    l = 1; 
    int count = 0; 
 
    for (i = 0; i < r; i++) { 
        z = pow(2, i);  
        c = 0; 
        for (j = z; j <= dl; j = j + 2 * z) { 
            for (k = j; k < j + z; k++) { 
                if (k <= dl) 
                    c = c + data1[k]; 
            } 
        } 
        data2[l] = c % 2; 
        count = count + data2[l]; 
        l++; 
    } 
 
    // Check if the data is correct or has an error 
    if (count == 0) 
        printf("\nActual data received\n"); 
    else { 
        printf("\nWrong data received\n"); 
        j = 0; 
 
               for (i = r - 1; i >= 0; i--) { 
            if (data2[i + 1] == 1) 
                j = j + pow(2, i); 
        } 
 
        printf("\nError at position %d\n", j); 
 
               if (data1[j] == 0) 
            data1[j] = 1; 
        else 
            data1[j] = 0; 
 
        printf("\nCorrected codeword is: "); 
        for (i = dl; i >= 1; i--) 
            printf("%d ", data1[i]); 
        printf("\n"); 
    } 
    close(cd); 
    close(sd); }