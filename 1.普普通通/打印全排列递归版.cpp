//打印全排列 
#include<bits/stdc++.h>
using namespace std;
#define swap(a,b){int temp=a;a=b;b=temp;}//比swap（）函数会快一点 
int a[]={1,2,3,4};
int num=0;//记录全排列个数 
void perm(int begin,int end)//begin、end分别为左边界和有边界 
{
	int i;
	if(begin==end){		//递归出口 
		for(i=0;i<=end;i++) printf("%d",a[i]);//打印 
		printf("\n");
		num++;
	}
	else{  //每次把第一个数和后面的每个数交换，去掉第一个数后对后面的n-1个数进行交换，再...
		   //第一次交换，有n次，去掉第一个数后再交换，有n-1次...   共n*(n-1)*(n-2)*...*1 
		for(i=begin;i<=end;i++){//进行一层循环 
			swap(a[begin],a[i]);//交换begin与i 
			perm(begin+1,end);//在一次交换后进入到下一层 
			swap(a[begin],a[i]);//回到这一层，再交换过来，回归原样，准备下一次begin与i+1交换 
		}
	}
}

int main()
{
	perm(0,3);
	printf("%d",num);		
} 
