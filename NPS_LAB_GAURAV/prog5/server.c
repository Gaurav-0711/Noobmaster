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

	while((fputs(buffer,stdout))!=NULL)
	{
		send(sockfd,buffer,bufsize,0);
		if(cont = recv(sockfd,buffer,bufsize,0)>0)
		fputs(buffer,stdout);
	}
}
		

main()
{
	int cont,listenfd,connfd,addrlen,pid;
	struct sockaddr_in address,cli_addr;
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))>0)
	{
		printf("\nSocket created\n");
		address.sin_family= AF_INET;
		address.sin_addr.s_addr=INADDR_ANY;
		address.sin_port = htons(32321);	
		bind(listenfd,(struct sockaddr *)&address,sizeof(address));
		listen(listenfd,5);
		printf("\nServer is listening\n");
		if((connfd=accept(listenfd,(struct sockaddr *)&cli_addr,&addrlen))>0)
		{		
			
			
				printf("\nInside Child\n");
				
				client_echo(stdin,connfd);
				
			
			close(connfd);
		}
		else
			printf("\nFailed to connect\n");
	}

	return 0;
}	

	
