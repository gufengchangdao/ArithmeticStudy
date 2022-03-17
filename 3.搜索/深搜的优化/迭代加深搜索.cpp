//问题：1最少经过多少次加或减可以变成n，可以加减之前的计算结果 
//IDDFS：指定递归深度，用for()循环实现，由于一定存在结果，就不用终止条件
//估价函数：即使用最快的递增方式也无法在剩余步数内达到n，及时退出
//递归广度，dfs判断退出和成立，并将当前数与之前的数都进行尝试，类似移动坐标 
#include<stdio.h>
#include<stdlib.h> //调用abs()必要的 
#include<iostream>
using namespace std;
int val[1010];//保存每一步的计算结果 
int pos,n;//pos为操作次数 

bool ida(int now,int depth)
{ 
	if(now>depth) return false;//大于设定的深度，退出 
	if(val[pos]<<(depth-now)<n) return false;// 估价函数，最快的倍增也达不到，退出
	if(val[pos]==n) return true;//整个递归的出口，即计算结果达到了n
	//当前结果与之前结果加减//pos同now等同，都是当前深度	  
	pos++;//操作一次 
	for(int i=0;i<pos;i++){//pos次循环，即当前计算结果与前面所有的数(包括本身)相加减，类似移动坐标 
		val[pos]=val[pos-1]+val[i];//加 
		if(ida(pos,depth)) return true;
		val[pos]=abs(val[pos-1]-val[i]);//减 
		if(ida(pos,depth)) return true;
	}
	pos--;//没有找到，取消这次操作 
	return false; 
}

int main()
{
	while(cin>>n&&n){
		int depth;//次数 
		for(depth=0;;depth++){//depth从0开始，now也要从0开始。要验证n是否为1，为1时depth=0  
			val[pos=0]=1;//从1开始计算，pos=0,val[0]=1,由于val[]的值都是由前两项得出的，所以不需要重置 
			if(ida(0,depth)) break;//每次只dfs到深度depth,找到结果就退出 
		}
		cout<<depth<<endl;
	}
	return 0;
}
