#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
ll n,m,a[maxn],tr[maxn],trr[maxn];
void update(ll i,ll k,ll tree[])
{
	while(i<=n){
		tree[i]+=k;
		i+=i&(-i);
	}
}

ll getsum(ll i,ll tree[])
{
	ll ans=0;
	while(i>0){
		ans+=tree[i];
		i-=i&(-i);
	}
	return ans;
}

int main()
{
	ll op,l,r,k;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		update(i,a[i]-a[i-1],tr);
		update(i,(a[i]-a[i-1])*(i-1),trr);
	}
	while(m--){
		scanf("%lld",&op);
		if(op&1){//Çø¼äÐÞ¸Ä 
			scanf("%lld%lld%lld",&l,&r,&k);
			update(l,k,tr);update(r+1,-k,tr);
			update(l,k*(l-1),trr);update(r+1,-k*r,trr);
		}
		else{
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",r*getsum(r,tr)-(l-1)*getsum(l-1,tr)-getsum(r,trr)+getsum(l-1,trr));
		}
	}
}
