## 1.什么是make
在Linux下利用make工具可以自动完成编译工作，对于一个大型的C/C++项目：
- 如果仅仅修改了某几个源文件，则只重新编译这几个源文件；  
- 如果某个头文件被修改，则重新编译所有包含该头文件的源文件。 
## 2.什么是makefile
> makefile 可以简单的认为是一个工程文件的编译规则，描述了整个工程的编译和链接等规则。其中包含了那些文件需要编译，那些文件不需要编译，那些文件需要先编译，那些文件需要后编译，那些文件需要重建等等。编译整个工程需要涉及到的，在 Makefile 中都可以进行描述。也就是说，Makefile 可以使得我们的项目工程的编译变得自动化，不需要每次都手动输入一堆源文件和参数。  
## 3.makefile文件的格式
makefile文件主要包含两部分，分别是依赖关系和执行的命令，如下所示：  
> targets : prerequisites  
>   command  
说明：  
- targets：规则的目标，可以是 Object File（一般称它为中间文件），也可以是可执行文件，还可以是一个标签；  
- prerequisites：是我们的依赖文件，要生成 targets 需要的文件或者是目标。可以是多个，也可以是没有；  
- command：make 需要执行的命令（任意的 shell 命令）。可以有多条命令，每一条命令占一行。  
```
//编译test.c,前置条件test.c存在
//相当于执行了两条命令
test:test.c
    gcc test.c -o test
    ./test
```
## 4.makefile的工作流程
在makefile中添加如下代码
```
main:main.o impl.o
	gcc main.o impl.o -o main
	./main
main.o:main.c main.h
	gcc -c main.c
impl.o:impl.c
	gcc -c impl.c
```
在默认情况下make执行的是第一条规则，即以第一条规则为最终目标，它的具体工作流程是：  
1. shell执行make命令，读取目录下的makefile文件，并以第一条规则main:main.o impl.o为最终目标，执行第一条规则  
2. 如果依赖文件main.o和impl.o文件不存在，将会使用其描述规则创建它
上述makefile文件的执行结果：
```
gcc -c main.c
gcc -c impl.c
gcc main.o impl.o -o main
./main
hello world！
this is func1
this is func2
this is func3
```
## 5.makefile变量的定义和使用
在makefile中可以定义变量来表示某些多处使用而又可能发生变化的内容，不仅可以节省重复修改的工作，还可以避免遗漏。  
  
变量定义的语法：
> 变量名称=值
```
OBJ=main.o impl.o
main:$(OBJ)
	gcc $(OBJ) -o main
	./main
main.o:main.c main.h
	gcc -c main.c
impl.o:impl.c
	gcc -c impl.c
```
## 6.makefile自动化变量
|   自动化变量        |     说明     |
|     ---------      |     ----     |
| $@ | 	表示规则的目标文件名。如果目标是一个文档文件（Linux 中，一般成 .a 文件为文档文件，也成为静态的库文件），那么它代表这个文档的文件名。在多目标模式规则中，它代表的是触发规则被执行的文件名。| 
| $% | 	当目标文件是一个静态库文件时，代表静态库的一个成员名。| 
| $< | 	规则的第一个依赖的文件名。如果是一个目标文件使用隐含的规则来重建，则它代表由隐含规则加入的第一个依赖文件。| 
| $? | 	所有比目标文件更新的依赖文件列表，空格分隔。如果目标文件时静态库文件，代表的是库文件（.o 文件）。| 
| $^ | 	代表的是所有依赖文件列表，使用空格分隔。如果目标是静态库文件，它所代表的只能是所有的库成员（.o 文件）名。一个文件可重复的出现在目标的依赖中，变量“$^”只记录它的第一次引用的情况。就是说变量“$^”会去掉重复的依赖文件。| 
| $+ | 	类似“$^”，但是它保留了依赖文件中重复出现的文件。主要用在程序链接时库的交叉引用场合。| 
| $* | 	在模式规则和静态模式规则中，代表“茎”。“茎”是目标模式中“%”所代表的部分（当文件名中存在目录时，“茎”也包含目录部分）。| 
  
## 7.makefile隐藏规则
makefile如下：
```
main:main.o impl.o
	gcc main.o impl.o -o main
	./main

执行结果：
cc    -c -o main.o main.c
cc    -c -o impl.o impl.c
gcc main.o impl.o -o main
./main
hello world！
this is func1
this is func2
this is func3
```
在规则缺省的情况下但是执行结果并未发生改变，在其中起作用的就是makefile的隐藏规则，隐藏规则的工作流程是：  
- 隐含规则的具体的工作流程：make 执行过程中找到的隐含规则，提供了此目标的基本依赖关系。确定目标的依赖文件和重建目标需要使用的命令行。隐含规则所提供的依赖文件只是一个基本的对应关系（在C语言中，通常他们之间的对应关系是：test.o 对应的是 test.c 文件）。当需要增加这个文件的依赖文件的时候要在 Makefile 中使用没有命令行的规则给出。  
## 8.makefile伪目标
使用伪目标可以通过make命令明确指定它来执行一些特定的命令，如：
```
clean:
	rm *.o main
```
规则中 rm 命令不是创建文件 clean 的命令，而是执行删除任务，删除当前目录下的所有的 .o 结尾和文件名为 main 的文件。当工作目录下不存在以 clean 命令的文件时，在 shell 中输入 make clean 命令，命令 rm -rf *.o test 总会被执行;但是如果存在clean文件，rm命令将不会被执行，可以将clean设置为一个特殊目标解决这个问题：
```
.PHONY:clean
clean:
	rm *.o main
```
## 9.makefile嵌套
在一个大的工程文件中，不同的文件按照功能被划分到不同的模块中，也就是说很多的源文件被放置在了不同的目录下。每个模块可能都会有自己的编译顺序和规则，如果在一个 Makefile 文件中描述所有模块的编译规则，就会很乱，执行时也会不方便，所以就需要在不同的模块中分别对它们的规则进行描述，也就是每一个模块都编写一个 Makefile 文件，这样不仅方便管理，而且可以迅速发现模块中的问题。这样我们只需要控制其他模块中的 Makefile 就可以实现总体的控制，这就是 make 的嵌套执行。  
  
全局控制makefile文件  
```
CC = gcc
CFLAGS = -g -o -Wall

OBJ := main.o sub.o add.o #声明依赖文件
TOPDIR := $(pwd) #声明顶级目录
OBJDIR := $(TOPDIR)/obj #编译中间文件存放目录
BINDIR := $(TOPDIR)/bin #可执行文件存放目录
BIN := main #可执行文件名称
SUBDIR := sub main add obj #声明所有的子目录
OBJHEAD := $(TOPDIR)/add/add.h $(TOPDIR)/sub/sub.h #声明所有的头文件
OBJLINK := --std=c99
export CC CFLAGS OBJ TOPDIR OBJDIR BINDIR BIN SUBDIR OBJLINK #全局变量给所有子目录的makefile使用

all:CHECKDIR $(SUBDIR)  #执行CHECKDIR $(SUBDIR)
CHECKDIR: #创建目录
	mkdir -p $(SUBDIR) $(BINDIR) 
$(SUBDIR):RUN
	make -C $@
RUN:
	
clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)
```






