#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdarg.h>

/*socket file transfer,download file from server*/
int main(){
	int clnt_sock;
	int serv_sock;
	char buff[1024];
	FILE *file;
	char down_name[10];
	socklen_t clnt_addr_size;
	char *psrc;
	char *pfile;

	serv_sock=socket(AF_INET,SOCK_STREAM,0);

	if(serv_sock<0){
		fputs("create socket() error!\n",stdout);
		return 0;
	}

	struct sockaddr_in servaddr;


	memset(&servaddr,0,sizeof(servaddr));//结构清0
	servaddr.sin_family=AF_INET;//IPv4
	servaddr.sin_port=htons(2048);//端口
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(bind(serv_sock,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
		fputs("bind() error!\n",stdout);
		return 0;
	}

	if(listen(serv_sock,5)<0){
		fputs("listen() error!\n",stdout);
		return 0;
	}

	struct sockaddr_in clntaddr;

	clnt_addr_size=sizeof(clntaddr);
	if((clnt_sock=accept(serv_sock,(struct sockaddr*)&servaddr,&clnt_addr_size))==-1){
		fputs("accept() error!\n",stdout);
		return 0;
	}

	for(;;)
	{
		char temp[]="/media/ftp/download/";
		if(read(clnt_sock,down_name,sizeof(down_name))<0)
		{
			fputs("read file name failed\n",stdout);
			return 0;
		}

		printf("%d\n",1);
		//文件完整路径
		strcat(temp,down_name);
		printf("%d\n",2);
		//打开文件，赋予读写权限
		if((file=fopen(temp,"r+"))==NULL)
		{
			if(write(clnt_sock,"file is not exit,please input again.\n",sizeof("file is not exit,please input again."))<0)
			{
				fputs("write() error\n",stdout);
				return 0;
			}
			printf("%d\n",3);
			fputs("file is not exit\n",stdout);
			memset(down_name,0,strlen(down_name));
			memset(temp,0,strlen(temp));
		}else
		{
			write(clnt_sock,"OK\n",sizeof("OK"));
			psrc=temp;
			printf("%d\n",4);
			break;
		}
	}

	bzero(buff,sizeof(buff));
	int file_len=0;
	while((file_len=fread(buff,sizeof(char),sizeof(buff),file))>0){
		printf("file length is :%d\n",file_len);
		if(write(clnt_sock,buff,file_len)<0){
			fputs("send file failed\n",stdout);
			return 0;
		}
		printf("file data is :%s\n",buff);
	}
	printf("file transfer finished...");
	bzero(buff,sizeof(buff));
	if(read(clnt_sock,buff,sizeof(buff))>0)
	{
		if(buff=="OK")
		{
			fclose(file);
			close(serv_sock);
			close(clnt_sock);
		}
	}
	return 0;
}











































