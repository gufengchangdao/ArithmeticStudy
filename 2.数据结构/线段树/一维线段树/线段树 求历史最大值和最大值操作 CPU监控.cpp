#include <cstdio>
#include <climits>
#include <algorithm>
#define lc (o<<1)
#define rc (o<<1|1)
using namespace std;
const int MAXN=110000;
int a[MAXN];
struct Node
{
	int l, r; 
	bool tag;	//tag表示有没有区间覆盖标记,有了这个就可以代替cov初始化了，否则cov就得初始化为覆盖取不到的值了 
	int mx, add, cov;	//二元组(add,cov) 
	int mx_, add_, cov_;	//历史最大区间覆盖cov_是为了应对区间多次覆盖的情况 
} tr[4*MAXN];
//状态合并 
void pushup(int o)
{
	tr[o].mx=max(tr[lc].mx, tr[rc].mx);
	tr[o].mx_=max(tr[lc].mx_, tr[rc].mx_);
}
//更新数据 
void update(int o, int k, int k_)
{
	// 更新历史最大值和当前最大值，这里要注意顺序,因为历史最值和当前最值与当前历史最大加减标记之和得到的最大值比较的 
	tr[o].mx_=max(tr[o].mx_, tr[o].mx+k_);
	tr[o].mx+=k;
	if (!tr[o].tag){// 如果没有区间覆盖标记，正常更新 add 标记
		tr[o].add_=max(tr[o].add_, tr[o].add+k_);
		tr[o].add+=k;
	}
	else{  // 有区间覆盖标记的把父结点的加法标记加到区间覆盖标记上 
		tr[o].cov_=max(tr[o].cov_, tr[o].cov+k_);
		tr[o].cov+=k; 
	}
}
 // 区间覆盖
void cover(int o, int k, int k_)//区间覆盖标记 
{
	tr[o].mx_=max(tr[o].mx_, k_);
	tr[o].mx=k;
	tr[o].cov_=max(tr[o].cov_, k_);//相当于赋初值 
	tr[o].cov=k;
	tr[o].tag=1;//打上标记，表示该区间已进行区间覆盖过，把区间覆盖传给儿子结点 
}
//下传标记 
void pushdown(int o)
{
	if (tr[o].add){
		update(lc, tr[o].add, tr[o].add_);//下传左儿子标记 
		update(rc, tr[o].add, tr[o].add_);
		tr[o].add=tr[o].add_=0;
	}
	if (tr[o].tag){// 这里的 tag 表示当前节点有没有区间覆盖标记
		cover(lc, tr[o].cov, tr[o].cov_);
		cover(rc, tr[o].cov, tr[o].cov_);
		tr[o].tag=0;
		tr[o].cov_=INT_MIN;//有tag=0，cov不用初始化，
	//	但是历史最大覆盖值要初始化，不能让下一次区间覆盖继承这个结果，不过去掉这一步好像也是对的 
	}
}

void build(int o, int l, int r, int* a)
{
	tr[o].l=l, tr[o].r=r;
	tr[o].add=tr[o].add_=tr[o].tag=0;//标记初始化 
	tr[o].cov_=INT_MIN;	//标记初始化为最小值，与次大值初始化为最小值同理 
	if (l==r){ 
		tr[o].mx=tr[o].mx_=a[l]; 
		return; 
	}
	int mid=l+r>>1;
	build(lc, l, mid, a);
	build(rc, mid+1, r, a);
	pushup(o);
}
//求[x,y]的最大值 
int queryQ(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return INT_MIN;//出界就返回最小值 
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
	pushdown(o);
	return max(queryQ(lc, l, r), queryQ(rc, l, r));
}
//求区间历史最大值 
int queryA(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return INT_MIN;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx_;
	pushdown(o);
	return max(queryA(lc, l, r), queryA(rc, l, r));
}
//区间加法：[l,r]+k 
void updateP(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l) return;
	if (l<=tr[o].l&&tr[o].r<=r){
	 	update(o, k, k); 
		 return; 
	}
	pushdown(o);
	updateP(lc, l, r, k), updateP(rc, l, r, k);
	pushup(o);
}
//区间覆盖：[l,r]=k 
void updateC(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l) return;
	if (l<=tr[o].l&&tr[o].r<=r){ 
		cover(o, k, k); 
		return; 
	}
	pushdown(o);
	updateC(lc, l, r, k), updateC(rc, l, r, k);
	pushup(o);
}

int main()
{
	int n, q;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	build(1, 1, n, a);
	scanf("%d", &q);
	while (q--){
		char op[2]; int x, y, z;
		scanf("%s", op);//这里就读取一个字符，用数组存，%s读取就不用管换行符了 
		switch (op[0]){ 
			case 'Q':	//求[x,y]的最大值 
				scanf("%d%d", &x, &y);
				printf("%d\n", queryQ(1, x, y));
				break;
			case 'A':
				scanf("%d%d", &x, &y);
				printf("%d\n", queryA(1, x, y));
				break;
			case 'P':
				scanf("%d%d%d", &x, &y, &z);
				updateP(1, x, y, z);
				break;
			case 'C':
				scanf("%d%d%d", &x, &y, &z);
				updateC(1, x, y, z);
				break;
		}
	}
	return 0;
}
/*
关键点 
操作有 求区间最大值、求区间历史最大值
	   区间加k、区间覆盖 
两个询问：求区间最大值、区间历史最大值->mx、mx_ 
两个操作：区间加k、区间覆盖->引入二元组(add,cov)，对区间值加上add,再变成cov 
	区间加k：(add+k,cov)	变add、add_即可
	区间覆盖：(add,cov+k) tag标记上，变cov、cov_即可  

对最值和历史区间最值的更新有先后顺序 
	先历史区间最值：与当前最值加上当前历史最大标记后的值比大小 
	再最值
父结点标记使用后都要初始化，包括tag和cov_，cov不用，因为有tag的判断，但是cov_要初始化，因为不能
	让下一次区间覆盖继承这个历史最大的结果
*/
