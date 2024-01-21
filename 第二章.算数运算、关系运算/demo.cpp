// demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    //算数运算
    int a = 8;
    int b = 4;
    double c = 8.9;
    double d = 0;
    cout << a + b << " " << a - b << " " << a * b << " " << a / b;
    cout << c / d << endl;

    //自增和自减
    int i = 0;
    i++;
    ++i;
    i--;
    --i;

    //赋值运算
    c += a;
    c -= a;
    a = b = 3;



    //c++初始化赋值
    int e(10);
    cout << "e="<<e << endl;
    int f{ 10 };
    cout << "f="<<f << endl;



    //关系运算
    bool result;
    result = a == b;
    cout << "result=" << result << endl;
    result = a < b;
    cout << "result=" << result << endl;
    result = a > b;
    cout << "result=" << result << endl;
    cout << "result=" << (a == b) << endl;//必须加小括号


    //逻辑运算
    bool g = true;
    bool h = true;
    bool l;
    l = g && h;
    cout << "l=" << l << endl;
    cout << (g || h) << endl;


    //逗号运算
    int a1, a2;
    a1 = 10, a2 = 2;




    //运算的优先级
}


