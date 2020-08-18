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
- 常用命令    
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
4. 查看提交记录    
使用git log命令可查看从最近到最远的提交记录  
> $ git log  
 commit 8aeceadbca6de5480ca59613c27010f1005625b9 (HEAD -> master)  
 Author: lhaisong <liuhaisong@skyworth,com>  
 Date:   Tue Aug 18 15:42:13 2020 +0800  
  
    第二次提交  
  
 commit 789484c3bec4c967666d56ae1bdcb2f9e852c3a6  
 Author: lhaisong <liuhaisong@skyworth,com>  
 Date:   Tue Aug 18 15:30:01 2020 +0800  
  
    第一次提交  
5. 版本回退  
使用git reset -hard HEAD^命令将文件版本回退到上一版本，其中HEAD表示当前版本，HEAD^表示当前的上一版本，HEAD^^当前上二版本，以此类推，HEAD~100表示当前上100版本  

6. 撤销修改  
两个重要概念：  
> 工作区：电脑里能看见的文件目录可以看作一个工作区，如learn文件夹。  
  工作区中的隐藏文件.git叫做版本库，版本库中存在暂存区(stage),以及git自动创建的第一个分支master，提交文件的过程使用git add将文件提交到暂存区，然后git commit命令将文件提交到分支master  
  如果对工作区的文件做了修改但并没有使用git add指令提交到暂存区，直接使用git restore <filename>即可撤销修改，如果已经提交到暂存区，需要使用git restore --staged <filename>命令将文件移出暂存区，然后再做撤销。  



