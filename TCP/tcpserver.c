#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
void main()
{
	int server,newsock;
	char buffer[1024];
	server=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	struct sockaddr_storage store;
	servaddr.sin_port=htons(6265);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	socklen_t addrsize;
	bind(server,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(listen(server,5)==0)
	printf("Listening\n");
	newsock=accept(server,(struct sockaddr*)&store,&addrsize);
	recv(newsock,buffer,1024,0);
	printf("Message received from the client %s\n",buffer);
	strcpy(buffer,"Hi this is server\n");
	send(newsock,buffer,19,0);
	close(server);
	close(newsock);
}
