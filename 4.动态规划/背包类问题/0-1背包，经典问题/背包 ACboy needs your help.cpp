#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int v[105][105],f[105],w[10005];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		int k=1;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&v[i][j]);
		for(int k=1;k<=n;k++)
			for(int j=m;j>=0;j--)
				for(int i=1;i<=j;i++)//每组的第i个物品消耗为i，要小于等于j,f才会改变 
					f[j]=max(f[j],f[j-i]+v[k][i]);
		printf("%d\n",f[m]);
	}
}
