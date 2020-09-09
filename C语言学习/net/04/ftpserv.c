#include "common.h"



int main(int argc,char *argv[])
{
    int sock_listen,sock_control,port,pid;

    if(argc!=2)
    {
        printf("usage:./ftpserv port\n");
        exit(0);
    }

    port=atoi(argv[1]);

    if((sock_listen=socket_create(port))<0)
    {
        perror("error creating socket\n");
        exit(1);
    }

    while(1)
    {
        if((sock_control=socket_accept(sock_listen))<0)
        {
            perror("error accept\n");
            break;
        }
        if((pid=fork())<0)
        {
            perror("fork child process error\n");
        }
        else if(pid==0)
        {
            close(sock_listen);
            handle_process(sock_control);
            close(sock_control);
            exit(0);
        }
    }
    close(sock_listen);

    return 0;

}

void handle_process(int sock_control)
{
    int sock_data;
    char cmd[5];
    char argv[512];
    send_response(sock_control,220);

    while(1)
    {
        int usr_cmd=ftpserv_recv_cmd(sock_control,cmd,argv);
        if(usr_cmd<0||usr_cmd==221)
        {
            break;
        }
        if(usr_cmd==200)
        {
            if(sock_data=ftpserv_start_data_conn(sock_control)<0)
            {
                close(sock_control);
                exit(0);
            }
            if(cmd=="list")
            {
                ftpserv_list(sock_data,sock_control);
            }
            if(cmd=="get"){
				ftpserv_get(sock_data,argv);
            }
    }
}

int send_response(int sock_control,int c)
{
    int code=htons(c);

    if(write(sock_control,code,sizeof(code))<0)
    {
        perror("error in send response.\n");
        return -1;
    }
    return 0;
}

int ftpserv_recv_cmd(int sock_control,char *cmd,char *argv)
{
    int rc=200;
    char buff[512];

    memset(cmd,0,5);
    memset(argv,0,512);
    memset(buff,0,512);

    if(recv_data(sock_control,buff,sizeof(buff))<0)
    {
        perror("receive data from client error.\n");
        return -1;
    }

    strncpy(cmd,buff,4);
    char *tmp = buff + 5;
    strcpy(argv, tmp);

    if(strcmp(cmd,"quit")==0)
    {
        rc=221;
    }
    else if(strcmp(cmd,"get")==0||strcmp(cmd,"list")==0)
    {
        rc=200;
    }
    else
    {
        //invalid command
        rc=500;
    }

    send_response(sock_control,rc);
    return rc;
}

int ftpserv_start_data_conn(int sock_control)
{
    int sock_data_cnne;

    struct sockaddr_in sockaddr;

    socklen_t len=sizeof(sockaddr);

    if((sock_data_cnne=connect(sock_control,(struct sockaddr*)&sockaddr,len))<0)
    {
        perror("connect error!\n");
        return -1;
    }

    return sock_data_cnne;
}

int ftpserv_list(int sock_data,int sock_control)
{
    DIR *filedir=NULL;
    char buff[512];
    struct dirent* entry;

    bzero(buff,512);
    if((filedir=opendir(FILEPATH))==NULL)
    {
        perror("open directory failed\n");
        return -1;
    }

    while((entry=readdir(filedie))!=NULL)
    {
        if(sprintf(buff,entry->d_name,512)<0)
        {
            perror("sprintf error!\n");
            return -1;
        }
        if(write(sock_data,buff,512)<0)
        {
            perror("write error.\n");
            return -1;
        }
    }
    closedir(filedir);
    return 0;
}

int ftpserv_get(int sock_data,char *filename)
{

    char src[]=FILEPATH;

    strcat(src,filename);

    char *pfile=src;

    FILE *file;

    char buff[1024];
    int file_len=0;
    bzero(buff,1024);

    if((file=fopen(pfile,"r+"))==NULL)
    {
        perror("open file failed.\n");
        return -1;
    }
    while((file_len=fread(buff,sizeof(char),sizeof(buff),file))>0)
    {
        if(write(sock_data,buff,file_len)<0)
        {
            fputs("send file failed\n",stdout);
            return 0;
        }
    }
	return 0;
}



