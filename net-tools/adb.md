# curl学习
## curl是一种命令行工具，作用是发出网络请求，然后得到和提取数据，显示在"标准输出"（stdout）上面。
### curl功能命令
### 1.查看网页源码
> curl www.baidu,com
### 2.保存网页
> curl -o [filename] www.baidu.com
### 3.自动跳转
> curl -L www.baidu.com
### 4.显示头信息
> curl -i www.baidu.com //包含http response头信息和网页完整信息
> curl -I www.baidu.com //只包含http response头信息
### 5.显示通信过程
> curl -v www.baidu.com
> curl --trace output.txt www.baidu.com  //可以将详细的通信过程保存到output.txt中
### 6.发送表单信息
> 假设表单信息如下：
```
    <form  action="doLogin" method="post">
        <input type="text"  name="username"  value="admin"/>
        <input type="password"  name="password"  value="admin"/>
        <button type="submit"  value="submit" />
    </form>
```
> curl -d "username=admin&password=admin" "www.xxx.com/doLogin"


# adb学习
## ADB，即 Android Debug Bridge 是一种允许模拟器或已连接的 Android 设备进行通信的命令行工具，它可为各种设备操作提供便利，如安装和调试应用，并提供对 Unix shell（可用来在模拟器或连接的设备上运行各种命令）的访问。ADB 是 Android SDK 里的一个工具, 用这个工具可以直接操作管理Android模拟器或者真实的Android设备。主要的功能有：
- 在设备上运行Shell命令；
- 将本地APK软件安装至模拟器或Android设备；
- 管理设备或手机模拟器上的预定端口；
- 在设备或手机模拟器上复制或粘贴文件。
## adb常用的功能命令
### 基本命令
### 1.查看adb版本/启动adb服务
> adb version
> adb start -server
### 2.在同一局域网下链接Android设备
> adb connect ip_addr
### 3.查看已连接的设备列表
> adb devices
### 应用管理
### 1.查看应用
> adb shell pm list packages    //查看所有应用
> adb shell pm list packages -s //查看系统应用
> adb shell pm list packages -3 //查看第三方应用
### 2.安装应用
> adb install [-l] [-r] [-t] [-s] [-d] [-g] [apk-file-path]  

| 参数 | 含义 | 
| ------ | ------ | 
| -l | 将应用安装到保护目录 | 
| -r | 允许覆盖安装| 
| -t | | 
| -s | 安装应用到sdcard| 
| -d | 降级覆盖安装| 
| -g | 授予所有运行权限| 
### 3.卸载应用
> adb uninstall [-k] [package-name] //其中-k参数可选，表示清除应用数据和缓存目录
### 4.清除应用数据和缓存
> adb shell pm clear [package-name]
### 5.查看应用详细信息
> adb shell dumpsys package [package-name] 
### 6.查看正在运行的服务
> adb shell dumpsys activity services [<package-name>]
### 7.查看应用的安装路径
> adb shell pm path [package-name]
### 8.强制停止应用
> adb shell pm force-stop [package-name]

### 文件管理
### 1.从Android设备下载文件到计算机
> adb pull [remote] [local]  //remote:Android设备里的文件  local：计算机目录
> adb push [local] [remote]  //将计算机的文件上传到Android设备
### 2.列出指定目录的内容
> adb shell ls [options] [directory] //directory可选，省略则表示列出根目录

| 参数 | 含义 | 
| ------ | ------ | 
| 无 | 列出所有文件和目录 | 
| -a | 列出目录下所有文件(包含隐藏的)| 
| -i | 列出所有文件以及对应的索引编号| 
| -s | 列出所有文件以及文件大小| 
| -n | 列出所有文件及其UID和GID| 
| -R | 列出所有的子目录中的文件|
### 3.文件目录操作
> adb shell 
> cd [directory] //切换到指定目录
> pwd  //输出当前目录
> mkdir [options] [directory-name] //创建文件目录 options：无->创建目录；-m->创建目录并赋予读写权限
> cp [source] [dest] //复制文件或目录
> mv [source] [dest] //移动文件或目录
>
### 4.删除文件或目录
> adb shell 
> rm [options] [file or directory]  //options参数可选

| 参数 | 含义 | 
| ------ | ------ | 
| 无 | 删除文件 | 
| -f | 强制删除文件，系统不提示| 
| -r | 强制删除指定目录中的文件和子目录| 
| -d | 删除指定目录，即使是非空目录| 
| -i | 交互性删除，删除前提示| 

### 网络管理
### 1.查看网络统计信息
> adb shell netstat
> adb shell netstat [filepath]  //将网络统计信息输出到指定文件夹
### 2.测试网络延迟(ping)
> adb shell ping [域名] //不结束会一直ping ctrl+c停止

### 模拟按键输入
> adb shell input keyevent [code]

| code | 功能 | 
| ------ | ------ | 
|  4   | 返回 | 
|  26  | 电源 | 
|  82  | 菜单 | 
|  24/25 | 音量加/减 | 
|  85   | 播放/暂停 | 
|  224/223| 点亮/熄灭屏幕 | 

### 日志打印
> adb logcat [filter-specs]

| 参数 | 含义 | 
| ------ | ------ | 
|*:V |过滤只显示 Verbose 及以上级别(优先级最低)|
|*:D |过滤只显示 Debug 及以上级别|
|*:I |过滤只显示 Info 及以上级别|
|*:W |过滤只显示 Warning 及以上级别|
|*:E |过滤只显示 Error 及以上级别|
|*:F |过滤只显示 Fatal 及以上级别|
|*:S |过滤只显示 Silent 及以上级别(优先级最高，什么也不输出)|

> adb logcat *:W //会将 Warning、Error、Fatal 和 Silent 日志输出。

### 查看Android设备系统属性
> adb shell getprop ro.product.model  //查看设备型号
> adb shell dumpsys battery  //查看设备电池状况
> adb shell wm size  //查看分辨率
> adb shell wm density  //查看屏幕密度
> adb shell getprop ro.build.version.release  //系统版本
> adb shell ifconfig  //查看IP地址
> adb shell cat /sys/class/net/wlan0/address  //查看mac地址
> adb shell cat /proc/cpuinfo  //CPU信息
> adb shell cat /proc/meminfo  //内存信息
> adb shell cat /system/build.prop  //硬件与系统属性
