
#include <iostream>
using namespace std;


void func(int bh,const string& name="西施",const string & message = "我喜欢你");  //表白函数 默认参数
void myswap(int& a, int& p);
void myswap(string& a, string& p);

inline void show(const short bh, const string message);//表白函数
inline void show(const short bh, const string message)//声明和定义写在一起
{
    cout << "情爱的" << bh << "号：" << message << endl;
}
int main()
{
    int t;
    cin >> t;
    if (t == 0)
    {   //默认参数
        func(1);
        func(2, "我能爹");
    }
    else if (t == 1)
    {   //函数重载
        //函数形参的个数类型顺序不同，函数名相同
        //数据类型不匹配，C++尝试类型转换与形参
        //引用作为函数重载条件，调用时，实参是变量，编译器将类型本身和类型引用视为同一特征
        //如果函数有默认参数，调用时，可能导致失败
        //const不能作为函数重载的特征
        //返回值类型不同不能作为函数的特征
        int a = 3, b = 5;
        myswap(a, b);
        cout << "a=" << a << ",b=" << b << endl;

        string c = "西施", d = "西瓜";
        myswap(c, d);
        cout << "c=" << c << ",d=" << d << endl;
    }
    else if (t == 2)
    {   //内联函数
        show(1, "撒低级佛i啊是大家偶分");

    }
}

void func(int bh, const string& name , const string& message)  //表白函数 默认参数
{   //有声明只能在声明里写默认参数
    //多个参数时，一个参数有默认值，则后面的参数都有默认值
    //没默认值的必须填值
    //填了某一个参数的值，则前面的参数都要填缺省值，就算有默认值也要填
    cout << "亲爱的：" << name<<"("<<bh<<")"<<message << endl;
}

void myswap(int& a, int& p)
{
    int tmp = a; a = p; p = tmp;
}

void myswap(string& a, string& p)
{
    string tmp = a; a = p; p = tmp;
}

