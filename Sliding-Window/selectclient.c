#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
void main()
{
	int client,x,w;
	scanf("%d",w);
	char buffer[1024];
	client=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_port=htons(6265);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr));
	strcpy(buffer,"Hi this is client\n");
	send(client,buffer,19,0);
	recv(client,buffer,1024,0);
	printf("Message received from the server %s\n",buffer);
	
	for(int x=1;x<=w;x++)
	{
		sprintf(buffer,"%d",x);
		send(client,buffer,19,0);
	}
	
	close(client);
}
