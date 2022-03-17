/*
https://www.nitacm.com/problem_show.php?pid=7541
在满二叉树的最后一行前n个都设为1，不断往上推个结点都为两子结点之和，表示长度 
对于ans[i]为当前区间中左起第num个元素，如果左区间长度>num，表示数在左边，否则在右边 
*/
#include<stdio.h>
#include<cmath> 
using namespace std;
const int maxn=10000;
int pre[maxn],ans[maxn],tree[4*maxn];
//tree是用数组实现的慢二叉树，需要4倍大的空间 

void buildtree(int n,int last_left)
{
	int i;
	for(i=last_left;i<last_left+n;i++) 
		tree[i]=1;	//先给二叉树的最后一行赋1，左边n个结点就是n个牛 
	while(last_left!=1){
		for(int i=last_left/2;i<last_left;i++)
			tree[i]=tree[i*2]+tree[i*2+1];
		last_left=last_left/2;
	}
}
//查询+维护，所求值为当前区间中左起第num个元素 
int query(int u,int num,int last_left)
{
	tree[u]--;//对访问到的区间维护剩下的牛的数量 
	if(tree[u]==0&&u>=last_left) return u;
	//左子区间数字个数不够 
	if(tree[u<<1]<num)
		return query((u<<1)+1,num-tree[u<<1],last_left);
	//左子区间数字个数够 
	else
		return query(u<<1,num,last_left);
}
int main()
{
	int n,last_left;
	scanf("%d",&n);
	last_left=1<<(int(log(n)/log(2))+1);//加1是因为11<<(int(log(n)/log(2)))这一层装不下 
	//二叉树最后一行的最左边一个，计算方法是找离n最近的2的指数 
	buildtree(n,last_left);
	for(int i=2;i<=n;i++) scanf("%d",&pre[i]);
	for(int i=n;i>=1;i--)//从后往前推断每一个数 
		ans[i]=query(1,pre[i]+1,last_left)-last_left+1;//这里不要忘了减 
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
