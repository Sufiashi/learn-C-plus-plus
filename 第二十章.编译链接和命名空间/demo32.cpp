
#include <iostream>//类型转换
using namespace std;

void func(void* ptr) {
    double* pp = static_cast<double*>(ptr);
}
int main()
{
    int ii = 3;
    long ll = ii;

    double dd = 1.23;
    long ll2 = (long)dd;
    long ll3 = static_cast<long>(dd);

    double* pd1 = (double*) & ii;
    void* pv = &ii; //任何指针都可以转换为空的指针
    double* pd2 = static_cast<double*>(pv);
    func(&ii);
    //reinterpret_cast 随意转换指针
    //改变指针类型，将指针转换为整形，将整形转换为指针
    func(reinterpret_cast<void*>(ii));

    //const_cast
    const int aa = 10;
    int bb = aa;
    const int* cc = &aa;
    int* dd = (int *)cc;
    int* ee = const_cast<int*>(cc);//强制转换丢掉const限定符 

}

