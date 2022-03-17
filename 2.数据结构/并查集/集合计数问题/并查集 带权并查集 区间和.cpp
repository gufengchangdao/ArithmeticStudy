//How Many Answers Are Wrong
/*
题意：1~n的区间，m个已知区间和，但是由前面的区间和推出的区间和可能和后面给出的该区间的和不同，求错
	误的区间和有多少
	带权并查集:每个结点到根结点有权值，在这里就是区间和 
	产生矛盾的前提是能够用已给的区间和求出的区间和与现在给的区间和矛盾，把最大的n作为根结点，则只
		要l和r的根节点相同，便可以求出
	注意：题中给的是[l,r]这个区间的区间和，是闭区间，包括第l和第r个数，不能画图，我们转化为(l-1,r] 
		sum[l-1]就是[l,r]的区间和，l-1到r这条边的边权值 
		  sum[x] 				sum[xx]=-sum[x]+cal+sum[y]
		x----->xx
	val	| 	   |  sum[xx]
		y----->yy
		 sum[y]
*/
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=200005;
int s[maxn],sum[maxn];//sum[i]是从i出发，到跟结点的所有边的边权值之和，类似前缀和 
int ans;

int findset(int x)
{
	if(x!=s[x]){
		int tem=s[x];
		s[x]=findset(s[x]);
		sum[x]+=sum[tem];//递归求由根结点开始的前缀和，tem就是x的父节点 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy)//两结点的根结点相同，可以推出(x,y]的区间和了 
		if((sum[x]-sum[y])!=val) ans++;
	else{	//根结点不同，不能推出，接受给的区间和 
		s[xx]=yy;
		sum[xx]=-sum[x]+val+sum[y];//求出xx到yy的边权值
	}//我们规定只要s[i]连接到根结点，就要更新sum[i],因为就算在findset里面由于x==s[x]而不会更新sum 
}

int main()
{
	int m,n,l,r,val;
	while(~scanf("%d%d",&n,&m)){
		ans=0;
		memset(sum,0,sizeof(sum));
		for(int i=0;i<=n;i++) s[i]=i;//意从0开始 
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&l,&r,&val);//题目中给的l是严格小于等于r 
			unionset(l-1,r,val);//注意是l-1	
		}
		printf("%d\n",ans);
		
	}
	
}
 
