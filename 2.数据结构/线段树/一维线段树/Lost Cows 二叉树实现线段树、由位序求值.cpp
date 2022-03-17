/*
https://www.nitacm.com/problem_show.php?pid=7541
寻找ans要从n开始逆序寻找，pre[i]+1便是ans[i]在 由小到大数列中的位序 
从根结点开始，将要找数的位序与左子树和右子树的长度比较，小于左子树就在左子树上，
否则在右子树上，在右子树时还要将位序减去左子树的长度 
每过一个结点，都将结点的长度减一，相当于ans[i]取过，与ans[i]相关的tree[i]长度都要减1
重点：所求值为当前区间中左起第num个元素  
*/
#include<stdio.h>
using namespace std;
const int maxn=10000;
struct node{
	int l,r,len;//用len储存区间的数字个数 
}tree[4*maxn];//这里是4倍，是因为线段树的空间需要 
int pre[maxn],ans[maxn];
//建树 
void buildtree(int left,int right,int u)
{
	tree[u].l=left;
	tree[u].r=right;
	tree[u].len=right-left+1;//更新结点u的值 
	if(left==right) return;//递归到叶结点结束 
	buildtree(left,(left+right)>>1,u<<1);//递归左子树 
	buildtree(((left+right)>>1)+1,right,(u<<1)+1);//递归右子树，	
}//注意+的优先级高于左移、右移，括号不能省
//查询+维护，对访问到的区间维护len,即把这个结点的len减1 
int query(int u,int num)
{
	tree[u].len--;
	if(tree[u].l==tree[u].r) return tree[u].l;
	//情况1：左子区间内的牛数量不够，则从右子树查询不够的部分 
	if(tree[u<<1].len<num) 
		return query((u<<1)+1,num-tree[u<<1].len);
	//情况2：左子区间内的牛数量不够，继续查询左子区间 
	if(tree[u<<1].len>=num)
		return query(u<<1,num);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	pre[1]=0;
	for(int i=2;i<=n;i++) scanf("%d",&pre[i]);
	buildtree(1,n,1);
	for(int i=n;i>=1;i--)//从后往前推断出每次最后一个数字 
		ans[i]=query(1,pre[i]+1);//比ans[i]小的数有pre[i]个,则ans[i]是第pre[i]+1小的数，寻找第k小值 
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;	
} 
