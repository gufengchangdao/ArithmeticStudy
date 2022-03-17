//将原数组按编号遍历，把a[i]+1作为树状数组的下标，b[i]之和为值
//f[i]则表示为a[1]到a[i]中当前最大权值和 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int 
const int maxn=1e5+5;
struct su{
	ll id,v,sum;
	bool operator <(su &b){
		if(b.v==v) return id>b.id;
		return v<b.v;
	}
}a[maxn];
ll f[maxn];
ll n,ans;

void add(ll i,ll big)
{
	while(i<=maxn){
		f[i]=max(big,f[i]);
		i+=i&(-i);	
	}
}
ll ask(ll i)
{
	ll ans=0;
	while(i>0){
		ans=max(ans,f[i]);
		i-=i&(-i);
	}
	return ans;
}
int main()
{
	
	while(~scanf("%lld",&n)){
		ans=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(ri i=1;i<=n;i++){
			scanf("%lld",&a[i].v);
		//	a[i].id=i;
		}
		for(ri i=1;i<=n;i++) scanf("%lld",&a[i].sum);
		for(ri i=1;i<=n;i++){
			ll s=ask(a[i].v+1)+a[i].sum;//因为a[i]>=0，但是在树状数组中下标应该大于0,不加1会错误还好超时 
			ans=max(ans,s);//更新答案 
			add(a[i].v+1,s); 
		}
		printf("%lld\n",ans);	
	}
}
