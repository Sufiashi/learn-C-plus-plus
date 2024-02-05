// demo19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class CGirl  //自定义字符串
{
public:
    int m_bh;   //编号
    string m_name;  //姓名
    double m_weight;    //体重

    //默认构造函数
    CGirl() { m_bh = 0; m_name.clear(); m_weight = 0; }
    //自我介绍方法
    void show() { cout << "bh=" << m_bh << ",name=" << m_name << ",weight=" << m_weight; }
    CGirl(int bh) {
        m_bh = bh; m_name.clear();  m_weight = 0;
        cout << "调用了一个参数的构造函数\n";
    }

    operator int(){return m_bh;}
    operator string() { return m_name; }
    operator double() { return m_weight; }
};


int main()
{
    CGirl g1(8);    //常规写法
    CGirl g2 = CGirl(8);//显示转化
    CGirl g3 = 8;    //隐士转化
    CGirl g4;   //创建对象
    g4= 8; //用CGirl(8)创建零食对象，再赋值给g
    g1.show();

    int a = g1;    cout << "a的值是：" << a << endl;
    string b = g1;    cout << "b的值是：" << b << endl;
    double c= (double)g1;    cout << "c的值是：" << c << endl;
}

