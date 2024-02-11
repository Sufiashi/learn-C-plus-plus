// demo43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;
mutex mtx;//创建互斥锁保护cout资源
once_flag onceflag;//只调用一次
void once_func(const int bh, const string& str) {
    cout << "once_func()bh=" << bh << ",str=" << str << endl;
}
//普通函数
void func(int bh, const string& str) {
    
    call_once(onceflag, once_func,0, "汤姆森");
    for (int ii = 0; ii < 10; ii++) {
        mtx.lock();
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        Sleep(1000);//休眠疫苗
        mtx.unlock();
    }
}

//lambda函数
auto f = [](int bh, const string& str) {
    for (int ii = 0; ii < 10; ii++) {
        lock_guard<mutex> m(mtx);
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        Sleep(1000);//休眠疫苗
    }
    };

//仿函数
class mythread1
{
public:
    void operator()(int bh, const string& str) {
        for (int ii = 0; ii < 10; ii++) {
            cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
            Sleep(1000);//休眠疫苗
        }
    };
};

//静态成员函数
class mythread2
{
public:
    static void func(int bh, const string& str) {
        for (int ii = 0; ii < 10; ii++) {
            cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
            Sleep(1000);//休眠疫苗
        }
    };
};


//普通成员函数
class mythread3
{
public:
    void func(int bh, const string& str) {
        
        cout << "子线程:" << this_thread::get_id() << endl;
        for (int ii = 0; ii < 10; ii++) {
            cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
            Sleep(1000);//休眠疫苗
        }
    };
};
mythread3 myth;
//thread t3(f, 3, "我是t3");

int main()
{
    //thread t1(func,3,"我是t1");
    //thread t2(func,8,"我是t2");
    //thread t3(f,3,"我是t3");
    //thread t4(mythread1(), 3, "我是t4");
    //thread t5(mythread2::func, 3, "我是t5");
    //thread t6(&mythread3::func, &myth, 3, "我是t6");
    //thread t7 = move(t6);//转为右值后才能赋值
    //cout << "主线程：" << this_thread::get_id() << endl;
    /*cout << "任务开始" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "执行任务中...\n";
        Sleep(1000);    //假设执行任务的时间
    }
    cout << "任务完成" << endl;

    return 0;*/

    thread t1(func, 3, "我是t1");
    thread t2(func, 3, "我是t2");
    thread t3(func, 3, "我是t3");
    thread t4(func, 3, "我是t4");
    thread t5(func, 3, "我是t5");
    t1.join();//回收线程资源 
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    //t6.join();
    //t7.join();
}


