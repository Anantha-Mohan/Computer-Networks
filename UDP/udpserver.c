#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
void main()
{
	int server,clisize;
	char buffer[1024];
	server=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in servaddr,cliaddr;
	servaddr.sin_port=htons(2002);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clisize=sizeof(cliaddr);
	bind(server,(struct sockaddr*)&servaddr,sizeof(servaddr));
	recvfrom(server,buffer,1024,0,(struct sockaddr*)&cliaddr,&clisize);
	printf("Message received from the client %s\n",buffer);
	strcpy(buffer,"Hi this is server\n");
	sendto(server,buffer,1024,0,(struct sockaddr*)&cliaddr,clisize);
	close(server);
}
