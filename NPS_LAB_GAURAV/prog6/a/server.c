#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void str_cli(int connfd)
{
	int n;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	again : while((n=recv(connfd,buffer,bufsize,0))>0)
		{
			send(connfd,buffer,n,0);
		}
	if(n<0)
		goto again;
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
			if((pid=fork())==0)
			{
				printf("\nInside Child\n");
				close(listenfd);
				str_cli(connfd);
				exit(0);
			}
			close(connfd);
		}
		else
			printf("\nFailed to connect\n");
	}

	return 0;
}	

	
