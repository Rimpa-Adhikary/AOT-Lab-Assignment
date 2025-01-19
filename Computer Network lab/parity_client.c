#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
    int sd,cd,cadl;
    struct sockaddr_in sad,cad;
    char str[50];

    //socket creation
    sd= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    sad.sin_family=AF_INET;
    sad.sin_port= htons(9975);
    sad.sin_addr.s_addr= inet_addr("127.0.0.1");

    //connect
    connect(sd,(struct sockaddr*)&sad, sizeof(sad));
    
    //initalization
    int len=0, count=0;
    char A[50],B[50],C[50];
    printf("Enter codeword :");
    scanf("%s",A);
    len= strlen(A);

    //count no. of 1 in A
    for(int i=0; i<=len; i++)
    {
        if(A[i]=='1'){
            count++;
        }
    }
    printf("the number of 1 in codeword :%d",count);

    //parity calculation
    strcpy(B,A);
    if(count%2==0){
        C[0]='0';
        C[1]='\0';
        strcat(B,C);
        printf("Even parity bit will be :");
        puts(B);

        C[0]='1';
        C[1]='\0';
        strcat(A,C);
        printf("Odd parity bit will be :");
        puts(A);
    }
    else{
        C[0]='1';
        C[1]='\0';
        strcat(B,C);
        printf("Even parity bit will be :");
        puts(B);

        C[0]='0';
        C[1]='\0';
        strcat(A,C);
        printf("Odd parity bit will be :");
        puts(A);
    }
    send(cd,A,sizeof(A),0);

    close(cd);

    return 0;
}