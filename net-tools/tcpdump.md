# tcpdump
## tcpdump 是一款强大的网络抓包工具，它使用 libpcap 库来抓取网络数据包，这个库在几乎在所有的 Linux/Unix 中都有。
## tcpdump常用参数
```
tcpdump -i eth0 -nn -s0 -v port 80
-i:选择要捕获的接口，通常是以太网卡或无线网卡，也可以是vlan或者其他特殊接口
-nn:单个n表示不解析域名，直接显示IP，两个n表示不解析域名和端口。这样可以方便查看IP和端口，当抓取的数据量大时很高效，因为域名解析是个费时的操作
-s0:tcpdump默认截取96字节的报文内容。使用-s number可以自定截取长度，number为0时表示截取报文全部内容
-v:-v/-vv/-vvv可以用来显示更多详细的信息
port 80：端口过滤器，表示仅抓取端口号80上的流量
```
## tcpdump抓包命令
### 1.sudo tcpdump -D
> 列出可抓取的网络接口
### 2.将抓取的数据写入文件
> sudo tcpdump -w test.pcap
> sudo tcpdump -r test.pcap //载入已存在的文件

## 过滤器
### 1.host过滤器
> sudo tcpdump host 192.168.1.101  //该命令会抓取来自192.168.1.101和发往192.168.1.101的流量  
> sudo tcpdump src host 192.168.1.101  //该命令会抓取192.168.1.101发出的数据  
### 2.network过滤器
- network过滤器用于过滤某个网段的数据
> sudo tcpdump net 192.168.1  //该命令抓取所有从192.168.1.x发出或发往192.168.1.x的数据  
> sudo tcpdump net 192.168    //该命令抓取所有从192.168.x.x发出或发往192.168.x.x的数据  
> 该过滤器和host过滤器一样也可以指定源和目的地（src/dst）  
### 3.proto过滤器
- proto过滤器用来过滤某个协议的数据，关键字为proto,可省略。proto后面可以跟上协议号或协议名称，支持 icmp, igmp, igrp, pim, ah, esp, carp, vrrp, udp和 tcp。  
> sudo tcpdump -n tcp  //抓取TCP协议的报文
### 4.port过滤器
- 用于过滤经过某个端口的报文
> sudo tcpdump port 80
## 例子
### 1.提取 HTTP 用户代理
> sudo tcpdump -nn -A -s1500 -l | grep "User-Agent:"  
### 2.抓取 HTTP GET/POST流量
> sudo tcpdump -s 0 -A -vv 'tcp[((tcp[12:1] & 0xf0) >> 2):4] = 0x47455420'  //抓取get流量
> sudo tcpdump -s 0 -A -vv 'tcp[((tcp[12:1] & 0xf0) >> 2):4] = 0x504f5354'  //抓取post流量
### 3.提取HTTP url
> tcpdump -s 0 -v -n -l | egrep -i "POST /|GET /|Host:"
### 4.提取服务器端和客户端的cookie
> tcpdump -nn -A -s0 -l | egrep -i 'Set-Cookie|Host:|Cookie:'