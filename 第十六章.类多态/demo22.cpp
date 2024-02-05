// demo22.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//基类指针可表现多重形式，称为多态，引用同理
//只用在虚函数声明式加上virtual，定义时不用
//基类中的函数和派生类中的函数要特征相同，特征相同指的是名字和参数列表
//基类指针用的是派生类的函数，要用基类的函数，则要加类名和与解析附

class CALLComers {   //报名者类

public:
    int m_bh = 0;   //编码
    virtual void show() { cout << "CALLComers::show():我是" << m_bh << "号" << endl; }
};

class CGirl: public CALLComers{//超女类
public:
    int m_age = 0;//年龄
    void show() { cout << "CGirl():我是" << m_bh << "号，" << m_age << "岁。" << endl; }
};

int main()
{
    CGirl g;
    g.m_bh = 8;
    g.m_age = 23;
    g.show();
    CALLComers* pa = &g;
    pa->show();

    CALLComers a; a.m_bh = 3;
    CGirl g1; g1.m_bh = 8; g1.m_age = 23;

    CALLComers* p;  //声明基类指针
    p = &a; p->show();//让基类指针指向基类对象
    p = &g1; p->show();  //让基类指针指向派生对象
}

