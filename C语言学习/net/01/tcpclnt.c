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

int main(){
	int clnt_sock;
	char message[512];
	struct sockaddr_in serv_addr;

	clnt_sock=socket(AF_INET,SOCK_STREAM,0);
	if(clnt_sock==-1){
		printf("socket() error");
	}

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(2048);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	/*连接服务器*/
	if(connect(clnt_sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1){
		fputs("connect() error\n",stdout);
	}
	int mess_len=read(clnt_sock,message,sizeof(message)-1);

	if(mess_len=-1){
		fputs("read() error\n",stdout);
	}
	printf("server message is:%s\n",message);

	printf("now input your message send to server:\n");

	while(fgets(message,511,stdin)!=NULL)
	{
		write(clnt_sock,message,sizeof(message));
	}

	close(clnt_sock);
}

