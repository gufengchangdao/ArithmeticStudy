#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int w[105],v[105],f[105][105];
int main()
{
	int sum,V,n,T,ans;
	while(~scanf("%d%d%d%d",&sum,&V,&n,&T)){
		memset(f,0,sizeof(f));
		ans=-1;
		for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
		for(int i=1;i<=n;i++)
			for(int j=w[i];j<=V;j++)
				for(int k=T;k>=1;k--){
					f[j][k]=max(f[j][k],f[j-w[i]][k-1]+v[i]);
					if(f[j][k]>=sum) ans=max(ans,V-j);
				}
		printf("%d\n",ans);
	}
}
