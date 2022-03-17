/*
线段树模板：区间加法、区间乘法、区间查询 
https://www.luogu.com.cn/problem/P3373
区间加法、区间乘法都用懒标记实现 
本题亮点：
	同时需要加法和乘法两个懒标记，在标记下传中：
	值的更新： 
		儿子的值=儿子的值*父亲的乘法标记+儿子的区间长度*父亲的加法标记
	标记的更新：
		儿子的加法标记=儿子的加法标记*父亲的乘法标记+父亲的加法标记
		儿子的乘法标记=儿子的乘法标记*父亲的乘法标记 
*/
#include<bits/stdc++.h>
#define L (k<<1)
#define R (k<<1|1) 
#define ll long long
using namespace std;
struct node{
	int l,r;
	ll v,f,a;	//f为乘法懒标记，a为加法懒标记 
}tree[400005];
int n,m,x,y,rat,op;
ll ans,mod;
/*
void check(int k)//这里整个没用的函数，实在答案错误就不断检查 
{
	if(k>n*4) return;
	printf("tree[%d]=%d\n",k,tree[k].v);
	check(k*2);
	check(k*2+1);	
}
*/
void build(int l,int r,int k)
{
	tree[k].l=l;tree[k].r=r;tree[k].f=1;tree[k].a=0;//加法和乘法懒标记的初始化不同 
	if(l==r){
		scanf("%lld",&tree[k].v);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,L);
	build(mid+1,r,R);
	tree[k].v=(tree[L].v+tree[R].v)%mod;	
}

void down(int k)//标记下传，重点 
{
	tree[L].f=tree[L].f*tree[k].f%mod;//更新乘法标记 
	tree[R].f=tree[R].f*tree[k].f%mod;
	tree[L].a=(tree[L].a*tree[k].f+tree[k].a)%mod;//更新加法标记 
	tree[R].a=(tree[R].a*tree[k].f+tree[k].a)%mod;
	tree[L].v=(tree[L].v*tree[k].f%mod+tree[k].a*(tree[L].r-tree[L].l+1)%mod)%mod;//更新值 
	tree[R].v=(tree[R].v*tree[k].f%mod+tree[k].a*(tree[R].r-tree[R].l+1)%mod)%mod;
	tree[k].a=0;tree[k].f=1;//传给子结点后就初始化	
} 
//区间乘法 
void qchange(int k)
{
	//if(k>n*4) return;既可以根据结点下标剪枝，又可以根据结点的区间剪枝，毕竟 x>0,无效数据的l=0，不可能记录进去 
	if(y<tree[k].l || tree[k].r<x) return;
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].v=tree[k].v*rat%mod;
		tree[k].f=tree[k].f*rat%mod;//对于修改过的区间不能忘了懒标记 
		tree[k].a=tree[k].a*rat%mod;//加法懒标记也要改变 
		return;
	}
	if(tree[k].f!=1||tree[k].a)//虽然可以直接下传，但是判断一下再下传更好 
		down(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) qchange(L);
	if(y>mid) qchange(R);
	tree[k].v=(tree[L].v+tree[R].v)%mod; 
}
//区间加法 
void add(int k)
{
	//if(k>n*4) return;
	if(y<tree[k].l || tree[k].r<x) return;
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].v=(tree[k].v+rat*(tree[k].r-tree[k].l+1)%mod)%mod;
		tree[k].a=(tree[k].a+rat)%mod;//只用修改加法标记就可以了 
		return;
	}
	if(tree[k].f!=1||tree[k].a) down(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) add(L);
	if(y>mid) add(R);
	tree[k].v=(tree[L].v+tree[R].v)%mod; 
}
//求区间和 
void sum(int k)
{
	//if(!tree[k].v) return;
	if(y<tree[k].l || tree[k].r<x)
        return;
	if(tree[k].l>=x&&tree[k].r<=y){
        ans=(ans+tree[k].v)%mod;
        return;
    }
    if(tree[k].f!=1||tree[k].a) down(k);
    int mid=(tree[k].l+tree[k].r)>>1;
    if(x<=mid) sum(L);
    if(y>mid) sum(R);
}

int main()
{
	
	scanf("%d%d%d",&n,&m,&mod);
	build(1,n,1);
//	check(1);
	while(m--){
		ans=0;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&x,&y,&rat);
			qchange(1);			
		}
		else if(op==2){
			scanf("%d%d%d",&x,&y,&rat);
			add(1);		
		}
		else{
			scanf("%d%d",&x,&y);
			sum(1);
			printf("%lld\n",ans);
		}	
	}	
} 
