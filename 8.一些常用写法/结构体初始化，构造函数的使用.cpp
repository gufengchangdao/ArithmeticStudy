//结构体构造函数初始化三种方法 
//	1.利用结构体自带的默认构造函数
//  2.利用带参数的构造函数
//  3.利用默认无参的构造函数
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	string str;
	void init(int a,int b,string c){//自己写的初始化函数，这里也可以不要参数，直接赋值，用来初始化 
		x=a;
		y=b;
		str=c;
	}//注意构造函数最后这里没有分号
	node():x(0),y(0),str("d"){}//无参数的构造函数数组初始化时调用
	node(int x,int y,string str):x(x),y(y),str(str){}//有参构造 
}a[10];
int main()
{
	a[0].init(1,1,"a");//自定义初始化函数的调用
	a[1]={2,2,"b"};
	a[2]=node(3,3,"c");//有参数结构体构造函数，注意括号中定义了几个变量这里就得传几个 
	a[3]=node();//无参默认结构体构造体函数，可以用来给数据赋初值 
	for(int i=0;i<4;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].str<<endl;
}
/*
一般的结构体可以用memset 
node b;
memset(a,0,sizeof(node)*10);
memset(&b,0,sizeof(node)); 
*/
