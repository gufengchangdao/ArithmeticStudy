//你的任务是找出最坏的情况，并确定存钱罐里的最低金额
/*
只需要把dp[1~n]全部赋值为最大值，遍历时选择最小的即可，当dp[V]等于最大值时，说明不存在这种情况 
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=5e8;
int v[505],w[505],dp[10005];
int main()
{
	int t,e,f,n,V;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&e,&f);
		V=f-e;
		for(int i=1;i<=V;i++) dp[i]=100000000;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
		for(int i=1;i<=n;i++)
			for(int j=w[i];j<=V;j++){
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]); 
			}
			if(dp[V]==100000000) printf("This is impossible.\n");
			//dp[V]=min(dp[V],dp[V-w[i]]+v[i])时，不存在金额之和为V-w[i]的情况，这时候没有解 
			else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
	}
}
/*
Captain on the bridge
*/
