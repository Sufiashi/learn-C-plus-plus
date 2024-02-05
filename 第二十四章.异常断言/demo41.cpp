
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
/*
    try
    {
        //可能抛出异常的代码
        int i = 0;
        cout << "你是一只什么鸟？";
        cin >> i;

        if (i == 1)throw "不好，有人说我是一傻傻鸟";//抛出异常，给catch捕获
        cout << "我不是一只啥啥鸟\n";
    }
    catch(string str)//不管什么异常都在这处理
    {
        cout << "捕获到异常，具体美观\n";
    }
*/
    //断言：避免异常
    const int ii = 1;
    static_assert(ii, "ii的值不合法");//只对常量断言，只在编译时检查

}
