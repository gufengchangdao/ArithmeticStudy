//��԰���� 
/*
���⣺��(1,1)���������ξ���k���㣬��󵽴�(n,m)�㣬�������·��ʱ�ķ����� 
	���� ���� Ҫ��(1,1)��(x1,y1) ��(x2��y2)��(n,m)
������⣺��(x1,y1)����(x2,y2) ���|dx|��|dy|����C(dx+dy,dx)��
�Ƶ�����շ�����x���꿴����dx������Ҫ�ߣ���������һ�����������ߣ���dx+dy��λ�ò���dy����
	��ΪC(dx+dy,dy)��Ҳ����C(dx+dy,dx)��ע���������һ�㶼Ҫ����Ԫ 
*/
#include<stdio.h>
#include<cmath>
#define int long long
using namespace std;
const int maxn=2e5+5;	//ע�⣬����n,m��������1e+5����������Ҫ����������Ϊ���������ʱ����dx+dy 
const int mod=1e9+7;
int inv[maxn],fac[maxn];	//facΪ�׳ˣ�invΪ�׳˵���Ԫ 
	
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
	fac[0]=1;	//��׳� 
	for(int i=1;i<=maxn;i++) 
		fac[i]=fac[i-1]*i%mod;

	inv[maxn]=powermod(fac[maxn],mod-2);	//��׳���Ԫ 
	for(int i=maxn-1;i>=0;i--)	//ע������inv[0]=1����Ϊc(m,0)=1 
		inv[i]=inv[i+1]*(i+1)%mod;
}
//������� 
int C(int m,int n)
{
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
}

signed main()
{
	init();
	int n=read(),m=read(),k=read();
	//�����е�������� 
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
