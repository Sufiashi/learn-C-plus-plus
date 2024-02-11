#### 命令

关机：init 0

重启：init 6

查看当前目录：pwd

切换目录：cd	

显示当前目录文件：ls＋路径

清屏：clear

查看设置时间：date

#### 目录和文件

#### 相对路径和绝对路径

#### vi

ctrl+insert 复制

shift+insert 粘贴

ctrl+g 显示行号

n+G 跳到第n行行首

yy复制一行

nyy复制n行

p复制

#### 用户管理

组管理

groupadd

groupdel

用户管理

useradd -n 用户名 -g 组名 -d 主目录

切换用户

su - 用户名



#### 目录和文件操作

ls :

​	-l	

​	-lt

mkdir 创建目录

touch 创建文件

ls -l > t.txt 	输出创建文件

rm -rf 目录和文件列表

​	-r删除目录

​	-f强制删除

cp 旧 新

​	-r目录

mv 旧 新

#### 文件目录权限

chown 改变权限

chown -R mysql:dba /aa

r读w写x执行

设置权限：7=4+2+1

​					5=4+1

​					4=4

6 rw-

3 -wx

1 --x

0 ---

chmod -R

u用户o主人g主人所在组 + - =



#### 文件内容操作

cat 看少的文件

less ：ctrl+d下一页

more：空格下一页 b上一页

wc:统计文件行数

grep：查找文件的内容 grep＋字符串+文件

head：显示文件头部内容 -n行数 文件名

tail：显示文件后部内容 -n行数 文件名 -f跟踪查看

#### 管道

输出|输入

#### 链接

软链接：ln -s 文件名 链接名	

硬连接：:ln 文件名 连接名

#### 软件包安装

yum -y -intall  ...

#### 打包和压缩

zip -r

unzip

#### 进程

查看进程 ps

终止进程 kill

#### 性能分西

top

#### 命令

scp -r 文件名	地址		跨系统陈传文件

df

du 统计目录大侠		-m M单位   -h G为单位

#### 静态ip

桥接模式	与主机平等

nat模式	虚拟出一个网卡

#### 网络故障诊断

ping

telnet+ip+端口号

#### 系统服务

systemctl 操作 服务名

#### 防火墙

端口

服务

#### 环境变量

env查环境变量



LANG 字符集utf-8

SHELL 

PATH 

LD_LIBRARY_PATH

CLASSPATH



变量名=值

export 变量名

系统环境变量	/etc/profile.d/

用户环境变量	.bash_profile
