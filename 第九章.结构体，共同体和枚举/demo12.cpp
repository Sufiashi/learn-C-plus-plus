#include <iostream>
using namespace std;


struct st_girl  //超女单链表
{
    int     no; //超女编号
    string name;//超女姓名
    struct st_girl* next;   //下一个超女节点的地址，如果本届点是最后一条记录，填nullptr
};

union udata
{
    int a;
    double b;
    char c[25];
};

int main()
{
    int t;
    cin >> t;
    if (t == 0)
    {
        st_girl* head = nullptr, * tail = nullptr, * tmp = nullptr; //head指针，tail指针，tmp指针

        tmp = new st_girl({ 1,"西施",nullptr });  //分配第一个节点
        head = tail = tmp;

        tmp = new st_girl({ 6,"冰冰",nullptr });  //分配第二个节点
        tail->next = tmp;                         //把上一个节点的next指针指向新节点
        tail = tmp;                               //移动尾指针，让尾指针指向刚分配出来的新节点

        tmp = new st_girl({ 3,"秘密",nullptr });  //分配第三个节点
        tail->next = tmp;                         //把上一个节点的next指针指向新节点
        tail = tmp;                               //移动尾指针，让尾指针指向刚分配出来的新节点

        //遍历链表
        tmp = head; //从头开始
        while (tmp != nullptr)
        {
            cout << "no=" << tmp->no << "name=" << tmp->name << "tmp->next" << tmp->next << endl;
            tmp = tmp->next;
        }

        //释放链表
        while (head != nullptr)
        {
            tmp = head; //让零食节点指向头节点
            head = head->next;  //头节点后裔
            delete tmp;     //删除零食节点
        }
    }
    else if (t == 1)
    {   //共同体
        udata data;   //定义共同体变量

        cout << "sizeof(data)=" << sizeof(udata) << endl;

        cout << "data.a的地址是：" << (void*)&data.a << endl;
        cout << "data.a的地址是：" << (void*)&data.b << endl;
        cout << "data.a的地址是：" << (void*)&data.c << endl;

        data.a = 3;
        data.b = 8.8;
        strcpy(data.c, "我是一致啥啥鸟。");
        cout << "data.a的地址是：" << (void*)&data.a << endl;
        cout << "data.a的地址是：" << (void*)&data.b << endl;
        cout << "data.a的地址是：" << (void*)&data.c << endl;
    }
    else if (t == 2)
    {   //枚举
        enum colors{red=0,yellow=1,blue=2,other=3}; //创建枚举类型colors

        colors cc = yellow;     //创建枚举变量，并符初值
        cout << "red=" << red << ",yellow=" << yellow << ",blue=" << blue << ",other=" << other << endl;
        switch (cc)
        {
        case red:   cout << "红色。\n"; break;
        case yellow:   cout << "黄色。\n"; break;
        case blue:   cout << "蓝色。\n"; break;
        default: cout << "未知.\n";
        }

    }
}

