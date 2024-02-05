// demo26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define MAXLEN 10
//typedef int DATATYPE;

template <class T1,class T2>
class AA
{
public:
    AA(){}
    T1 m_a; //通用类型用于成员变量
    T2 m_b; //通用类型用于成员变量
    T1 geta()//获取m_a
    {
        T1 a = 2;
        return m_a + a;
    }
    T2 getb()//获取m_b
    {
        T2 b = 1;
        return m_b + b;
    }
};
template <class DATATYPE>
class Stack //栈类
{
private:
    DATATYPE* items; //栈数组
    int stacksize;  //栈实际大小
    int top;//栈顶指针
public:
    //构造函数  1）分配内存 2）栈顶指针设为0
    Stack(int size=3) :stacksize(size), top(0) {
        items = new DATATYPE[stacksize];
    }
    ~Stack() {
        delete[] items; items = nullptr;
    }
    bool isempty() const {  //判断栈是否为空
        if (top == 0)return true;
        return false;
    }
    bool isfull() const {   //判断栈是否满
        if (top == stacksize)return true;
        return false;
    }
    bool push(const DATATYPE& item) {    //元素入栈
        if (isfull())return false;
        items[top++] = item;
        return true;
    }
    bool pop(DATATYPE& item)    //元素出栈
    {
        
        if (isempty())return false;
        item = items[--top];
        return true;
    }
    Stack& operator=(const Stack& v) {//重载拷贝构造函数，实现深拷贝
        delete[] items; //释放原内存
        stacksize = v.stacksize;    //栈实际大小
        items = new DATATYPE[stacksize];    //重新分配数组
        for (int ii = 0; ii < stacksize; ii++)items[ii] = v.items[ii];//赋值数组中的元素
        top = v.top;    //栈顶指针
        return *this;

    }
};

template <class T,int LEN=3>
class Array
{
private:
    T items[LEN];  //数组元素
public:
    Array() {
        //memset(items, 0, sizeof(items));//string不能用memset初始化
    }
    ~Array(){}
    

    T& operator[](int ii) {return items[ii];} //重载操作符[]，可以修改数组中的元素
    const T& operator[](int ii) const{ return items[ii]; }//重载操作符[],不能修改数组中的元素
};

template <class T>
class Vector
{
private:
    int len;
    T* items;
public:
    Vector(int size=2):len(size) {
        items = new T[len];
    }
    ~Vector() {
        delete [] items; items = nullptr;
    }
    void resize(int size) {
        if (size <= len)return; //只能扩大
        T* tmp = new T[size];
        for (int ii = 0; ii < len; ii++)tmp[ii] = items[ii];//把原来数组中的元素赋值到新数组
        delete[] items;//十方原来的内存
        items = tmp;//让数组指针指向新的数组
        len = size;//扩展后的数组长度
    }
    int size()const { return len; }
    T& operator[](int ii) { 
        if (ii >= len)resize(ii + 10);
        return items[ii]; } //重载操作符[]，可以修改数组中的元素
    const T& operator[](int ii) const { return items[ii]; }//重载操作符[],不能修改数组中的元素
};
int main()
{
    AA<int, double> a;  //用模板类AA创建对象a
    Stack<int> ss(5);
    //元素入栈
    ss.push(1); ss.push(2); ss.push(3); ss.push(4); ss.push(5);

    //元素出战
    int item;
    while (ss.isempty() == false) {
        ss.pop(item); cout << "item=" << item << endl;
    }
    cout << endl << endl;

    Array<string,10> aa;//创建模板类Array的对象
    aa[0] = "汤姆森"; aa[1] = "汤姆逊"; aa[2] = "汤姆苏"; aa[3] = "汤姆孙"; aa[4] = "汤姆";
    for (int i = 0; i < 5; i++)cout << "aa[" << i << "]=" << aa[i] << endl;

    Vector<string>vv(1);//创建vector对象
    vv[0] = "汤姆森"; vv[1] = "汤姆逊"; vv[2] = "汤姆苏"; vv[3] = "汤姆孙"; vv[4] = "汤姆";
    for (int i = 0; i < 5; i++)cout << "vv[" << i << "]=" << vv[i] << endl;

    cout << endl << endl;
    Vector<Stack<string>> vs(2);
    vs[0].push("西施1"); vs[0].push("西施2"); vs[0].push("西施3");
    vs[1].push("西瓜1"); vs[1].push("西瓜2"); vs[1].push("西瓜3");
    vs[2].push("西瓜1"); vs[2].push("西瓜2"); vs[2].push("西瓜3");

}