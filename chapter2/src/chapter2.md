# 信息的表示和处理

## Makefile

target: prerequisites

command

$@ 目标文件的名称  
@< 依赖项中的第一个依赖文件的名称

在64位机器上编译32位程序，需要安装兼容库
`sudo apt-get install libc6-dev-i386`

## 大小端

小端： 最低有效字节在最低地址
大端： 最低有效字节在最高地址