#include<bits/stdc++.h>
using namespace std;
int a[35],b[35],f[1005][35],v[105],w[105];
int main()
{
	int t,n,V,k;
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%d%d%d",&n,&V,&k);
		for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		
		for(int i=1;i<=n;i++)
			for(int j=V;j>=w[i];j--){
				for(int l=1;l<=k;l++){//将下一次结果分成k份 
					a[l]=f[j][l];
					b[l]=f[j-w[i]][l]+v[i];
				}
				a[k+1]=-1;b[k+1]=-1;//设置边界 
				int x=1,y=1,o=1;
				while(o!=k+1&&(x!=k+1||y!=k+1)){//即便x=k+1后，b[y]>a[x]一定成立,a[x]和b[y]要每个都会遍历到 
					if(a[x]>b[y]) f[j][o]=a[x],x++;
					else f[j][o]=b[y],y++;
					if(f[j][o]!=f[j][o-1]) o++;//只记录最大权值不同的值 
				}
			}
			
		printf("%d\n",f[V][k]);
	}
}
