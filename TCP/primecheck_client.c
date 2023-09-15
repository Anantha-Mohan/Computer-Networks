#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
void main()
{
	int client;
	char buffer[1024];
	client=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_port=htons(6265);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr));
	printf("Enter number to check:");
	scanf("%s",buffer);
	send(client,buffer,19,0);
	recv(client,buffer,1024,0);
	printf("%s",buffer);
	close(client);
}
