#include <iostream>
using namespace std;



void func1(int no, string str)	//传值
{
	no = 8;
	str = "我有一只小小鸟。";
	cout << "亲爱的" << no << "号：" << str << endl;
}
void func2(int* no, string* str)	//传地址
{
	*no = 8;
	*str = "我有一只小小鸟。";
	cout << "亲爱的" << *no << "号：" << *str << endl;
}
void func3(int& no,string& str)	//传引用
{

	cout << "亲爱的" << no << "号：" << str << endl;
}
void func4(const int no,const string str)	//传值
{
	cout << "亲爱的" << no << "号：" << str << endl;
}
void func5(const int* no,const string* str)	//传地址
{
	cout << "亲爱的" << *no << "号：" << *str << endl;
}
void func6(const int& no,const string& str)	//传引用
{
	cout << "亲爱的" << no << "号：" << str << endl;
}
int func7()//返回值
{
	int i = 3;
	return i;
}
int &func8()//返回引用
{
	static int i = 3;
	return i;//返回野指针
}
int main()
{
	int t;
	cin >> t;
	if(t==0)
	{	//引用=指针常量，就是指向一个不变的地址
		//声明/创建引用的语法：数据类型 & 引用名 =原变量名
		int a = 3;		 //声明普通的整形变量
		int& ra = a;	//创建引用ra，ra是a的别名
		cout << "a的地址是：" << &a << ",a的值是：" << a << endl;
		cout << "ra的地址是：" << &ra << ",ra的值是：" << ra << endl;

		int b = 4;
		ra = b;//只是赋值，不是引用
		cout << "a的地址是：" << &a << ",a的值是：" << a << endl;
		cout << "ra的地址是：" << &ra << ",ra的值是：" << ra << endl;
		cout << "b的地址是：" << &b << ",ra的值是：" << b << endl;
		/*
		1.引用类型要相同
		2.引用和原本一样
		3.引用在声明时初始化
		4.&取地址，也可表示引用
		*/
	}
	else if (t == 1)
	{	//用于函数的参数
		int bh = 3;	//超女编号
		string message = "我是一只傻傻鸟.";	//向超女表白的内容
		func1(bh, message);	//传值
		func2(&bh, &message);	//传地址
		func3(bh, message);	//传引用

		cout << "亲爱的" << bh << "号：" << message << endl;
	}
	else if (t == 2)
	{	//引用的形参和const
		int bh = 3;	//超女编号
		string message = "我是一只傻傻鸟.";	//向超女表白的内容
		func4(bh, message);	//传值
		func5(&bh, &message);	//传地址
		func6(bh, message);	//传引用
		func4(1, "是哦放大");


		//引用是const，会建立临时变量
		const int& ra = 8;
		//int tmp = 8;
		//const int& ra = tmp;
		/*
		1.const可以避免修改数据
		2.const'函数处理const和非const实参，否则只能接受非const
		3.使用const，函数能正确生成并使用临时变量
		*/
	}
	else if (t == 3)
	{	//引用用于函数返回值
		int a = func7(); cout << "a=" << a << endl;//返回的是值
		int& b = func8();	cout << "b=" << b << endl;//返回的是引用
	}
	/*
	1.不用在函数中修改实参
		实参很小，按值传递
		实参是数组，用const指针，不能建立引用
		实参较大，用const指针或const引用
		实参是类，用const引用
	2.修改
		实参是内置数据类型，用指针。只要看到func(&x)的调用，表示函数将修改x
		实参是数组，则用指针
		实参是结构体，用指针或引用
		实参是类，用引用
	*/
}

