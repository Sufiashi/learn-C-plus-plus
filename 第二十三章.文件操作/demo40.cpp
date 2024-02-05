// demo40.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//ofstream fout;
	//fout.open("D:\\迅雷云盘\\b.txt", ios::app);
	//fout.write("abcde\n",sizeof("abcde\n"));
	//fout.close();
	ifstream fin;
	fin.open("D:\\迅雷云盘\\bbb.txt",ios::binary);
	if (fin.is_open() == false)cout << "打开失败" << endl;
	char buffer[20];
	fin.read(buffer, 20);
	for (auto c : buffer)
		cout << (int)c << endl;
	//位置指针
	//tellg();tellp()
	//seekp();seekg();
	//seekp(ios::beg);seekg(ios::end)
	//seekp(int,enum)

	//文件缓冲区和流状态
	//刷新缓冲区flush,endl,unitbuf,
	//eof()输入流到达文件末尾时，设置
	//bad
	//fail
	//good

	fin.close();

	
}

