#include <iostream>
using namespace std;
class CGirl //超女类
{
    friend void addscore(CGirl& g, int score);  //C方法
    friend CGirl operator+(CGirl& g, int score); //+运算符重载
    friend CGirl operator+(int score, CGirl& g);
    friend CGirl operator+(CGirl& g1, CGirl& g2);
    friend CGirl operator-(CGirl& g, int score); //-
    //friend  ostream& operator<<(ostream& cout, const CGirl& g);//<<
private:
    int m_xw;   //胸围
    int m_score;    //分数
    int m_yz;   //颜值
    int m_act;  //演技
    string m_boys[3]; //男朋友
    
public:
    string m_name;  //姓名
    int* m_ptr; //指针
    //默认构造函数
    CGirl(string name = "西施", int score = 0, int xw = 0, int act = 0, int yz = 0,string b1="21", string b2="23", string b3="123") {
        cout << "调用构造函数。" << endl;
        m_name = name; m_score = score; m_xw = xw; m_act = act; m_yz = yz;
        m_boys[1] = b1; m_boys[2] = b2; m_boys[3] = b3;
        m_ptr = nullptr;
    }
    ~CGirl() {
        cout << "调用析构函数。" << endl;
        if (m_ptr)delete m_ptr;
    }
    //自我介绍的方法
    void show() { cout << "姓名：" << m_name << ",胸围：" << m_xw << ",评分：" << m_score <<",m_ptr地址："<<m_ptr<< endl; }
    //比价两个超女的商业价值   常见关系运算符
    bool operator==(const CGirl& g) {
        if ((m_act + m_score + m_yz) == (g.m_act + g.m_score + g.m_yz))return true;
        return false;
    }
    bool operator>(const CGirl& g) {
        if ((m_act + m_score + m_yz) > (g.m_act + g.m_score + g.m_yz))return true;
        return false;
    }
    bool operator<(const CGirl& g) {
        if ((m_act + m_score + m_yz) < (g.m_act + g.m_score + g.m_yz))return true;
        return false;
    }
    //左移运算符
    ostream& operator<<(ostream& cout) {
        cout << "姓名：" << m_name << ",胸围：" << m_xw << ",评分：" << m_score << endl;
        return cout;
    }
    
    //下标运算符
    const string& operator[](int i) const
    {
        return m_boys[i];
    }
    string& operator[](int i)
    {
        //下标合法时
        return m_boys[i];
        //下标非法时
    }
 
    //赋值运算符
    CGirl& operator=(const CGirl& g) {
        if (this == &g)return *this;    //给自己赋值
        m_name = g.m_name; m_score = g.m_score; m_xw = g.m_xw; m_act = g.m_act; m_yz = g.m_yz;
        m_boys[1] = g.m_boys[1]; m_boys[2] = g.m_boys[2]; m_boys[3] = g.m_boys[3];
        if (g.m_ptr == nullptr) {
            if (m_ptr != nullptr) { delete m_ptr; m_ptr = nullptr; }
        }
        else {
            if (m_ptr == nullptr)m_ptr = new int;
            memcpy(m_ptr, g.m_ptr, sizeof(int));
        }
        cout << "调用了重载赋值函数。" << endl;
        return *this;
    }
    //new和delete
    void* operator new(size_t size) //参数必须是size_t,返回值是void*
    {
        cout << "调用了类的重载的new：" << size << "字节" << endl;
        void* ptr = malloc(size);   //申请内存
        cout << "申请到的内存地址是：" << ptr << endl;
        return ptr;
    }
    void operator delete(void* ptr)//参数必须是void*，返回值必须是void
    {
        cout << "调用了类重载的delete" << endl;
        if (ptr == nullptr)return;  //堆空指针是安全的
        free(ptr);  //释放内存
    }
};
// 左移运算符
/*
ostream& operator<<(ostream& cout,const CGirl& g) {
    cout << "姓名：" << g.m_name << ",胸围：" << g.m_xw << ",评分：" << g.m_score << endl;
    return cout;
}*/
//new和delete

void* operator new(size_t size) //参数必须是size_t,返回值是void*
{
    cout << "调用了全局重载的new：" << size << "字节" << endl;
    void* ptr = malloc(size);   //申请内存
    cout << "申请到的内存地址是：" << ptr << endl;
    return ptr;
}
void operator delete(void* ptr)//参数必须是void*，返回值必须是void
{
    cout << "调用了全局重载的delete" << endl;
    if (ptr == nullptr)return;  //堆空指针是安全的
    free(ptr);  //释放内存
}


void addscore(CGirl& g, int score) {    //给超女加分的函数
    g.m_score += score;
}

CGirl operator+(CGirl& g, int score) {    //给超女加分的函数
    g.m_score += score;
    return g;
}
CGirl operator+(int score,CGirl& g ) {    //给超女加分的函数
    g.m_score += score;
    return g;
}
CGirl operator+(CGirl& g1, CGirl& g2) {    //给超女加分的函数
    g1.m_score += g2.m_score;
    return g1;
}
 

CGirl operator-(CGirl& g, int score) {    //给超女加分的函数
    g.m_score -= score;
    return g;
}


int main()
{

    //导演的要求：每轮比赛之后，给超女加上她的得分
    CGirl g;
    addscore(g, 30);
    g = g + 40;
    g = g - 20;
    g.m_ptr = new int(2);
    g.show();
    CGirl g1("西施", 1, 2, 3,4,"汤姆森","但尔森","石琛"), g2("冰冰", 3, 2, 1,3, "汤姆森", "但尔森", "石琛");
    if (g1 == g2)cout << g1.m_name << "和" << g2.m_name << "商业价值相同。" << endl;
    if (g1 > g2)cout << g1.m_name << "比" << g2.m_name << "商业价值大。" << endl;

    g << cout << endl;

    g2.m_ptr = new int(32);
    CGirl g3;
    g3 = g2;
    g3.show();
    //g2 << cout << endl;

    cout << endl << endl;
    int* p1 = new int(3);
    cout << "p1=" << (void*)p1 << ",*p1=" << *p1 << endl;
    delete p1;
    cout << endl << endl;

    CGirl* p2 = new CGirl;
    cout << "p2的地址：" << p2 << endl;
    delete p2;
    cout << endl << endl;

}

