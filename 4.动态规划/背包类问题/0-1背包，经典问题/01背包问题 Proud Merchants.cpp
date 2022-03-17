题意： 
n件商品，m钱，每件商品只能买一件，每件商品都有价格p,购买要求q,估价(对于自己的价值)v
必须所拥有的钱>=q时才能购买该商品，问最多价值,这里q>=p 
重点：购买要求
假如两个商品a: p1 q1 ;b:p2 q2 都要买 
	先a后b需要p1+q2 
	先b后a需要p2+q1
	先a后b时花钱最少应有p1+q2>=p2+q1  ,得到q1-p1>=q2-p2  所以q-p最大的先买 
因为dp过程中，dp[1][n]先将第一件物品考虑完，dp[2][n]在第一件物品的情况下考虑第二件物品，所以第二件
物品会更新第一种物品，但第一种物品不会更新第二种物品，相当于先购买第二种物品再购买第一种物品，第二
种物品的购买与否会影响第一种物品的购买


#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int f[5005];
struct node{
	int p,q,v;
}goods[maxn];
bool cmp(node a,node b)
{
    return a.q-a.p < b.q-b.p;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&goods[i].p,&goods[i].q,&goods[i].v);
		}
		sort(goods+1,goods+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=goods[i].q;j--){	
				f[j]=max(f[j],f[j-goods[i].p]+goods[i].v);
			}
		}
		printf("%d\n",f[m]);
	}
}
