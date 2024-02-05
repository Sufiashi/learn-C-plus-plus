// demo21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


class A {   //j基类
public:
    int m_a;
private:
    int m_b;
public:
    A() :m_a(0), m_b(0)   //基类的默认构造函数
    {
        cout << "调用了基类的默认构造函数A().\n";
    }
    A(int a, int b) :m_a(a), m_b(b) //基类有两个参数的构造函数
    {
        cout << "调用了基类的构造函数A(int a,int b.\n";
    }
    A(const A& a) :m_a(a.m_a + 1), m_b(a.m_b + 1) //基类的拷贝构造函数
    {
        cout << "调用了基类的拷贝构造函数.\n";
    }
    
    //显示基类A的所有成员
    void showA() { cout << "m_a=" << m_a << ",m_b" << m_b << endl; }
};

class B :public A//派生类
{
public:
    int m_c;
    B() :m_c(0),A()  //派生类的默认构造寒素
    {
        cout << "调用了派生类的构造函数B().\n";
    }
    B(int a,int b,int c) :m_c(c), A(a,b)  //派生类的默认构造寒素
    {
        cout << "调用了派生类的构造函数B(int a,int b,int c).\n";
    }
    B(const A& a, int c) :A(a), m_c(c)
    {
        cout << "调用了派生类的构造函数B(const A* a, int c).\n";
    }

    //显示B的全部成员
    void showB(){ cout << "m_c=" << m_c << endl << endl; }
};

int main()
{
    B b1;   //将调用基类的默认构造函数
    b1.showA(); b1.showB();  //

    B b2(1, 2, 3);
    b2.showA(); b2.showB();

    A a(10, 23);
    B b3(a, 30);
    b3.showA(); b3.showB(); 
}

