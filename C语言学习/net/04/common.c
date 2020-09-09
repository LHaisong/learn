#include "common.h"

/*创建socket*/
int socket_create(int port)
{
	int sockfd;

	struct sockaddr_in sockaddr;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		close(sockfd);
		perror("create socket error!\n");
		return -1;
	}

	sockaddr.sin_family=AF_INET;
	sockaddr.sin_port=htons(port);
	sockaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(bind(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))<0)
	{
		close(sockfd);
		perror("bind() socket error!\n");
		return -1;
	}

	if(listen(sockfd,5)<0)
	{
		close(sockfd);
		perror("listen() error!\n");
		return -1;
	}

	return sockfd;
}

/*创建新socket，等待连接*/
int socket_accept(int sock_listen)
{
	int sockfd;

	struct sockaddr_in clntaddr;

	socketlen_t clnt_addr_size=sizeof(clntaddr);

	sockfd=accept(sock_listen,(struct sockaddr*)&clntaddr,&clnt_addr_size);

	if(sockfd<0)
	{
		close(sockfd);
		perror("accept() error!\n");
		return -1;
	}

	return sockfd;
}

/*socket 连接操作*/
int socket_connect(int port,char *host)
{
	int sockfd;

	struct sockaddr_in serv_addr;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("create socket error!\n");
		return -1;
	}

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(port);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		perror("connect error!\n");
		return -1;
	}

	return sockfd;

}

int recv_data(int sockfd, char* buf, int bufsize)
{
	size_t datazize;
	memset(&buff,0,bufsize);

	if((datasize=read(sockfd,buf,bufsize))<0)
	{
		perror("receive data from server error!\n");
		return -1;
	}
	return datasize;
}
























































