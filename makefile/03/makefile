CC = gcc
CFLAGS = -g -o -Wall
#声明依赖文件
OBJ := main.o sub.o add.o
#声明顶级目录
TOPDIR := $(pwd)
#编译中间文件存放目录
OBJDIR := $(TOPDIR)/obj
#可执行文件存放目录
BINDIR := $(TOPDIR)/bin
#可执行文件名称
BIN := main
#声明所有的子目录
SUBDIR := sub main add obj
#声明所有的头文件
OBJHEAD := $(TOPDIR)/add/add.h $(TOPDIR)/sub/sub.h
OBJLINK := --std=c99
#全局变量给所有子目录的makefile使用
export CC CFLAGS OBJ TOPDIR OBJDIR BINDIR BIN SUBDIR OBJLINK
#执行CHECKDIR $(SUBDIR)
all:CHECKDIR $(SUBDIR)
#创建目录
CHECKDIR:
	mkdir -p $(SUBDIR) $(BINDIR)
$(SUBDIR):RUN
	make -C $@
RUN:
	
clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)