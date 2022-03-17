
/*
题意：字符串删除两个字符使其成为回文串 
	从两边向中间逼近，在有解的情况下，出现不相等的时候，一定要删除两边的某一个数，dfs递归即可 
*/
#include<bits/stdc++.h>
//#define sc(n) scanf("%d",&n);
//#define scl(n) scanf("%lld",&n); 
using namespace std;
const int maxn=1e5;
char a[2005];

int dfs(int l,int r,int k)
{
//	if(k>2) return 0;
	if(l>=r) return 1;
	if(a[l]==a[r]) return dfs(l+1,r-1,k);
	if(k==2) return 0;//运行到这里，说明a[l]！=a[r]，此时k==2，无解 
	return dfs(l+1,r,k+1)||dfs(l,r-1,k+1);
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,a);
		if(dfs(0,n-1,0)) printf("Yes\n");
		else printf("No\n");
	}	
}
