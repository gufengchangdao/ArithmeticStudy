//�ṹ�幹�캯����ʼ�����ַ��� 
//	1.���ýṹ���Դ���Ĭ�Ϲ��캯��
//  2.���ô������Ĺ��캯��
//  3.����Ĭ���޲εĹ��캯��
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	string str;
	void init(int a,int b,string c){//�Լ�д�ĳ�ʼ������������Ҳ���Բ�Ҫ������ֱ�Ӹ�ֵ��������ʼ�� 
		x=a;
		y=b;
		str=c;
	}//ע�⹹�캯���������û�зֺ�
	node():x(0),y(0),str("d"){}//�޲����Ĺ��캯�������ʼ��ʱ����
	node(int x,int y,string str):x(x),y(y),str(str){}//�вι��� 
}a[10];
int main()
{
	a[0].init(1,1,"a");//�Զ����ʼ�������ĵ���
	a[1]={2,2,"b"};
	a[2]=node(3,3,"c");//�в����ṹ�幹�캯����ע�������ж����˼�����������͵ô����� 
	a[3]=node();//�޲�Ĭ�Ͻṹ�幹���庯�����������������ݸ���ֵ 
	for(int i=0;i<4;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].str<<endl;
}
/*
һ��Ľṹ�������memset 
node b;
memset(a,0,sizeof(node)*10);
memset(&b,0,sizeof(node)); 
*/
