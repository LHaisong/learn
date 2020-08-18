## 1.什么是git？
>   git是一个分布式版本控制系统，与集中的版本控制系统相比，在使用git的时候本地也会被当做一个版本库  
  
## 如何使用？  
- 安装git  
> 在Linux上使用sudo apt-get install git命令即可完成安装，Windows下载安装程序即可。  
   
- 创建仓库
> 可以把一个已经存在的目录作为仓库也可以新建一个目录作为本地仓库  
  cd learn  
  git init  
  使用上面两个命令可将learn文件夹设置为本地仓库  
- 将文件提交到仓库  
1. 通过git add命令将文件添加到仓库  
  > git add learn-git.md  
    无任何显示即提交成功  
2. 通过git commit命令将文件提交到仓库  
  >  git commit -m "第一次提交"  
     -m后接提交说明  
     **需要注意的是：一次commit可以添加多个文件，所以是可以多次add不同的文件的**  
3. 使用git status查看仓库状态  
  >  使用git status命令，可以查看文件是否被修改过。  
     $ git status  
  >  使用git diff查看修改内容  



