#include <iostream>
#include <vector>
#include <list>
using namespace std;

//vector
int main()
{
    //1)创建一个空的vector
    vector<int> v1;
    cout << "v1.capacity()=" << v1.capacity() << ",v1.size()=" << v1.size() << endl;

    //2)创建vector容器，元素个数为n
    vector<int>v2(8);
    cout << "v2.capacity()=" << v2.capacity() << ",v2.size()=" << v2.size() << endl;


    //迭代器
    //在容器中查找元素
    vector<int> vv = { 1,2,3,4,5 };
    vector<int>::iterator it = find(vv.begin(), vv.end(), 3);
    if (it == vv.end())cout << "查找失败\n";
    else cout << "查找成功\n";

    list<int> ll = { 1,2,3,4,5 };
    list<int>::iterator it1 = find(ll.begin(), ll.end(), 3);
    if (it1 == ll.end())cout << "查找失败\n";
    else cout << "查找成功\n";

}


