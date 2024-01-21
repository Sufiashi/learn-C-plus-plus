// demo11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#pragma pack(8)

//超女基本信息结构体st_girl,存放了超女全部的数据项
struct st_girl
{
    char name[21];  //姓名
    int age;        //年龄
    double weight;  //体重（kg）
    char sex;       //性别：X-女；Y-男
    bool yz;        //颜值：true-漂亮；faklse-不漂亮
};

struct st_message   //QQ报文/消息结构体
{
    int srcqq;  //发送方QQ号码
    int dstqq;  //接收方QQ号码
    char ccontex[1024]; //消息内容
};

struct st_t
{
    int a;
    int* p;
};

void func(const st_girl* pst)
{
    cout << "姓名：" << pst->name << "，年龄：" << pst->age << "，体重：" << pst->weight
        << ",性别：" << pst->sex << ",颜值：" << pst->yz << endl;
}

int main()
{
    int t;
    cin >> t;
    if (t == 0) 
    {   //创建结构体
        st_girl stgirl{ "西施",26,33.8,'X',true };    //创建结构体

        cout << "sizeof(st_girl)=" << sizeof(st_girl) << endl;

        memset(&stgirl, 0, sizeof(stgirl));

        cout << "姓名：" << stgirl.name << ",年龄：" << stgirl.age << ",体重：" << stgirl.weight
            << ",性别：" << stgirl.sex << ",颜值：" << stgirl.yz << endl;
    }
    else if (t == 1)
    {   //结构体指针
        st_girl* stgirl = new st_girl{ "西施",26,33.8,'X',true };
        cout << "姓名：" << stgirl->name << ",年龄：" << stgirl->age << ",体重：" << stgirl->weight
            << ",性别：" << stgirl->sex << ",颜值：" << stgirl->yz << endl;
        func(stgirl);
    }
    else if (t == 2)
    {
        st_girl  stgirl= { "西施",26,33.8,'X',true };     //创键结构体变量
        st_girl girls[3];
        memset(girls, 0, sizeof(girls));        //清空整个数组
        strcpy((girls + 0)->name, "西施"); (girls + 0)->age = 25; girls[0].weight = 45; girls[0].sex = 'X'; girls[0].yz = true;
        girls[1] = { "西瓜",2,10.6,'Y',false };
        *(girls + 2) = { "冰冰",23,50.3,'X',true };

        for (int i = 0; i < 3; i++)
        {
            cout << "姓名：" << (girls + i)->name << ",年龄：" << (girls + i)->age << ",体重：" << girls[i].weight
                << ",性别：" << girls[i].sex << ",颜值：" << girls[i].yz << endl;
        }
    }
    else if (t == 3)
    {   //memset函数
        st_message message;     //创建QQ报文/消息结构体变量
        /*
        memset函数
        
        
        */
        while (true)
        {
           // memset(&message,0, sizeof(message));//清空QQ报文/消息结构体
            //接受QQ报文
            //处理QQ报文
            //把QQ报文/消息发送给接收方

        }
    }
    else if (t == 4)
    {
        st_t stt;       //创建结构体变量
        memset(&stt, 0, sizeof(stt));

        stt.a = 3;
        stt.p = new int[100];   //动态创建一个长度为100的整形数组，让指针指向它

        cout << "sizeof(stt)=" << sizeof(stt) << endl;

        cout << "调用前：stt.a=" << stt.a << ",stt.p=" << stt.p << endl;
        
        memset(&stt, 0, sizeof(stt));//分配地址后不能用memset来清空，得分开来清理
        //stt.a = 0;      //清空成员a
        //memset(stt.p, 0, 100 * sizeof(int));    //清空成员p
        cout << "调用后：stt.a=" << stt.a << ",stt.p=" << stt.p << endl;

        delete[] stt.p; //释放
    }
}
