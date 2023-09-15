#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
void main()
{
	int client,servsize;
	char buffer[1024];
	client=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_port=htons(2002);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servsize=sizeof(servaddr);
	bind(client,(struct sockaddr*)&servaddr,sizeof(servaddr));
	strcpy(buffer,"Hi this is client\n");
	sendto(client,buffer,1024,0,(struct sockaddr*)&servaddr,servsize);
	recvfrom(client,buffer,1024,0,(struct sockaddr*)&servaddr,&servsize);
	printf("Message received from the server %s\n",buffer);
	close(client);
}
