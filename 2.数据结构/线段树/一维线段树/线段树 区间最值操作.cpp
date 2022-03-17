//Gorgeous Sequence
/*
变量类型的亏，吃了还想吃
本题亮点：
	本题为求区间最值和区间修改min(a[i],k),故需要
	ma为最大值，se为次大值，cnt为最大值个数，f为最值懒标记，区间最值修改过就加上标记，用于标记下传 
 	对要修改的k值有三种情况：
		k>ma	不用修改，退出 
		ma>k>se	只用修改最值，利用cnt求sum 
		se>=k 	寻找子结点，即便k=se，但无法修改后无法求和也不要 
	状态合并的式子太多了所以写了个函数，难点就是式子太长，容易写错，对于求和的式子也不能忘了用ll 
*/	 
#include<bits/stdc++.h>
using namespace std;
#define L (k<<1)
#define R (k<<1|1)
typedef long long ll;
const int maxn=1100000;
struct node{
	int l,r,ma,se,cnt;
	int f;	//f为区间最大值标记，记录修改之前的最大值 
	ll sum;
}tree[maxn*4];

int read()
{
	int x=0; char ch=0;
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return x;
}
//标记下传 
inline void down(int k)//利用最大值标记，修改儿子结点的最值、和、标记 
{
	if(~tree[k].f){//打上最值标记的结点，说明最值修改过，找到待修改的子结点 
		if(tree[L].ma>tree[k].f){//判断父节点的最大值是哪个儿子的 
			tree[L].sum+=tree[L].cnt*(1ll*tree[k].f-tree[L].ma);//涉及大数相乘 
			tree[L].ma=tree[L].f=tree[k].f;
		}
		if(tree[R].ma>tree[k].f){
			tree[R].sum+=tree[R].cnt*(1ll*tree[k].f-tree[R].ma);
			tree[R].ma=tree[R].f=tree[k].f;
		}
		tree[k].f=-1;//清空标记		
	} 
}
//状态合并 
void combine(int k)//利用儿子结点，修改父亲结点的和、最值、次大值、最值个数、 
{
	tree[k].sum=tree[L].sum+tree[R].sum;
	if (tree[L].ma==tree[R].ma){	//左右结点最值相同时 
		tree[k].ma=tree[L].ma;
		tree[k].se=max(tree[L].se, tree[R].se);
		tree[k].cnt=tree[L].cnt+tree[R].cnt;
	} 
	else if (tree[L].ma>tree[R].ma){	//左结点最值大 
		tree[k].ma=tree[L].ma;
		tree[k].se=max(tree[L].se, tree[R].ma);//比较的是左结点的次大值和右结点的最大值 
		tree[k].cnt=tree[L].cnt;
	}
	else{//	右结点最值大 
		tree[k].ma=tree[R].ma;
		tree[k].se=max(tree[L].ma, tree[R].se);
		tree[k].cnt=tree[R].cnt;
	}
}

void build(int l,int r,int k)
{
	tree[k].l=l;tree[k].r=r;tree[k].f=-1;
	if(l==r){
		tree[k].sum=read();
		tree[k].ma=tree[k].sum;
		tree[k].se=-1;//最小数也是0，故次大值赋为-1 
		tree[k].cnt=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,L);
	build(mid+1,r,R);
	combine(k); 
}
//最值修改操作、min(max,k)
void modify(int k,int l,int r,int dat)
{
	if(tree[k].l>r||tree[k].r<l||tree[k].ma<=dat) return;// 情况 1:k大于最大值或者出界，不用修改 
	if(tree[k].l>=l&&tree[k].r<=r&&tree[k].se<dat){// 情况 2：k在最大值和次大值之间
		tree[k].sum+=tree[k].cnt*(1ll*dat-tree[k].ma);//涉及乘法，不取ll型会答案错误 
		tree[k].ma=tree[k].f=dat;	//修改最值标记 
		return;
	}
	//情况 3：k小于等于次大值，需要在左右子结点中继续寻找 
	down(k);//从上到下 
	modify(L,l,r,dat);modify(R,l,r,dat);
	combine(k);//从下到上 
}
//求区间最大值 
int getmax(int l,int r,int k)//利用递归求值 
{
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r) return tree[k].ma;
	down(k);
	return max(getmax(l,r,L),getmax(l,r,R));
}
//区间求和 
ll getsum(int l,int r,int k)
{
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r) return tree[k].sum;
	down(k);
	return getsum(l,r,L)+getsum(l,r,R);
}

int main()
{
	int t,n,m,l,r,k,op,dat;
	t=read();
	while(t--){
		n=read();m=read();
		build(1,n,1);
		while(m--){
			op=read();
			if(op==0){
				l=read();r=read();dat=read();
				modify(1,l,r,dat);
			}
			else if(op==1){
				l=read();r=read();	
				printf("%d\n",getmax(l,r,1));
			}
			else{
				l=read();r=read();	
				printf("%lld\n",getsum(l,r,1));//输出必须为ll型 
			}
		}
	}
}

