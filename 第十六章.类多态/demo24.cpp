// demo24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class AA {//基类
public:
	AA() { cout << "调用了基类的构造函数AA()。\n"; }
	virtual void func() { cout << "调用了基类的func()。\n"; }
	virtual ~AA() { cout << "调用了基类的析构函数~AA().\n"; }
};

class BB :public AA {	//派生类
public:
	BB() { cout << "调用了派生类的构造函数BB()。\n"; }
	void func() { cout << "调用了派生类的func().\n"; }
	~BB() { cout << "调用了派生类的析构函数~BB().\n"; }


};
int main()
{
	BB* b = new BB;
	b->~BB();//每次调用派生类的析构函数时，都会调用基类的析构函数
	delete b;

	AA* a = new BB;
	delete a;
}

