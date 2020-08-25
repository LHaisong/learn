## 远程连接配置
### 1.在Ubuntu中部署telnet服务端
> sudo apt install telnetd  //1.首先安装telnetd
> sudo apt install xinetd   //2.安装xinetd
> sudo service xinetd status//3.查看服务是否正常运行
> sudo /etc/init.d/openbsd-inetd restart  //telnet服务启动
### 2.在Ubuntu中配置ssh远程登陆
> sudo apt-get install openssh-server  //安装ssh服务
> dpkg -l | grep ssh                   //查看安装的服务
> ps -e | grep ssh                     //查看服务是否启动
> sudo /etc/init.d/ssh stop/start      //服务暂停/启动

## ubuntu ftp服务器搭建
### 1.ubuntu安装配置vsftpd
> sudo apt-get install vsftpd
> sudo vim /etc/vsftpd.config  //配置  
### 2.ftp配置
> sudo mkdir /media/ftp  //创建ftp目录  
> sudo useradd -d /media/ftp  -s /bin/bash ftpuser  //添加用户ftpuser  
> sudo passwd ftpuser  // 设置用户密码  
> sudo chown ftpuser:ftpuser /media/ftp //设置ftp目录用户权限  
> sudo touch /etc/vsftpd.user_list //创建存放登陆用户的文件   
> sudo vim /etc/vsftpd.user_list   //在vsftpd.user_list中添加ftpuser，表示可使用ftpuser登入ftp服务器  
> sudo service vsftpd stop/start  //ftp服务暂停与停止  
- ftp服务器测试正常，在Windows上能进行远程访问  
## Ubuntu HTTP服务器搭建
