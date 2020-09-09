#ifndef COMMON_H
#define COMMON_H

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>		// getaddrinfo()
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>



/* constants */
#define DEBUG				1
#define MAXSIZE 			512 	// max buffer size
#define CLIENT_PORT_ID		30020


/* Holds command code and argument */
struct command {
	char arg[255];
	char code[5];
};




/**
 * 在服务器创建socket
 */
int socket_create(int port);


/**
 * 客户端socket连接
 */
int socket_accept(int sock_listen);


/**
 * 连接到远程主机
 */
int socket_connect(int port, char *host);



/**
 * 数据接收
 */
int recv_data(int sockfd, char* buf, int bufsize);


/**
 * 发送响应
 */
int send_response(int sockfd, int rc);



//------------------- UTILITY FUNCTIONS-------------------//

/**
 * Trim whiteshpace and line ending
 * characters from a string
 */
void trimstr(char *str, int n);



/**
 * Read input from command line
 */
void read_input(char* buffer, int size);


#endif








