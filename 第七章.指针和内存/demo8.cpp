// demo8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//调用函数的时候，调用者把数值付给了函数的参数
//实参：调用者程序中书写的在函数名括号中的参数
//形参：函数的参数列表

void func(int* no, string* str) {
    //向超女表白函数
    cout << "亲爱的" << *no << "号：" << *str << endl;
    *no = 8;
    *str = "我有一只小小鸟。\n";

}



void func1(int a, int b, int c, int* max, int* min) {
    *max = a > b ? a : b;
    *min = a < b ? a : b;
    *max = *max > c ? *max : c;
    *min = *min < c ? *min : c;
}

void func2(string varname, void* p) {
    cout << varname << "的地址是：" << p << endl;
    cout << varname << "的值是：" << *(char*)p << endl;
}


int main()
{
    int t;
    cin >> t;
    if (t == 0) {
        //指针变量
        int no = 38;
        int* ptr = &no;

        int bh = 3;//超女的编号
        string message = "我是一只傻傻鸟。";//向超女表白内容

        func(&bh, &message);//调用向超女表白函数

        //从3名超女的身高数据中，选出最高和最爱的
        int a = 180, b = 170, c = 175, m, n;
        func1(a, b, c, &m, &n);
        cout << "m=" << m << " n=" << n << endl;
    }
    else if (t == 1) {
        //const修饰指针
        //1)常量指针 const 数据类型 *变量名   不能修改地址中的值
        //2)指针常量 数据类型 *const 变量名   指向的变量不可改变
        //3）常指针数量
        int a = 3, b = 8;
        const int* p = &a;
        a = 13;//不能用*p来修改，但能用a来修改
        cout << "a=" << a << ",*p=" << *p << endl;
        p = &b;
        cout << "b=" << b << ",*p=" << *p << endl;

        int* const q = &a;
        *q = 13;//可以用*q来修改值
        cout << "a=" << a << ",p=" << *p << endl;
    }
    else if (t == 2) {
        //void关键字
        int a = 89;
        char b = 'X';

        cout << "a的地址是：" << &a << endl;
        cout << "b的地址是：" << &b << endl;

        func2("a", &a);
        func2("b", &b);
    }

}

