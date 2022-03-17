//公园游玩 
/*
题意：从(1,1)出发，依次经过k个点，最后到达(n,m)点，求走最短路径时的方案数 
	就是 依次 要走(1,1)、(x1,y1) 、(x2、y2)、(n,m)
组合问题：从(x1,y1)到达(x2,y2) 求出|dx|、|dy|，有C(dx+dy,dx)种
推导：插空法，从x坐标看，有dx个格子要走，决定在哪一个格子向上走，在dx+dy个位置插入dy个数
	即为C(dx+dy,dy)，也等于C(dx+dy,dx)，注意求组合数一般都要求逆元 
*/
#include<stdio.h>
#include<cmath>
#define int long long
using namespace std;
const int maxn=2e5+5;	//注意，这里n,m都不超过1e+5，但是数组要开两倍，因为求组合数的时候有dx+dy 
const int mod=1e9+7;
int inv[maxn],fac[maxn];	//fac为阶乘，inv为阶乘的逆元 
	
struct node{
	int x,y;
}poi[maxn];

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

int powermod(int a,int b)
{
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;	
	}
	return ans;
}

void init()
{
	fac[0]=1;	//求阶乘 
	for(int i=1;i<=maxn;i++) 
		fac[i]=fac[i-1]*i%mod;

	inv[maxn]=powermod(fac[maxn],mod-2);	//求阶乘逆元 
	for(int i=maxn-1;i>=0;i--)	//注意这里inv[0]=1，因为c(m,0)=1 
		inv[i]=inv[i+1]*(i+1)%mod;
}
//求组合数 
int C(int m,int n)
{
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
}

signed main()
{
	init();
	int n=read(),m=read(),k=read();
	//将所有点存入数组 
	poi[0]=(node){1,1};	
	for(int i=1;i<=k;i++)
		poi[i].x=read(),poi[i].y=read();
	poi[k+=1]=(node){n,m};

	int ans=1;
	for(int i=1;i<=k;i++){
		int dx=abs(poi[i].x-poi[i-1].x);
		int dy=abs(poi[i].y-poi[i-1].y);
//		printf("%lld\n",C(dx+dy,dy));
		ans=ans*C(dx+dy,dy)%mod;
	}
	printf("%lld\n",ans);	
} 
