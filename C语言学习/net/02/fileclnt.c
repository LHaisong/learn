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


/*socket file transfer*/
int main(){
	int clnt_sock;
	char buff[1024];
	char dst[]="/media/ftp/upload/test.txt";
	char *file_dst;
	char file_name[10];
	char down_name[10];
	char temp[100];

	clnt_sock=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in clntaddr;
	clntaddr.sin_family=AF_INET;
	clntaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clntaddr.sin_port=htons(2048);

	if(connect(clnt_sock,(struct sockaddr*)&clntaddr,sizeof(clntaddr))==-1){
		fputs("connect fail",stdout);
		return 0;
	}
	printf("please input the file you want to download....\n");
	for(;temp!="OK";)
	{
		memset(temp,0,strlen(temp));
		scanf("%s",down_name);
		if(write(clnt_sock,down_name,sizeof(down_name))<0)
		{
			fputs("type file name error",stdout);
			return 0;
		}
		if(read(clnt_sock,temp,sizeof(temp))<0)
		{
			fputs("read() from server failed",stdout);
		}
		printf("tmp is:%s",temp);
	}


    /**
	printf("please input file save name\n");
	scanf("%s",file_name);
	strcat(dst,file_name);
	**/
	file_dst=dst;


	FILE *file=fopen(file_dst,"w+");
	if(file==NULL){
		fputs("can`t open file to write",stdout);
		return 0;
	}
	bzero(buff,sizeof(buff));
	int len=0;
	while(len=read(clnt_sock,buff,sizeof(buff))){
		if(len<0){
			fputs("read data from server failed",stdout);
			break;
		}
		printf("file content is:%s\n",buff);

		int w_len=fwrite(buff,sizeof(char),len,file);
		if(w_len<len){
			fputs("write file failed",stdout);
			break;
		}
	}
    write(clnt_sock,"OK",sizeof("OK"));
	fclose(file);
	close(clnt_sock);
}
