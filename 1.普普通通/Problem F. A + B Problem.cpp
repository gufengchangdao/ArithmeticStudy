#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[10000000],i,m,n,l,r;
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		b[l]++;
		b[r+1]--;
	}
	for(i=1;i<=n;i++)
		a[i]=a[i-1]+b[i];
	for(i=1;i<=n;i++)
		if(a[i]==0) break;
	if(i<=n) printf("No\n");
	else printf("Yes\n");
}
