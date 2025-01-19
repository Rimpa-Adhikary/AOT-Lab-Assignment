#include<stdio.h> 
#include<arpa/inet.h> 
#include<string.h> 
#include<unistd.h> 
int main()
{ 
    int sd,cd,cadl,i=0,dl,divl,j=0; 
    struct sockaddr_in sad, cad; 
    char codeword[100],div[100],data[100]; 

    sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 

    sad.sin_family = AF_INET; 
    sad.sin_port = htons(9995); 
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    bind(sd,(struct sockaddr*)&sad, sizeof(sad)); 

    listen(sd,10); 

    printf("Server is listening on port 9995...\n"); 

    cadl = sizeof(cad); 
    cd = accept(sd, (struct sockaddr *)&cad, &cadl); 

    recv(cd, codeword, sizeof(codeword), 0); 
    printf("Received codeword from client: %s\n", codeword); 

    dl=strlen(codeword); 

    printf("\nEnter coefficients of generator polynomial:"); 
    fflush(stdout); 
    scanf("%s",div); 

    divl=strlen(div); 

    strcpy(data,codeword); 
    for(i=0; i<dl-(divl-1);i++)
    { 
        if(codeword[i] == '1')
        { 
            for(j=0; j<divl; j++)
            { 
                if(codeword[i+j] == div[j]) 
                codeword[i+j] = '0'; 
                else 
                codeword[i+j] = '1'; 
            } 
        } 
    } 
    j=0; 
    for(i=dl-(divl-1); i<dl; i++) 
        j=j+codeword[i]-48; 
    if(j==0)
    { 
        printf("\nOriginal data receive\n"); 
        printf("\n Actual data : "); 
        for(i=0;i<dl-(divl-1);i++) 
            printf("%c ",data[i]); 
    } 
    else 
    printf("\n data recv wrong \n"); 
    close(cd); 
    close(sd); 
    return 0; 
}