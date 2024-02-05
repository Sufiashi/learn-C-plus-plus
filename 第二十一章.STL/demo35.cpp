#include <iostream>
#include <list>
//#include <pair>
using namespace std;


int main() {
	//构造函数
	list<int> l1;	//创建空的链表
	list<int> l2({ 1,2,3,4,5,6,7,8,9 });//
	list<int>l3(l2);//拷贝构造
	list<int>l4(l3.begin(), l3.end());//迭代器构造

	//操作



	//pair
	pair<int, string> p0;
	cout << "p0 first=" << p0.first << ",second=" << p0.second << endl;



}
