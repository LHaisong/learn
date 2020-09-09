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
	int serv_sock;
	int clnt_sock;
	socklen_t clnt_addr_size;
	char mess[512];
	/*��һ��:�����׽��֣�Linux�����·���һ������*/
	if((serv_sock=socket(AF_INET,SOCK_STREAM,0))<0){
		printf("�׽��ִ���ʧ�ܣ�");
		exit(0);
	}
	struct sockaddr_in clntaddr;
	struct sockaddr_in servaddr;
	/*�ڶ���:���׽��ְ���IP��ַ�˿��Լ�Э��(tcp/udp)��Ϣ*/
	memset(&servaddr,0,sizeof(servaddr));//�ṹ��0
	servaddr.sin_family=AF_INET;//IPv4
	servaddr.sin_port=htons(2048);//�˿�
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	/*��socket*/
	if(bind(serv_sock,(struct sockaddr *)&servaddr,sizeof(servaddr))==-1){
		fputs("bind() error!",stdout);
		return 0;
	}
	/*������:��������*/
	if(listen(serv_sock,5)==-1){
		fputs("listen() error!",stdout);
		return 0;
	}

	clnt_addr_size=sizeof(clntaddr);
	//���տͻ�������
	if((clnt_sock=accept(serv_sock,(struct sockaddr *)&clntaddr,&clnt_addr_size))==-1){
		fputs("accept() error!",stdout);
		return 0;
	}else{
		char message[]="hello client,this is server response message";
		write(clnt_sock,message,sizeof(message));
	}

	printf("�ȴ���Ϣ�С�������\n");

	int mess_len;
	/*���տͻ��˵���Ϣ*/
	while((mess_len=read(clnt_sock,mess,sizeof(mess)))!=-1){
		if(mess=="quit"){
			fputs("�Ͽ�����...",stdout);
			break;
		}
		fputs(mess,stdout);
	}
	/*�ر�socket*/
	close(serv_sock);
	close(clnt_sock);
	return 0;
}




