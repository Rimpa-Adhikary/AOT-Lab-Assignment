#include<stdio.h> 
#include <math.h> 
#include<arpa/inet.h> 
#include<string.h> 
#include<unistd.h> 
int main(){ 
    int sd,cadl,dl,r,i=0,j=0,k=0,z,c; 
    struct sockaddr_in sad, cad; 
    char dataword[100],codeword[100]; 
    int data1[100], data2[100]; 
 
    sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
 
    sad.sin_family = AF_INET; 
    sad.sin_port = htons(9995); 
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    connect(sd,(struct sockaddr*)&sad, sizeof(sad)); 
    printf("\n Enter the dataword: "); 
    fflush(stdout); 
    scanf("%s",dataword); 
    dl=strlen(dataword); 
    while(1){ 
        if(pow(2,i)>=dl+i+1) 
            break; 
        i++; 
    } 
    r=i; 
    printf("\n No of redundant bits: %d \n",r); 
    for(i=0;i<dl;i++) 
        data1[i]=dataword[i] - '0'; 
     
    for(i=0;i<r;i++){ 
        z=pow(2,i); 
        data2[z]=999;  
    } 
    for(i=dl+r;i>=1;i--) 
    { 
        if(data2[i]!=999) 
        { 
            data2[i]=data1[j];  
            j++; 
        } 
    } 
    for(i=0;i<r;i++){ 
        z=pow(2,i);  
        c=0; 
        for(j=z;j<=dl+r;j=z+k){ 
            for(k=j;k<z+j;k++){ 
                if(k<=dl+r){ 
                    if(data2[k]!=999) 
                        c=c+data2[k]; 
                } 
            } 
        } 
        data2[z]=c%2; 
    } 
    printf("\n The codeword is: "); 
    j=0; 
    for(i=dl+r;i>=1;i--) 
        printf("%d",data2[i]); 
    j = 0; 
    for (i = dl + r; i >= 1; i--) { 
        codeword[j++] = data2[i] + '0';  
    } 
    codeword[j] = '\0';  
    send(sd, codeword, sizeof(codeword), 0); 
    close(sd); 
} 
