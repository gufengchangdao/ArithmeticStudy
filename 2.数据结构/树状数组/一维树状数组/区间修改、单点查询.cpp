/*
区间修改、单点查询
利用差分数组c[i]=a[i]-a[i-1],可知a[n]=c[n]+c[n-1]+...+c[1]
利用树状数组单点修改和求前缀和的性质
可将差分的数组作为树状数组，区间修改时修改差分数组的端点，单点查询的时候就求前缀和
而且这里不需要存入原数组 
*/
#include<stdio.h>
using namespace std;
const int maxn=500005;
int n,m,tree[maxn];
//单点修改 
void add(int i,int k)
{
	while(i<=n){
		tree[i]+=k;
		i+=i&(-i);
	}	
}
//求前缀和 
int query(int i)
{
	int ans=0;
	while(i>0){
		ans+=tree[i];
		i-=i&(-i);
	}
	return ans;	
}

int main()
{
	int x=0,y,op,l,r,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&y);
		add(i,y-x);//关键所在，存入后数与前数之差 
		x=y;
	}
	while(m--){
		scanf("%d",&op);
		if(op==1){//区间修改 
			scanf("%d%d%d",&l,&r,&k);
			add(l,k);
			add(r+1,-k);
		}
		else{//查询单点 
			scanf("%d",&k);
			printf("%d\n",query(k));
		}
	}	
} 
