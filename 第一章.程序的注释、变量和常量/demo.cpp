// demo01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define MONTHS 12//1年12个月
#define PI  3.1415926 //圆周率



int main()
{
//注释
    //1.单行注释
    std::cout << "Hdddd\n"; //1.单行注释
    /*
    2.多行注释
    */
    ///*
    std::cout<<"这是注释的注释\n";
    //*/

    std::cout << "注释的快捷键是ctrl+k+c\n";
    std::cout << "注释删除的快捷键是ctrl+k+u\n";

//变量
    //整数（int),浮点数（float和double），字符（char），字符串（string）和布尔（bool）
    //超女基本信息：姓名，年龄，体重，性别，颜值
    string name;//姓名
    int age;//年龄
    double weight;//体重
    char sex;//性别：X-女；Y-男
    bool yz;//颜值：true-漂亮；false-丑
    name = "西施";
    age = 25;
    weight = 48.6;
    sex = 'X';
    yz = true;

    cout << "姓名：" << name << ",年龄：" << age << ",体重：" << weight << ",性别：" << sex << ",颜值：" << yz << endl;


//常量
    //宏常量：#define MONTHS 12
    //命名一般用大写
    cout << "月数：" << MONTHS << ",圆周率：" << PI << endl;
    //const修饰的变量
    const int days = 7;//一个星期有七天
    cout << "一个星期有" << days << "天" << endl;
    //不允许改常量的值
    //days = 9;



//标识符命名
    //名称中只能用字母字符数字和下划线
    //int a1_~;
    //第一个字符不能是数字
    //int 11a;
    //名称区分大写小写
    //不能用c++关键字做名称


//输入数据
    //控制台输入:
    cout << "输入超女的名字:";
    cin >> name;
    cout << "已输入超女的姓名：" << name << endl;

}


