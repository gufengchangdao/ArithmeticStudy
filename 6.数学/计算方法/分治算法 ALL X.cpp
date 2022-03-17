//All X
/*
计算 10^1+10^2+...+10^k,但是k非常大 
运用分治的思想，用两个数组存下子问题的答案， 求问题10^1+10^2+...+10^k，求子问题10^x 
利用 10^1+...+10^k=(10^1+...+10^(k/2))*10^(k/2)+10^1+...+10^(k/2); 一分为二，k如果为奇数还少个10^k 
利用 10^x=10^(x/2) 一分为二，x如果为奇数还少个10
利用下标d表示每种状态，return mi[d]，路径压缩 
*/
#include<cstdio> 
#include<iostream> 
#include<cstring> 
#define ll long long 
using namespace std; 
int cas; 
ll x,m,mod,c,ans; 
ll mi[105],sum[105]; 
//基本子算法 
ll quick(ll k,int d) //求10^k
{ 
    if(k==1) return 10; 
    if(mi[d]!=-1) return mi[d];
	 
    ll s=(quick(k/2,d+1)*quick(k/2,d+1))%mod; 
    if(k%2==1) s=(s*10)%mod; 
    return mi[d]=s; 
} 

ll solve(ll k,int d) //求10^1+...+10^k 
{ 
    if(k==1) return 10; //阈值 
    if(sum[d]!=-1) return sum[d]; 	
	ll s=((solve(k/2,d+1)*quick(k/2,d+1))%mod+solve(k/2,d+1))%mod; //用基本子算法，递归解决 
    if(k%2==1) s=(s+quick(k,d))%mod; //k是奇数的时候，还少一个10^k 
    return sum[d]=s; 	//合并子问题	保存起来是因为27行有两次相同的查找 
} 

int main() 
{ 
    cin>>cas; 
    for(int i=1;i<=cas;i++){ 
        memset(sum,-1,sizeof(sum)); 
        memset(mi,-1,sizeof(mi)); 
        scanf("%lld%lld%lld%lld",&x,&m,&mod,&c); 
        m--; 
        ans=solve(m,1)+1; 
        ans=(ans*x)%mod; 
        printf("Case #%d:\n",i); 
        if(ans%mod==c) printf("Yes\n");
		else printf("No\n"); 
    } 
    return 0; 
} 
