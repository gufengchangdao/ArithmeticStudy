//��ԭ���鰴��ű�������a[i]+1��Ϊ��״������±꣬b[i]֮��Ϊֵ
//f[i]���ʾΪa[1]��a[i]�е�ǰ���Ȩֵ�� 

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
			ll s=ask(a[i].v+1)+a[i].sum;//��Ϊa[i]>=0����������״�������±�Ӧ�ô���0,����1����󻹺ó�ʱ 
			ans=max(ans,s);//���´� 
			add(a[i].v+1,s); 
		}
		printf("%lld\n",ans);	
	}
}
