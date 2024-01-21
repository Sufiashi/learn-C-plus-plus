// demo6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "tools.h"			//包含头文件tools.h,min和max函数在里
#include "girls.h"			//包含头文件girls.h,print函数在里面
using namespace std;

//函数的声明和定义
  /*
  返回值类型 函数名（参数1数据类型 参数1，参数2数据类型 参数2，。。。）{
	   功能
	   return 返回值;|
  }
  声明：
	   1.后有分号
	   2.写在定义前面
	   3.声明与定义要一致

  */


//写一个函数，在控制台输出九九乘法表
void printmt();
//写一个向超女表白的函数
void func(int no, string str);

//1）全局变量
int a;//默认初始化为0


//递归函数
int f(int x)								//递归函数
{
	if (x == 0)return 0;					//递归终止条件
	return x + f(x - 1);					//调用之际
}

int main()
{
	//函数调用
	printmt();
	cout << "max(5,8)=" << max(5, 8) << endl;//5和8是函数的实参
	print(8, "请借给我五分钱吧。");//F9设置断点，F10逐过程，F11逐句

	//变量的作用域
	//1）全局变量
	//2）局部变量
	int b;//初始化未知
	//3）静态局部变量
	static int c;//只会被初始化一次，默认自动初始化为0
	//4）注意

	//形参和实参
	func(1, "");

	//头文件

	return 0;
}
int max(int a, int b)//函数定义后面不能加分号。a和b是函数的形参
{
	if (a > b)return a;
	return b;
}

void print(int no,string str)
{
	cout <<"亲爱的"<<no<<"号"<<str << endl;
}
void printmt()
{
	//输出99乘法表
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << "*" << j << "=" << i * j<<" ";
		}
		cout << endl;
	}
}

void func(int no, string str)
{
	//向超女表白的函数
	no = 5; str = "我有一只小小鸟.";
	cout << "亲爱的" << no << "号;" << str << endl;
}