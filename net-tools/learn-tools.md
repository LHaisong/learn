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
### adb常用的功能命令
### 1.查看adb版本/启动adb服务
> adb version
> adb start -server
### 2.在同一局域网下链接Android设备
> adb connect ip_addr
### 3.查看已连接的设备列表
> adb devices
### 4.查看应用
> adb shell pm list packages    //查看所有应用
> adb shell pm list packages -s //查看系统应用
> adb shell pm list packages -3 //查看第三方应用
### 5.安装应用
> adb install [-l] [-r] [-t] [-s] [-d] [-g] [apk-file-path]  

| 参数 | 含义 | 
| ------ | ------ | 
| -l | 将应用安装到保护目录 | 
| -r | 允许覆盖安装| 
| -t | | 
| -s | 安装应用到sdcard| 
| -d | 降级覆盖安装| 
| -g | 授予所有运行权限| 
### 6.卸载应用
> adb uninstall [-k] [package-name] //其中-k参数可选，表示清除应用数据和缓存目录
### 7.清除应用数据和缓存
> adb shell pm clear [package-name]
### 8.查看应用详细信息
> adb shell dumpsys package [package-name] 
### 9.查看正在运行的服务
> adb shell dumpsys activity services [<package-name>]
### 10.查看应用的安装路径
> adb shell pm path [package-name]
### 11.强制停止应用
> adb shell pm force-stop [package-name]
### 12.从Android设备下载文件到计算机
> adb pull [remote] [local]  //remote:Android设备里的文件  local：计算机目录
> adb push [local] [remote]  //将计算机的文件上传到Android设备
