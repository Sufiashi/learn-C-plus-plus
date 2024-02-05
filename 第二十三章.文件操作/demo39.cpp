#include <iostream>
#include <fstream>  //包含ofstream类的头文件
#include <string>
using namespace std;
//文件操作
//像文件中写入数据
struct st_girl {//超女结构体
    char name[31];  //姓名
    int no; //编号
    char memo[301]; //备注
    double weight;  //体重
}girl;
int main()
{
   /*
    string filename = "D:\\迅雷云盘\\text.txt";
    //fout.open(filename);  //打开文件，如果文件不存在，则创建它；如果文件已存在，则截断其内容
    //fout(文件名,打开方式)
    //out
    //trunc
    //app
    ofstream fout(filename,ios::app);  //创建文本输出流对象
    if (fout.is_open() == false) {
        cout << "打开文件" << filename << "失败\n";
        return 0;
    }
    //向文件中写入数据
    fout << "西施|19|既漂亮\n";
    fout << "冰冰[22]漂亮\n";
    fout << "秘密}25}一般\n";

    fout.close();   //关闭文件，fout对象失效

    cout << "操作文件完成\n";


    ifstream fin (filename,ios::in);
    if (fin.is_open() == false) {
        cout << "打开文件" << filename << "失败\n";
        return 0;
    }
    //读取文件的内容
    //1.文本文件一般以行为单位
    string buffer;
    while (getline(fin, buffer)) {
        cout << buffer << endl;
    }
    
    //2.
    char buffer1[101];
    while(fin.getline(buffer1,100)) {
        cout << buffer << endl;
    }
    //3
    while (fin >> buffer) {
        cout << buffer << endl;
    }
    fin.close();
    cout << "操作文件完成\n";
    

    //二进制文件
    string bfilename = "D:\\迅雷云盘\\text.dat";
    ofstream bfout;// (bfilename, ios::app);
    bfout.open(bfilename, ios::app|ios::binary);
    if (bfout.is_open() == false) {
        cout << "打开文件" << bfilename << "失败\n";
        return 0;
    }
    
    girl = { "西施",3,"中国历史第一美女",45.7 };
    bfout.write((const char*)& girl, sizeof(st_girl));
    bfout.close();  //关闭文件
    cout << "操作文件成功\n";

    ifstream bfin;
    bfin.open(bfilename, ios::in | ios::binary);
    if (bfin.is_open() == false) {
        cout << "打开文件" << bfilename << "失败\n"; return 0;
    }
    while(bfin.read((char*)&girl, sizeof(girl)));
    {
        cout << "name=" << girl.name << ",no=" << girl.no
            << ",memo=" << girl.memo << ",weight=" << girl.weight << endl;
    }

    bfin.close();
    cout << "操作文件成功";
    */



}


