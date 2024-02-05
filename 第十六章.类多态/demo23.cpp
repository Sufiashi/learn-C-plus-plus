

#include <iostream>
using namespace std;

class Hero  //英雄基类
{
public:
    int viability;//生存能力
    int attack;//攻击伤害

    virtual void skill1() { cout << "英雄释放了一技能。" << endl; }
    virtual void skill2() { cout << "英雄释放了二技能。" << endl; }
    virtual void skill3() { cout << "英雄释放了三技能。" << endl; }
};

class HX :public Hero
{
public:
    void skill1() { cout << "韩星释放了一技能。" << endl; }
    void skill2() { cout << "韩信释放了二技能。" << endl; }
    void skill3() { cout << "韩信释放了三技能。" << endl; }
};
class LB :public Hero
{
public:
    void skill1() { cout << "李白释放了一技能。" << endl; }
    void skill2() { cout << "李白释放了二技能。" << endl; }
    void skill3() { cout << "李白释放了三技能。" << endl; }
};
class XS :public Hero
{
public:
    void skill1() { cout << "西施释放了一技能。" << endl; }
    void skill2() { cout << "西施释放了二技能。" << endl; }
    void skill3() { cout << "西施释放了三技能。" << endl; }
    void show() {cout << "我是西施。" << endl;}
};

int main()
{
    //根据用户选择的英雄，施展一技能，二级能和大招
    int id = 0; //英雄的id
    cout << "请输入英雄(1-西施；2-韩信；3-李白）：";
    cin >> id;
    if(id==1){  //西施
        XS h;
        h.skill1();
        h.skill2();
        h.skill3();
    }
    else if (id == 2) {  //韩信
        HX h;
        h.skill1();
        h.skill2();
        h.skill3();
    }
    else if (id == 3) {  //李白
        LB h;
        h.skill1();
        h.skill2();
        h.skill3();
    }


    Hero* ptr = nullptr;
    if (id == 1) {  //西施
        ptr = new XS;
        
    }
    else if (id == 2) {  //韩信
        ptr = new HX;
    }
    else if (id == 3) {  //李白
        ptr = new LB;
    }
    cout << endl << endl;
    if (ptr != nullptr) {
        ptr->skill1();
        ptr->skill2();
        ptr->skill3();
        /*if (id == 1) {//如果指向的对象是西施，哪就调用他的show函数
            XS* pxs = (XS*)ptr;//基类指针转换为派生类指针
            pxs->show();
        }*/
        XS* vxsptr = dynamic_cast<XS*>(ptr);    //基类指针转换为派生类指针
        //指向基类的指针来派生生成派生类的指针，成功返回对象的地址，失败返回空指针
        if(vxsptr != nullptr)vxsptr->show();    //转换成功，调用派生类西施的非虚函数
        delete ptr;

    }



    
}


