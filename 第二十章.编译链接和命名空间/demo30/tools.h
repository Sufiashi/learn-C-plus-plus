#pragma once
#include <iostream>	//包含头文件
#include "girls.h"	//包含头文件girls.h,print函数在里面
using namespace std;	//包含缺省命名空间


extern int aa;//全局变量在头文件中声明，在对应的源文件定义
const int bb = 3;//全局const在头文件中定义
int max(int a, int b);	//比较两个数的大小，返回较大者
int min(int a, int b);//比较两个数的大小，返回较小者

//函数模板和类模板的声明和定义可以分开写，都放在头文件中，具体化版本放在源文件中