#include<bits/stdc++.h>
using namespace std;
const int maxn=100000005;
double f[maxn];

void init()
{
	f[0]=0;f[1]=1;
	for(int i=2;i<maxn;i++) f[i]=f[i-1]+f[i-2];
}

int main()
{
	init();
	int n;
	while(~scanf("%d",&n)){
		double ans=f[n];
	//	int m=(int)log10(ans);
	//	while(m-->=4) ans*=0.1;
		printf("%d\n",(int)ans); 
	}
		
} 
