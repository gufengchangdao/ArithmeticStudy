//色板游戏 
/*
题意:len长度的画板，n种颜色，op个操作
		两种操作：P区间覆盖为cal，C查询区间有多少种颜色
可以用珂朵莉树，简单得很
用线段树做的话，如何让每个节点记录颜色的种类呢？状态压缩 
	由于n<=30,故可用状态压缩的线段树，用二进制的1表示存在这种颜色，0表示没有这种颜色，用上 | 运算符 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
#define ri register int
#define L (o<<1)
#define R (o<<1|1)
#define ll long long
const int maxn=100005;

struct node{
	int l,r;
	ll v;
	int tag;	//颜色懒标记(区间覆盖标记) 
}tr[maxn<<2];
//状态合并 
void pushup(int o)
{
	tr[o].v=tr[L].v|tr[R].v;//左边颜色种类并上右边颜色种类 
}
//更新数据 
void update(int o,int l,int r,int cal)
{
	tr[o].tag=cal;
	tr[o].v=(1<<(cal-1));	//v为右边第cal位是1的数 
}
//标记下传 
void down(int o)
{
	if(tr[o].tag==-1) return;
	tr[L].tag=tr[o].tag; tr[R].tag=tr[o].tag;
	tr[L].v=(1<<(tr[o].tag-1)); tr[R].v=(1<<(tr[o].tag-1));
	tr[o].tag=-1;
}

void build(int o,int l,int r)
{
	
	tr[o].v=1;tr[o].tag=-1;tr[o].l=l;tr[o].r=r;//初始的时候所有区间颜色都为1 ，标记赋为0也可以 
	if(l==r) return;
	int mid=(l+r)>>1;
	build(L,l,mid);
	build(R,mid+1,r);
}
//区间覆盖 
void modify(int o,int l,int r,int cal)
{
//printf("%d %d %d\n",tr[o].l,tr[o].r,tr[o].v);
	if(tr[o].l>r||tr[o].r<l) return;
	if(tr[o].l>=l&&tr[o].r<=r){
		update(o,tr[o].l,tr[o].r,cal);
		return;
	}
	down(o);
	modify(L,l,r,cal);//注意：l,r是要查询的区间范围，不要动 
	modify(R,l,r,cal);
	pushup(o);
}

ll query(int o,int l,int r)
{
//printf("%d %d %d\n",tr[o].l,tr[o].r,tr[o].v);
	if(tr[o].l>r||tr[o].r<l) return 0;//0不会影响其他数，返回0即可 
	if(tr[o].l>=l&&tr[o].r<=r) return tr[o].v;
	down(o);
	return query(L,l,r)|query(R,l,r);
}

int main()
{
	int len,n,op,l,r,cal;
	char k;
	scanf("%d%d%d",&len,&n,&op);
	build(1,1,len);

	while(op--){
		scanf(" %c",&k);
		if(k=='C'){//区间覆盖操作 
			scanf("%d%d%d",&l,&r,&cal);
			if(l>r) swap(l,r);//这题有l>r的可能，没有这个会运行错误 
			modify(1,l,r,cal);
		}
		else{//区间查询操作 
			scanf("%d%d",&l,&r);
			if(l>r) swap(l,r);
			ll sum=query(1,l,r);
			int ans=0;
			for(int i=0;i<n;i++)	//统计颜色种类的关键步骤,i取[0,n) 
				if(sum&(1<<i)) ans++;
			printf("%d\n",ans);
		}
	}
} 
