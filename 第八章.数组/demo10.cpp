#include <iostream>
using namespace std;

//void func(int* arr,int len)
void func(int arr[],int len) 
{
	for(int i=0;i<len;i++)
	{
		cout<<"arr["<<i<<"]的值是："<<arr[i]<<endl;
		cout<<"*(arr+"<<i<<")的值是："<<*(arr+i)<<endl;
	}
}

int compasc(const void* p1,const void* p2)	//升序的回调函数
{
	return *((int*)p1)-*((int*)p2);
 } 
 
int compdesc(const void* p1,const void* p2)	//降序的回调函数
{
	return *((int*)p2)-*((int*)p1);
 } 

//在arr中查找key，成功返回key在arr中的数组下表，失败返回-1
int search(int arr[],int len,int key)
{
	int low=0,high=len-1,mid;		//初始化：low=0，high=数组长度-1
	while(low<=high)
	{
		mid=(low+high)/2;	//计算mid指针的位置
		if(arr[mid]==key) return mid;	//查找成功
		else if(arr[mid]>key)high=mid-1;	//在前半区查找 
		else low=mid+1; 		//在后半区查找 
	 } 
	 return -1;//查找失败 
 } 

//void func(int(*p)[3],int len)
void func(int p[][3],int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<3;j++){
			cout<<"p["<<i<<"]["<<j<<"]="<<p[i][j]<<"	";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	cin >> t;
	if(t==0)
	{   //一维数组
		int bh[] = { 3,6,1,6,7,4,3,5,6,7,8,322,2,3,9 };		//超女编号
		string name[3];		//超女姓名

		for (int i = 0; i < sizeof(bh) / sizeof(int); i++) {
			cout << "bh[" << i << "]=" << bh[i] << endl;
		}

		int bh1[sizeof(bh) / sizeof(int)];		//数组长度必须是整数，可以是常量，也可以是变量和表达式长度

		memcpy(bh1, bh, sizeof(bh));			//把数组bh中的内容复制到bh1

		for (int i = 0; i < sizeof(bh1) / sizeof(int); i++) {
			cout << "bh1[" << i << "]=" << bh1[i] << endl;
		}
	}
	else if(t==1)
	{	//一维数组和指针
		char a;		cout<<"sizeof(char)="<<sizeof(char)<<endl;	//1字节
		short b;		cout<<"sizeof(short)="<<sizeof(short)<<endl;	//2字节	 
		int c;		cout<<"sizeof(int)="<<sizeof(int)<<endl;	//4字节
		double d;		cout<<"sizeof(double)="<<sizeof(double)<<endl;	//8字节	
		
		cout<<"a的地址是："<<(void*)&a<<endl;
		cout<<"a的地址+1是："<<(void*)(&a+1)<<endl;
		
		cout<<"b的地址是："<<(void*)&b<<endl;
		cout<<"b的地址+1是："<<(void*)(&b+1)<<endl;
		
		cout<<"c的地址是："<<(void*)&c<<endl;
		cout<<"c的地址+1是："<<(void*)(&c+1)<<endl;
		
		cout<<"d的地址是："<<(void*)&d<<endl;
		cout<<"d的地址+1是："<<(void*)(&d+1)<<endl;
		
		double e[5];
		
		cout<<"e的值是："<<(long long)e<<endl;
		cout<<"&e的值是："<<(long long)&e<<endl;
		
		cout<<"&e[0]的值是："<<(long long)&e[0]<<endl;
		cout<<"&e[1]的值是："<<(long long)&e[1]<<endl;
		cout<<"&e[2]的值是："<<(long long)&e[2]<<endl;
		cout<<"&e[3]的值是："<<(long long)&e[3]<<endl;
		
		double* p=e;
		cout<<"p的值是："<<(long long)p<<endl;
		cout<<"p+0的值是："<<(long long)(p+0)<<endl;
		cout<<"p+1的值是："<<(long long)(p+1)<<endl;
		cout<<"p+2的值是："<<(long long)(p+2)<<endl;
		cout<<"p+3的值是："<<(long long)(p+3)<<endl;
		cout<<"p+4的值是："<<(long long)(p+4)<<endl;
	 } 
	 else if(t==2)
	 {	//一维数组用于函数参数
	 	 int a[]={5,8,4,6,7,1,9};
	 	 func(a,sizeof(a)/sizeof(int));
	 }
	 else if(t==3)
	 {	//用new动态创建一维数组 
	 	int *arr=new int[8];	//创建9个元素的整形数组
		for(int i=0;i<8;i++)
		{
			arr[i]=100+i;		//数组表示法 
			cout<<"arr["<<i<<"]="<<*(arr+i)<<endl;	//指针表示法 
		 } 
		 delete[] arr;
	 }
	 else if(t==4)
	 {	//一维数组的排序qsort
	 	int a[8]={4,2,7,5,8,6,1,3};
		  
		qsort(a,sizeof(a)/sizeof(int),sizeof(int),compasc);	//升序 
		for(int i=0;i<8;i++)
		{
			cout<<"a["<<i<<"]="<<a[i]<<endl;
		}
		  
		qsort(a,sizeof(a)/sizeof(int),sizeof(int),compdesc);	//升序 
		for(int i=0;i<8;i++)
		{
		  	cout<<"a["<<i<<"]="<<a[i]<<endl;
		}
	 	
	 }
	else if(t==5)
	{	//一维数组的查找 
	 	int a[15]={123,12,343,356,134,546,465,34,345,345,345,23,234,23,243};
	 	if(search(a,15,12)>=0)cout<<"在数组中查找12成功\n";
	 	else cout<<"查找失败\n";
	 }
	else if(t==6)
	{	//字符串
		//1.初始化
		char name[21];	//声明一个最多存放20个英文字符或十个中文的字符串
		char n1[11];
		char n2[11]="hello";
		char n3[]={"hello"};
		char n4[11]={0};
		
		//2.清空字符串
		//memset(name,0,sizeof(name));//全部元素置为0
		
		//字符串复制或赋值
		//char *strcpy(char* dest,const char* src);
		//char *strncpy(char* dest,const char* src,const size_t n);	 	
	}
	else if(t==7)
	{	//二维数组 
		int bh[][3]={11,12,13,21,22,23};
		for(int i=0;i<2;i++)//第一层循环表示行数 
		{
			for(int j=0;j<3;j++)//第二层循环表示列数 
			{
				cout<<"&bh["<<i<<"]["<<j<<"]="<<(long long)&bh[i][j]<<"   ";
			}
			cout<<endl;//遍历完一行，就换行 
		}
		
		int* p=(int *)bh;
		
		for(int i=0;i<6;i++)
		{
			cout<<"p["<<i<<"]="<<p[i]<<endl;	//一维数组表示法 
		}
	}
	else if(t==8)
	{	//二维数组函数 
		int bh[2][3]={{11,12,13},{21,22,23}};
		func(bh,2);
	}

}

