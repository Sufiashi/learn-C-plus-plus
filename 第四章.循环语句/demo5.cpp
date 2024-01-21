// demo5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    if (t == 0)
    {
        //有十个超女，编号1-10，在控制台输出者这10个超女的编号
        int no = 1;//超女编号
        while (true) {//循环结构
            cout << "这是第" << no++ << "名超女\n";
        }
    }
    else if (t == 1)
    {
        bool once = false;
        while (true) {

            if (once) {
                //a)显示是否继续下一名超女选秀（1-继续，0-结束）：的提示文字
                cout << "是否继续下一名超女选修（1-继续，0-结束）：";
                //b)输入是否继续的决定，存放在变量中
                bool exist; cin >> exist;
                //c)判断输入的决定，如果结束，流程跳出循环
                if (exist == false)break;
            }
            once = true;
            //1)显示输入超女的颜值(1-漂亮,0-不漂亮）：“的提示文字
            cout << "输入超女的颜值(1-漂亮,0-不漂亮）：";
            //2）输入超女的颜值，存放在变量中
            bool yz; cin >> yz;
            //3）判断超女的颜值，如果漂亮，显示”晋级成功“，流程跳转到循环的首部
            if (yz == true)
            {
                cout << "晋级成功\n"; continue;
            }
            //4）显示”请输入超女的身材（1-火辣，0-不辣）：“的提示文字
            cout << "请输入超女的身材（1-火辣，0-不辣）：";
            //5）输入超女的身材，存放在变量中
            bool sc; cin >> sc;
            //6）判断超女的身材，如果火辣，显示”晋级成功“
            if (sc == true)
            {
                cout << "晋级成功\n";
            }
        }
    }
    else if (t == 2) {//for循环
        for (int no = 1; no <= 10; no++) 
        {
            cout << "这是第" << no << "名超女的编号\n";
        }
    }
    else if (t == 3) //嵌套使用循环
    {
        //超女分组，每组3名超女，在控制台显示每个超女的小组编号和组内编号
        //用一个循环显示4个小组的信息
        for (int i = 1; i <= 4; i++) {
            cout << "这是第" << i << "个小组\n";
            //再用一个循环，显示一组超女的信息
            for (int j = 1; j <= 3; j++) {
                cout << "这是第" << j << "个超女\n";
            }
        }
        }
    else if (t == 3) {//goto
        //不建议用
    }
        
}

