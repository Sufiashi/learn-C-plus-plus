// demo17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//内存池
//预先分配一段内存
//提升分配和归还的速度
//减少内存碎片


#include <iostream>
using namespace std;



class CGirl
{
public:
    int m_bh;   //编号
    int m_xw;   //胸围
    static char* m_pool;   //内存池的起始地址

    static bool initpool()//初始化内粗吃
    {
        m_pool = (char*)malloc(18); //向系统申请18个字节的内存池
        if (m_pool == 0)return false;
        memset(m_pool, 0, 18);  //把内存池初始化为0
        cout << "内存池的起始地址是：" << (void*)m_pool << endl;
        return true;
    }

    static void freepool()//释放内存池
    {
        if (m_pool)return;  //内存池为空，直接返回
        free(m_pool);     //释放内存池
        cout << "内存池已经释放" << endl;
    }
    CGirl(int bh,int xw) {
        m_bh = bh; m_xw = xw; cout << "调用了构造函数。\n";
    }
    ~CGirl() {
        cout << "调用了析构函数。\n";
    }

    void* operator new(size_t size) {
        if (m_pool[0] == 0)    //判断第一个位置是否空闲
        {
            cout << "分配了第一块内存：" << (void*)(m_pool + 1) << endl;
            m_pool[0] = 1;//第一个设为已经分配
            return m_pool + 1;  //返回第一个用于存放对象的地址
        }
        if (m_pool[9] == 0)    //判断第二个位置是否空闲
        {
            cout << "分配了第一块内存：" << (void*)(m_pool + 9) << endl;
            m_pool[9] = 1;//第二个设为已经分配
            return m_pool +9;  //返回第二个用于存放对象的地址

        }

        //都用完了，直接申请内存
        void* ptr = malloc(size);   //申请内存
        cout << "申请到的内存地址是：" << ptr << endl;
        return ptr;
    }

    void operator delete(void* ptr) {
        if (ptr == nullptr)return;
        if (ptr == m_pool + 1)
        {
            cout << "释放了第一块内存.\n";
            m_pool[0] = 0;  //把第一个位置标记为空闲
            return;
        }
        if (ptr == m_pool + 9)
        {
            cout << "释放了第二块内存.\n";
            m_pool[9] = 0;  //把第二个位置标记为空闲
            return;
        }

        //不属于内存池，归还系统
        free(ptr);  //释放内存
    }
};


char* CGirl::m_pool = 0;    //初始化内存池的指针



int main()
{
    //初始化内存池
    if (CGirl::initpool() == false) { cout << "初始化内存池失败。\n"; return -1; }

    CGirl* p1 = new CGirl(3, 8);
    cout << "p1的地址是：" << p1 << "，编号：" << p1->m_bh << ",胸围：" << p1->m_xw << endl;
    

    CGirl* p2 = new CGirl(3, 8);
    cout << "p2的地址是：" << p2 << "，编号：" << p2->m_bh << ",胸围：" << p2->m_xw << endl;
    

    CGirl* p3 = new CGirl(3, 8);
    cout << "p3的地址是：" << p3 << "，编号：" << p3->m_bh << ",胸围：" << p3->m_xw << endl;
    

    CGirl* p4 = new CGirl(3, 8);
    cout << "p4的地址是：" << p4 << "，编号：" << p4->m_bh << ",胸围：" << p4->m_xw << endl;
   

    

    CGirl* p5 = new CGirl(3, 8);
    cout << "p5的地址是：" << p5 << "，编号：" << p5->m_bh << ",胸围：" << p5->m_xw << endl;


    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    CGirl::freepool();  //释放内存池
}
