#include <iostream>
using namespace std;

namespace aa {
    class A1 {
    public:
        void show() { cout << "使用了show函数\n"; }
        void func1(){ cout << "使用了func1函数\n"; }
    };
    void show() { cout << "使用了show函数\n"; }

}
int main()
{
    using aa::A1;
    using aa::show;
    using namespace aa;
}


