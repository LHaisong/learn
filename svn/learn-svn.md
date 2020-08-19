### 一.基本概念
1. 仓库
> 仓库是任何一个版本控制系统的核心，是软件开发者保存工作内容的地方，仓库不仅要处理文件，还需要保存历史记录；可能需要联网工作，扮演者服务器的角色，版本控制工具扮演客户端的角色  
2. 主干
> 主要开发所在的目录，是经常被访问的  
3. 标签
> tags存放了被保存项目的命名快照  
### 二.基本操作
#### 1. svn检出过程
```
svn checkout https://SDT15624.digital.com/svn/test/ checkouttest

# svn提供了checkout命令从版本库中拉取一个副本到本地,上面的命令会在当前目录创建一个checkouttest文件夹，并将仓库中的文件复制到该文件夹中

svn info 可以查看当前版本库的信息

Path: .
Working Copy Root Path: E:\checkouttest
URL: https://sdt15624.digital.com/svn/test
Relative URL: ^/
Repository Root: https://sdt15624.digital.com/svn/test
Repository UUID: a76b3ef9-af37-fe4e-892c-82b9d605d619
Revision: 2
Node Kind: directory
Schedule: normal
Last Changed Author: SDT15624
Last Changed Rev: 2
Last Changed Date: 2020-08-19 14:43:53 +0800 (周三, 19 8月 2020)

```
#### 2. 执行修改
```
svn status 可以检查当前工作副本的状态  

E:\test1>svn status
?       学习笔记\这是一个测试文档.txt
M       第一阶段：熟悉产品\测试总结.txt
注：？表示新建的文件，M表示已经修改过的文件；对于显示？的文件需要使用 svn add 这是一个测试文档.txt命令将文件添加到待变更列表

E:\test1\学习笔记>svn add 这是一个测试文档.txt
A         这是一个测试文档.txt
E:\test1>svn status
A       学习笔记\这是一个测试文档.txt
M       第一阶段：熟悉产品\测试总结.txt

然后通过svn commit -m "submit" 命令可将修改更新到远程版本库
```
#### 3. 更新过程
```
如果我当前工作区的文件已经被别人修改过，那当前工作区的修改将无法被提交，需要使用svn update命令更新本地工作区
```
#### 4. 修复错误
```
使用 svn revert <filename>可以撤销修改
```