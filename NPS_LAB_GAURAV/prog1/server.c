#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
int sockfd,connfd,clilen,n;
struct sockaddr_in servaddr,cliaddr;
char buff[100];
sockfd= socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("socket creation failed");
exit(0);
}
servaddr.sin_family= AF_INET;
servaddr.sin_port= htons(8099);
servaddr.sin_addr.s_addr= inet_addr("172.16.19.2");

if(bind(sockfd,(struct sockaddr* ) &servaddr,sizeof(servaddr))!=0)
{
printf("bind failed");
exit(0);
}

listen(sockfd,5);
clilen= sizeof(cliaddr);

connfd= accept(sockfd,(struct sockaddr*) &cliaddr,&clilen);

if(connfd<0)
{
printf("connection failed");
exit(0);

}
n= read(connfd,buff,sizeof(buff));

write(connfd,buff,n);
close(connfd);
close(sockfd);
}


