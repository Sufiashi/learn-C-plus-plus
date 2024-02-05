

#include <iostream>
using namespace std;


void show(string str)   //向超女表白的函数
{
    cout << "普通函数：" << str << endl;
}


class CGirl //超女类
{
public:
    string m_name;  //姓名
    int m_rank;;    //排名
    //默认构造函数
    CGirl(string name, int rank) {
        m_name = name;
        m_rank = rank;
    }

    CGirl& operator()(string str) //向超女表白的函数      仿函数
    {
        cout << "重载函数：" << str << endl;
        cout << "排名：" << m_rank << endl;
        return *this;
    }

    CGirl operator++(int) {//后置++
        CGirl tmp=*this;
        m_rank++;
        return *this;
    }
    CGirl & operator++() {//前置++
        m_rank++;
        return *this;
    }
};
int main()
{
    show("我是一只小小鸟。");
    CGirl girl("士大夫",12);
    girl("我是一只小小鸟。");
    ++girl;
    girl("我是一只小小鸟。");
    ++(++girl);
    girl("我是一只小小鸟。");
    girl++;
    girl("我是一只小小鸟。");


}

