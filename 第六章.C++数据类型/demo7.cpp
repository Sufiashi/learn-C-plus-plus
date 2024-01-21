// demo7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//C++数据类型

#include <iostream>
using namespace std;



int main()
{
    //sizeof运算符
    //sizeof(数据类型),sizeof(变量名)
    cout << "sizeof(int)=" << sizeof(int) << endl;
    cout << "sizeof(float)=" << sizeof(float) << endl;
    cout << "sizeof(double)" << sizeof(double) << endl;
    cout << "sizeof(char)=" << sizeof(char) << endl;
    cout << "sizeof(bool)=" << sizeof(bool) << endl;

    //
    int a; cout << "sizeof(int)=" << sizeof(a) << endl;
    float b; cout << "sizeof(float)=" << sizeof(b) << endl;
    double c; cout << "sizeof(double)" << sizeof(c) << endl;
    char d; cout << "sizeof(char)=" << sizeof(d) << endl;
    bool e; cout << "sizeof(bool)=" << sizeof(e) << endl;

    //整数的书写
    //1.二进制
    int aaa = 0b101;
    //2.八进制
    int bbb = 015;
    //3.十六进制
    int ccc = 0xffff;

    //浮点型
    float aa = 1234.45f; cout << "aa=" << aa << endl;
    double bb = 123456789.45; cout << "bb=" << bb << endl;
    printf("aa=%lf\n", aa);
    printf("bb=%lf\n", bb);

    //字符型
    //ASCII字符
    char dd = 33;
    cout << dd << endl;

    //转义字符
    cout << "1\t西施\n";
    cout << "100\t西瓜\n";
    cout << "10000\t冰冰\n";
    string path1 = "C:\\Program Files\\Microsoft OneDrive\\tail\\nation";
    cout << "path1 is " << path1 << endl;
    path1 = R"abcd(C:\Program Files\Microsoft OneDrive\tail\nation)abcd";//原始字面量
    cout << "path1 is " << path1 << endl;

    //字符串型
    //bool型
    
    //数据类型转换
    //1）自动转换    运算时
    /*
    char a=30;
    int b=102400;
    long long c=15000000000001;

    cout<<"a+b+v="<<a+b+c<<endl;
    */
    //2）强制转化
    //cout<<"8/5="<<（（double）8)/5<<endl;


    //数据类型的别名
    typedef short int16_t;  //16位的整数
    typedef int   int32_t;   //32位的整数
}


