#include<stdio.h> 
#include<arpa/inet.h> 
#include<string.h> 
#include<unistd.h> 
int main()
{ 
    int sd,cadl,i=0; 
    struct sockaddr_in sad, cad; 
    char dataword[100],divisor[100],data[100]; 
    sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
    sad.sin_family = AF_INET; 
    sad.sin_port = htons(9995); 
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    connect(sd,(struct sockaddr*)&sad, sizeof(sad));
 
    printf("\nEnter the input data: "); 
    fflush(stdout); 
    scanf("%s", dataword); 

    printf("\nEnter coefficients of generator polynomial: "); 
    fflush(stdout); 
    scanf("%s", divisor); 

    int dl = strlen(dataword); 
    int divl = strlen(divisor); 

    for(i=0; i<divl-1; i++) 
    dataword[dl+i] = '0'; 
    dataword[dl+i] = '\0'; 
    printf("\nThe updated dividend: %s",dataword); 
    strcpy(data,dataword); 

    for(i=0; i<dl; i++)
    { 
        if(data[i] == '1')
        { 
            for(int j=0; j<divl; j++)
            { 
            if(data[i+j] == divisor[j]) 
            data[i+j] = '0'; 
            else 
            data[i+j] = '1'; 
            } 
        } 
    } 
    for(i=dl; i<dl+(divl-1);i++) 
        dataword[i] = data[i]; 
    printf("\nThe codeword is: %s",dataword); 
    send(sd,dataword,sizeof(dataword),0); 
    close(sd); 
} 