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
	listen(server,5);
	newsock=accept(server,(struct sockaddr*)&store,&addrsize);
	
	recv(newsock,buffer,1024,0);
	printf("Client Request Obtained,Accepted\n\n");
	
	strcpy(buffer,"Accepted Request\nServer Name:server_name\nStatus Code:220\n");
	send(newsock,buffer,1024,0);
	
	memset(buffer,0,sizeof(buffer));
	recv(newsock,buffer,1024,0);
	printf("C:%s\n",buffer);
	
	strcpy(buffer,"Status Code:250\n");
	send(newsock,buffer,1024,0);
	
	memset(buffer,0,sizeof(buffer));
	recv(newsock,buffer,1024,0);
	printf("C:%s\n",buffer);
	
	strcpy(buffer,"Status Code:250\n");
	send(newsock,buffer,1024,0);
	
	memset(buffer,0,sizeof(buffer));
	recv(newsock,buffer,1024,0);
	printf("C:%s\n",buffer);
	
	strcpy(buffer,"Status Code:354\n");
	send(newsock,buffer,1024,0);
	
	memset(buffer,0,sizeof(buffer));
	recv(newsock,buffer,1024,0);
	printf("C:%s\n",buffer);
	
	strcpy(buffer,"Status Code:354\n");
	send(newsock,buffer,1024,0);
	
	while(1)
	{
		memset(buffer,0,sizeof(buffer));
		recv(newsock,buffer,1024,0);
		if(strncmp(buffer,".",1)==0){break;}else{
		printf("%s\n",buffer);
		}
	}
	
	memset(buffer,0,sizeof(buffer));
	recv(newsock,buffer,1024,0);
	printf("C:%s\n",buffer);
	
	strcpy(buffer,"Status Code:221\n");
	send(newsock,buffer,1024,0);
	
	close(server);
	close(newsock);
}
