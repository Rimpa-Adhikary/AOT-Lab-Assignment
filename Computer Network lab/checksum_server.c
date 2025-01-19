#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h> 

int main()
{
    int sd,cd,cadl;
    struct sockaddr_in sad,cad;
    char D[100]={0};
   
    //socket creation
    sd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    //bind
    bind(sd, (struct sockaddr *)&sad, sizeof(sad));
    //listen
    listen(sd,10);
    //accept
    cadl=sizeof(cad);
    cd=accept(sd, (struct sockaddr *)&cad, &cadl);
    
    //receive data from client
    recv(cd,D,sizeof(D),0);
    printf("\nthe dataword+checksum will be: %s",D);

    //int length_D,segment,x,sum[100],carry,k,t,i;
    int length_D, segment = 0, x = 0, sum[100] = {0}, carry = 0, k = 0, t = 0, i = 0,j=0;
    
    printf("\nenter the segment: ");
    scanf("%d",&segment);
   
    length_D=strlen(D);
     printf("\nthe length of the string_A %d",length_D);

     //Recalculates the checksum using D
    for(int i=length_D; i>0; i=i-segment)
    {
        carry=0;
        k=segment-1;
        for(int j=i-1;j>=i-segment;j--)
        {
            t=(sum[k]+(D[j]-48)+carry);
            sum[k]=t%2;
            carry=t/2;
            k--;
        }
        if(carry==1)
        {
            for(int j=segment-1;j>=0;j--)
            {
                t=sum[j]+carry;
                sum[j]=t%2;
                carry=t/2;
            }
        }
    }
    
    for(i=0;i<segment;i++)
    {
        if(sum[i]!=1)
        {
            j++;
            break;
        }
    }
    for(i=0;i<segment;i++)
    {
        printf("\n%d",sum[i]);
    }
    printf("\n");
    
    if(j==0)
    {
        printf("\n data recv ok \n");
        printf("\n ACTUAL data IS: \n");
        for(i=0;i<length_D-segment;i++)
        {
            printf("%c ",D[i]);
        }
        printf("\n");    
    }   
    else
    {    
        printf("\n data recv wrong \n");
    }
    
    close(cd);
    close(sd);
    return 0;
}