#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;	//终止温度 
double y;	
int f[2]={1,-1};	//用以生成新状态 
//求答案 
double func(double x)
{
	return 6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x;
}

double solve()
{
	double T=100;	//初始温度，初始时要设很高 
	double delta=0.98;	//降温系数 
	double x=50.0,now=func(x);	//初始化一个解，简单或者中分的就好 
	double ans=now;		//用来记录最值 
	while(T>eps){	//eps是终止温度 
		double newx=x+f[rand()%2]*T;	//产生一个新解 
		if(newx>=0&&newx<=100){			//该解为超界 
			double next=func(newx);		//计算新状态 
			ans=min(ans,next);
			double dE=next-now;
			if(dE<=0||exp(-dE/T)>rand()%RAND_MAX){	//dE<=0时说明该解更优，或者以一定概率接受该解
				x=newx;now=next;					//注意exp()中必须是负数 
			}
		}
		T*=delta;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&y);
		printf("%.4f\n",solve());
	}
}
