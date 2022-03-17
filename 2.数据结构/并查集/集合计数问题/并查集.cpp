//并查集，在一些有N个元素的集合应用问题中，我们通常是在开始时让每个元素构成一个单元素的集合，
//然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个元素在哪个集合中。
//并查集是一种树型的数据结构，用于处理一些不相交集合（disjoint sets）的合并及查询问题。 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1050;
int s[maxn+1];//s[i]对于第i个人处于第s[i]个集合内
int height[maxn];//储存每个集合树的高度，即集合中含的数最多的个数，初始都是零 
//初始化 
void initset(int num)//初始每个人对应一个集合
{
	for(int i=1;i<=num;i++){
		s[i]=i;
		height[i]=0;//重置为0 
	}
}
 
//查找
/* 
int findset(int x)//查找x身处的集合,即查找x的根节点
{
	return x==s[x]?x:findset(s[x]);
}

int findset(int x)//优化：查找一次就修改所有节点。路径压缩递归版，但是递归调用过多会爆栈 
{
	if(x!=s[x]) s[x]=findset(s[x]);//用递归，调用一次直接把集合内的所有结点全都指向根节点 
	return s[x];
}
*/
int findset(int x)//优化：路径压缩 
{
	int r=x;
	while(s[r]!=r) r=s[r];//找到根结点 
	int i=x,temp;	//把集合内的所有结点全都指向根节点 
	while(i!=r){	//循环出口为从x节点到根节点 
		temp=s[i];	//保存节点元素因为s[i]是下一个节点元素 
		s[i]=r;
		i=temp;
	}
	return r; 
} 
//合并 
void unionset(int x,int y)//让x存入y所在的集合s[y]。此时x不等于s[x],即x不在第s[x]个集合内了 
{
	x=findset(x);//先找到x所在的大集合 
	y=findset(y);//找y
	if(height[x]==height[y]){//两棵树一样高，y树并到x数上，x树高度加一 
		height[x]+=1;	
		s[y]=x;//这里x==s[x],y==s[y],把两个数都统一存入左边数的集合内。
	} 
	else{//把低树并到高树上，避免树的高度增加，此时树的高度不会变 
		if(height[x]<height[y]) s[x]=y;//x树低 
		else s[y]=x;//y树低 
	}	
}

int main()
{
	int t,x,y,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		initset(n);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			unionset(x,y);
		} 
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]==i) ans++;//统计树的个数 
		printf("%d\n",ans);
	}
} 
