// demo42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <chrono>   //时间
using namespace std;

void print() {
    cout << "终止" << endl;
}
template <typename T,typename ...Args> 
void print(T arg, Args... args) {
    cout << "参数：" << arg << endl;
    print(args...);
}

int main(void)
{
    //1.long long
    //2.原始字面量
    //3.初始化列表
    //4.auto
    //5.decltype
    //6.模板的别名
    //7.nullptr
    //8.智能指针
    

    //lambda函数
    //参数列表：不支持默认参数可变参数
    //返回类型：如果不屑，会自动推断
    //函数体
    //捕获列表:=和&自动判断要捕获的变量，&是引用捕获，=是值捕获
    int ii = 0;
    double dd = 1.0;
    auto f = [ii,dd](const int& no)->double {//捕获ii，dd
        cout << "ii=" << ii << endl;
        cout << "亲爱的" << no << "号：我是一只啥啥鸟" << endl;
        return 1.0;
        };
    f(8);


    //右值引用
    //右值：表达式结束后不存在。非引用返回值，表达式结果，字面常量。不能取地址
    int&& a = 12;
    //常量左值引用

    //移动语义：移动构造函数，传右值时
    //move，将左值转换为右值+
    //完美转发：forward<>
    

    //可变参数
    print("sdfsf", "SDf",12,34,54,6);
    return 0;

    //时间操作
    //duration：表示时间长度
    //hours,minutes,
    chrono::hours t1(1);
    chrono::minutes t2(60);

    if (t1 == t2)cout << "t1==t2";

    cout << "t1=" << t1.count() << endl;




}

