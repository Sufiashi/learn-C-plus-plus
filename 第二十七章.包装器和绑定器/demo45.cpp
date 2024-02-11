// demo45.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>

using namespace std;

using Fun = void(int, const string&);//函数类型的别名
Fun show;


struct AA//静态成员
{
    static void show(int bh, const string& message) {
        cout << "这是静态成员" << endl;
    }
};

struct BB//普通成员函数
{
    void show(int bh, const string& message) {
        cout << "这是普通成员" << endl;
    }
};
struct CC//仿函数
{
    void operator()(int bh, const string& str) {
        cout << "这是仿函数" << endl;
    }
};

struct DD //普通函数指针
{
    using Fun = void(*)(int, const string&);    //函数指针的别名
    operator Fun() {
        return show;//返回普通函数show的指针
    }
};


int main()
{
    using Fun = void(*)(int, const string&);//函数类型别名
    //普通函数
    void(*fp1)(int, const string & wtr) = show;//函数指针
    fp1(1, "1");
    function<void(int, const string& str)>fn1 = show;   //包装器   function<Fun>=show
    fn1(1, "1");


    //类的静态成员
    void(*fp2)(int, const string & wtr) = AA::show;
    fp2(1, "1");
    function<void(int, const string& str)>fn2 =AA::show;   //包装器   function<Fun>=show
    fn2(1, "1");


    //仿函数
    CC cc;
    cc(1, "1");
    function<void(int, const string& str)>fn3 = cc;   //包装器   function<Fun>=show
    fn3(1, "1");


    //lambda对象
    auto lb = [](int bh, const string& str) {
        cout << "这是lambda对象" << endl;
        };
    lb(1, "1");
    function<void(int, const string& str)>fn4 = lb;   //包装器   function<Fun>=show
    fn4(1, "1");

    //非静态成员
    BB bb;
    void(BB::*fp3)(int, const string & wtr) = &BB::show;
    (bb.*fp3)(1, "1");
    function<void(BB&,int, const string& str)>fn5 = &BB::show;   //包装器   function<Fun>=show
    fn5(bb,1, "1");


    //可以被转换为函数指针的类对象
    DD dd;
    dd(1, "1");
}

void show(int i, const string& str) {
    cout << "这是函数" << endl;
}
