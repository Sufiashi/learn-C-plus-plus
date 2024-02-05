#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
template <typename T>
class czs {
public:
    
    void operator()(T& s) {
        cout << "亲爱的" << s << "号：我是一只傻傻鸟.\n";
    }
};
void foreach(const vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
    }
}

void foreach(const vector<int>::iterator first,const vector<int>::iterator last) {
    for (auto it = first; it != last; it++)
    {
        cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
    }
}
template <typename T>
void foreach(const T first, const T last) {
    for (auto it = first; it != last; it++)
    {
        cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
    }
}

template <typename T>
void foreach(const T first, const T last,void (*pfun)(const string & )){
    for (auto it = first; it != last; it++)
    {
        //cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
        pfun(*it);
    }
}
template <typename T>
void foreach(const T first, const T last, czs<int> c) {
    for (auto it = first; it != last; it++)
    {
        //cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
        c(*it);
    }
}
template <typename T>
void zsshow(T& s) {
    cout << "亲爱的" << s<< "号：我是一只傻傻鸟.\n";
}

template <typename T1,typename T2>
void foreach(const T1 first, const T1 last, T2 c) {
    for (auto it = first; it != last; it++)
    {
        //cout << "亲爱的" << *it << "号：我是一只傻傻鸟.\n";
        c(*it);
    }
}


template<typename T1,typename T2,typename T3>
T1 findif(const T1 first, const T1 last, T2 pfun,T3 in_no) {
    for (auto it = first; it != last; it++)
        if (pfun(*it,in_no) == true)return it;
    return last;
}
template<typename T>
bool myshow(const T& no,const T& in_no) {
    if (no != in_no)return false;
    cout << "亲爱的" << no << "号，我是一只沙和尚.\n";
    return true;
}
int main()
{
    vector<string> bh = { "5","8","2","6","9","3","1","7" };   //存放超女编号的容器
    vector<int> bh1 = { 1,2,3,4,5,6,7,8 };
    //写一个函数，在函数中遍历容器，向超女表白
    //foreach(bh);
    //foreach(bh.begin(), bh.end());
    //foreach(bh1.begin(), bh1.end(), zsshow<int>);
    //czs c;
    //cout << endl;
    //foreach(bh1.begin(), bh1.end(), czs<int>());

    auto it1 = findif(bh1.begin(), bh1.end(), myshow<int>,3);
    if (it1 == bh1.end())cout << "查找失败\n";
    else cout << "查找成功：" << *it1 << endl;


}
