#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;	//��ֹ�¶� 
double y;	
int f[2]={1,-1};	//����������״̬ 
//��� 
double func(double x)
{
	return 6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x;
}

double solve()
{
	double T=100;	//��ʼ�¶ȣ���ʼʱҪ��ܸ� 
	double delta=0.98;	//����ϵ�� 
	double x=50.0,now=func(x);	//��ʼ��һ���⣬�򵥻����зֵľͺ� 
	double ans=now;		//������¼��ֵ 
	while(T>eps){	//eps����ֹ�¶� 
		double newx=x+f[rand()%2]*T;	//����һ���½� 
		if(newx>=0&&newx<=100){			//�ý�Ϊ���� 
			double next=func(newx);		//������״̬ 
			ans=min(ans,next);
			double dE=next-now;
			if(dE<=0||exp(-dE/T)>rand()%RAND_MAX){	//dE<=0ʱ˵���ý���ţ�������һ�����ʽ��ܸý�
				x=newx;now=next;					//ע��exp()�б����Ǹ��� 
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
