#include<bits/stdc++.h>
using namespace std;
int a[100005],b[105][100005]={0};
int main()
{
	int m,n,i,j,x,l,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&x);
		for(j=l-1;j<=r-1;j++)
			b[x][j]++;
	}
	for(i=0;i<n;i++){
		for(x=1;x!='0';x++){
			a[i]-=b[x][i]*x;
			printf("%d ",a[i]);
			break;
		}
	}
}
