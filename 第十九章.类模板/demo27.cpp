// demo27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



template <class T1,class T2>
class AA {
public:
    T1 m_x;
    T2 m_y;

    AA(const T1 x,const T2 y):m_x(x),m_y(y){cout<<"类模板：：构造函数\n" }
    void show() const;
};
template<class T1, class T2>
void AA<T1, T2>::show() const
{
    cout << "部分具体：x=" << m_x << ",y=" << m_y << endl;
}
//类模板完部分具体化
template<class T1>
class AA<T1, string> {
public:
    T1 m_x;
    string m_y;

    AA(const T1 x, const string y) :m_x(x), m_y(y) { cout << "具体模板：构造函数\n"; }
    void show() const;
};
template<class T1>
void AA<T1, string>::show() const {
    cout << "具体化：x=" << m_x << ",y=" << m_y << endl;
}

//类模板完全具体化
template<>
class AA<int, string> {
    public:
        int m_x;
        string m_y;

        AA(const int x, const string y) :m_x(x), m_y(y) { cout << "具体模板：构造函数\n"; }
        void show() const;
};
void AA<int, string>::show() const {
    cout << "具体化：x=" << m_x << ",y=" << m_y << endl;
}
int main()
{
    std::cout << "Hello World!\n";
}

