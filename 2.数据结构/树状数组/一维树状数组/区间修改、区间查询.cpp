#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int N=1003;
inline void inn(int & x) {
   // int快读
inline void lnn(ll & x) {
   // ll快读
int n,m;
ll a[N],tr[N],trr[N];//a原数组,设c为差分数组 tr为的c树状数组 trr为为c[i]*(i-1)的树状数组
//动态调整树状数组  
inline void add(int i,ll k,ll tree[]){
	for (;i<=n;i+=((i)&-(i)))
		tree[i]+=k;
}
//求tree中[1,i]的和，即前缀和 
inline ll sum(int i,ll tree[]){
	ll res=0;
	for (;i>0;i-=((i)&-(i)))
        res+=tree[i];
	return res;
}

int main(){
	inn(n);inn(m);
	//输入a[i]和初始化 
	fo(i,1,n+1){//a[i]从1开始存储 
		lnn(a[i]);
		add(i,a[i]-a[i-1],tr);//先建立差的树状数组用于求i*(tree[1]*i+tree[2]*i+...+tree[i])
		add(i,(i-1)*(a[i]-a[i-1]),trr);//用于求tree[1]*0+tree[2]*1+...+tree[i]*(i-1) 
	}
	while(m--){
        int bo,l,r;
        inn(bo);inn(l);inn(r);
        //在[l,r]区间中a[i]修改为a[i]+k
        if(bo&1){	//只用修改与a[l]和a[r+l]有关的tr和trr就可以
            ll k;lnn(k); 
            add(l,k,tr);
			add(r+1,-k,tr);
            add(l,k*(l-1),trr);//关于c[i]*(i-1)修改端点时修改为(c[l]+k)*(l-1)、(c[r+1]-k)*(r) 
			add(r+1,-r*k,trr);
        }
        //求a中[l,r]区间的和 ,sum[r]-sum[l-1]
        else{
            l--;
            printf("%lld\n",r*sum(r,tr)-sum(r,trr)-l*sum(l,tr)+sum(l,trr));
        }
	}
	return 0;
}


