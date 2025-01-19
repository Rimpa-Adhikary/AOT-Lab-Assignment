#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
    int sd,cd,cadl;
    struct sockaddr_in sad,cad;
    char A[50];

    //socket creation
    sd= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    sad.sin_family=AF_INET;
    sad.sin_port= htons(9975);
    sad.sin_addr.s_addr= inet_addr("127.0.0.1");
    //bind
    bind(sd,(struct sockaddr*)&sad, sizeof(sad));
    //listen
    listen(sd,10);
    //accept
    cadl= sizeof(cad);
    cd= accept(sd,(struct sockaddr*)&cad,&cadl);

    //write
    recv(cd,A,sizeof(A),0);

    printf("accepted codeword is %s",A);

    close(cd);
    close(sd);
    return 0;
}