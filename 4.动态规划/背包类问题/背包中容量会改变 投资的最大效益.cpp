题意： 
用本金去投资，本金算上投资每年获得的利息又可以选择更高收益的投资项目，求n年后获得的最大利益 
新：因为本金每件都会改变，故用个for循环就可以每年模拟并更新本金 
#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1e7;
int f[maxn];
struct node
{
	int w,v;	
}bond[15];
int main()
{
	long long V;
	int n,d,temp;
	scanf("%lld%d%d",&V,&n,&d);
	for(ri i=1;i<=d;i++){
		scanf("%d%d",&temp,&bond[i].v);
		bond[i].w=temp/1000;//这里投资所需金额为1000的倍数 
	}
	while(n--){
		for(ri i=1;i<=d;i++){
			temp=bond[i].w*1000;
			for(ri j=temp;j<=V;j++)
				f[j]=max(f[j],f[j-temp]+bond[i].v);
		}
		V+=f[V];//原本金加上投资获得的利息 

	}
	printf("%lld\n",V);
} 
