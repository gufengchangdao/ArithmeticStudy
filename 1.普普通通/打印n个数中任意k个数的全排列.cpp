 //打印n个数的任意k个数的组合 (不含空集)
#include<bits/stdc++.h>
using namespace std;
int n,k;
void subset(int n)
{
	for(int i=0;i<(1<<n);i++){//i:0-2^n,每个i对应一种组合
		int num=0,kk=i;
		while(kk){	//第i+1种组合的二进制数中有多少个1，便是有多少个元素 
			kk=kk&(kk-1);//每执行一次都会消除kk的二进制数的最后一个1 
			num++;//计数 
		} 
		if(num==k){
			for(int j=0;j<n;j++)//j:0-n,j为每种组合中元素对应的下标 
				if(i&(1<<j)) printf("%d ",j);
			printf("\n");
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	subset(n);
 } 
