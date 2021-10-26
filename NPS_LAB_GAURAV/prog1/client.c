#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
	char buff[10];
	int sockfd;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("\nError creating socket\n");
		exit(0);
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8099);
	servaddr.sin_addr.s_addr = inet_addr("172.16.18.189");
	
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0)
	{
		printf("\nConnect error\n");
		exit(0);
	}
	
	for(;;)
{
	write(sockfd,"#*#*",4);
	read(sockfd,buff,sizeof(buff));
	printf("\nServer echoed %.4s\n",buff);
}
	close(sockfd);
}
