//[USACO06NOV]Corn Fields G
/*
题意：从给定的01网格中选出一些1点，且四不连通，求方案数。
	要注意的几个操作： 
		在一行中合法(不相邻)的求法： i&(i<<1)==0 ，左移(或者右移)没有重合的1就合法
			与上行进行比较：i&k==0 
		是否满足条件 (j&F[i])==j ,就是j二进制含的1的集合包含在F[i]二进制1的集合中 
*/		
#include<stdio.h>
#define ri register int
using namespace std;
const int maxn=1<<12;
const int mod=100000000;
int f[13][maxn];	//f[i][j]为运行到第i行排列为j的的个数
int F[13];	//二进制下为条件中给的01数列 
bool state[maxn];	//是否合法打表 

void init(int n)//打表 
{
	int len=1<<n;
	for(int i=0;i<len;i++)//遍历所有的合法状态，即不相邻，要求1与1之间一定有0相隔
		state[i]=((i&(i<<1))==0);//判断是否相邻，左移、右移都可以。当然也包含啥也不选的0排列
}

int main()
{
	int m,n,tem;
	scanf("%d%d",&m,&n);
	init(n);
	for(ri i=1;i<=m;i++)
		for(ri j=1;j<=n;j++){
			scanf("%d",&tem);
			F[i]=(F[i]<<1)+tem; //把每一行的数倒叙存入f[i]，顺序无所谓，只要不相邻就行
		}
	
	f[0][0]=1;	//题目中什么也不选(全是0)也是一个方案 
	int len=1<<n;
	for(ri i=1;i<=m;i++){
		for(ri j=0;j<len;j++)
			if(state[j]&&(j&F[i])==j)//该排列合法并且从行看1的位置都满足条件
				for(ri k=0;k<len;k++)	//遍历上一行所有情况 
					if((j&k)==0) //从列看，上下不相邻 
						f[i][j]=(f[i][j]+f[i-1][k])%mod;//继承上一行的总数,注意第一行的上一行f全为0 
	}
	int ans=0;
	for(int i=0;i<len;i++)//遍历最后一行每一种状态就可以了
		ans=(ans+f[m][i])%mod;
	printf("%d\n",ans);
}
 
