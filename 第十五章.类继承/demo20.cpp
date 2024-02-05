
#include <iostream>
using namespace std;

class CALLComers    //海选报名者类
{
public:
    string m_name;//姓名
    string m_tel;   //电话

protected:
    int m_a;
private:
    int m_b;

public:
    //构造函数
    CALLComers() { m_name = "某女"; m_tel = "不详"; }
    //报名时需要唱一首歌
    void sing() { cout << "我是一只次奥次奥鸟。\n"; }
    //设置姓名
    void setname(const string& name) { m_name = name; }
    //设置电话号码
    void setel(const string& tel) { m_tel = tel; }
    //访问m_b
    void func() { m_b = 11; cout << "m_b=" << m_b << endl; }
};

class CGirl :private CALLComers      //超女类           继承
{
public:
    int m_bh;   //编号

    //修改访问权限
public:
    using CALLComers::m_a;  //把m_a的权限设为共有
private:
    using CALLComers::m_a;  //设为私有



    CGirl() { m_bh = 8; }
    void show() { 
        setname("西施");
        setel("12321321323");
        cout << "编号：" << m_bh << ",姓名：" << m_name << ",联系电话：" << m_tel << endl; }
};


int main()
{
    CGirl g;
    //g.setname("西施");
    //g.setel("13412341256");
    g.show();
}


