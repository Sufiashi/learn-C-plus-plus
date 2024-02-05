#include <iostream>
using namespace std;



int main()
{
    //unique_ptr
    //unique_ptr<AA> p0(new AA("西施"))
    //不能赋值和拷贝
    //不要用一个罗指针初始化多个unique指针
    //用于函数参数时，只能传引用
    // 
    //赋值只能赋临时的右值如函数返回值，临时构造值
    //nullptr给unique_ptr赋值会调用调用析构
    //p.release()释放资源的控制权，返回指向的地址，p称为空指针
    // move(p) 转移控制权给函数的形参
    //

    //shared_ptr
    //p.use_count()

    //可自定义删除器

    //weak_ptr
    //用于判断资源是否过期，不能用来使用资源

}

