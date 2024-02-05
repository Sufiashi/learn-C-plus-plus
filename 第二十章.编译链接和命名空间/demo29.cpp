// demo29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编译


//<>和""
//<>用于自带，""用于自定义

#include <stdio.h>
#include <iostream>
#include "public.h"
using namespace std;

//宏定义
#define BH 3
#define MESSAGE "我是一只傻傻鸟."
//常用宏

int main()
{
    //常用宏
    cout << "当前源代码文件名：_FILE_=" << __FILE__ << endl;
    cout << "当前源代码函数名：_FUNCTION_=" << __FUNCTION__ << endl;
    cout << "当前源代码行号：_LINE_=" << __LINE__ << endl;
    cout << "当前编译日期1：_DATE_=" << __DATE__ << endl;
    cout << "当前编译时间：_TIME_=" << __TIME__ << endl;
    cout << "当前系统时间戳：_TIMESRAMP_=" << __TIMESTAMP__ << endl;
    cout << "当前C++编译程序时，标识符_cplusplus就会被定义：_cplusplus=" << __cplusplus << endl;
#ifdef _WIN32
    cout << "这是windows系统\n";
    typedef long long int64;
#else 
    cout << "这不是windows系统\n";
    typedef long int 64;
#endif
}
