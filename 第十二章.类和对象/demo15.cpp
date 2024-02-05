// demo15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class CGirl	//超女类CGIRL
{
	friend int main();//友元函数
public:
	string name;	//姓名
	enum { girl = 1, boy = 2 };
	int sex;
	int age;	//年龄
	const int dd;//常量必须在构时初始化
	char memo[301];	//备注
	int times = 0;	//递归次数
	int* ptr;	//指针成员，计划使用堆内存
	static int tt;
	CGirl():dd(1)//初始化列表											//构造函数
	{
		name.clear(); age = 0; 
		memset(memo, 0, sizeof(memo));
		cout << "调用了构造函数。\n";
	}
	CGirl(string name1):dd(1)
	{
		name=name1; age = 0; memset(memo, 0, sizeof(memo));
		cout << "调用了构造函数。\n";
	}
	CGirl(string name1,int age1):dd(1)
	{
		//CGirl();//表示创建一个类对象，有指针时会很麻烦
		name = name1; age = age1; memset(memo, 0, sizeof(memo));
		ptr = new int(3);
		cout << "调用了构造函数。\n";
	}

	~CGirl()	//析构函数
	{
		delete ptr; ptr = nullptr; 
		cout << "调用了析构函数。\n";
	}

	CGirl(const CGirl& gg):dd(1) {//调用函数传递值时会调用拷贝函数，返回值时，在linux不调用，在win中会调用
		name = "漂亮的" + gg.name; age = gg.age - 1;// ptr = gg.ptr; //指针浅拷贝
		//深拷贝
		ptr = new int;	//分配内存
		//*ptr = *gg.ptr;	//拷贝数据
		memcpy(ptr, gg.ptr, sizeof(int));
		cout << "调用了拷贝构造函数。\n";
		cout << "&gg.name:" << &gg.name << endl;
		cout << "name:" << &name << endl;
	}

public:



	void setvalue(string name1, int age1);	//设置成员变量
	void show()	const;//显示超女自我介绍	const修饰表示函数不会修改成员变量
						//const函数可调用const函数，不能调用非const函数
	const CGirl& pk(const CGirl& gg1)
	{
		if (gg1.dd <dd)return gg1;
		return *this;
	}
	static void showtt() {		//静态函数只能访问静态变量
		cout << "静态成员tt：" << CGirl::tt << endl;		//访问静态成员
	}
	
};

int CGirl::tt = 8;		//初始化静态成员变量

int main()
{

	CGirl girl("西施",1);	//创建超女对象，没有参数时不要加()
	CGirl girl1 = CGirl("汤姆森", 12);
	CGirl* girl2 = new CGirl;
	const CGirl g3(girl);	//const对象不能调用非const函数
	//const CGirl& g4 = girl.pk( girl1);
	//g4.show();
	girl.ptr = new int(3);
	CGirl g1(girl);//拷贝构造函数
	delete girl2;
	//girl.setvalue("西施", 26);
	girl.show();
	girl.sex = girl.boy;
	  g1.show();

}

void CGirl::setvalue(string name1, int age1)
{
	name = name1; age = age1;
}

void CGirl::show() const
{
	cout << "我是" << name << ",今年" << age << "岁了。" << "ptr=" << ptr <<",*ptr="<<*ptr<<endl;

}
