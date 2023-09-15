#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
void main()
{
	int client;
	char buffer[1024],rcpt[100],sender[100];
	client=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_port=htons(6265);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
	
	
	printf("Requesting to server....\n");
	strcpy(buffer,"Requst to Server,Message from Client\n\n");
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("S: %s\n",buffer);
	
	printf("\nSending HELO command to the server with client name information....\n");
	strcpy(buffer,"HELO client_name\n");
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("\nS:%s\n",buffer);
	
	printf("Sender's Email ID:");
	scanf("%s",rcpt);
	printf("Sending MAIL FROM command to server with the above email id.....\n");
	sprintf(buffer,"MAIL FROM:%s",rcpt);
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("\nS:%s\n",buffer);
	
	printf("Receipients's Email ID:");
	scanf("%s",sender);
	printf("Sending RCPT TO command to server with the above email id.....\n");
	sprintf(buffer,"RCPT TO:%s",sender);
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("\nS:%s\n",buffer);
	
	printf("Sending DATA command to server\n");
	strcpy(buffer,"DATA");
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("\nS:%s\n\n",buffer);
	
	while(1)
	{
		memset(buffer,0,sizeof(buffer));
		scanf("%s",buffer);
		send(client,buffer,1024,0);
		if(strncmp(buffer,".",1)==0)
		{break;}
	}
	
	printf("Sending QUIT command to server\n");
	strcpy(buffer,"QUIT");
	send(client,buffer,1024,0);
	
	recv(client,buffer,1024,0);
	printf("\nS:%s\n\n",buffer);
	
	close(client);
}
