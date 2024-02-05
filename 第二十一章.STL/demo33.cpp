#include <iostream>
using namespace std;
//string
int main()
{
    //1)创建一个长度为0的string对象（默认构造函数
    string s1;
    cout << "s1=" << s1 << endl;
    cout << "s1.capacity=" << s1.capacity() << endl;    //返回当前容器的容量
    cout << "s1.size()=" << s1.size() << endl;  //返回容器中数据的大小
    cout << "容器首地址：" << (void*)s1.c_str() << endl;
    s1 = "132432432423432233232324";
    cout << "s1=" << s1 << endl;
    cout << "s1.capacity=" << s1.capacity() << endl;    //返回当前容器的容量
    cout << "s1.size()=" << s1.size() << endl;  //返回容器中数据的大小
    cout << "容器首地址：" << (void*)s1.c_str() << endl;
    //2)string(const char* s):将string对象初始化为s'指向的NBTS转换函数
    string s2("hellow world");
    cout << "s2=" << s2 << endl;
    string s3="hellow world";
    cout << "s3=" << s3 << endl;
    //3)string(const string &str) :将string对象初始化为str
    string s4(s3);
    cout << "s4=" << s4 << endl;
    string s5(s3);
    cout << "s5=" << s5 << endl;
    //4)string(const char* s,size_t n):将string对象初始化为s指向的NBTS的前n个字符，即使超过了NBTS结尾
    string s6("hellow world", 5);
    cout << "s6=" << s6 << endl;
    cout << "s6.capacity=" << s6.capacity() << endl;    //返回当前容器的容量
    cout << "s6.size()=" << s6.size() << endl;  //返回容器中数据的大小
    string s7("hellow world", 50);
    cout << "s7=" << s7 << endl;
    cout << "s7.capacity=" << s7.capacity() << endl;    //返回当前容器的容量
    cout << "s7.size()=" << s7.size() << endl;  //返回容器中数据的大小
    //5）string(const string &str,size_t pos=0,size_t n=npos):
    //将string对象初始化为str从位置pos开始到结尾的字符，或从位置pos开始的n个字符
    string s8(s3, 3, 5);
    cout << "s8=" << s8 << endl;
    string s9(s3, 3);
    cout << "s9=" << s9 << endl;
    cout << "s9.capacity=" << s9.capacity() << endl;    //返回当前容器的容量
    cout << "s9.size()=" << s9.size() << endl;  //返回容器中数据的大小
    //6)template<class T>string(T begin,T end):

    //7)string(size_t n,char c):创建ui一个由n个字符c组成的string对象
    string s12(8, 'X');
    cout << "s12=" << s12 << endl;
    cout << "s12.capacity=" << s12.capacity() << endl;    //返回当前容器的容量
    cout << "s12.size()=" << s12.size() << endl;  //返回容器中数据的大小


    //用作缓冲区

    //操作
    //特性操作:capacity(),length(),size(),empty(),reserve(),resize()
    //字符操作 [],at(),
 }


