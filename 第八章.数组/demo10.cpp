#include <iostream>
using namespace std;

//void func(int* arr,int len)
void func(int arr[],int len) 
{
	for(int i=0;i<len;i++)
	{
		cout<<"arr["<<i<<"]��ֵ�ǣ�"<<arr[i]<<endl;
		cout<<"*(arr+"<<i<<")��ֵ�ǣ�"<<*(arr+i)<<endl;
	}
}

int compasc(const void* p1,const void* p2)	//����Ļص�����
{
	return *((int*)p1)-*((int*)p2);
 } 
 
int compdesc(const void* p1,const void* p2)	//����Ļص�����
{
	return *((int*)p2)-*((int*)p1);
 } 

//��arr�в���key���ɹ�����key��arr�е������±�ʧ�ܷ���-1
int search(int arr[],int len,int key)
{
	int low=0,high=len-1,mid;		//��ʼ����low=0��high=���鳤��-1
	while(low<=high)
	{
		mid=(low+high)/2;	//����midָ���λ��
		if(arr[mid]==key) return mid;	//���ҳɹ�
		else if(arr[mid]>key)high=mid-1;	//��ǰ�������� 
		else low=mid+1; 		//�ں�������� 
	 } 
	 return -1;//����ʧ�� 
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
	{   //һά����
		int bh[] = { 3,6,1,6,7,4,3,5,6,7,8,322,2,3,9 };		//��Ů���
		string name[3];		//��Ů����

		for (int i = 0; i < sizeof(bh) / sizeof(int); i++) {
			cout << "bh[" << i << "]=" << bh[i] << endl;
		}

		int bh1[sizeof(bh) / sizeof(int)];		//���鳤�ȱ����������������ǳ�����Ҳ�����Ǳ����ͱ��ʽ����

		memcpy(bh1, bh, sizeof(bh));			//������bh�е����ݸ��Ƶ�bh1

		for (int i = 0; i < sizeof(bh1) / sizeof(int); i++) {
			cout << "bh1[" << i << "]=" << bh1[i] << endl;
		}
	}
	else if(t==1)
	{	//һά�����ָ��
		char a;		cout<<"sizeof(char)="<<sizeof(char)<<endl;	//1�ֽ�
		short b;		cout<<"sizeof(short)="<<sizeof(short)<<endl;	//2�ֽ�	 
		int c;		cout<<"sizeof(int)="<<sizeof(int)<<endl;	//4�ֽ�
		double d;		cout<<"sizeof(double)="<<sizeof(double)<<endl;	//8�ֽ�	
		
		cout<<"a�ĵ�ַ�ǣ�"<<(void*)&a<<endl;
		cout<<"a�ĵ�ַ+1�ǣ�"<<(void*)(&a+1)<<endl;
		
		cout<<"b�ĵ�ַ�ǣ�"<<(void*)&b<<endl;
		cout<<"b�ĵ�ַ+1�ǣ�"<<(void*)(&b+1)<<endl;
		
		cout<<"c�ĵ�ַ�ǣ�"<<(void*)&c<<endl;
		cout<<"c�ĵ�ַ+1�ǣ�"<<(void*)(&c+1)<<endl;
		
		cout<<"d�ĵ�ַ�ǣ�"<<(void*)&d<<endl;
		cout<<"d�ĵ�ַ+1�ǣ�"<<(void*)(&d+1)<<endl;
		
		double e[5];
		
		cout<<"e��ֵ�ǣ�"<<(long long)e<<endl;
		cout<<"&e��ֵ�ǣ�"<<(long long)&e<<endl;
		
		cout<<"&e[0]��ֵ�ǣ�"<<(long long)&e[0]<<endl;
		cout<<"&e[1]��ֵ�ǣ�"<<(long long)&e[1]<<endl;
		cout<<"&e[2]��ֵ�ǣ�"<<(long long)&e[2]<<endl;
		cout<<"&e[3]��ֵ�ǣ�"<<(long long)&e[3]<<endl;
		
		double* p=e;
		cout<<"p��ֵ�ǣ�"<<(long long)p<<endl;
		cout<<"p+0��ֵ�ǣ�"<<(long long)(p+0)<<endl;
		cout<<"p+1��ֵ�ǣ�"<<(long long)(p+1)<<endl;
		cout<<"p+2��ֵ�ǣ�"<<(long long)(p+2)<<endl;
		cout<<"p+3��ֵ�ǣ�"<<(long long)(p+3)<<endl;
		cout<<"p+4��ֵ�ǣ�"<<(long long)(p+4)<<endl;
	 } 
	 else if(t==2)
	 {	//һά�������ں�������
	 	 int a[]={5,8,4,6,7,1,9};
	 	 func(a,sizeof(a)/sizeof(int));
	 }
	 else if(t==3)
	 {	//��new��̬����һά���� 
	 	int *arr=new int[8];	//����9��Ԫ�ص���������
		for(int i=0;i<8;i++)
		{
			arr[i]=100+i;		//�����ʾ�� 
			cout<<"arr["<<i<<"]="<<*(arr+i)<<endl;	//ָ���ʾ�� 
		 } 
		 delete[] arr;
	 }
	 else if(t==4)
	 {	//һά���������qsort
	 	int a[8]={4,2,7,5,8,6,1,3};
		  
		qsort(a,sizeof(a)/sizeof(int),sizeof(int),compasc);	//���� 
		for(int i=0;i<8;i++)
		{
			cout<<"a["<<i<<"]="<<a[i]<<endl;
		}
		  
		qsort(a,sizeof(a)/sizeof(int),sizeof(int),compdesc);	//���� 
		for(int i=0;i<8;i++)
		{
		  	cout<<"a["<<i<<"]="<<a[i]<<endl;
		}
	 	
	 }
	else if(t==5)
	{	//һά����Ĳ��� 
	 	int a[15]={123,12,343,356,134,546,465,34,345,345,345,23,234,23,243};
	 	if(search(a,15,12)>=0)cout<<"�������в���12�ɹ�\n";
	 	else cout<<"����ʧ��\n";
	 }
	else if(t==6)
	{	//�ַ���
		//1.��ʼ��
		char name[21];	//����һ�������20��Ӣ���ַ���ʮ�����ĵ��ַ���
		char n1[11];
		char n2[11]="hello";
		char n3[]={"hello"};
		char n4[11]={0};
		
		//2.����ַ���
		//memset(name,0,sizeof(name));//ȫ��Ԫ����Ϊ0
		
		//�ַ������ƻ�ֵ
		//char *strcpy(char* dest,const char* src);
		//char *strncpy(char* dest,const char* src,const size_t n);	 	
	}
	else if(t==7)
	{	//��ά���� 
		int bh[][3]={11,12,13,21,22,23};
		for(int i=0;i<2;i++)//��һ��ѭ����ʾ���� 
		{
			for(int j=0;j<3;j++)//�ڶ���ѭ����ʾ���� 
			{
				cout<<"&bh["<<i<<"]["<<j<<"]="<<(long long)&bh[i][j]<<"   ";
			}
			cout<<endl;//������һ�У��ͻ��� 
		}
		
		int* p=(int *)bh;
		
		for(int i=0;i<6;i++)
		{
			cout<<"p["<<i<<"]="<<p[i]<<endl;	//һά�����ʾ�� 
		}
	}
	else if(t==8)
	{	//��ά���麯�� 
		int bh[2][3]={{11,12,13},{21,22,23}};
		func(bh,2);
	}

}

