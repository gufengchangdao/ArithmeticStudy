/*
P6242 【模板】线段树 3
操作中含有求历史最大值的情况：
	增加历史最大加减标记和其他历史最大加减标记
	“历史最大加减标记”，它表示的是从上一次下传 add 到现在，区间加标记达到的最大值
	历史标记的作用：
		当父结点最大值变小时，在更新操作中传入的k1是负值，使得标记值减小，无法判断取历史最大值时
		使用哪个阶段的标记，在下传标记的时候使用历史标记即不断更新的标记中值最大的那个标记 
	考虑历史最值标记的合并。
	当下传标记时，儿子历史最值=max(儿子历史最值,儿子当前最值+儿子的历史最大加减标记) 
	状态合并时，  历史最值=max(历史最值,当前最值+历史最大加减标记)  
*/

#include <cstdio>
#include <cctype>
#include <algorithm>
#define L (o<<1)
#define R (o<<1|1)
using namespace std;
typedef long long ll;
const int MAXN=550000;
const int INF=2E9+233;
int a[MAXN];
int read()
{
	int x=0, w=0; char ch=0;
	while (!isdigit(ch)) w|=ch=='-', ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return w?-x:x;
}
struct Node{
	int l, r;
	int mx, mx_, se, cnt; 
	ll sum;
	int add1, add1_, add2, add2_; //最大值标记，历史最大加减标记，其他标记，其他历史最大加减标记 
} tr[4*MAXN];
//状态合并 ,除了懒标记和l、r，其他的都更新 
void pushup(int o)
{
	tr[o].sum=tr[L].sum+tr[R].sum;
	tr[o].mx_=max(tr[L].mx_, tr[R].mx_);//更新历史最大值 
	if (tr[L].mx==tr[R].mx){	
		tr[o].mx=tr[L].mx;
		tr[o].se=max(tr[L].se, tr[R].se);
		tr[o].cnt=tr[L].cnt+tr[R].cnt;
	}
	else if (tr[L].mx>tr[R].mx){
		tr[o].mx=tr[L].mx;
		tr[o].se=max(tr[L].se, tr[R].mx);
		tr[o].cnt=tr[L].cnt;
	}
	else{
		tr[o].mx=tr[R].mx;
		tr[o].se=max(tr[L].mx, tr[R].se);
		tr[o].cnt=tr[R].cnt;
	}
}
//更新数据 ，除了最大值个数和l、r其他的都更新 
void update(int o, int k1, int k1_, int k2, int k2_)
{
	tr[o].sum+=1ll*k1*tr[o].cnt+1ll*k2*(tr[o].r-tr[o].l+1-tr[o].cnt);
	tr[o].mx_=max(tr[o].mx_, tr[o].mx+k1_);//更新历史最大值 
	tr[o].mx+=k1; 
	tr[o].add1_=max(tr[o].add1_, tr[o].add1+k1_);//更新历史最大值标记 
	tr[o].add1+=k1;
	tr[o].add2_=max(tr[o].add2_, tr[o].add2+k2_);
	tr[o].add2+=k2;
	if (tr[o].se!=-INF) tr[o].se+=k2;//更新次大值的时候要先判断一下是否存在次大值
}
//标记下传 
void pushdown(int o)
{
	int tmp=max(tr[L].mx, tr[R].mx);
	if (tr[L].mx==tmp)//判断最大值是否来自左子树 
		update(L, tr[o].add1, tr[o].add1_, tr[o].add2, tr[o].add2_);
	else update(L, tr[o].add2, tr[o].add2_, tr[o].add2, tr[o].add2_);
//其他历史最大加减标记作用，当最值不是来自左子树的时候，维护左子树的历史最大值就要用到其他历史最大值了	 
	if (tr[R].mx==tmp)//判断最大值是否来自右子树 
		update(R, tr[o].add1, tr[o].add1_, tr[o].add2, tr[o].add2_);
	else update(R, tr[o].add2, tr[o].add2_, tr[o].add2, tr[o].add2_);
	tr[o].add1=tr[o].add1_=tr[o].add2=tr[o].add2_=0;
}

void build(int o, int l, int r, int* a)
{
	tr[o].l=l, tr[o].r=r;
	tr[o].add1=tr[o].add1_=tr[o].add2=tr[o].add2_=0;
	if (l==r){
		tr[o].sum=tr[o].mx_=tr[o].mx=a[l];
		tr[o].se=-INF, tr[o].cnt=1;
		return;
	}
	int mid=l+r>>1;
	build(L, l, mid, a);
	build(R, mid+1, r, a);
	pushup(o);
}
//区间加k 
void modify1(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l) return;
	if (l<=tr[o].l&&tr[o].r<=r){ 
		update(o, k, k, k, k); 
		return; 
	}
	pushdown(o);
	modify1(L, l, r, k), modify1(R, l, r, k);
	pushup(o);
}
//a[i]=min(a[i],k) 
void modify2(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l||k>=tr[o].mx) return;
	if (l<=tr[o].l&&tr[o].r<=r&&k>tr[o].se){ 
		update(o, k-tr[o].mx, k-tr[o].mx, 0, 0); 
		return; 
	}
	pushdown(o);
	modify2(L, l, r, k), modify2(R, l, r, k);
	pushup(o);
}
//求和 
ll query3(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return 0;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
	pushdown(o);
	return query3(L, l, r)+query3(R, l, r);
}
//求最大值 
int query4(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return -INF;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
	pushdown(o);
	return max(query4(L, l, r), query4(R, l, r));
}
//求历史最大值 
int query5(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return -INF;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx_;
	pushdown(o);
	return max(query5(L, l, r), query5(R, l, r));
}

int main()
{
	int n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	build(1, 1, n, a);
	while (m--){
		int op=read(), l, r, k;
		switch (op){
			case 1://区间加k 
				l=read(), r=read(), k=read();
				modify1(1, l, r, k);
				break;
			case 2:	//a[i]=min(a[i],k) 
				l=read(), r=read(), k=read();
				modify2(1, l, r, k);
				break;
			case 3://求和 
				l=read(), r=read();
				printf("%lld\n", query3(1, l, r));
				break;
			case 4://求最大值 
				l=read(), r=read();
				printf("%d\n", query4(1, l, r));
				break;
			case 5://求历史最大值 
				l=read(), r=read();
				printf("%d\n", query5(1, l, r));
				break;
		}
	}
	return 0;
}
