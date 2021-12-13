#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void client_echo(FILE *fp,int sockfd)
{
	int bufsize = 1024;
	int cont;
	char *buffer = malloc(bufsize);
	while((fgets(buffer,bufsize,fp))!=NULL)
	{
		send(sockfd,buffer,bufsize,0);
		if(cont = recv(sockfd,buffer,bufsize,0)>0)
		fputs(buffer,stdout);
	}
}

int main(int argc , char *argv[])
{
	int sockfd;
	struct sockaddr_in address;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
	{
		printf("\nSocket created\n");
		address.sin_family=AF_INET;
		address.sin_port = htons(32321);
		inet_pton(AF_INET,argv[1],&address.sin_addr);
		connect(sockfd,(struct sockaddr *)&address,sizeof(address));
		client_echo(stdin,sockfd);
	}
	return 0;
}
