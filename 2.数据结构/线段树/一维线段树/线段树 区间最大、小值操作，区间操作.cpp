//最假女歌手 
/*
本题亮点：
	同时两个最值操作 
		就会有最值、次值、最值个数、最值的修改值 6个变量 
		当只有1、2种数的时候，变量会相同，即数域的重叠，在修改的时候要考虑 
	同时有最值操作和求和操作	 
		最值操作只会改变一些"最值"，但求和操作会改变整个区间
		为了区分，创立了三个标记：最小值、最大值标记、其他值标记 
*/
#include <cassert>
#include <cstdio>
#include <cctype>
#include <algorithm>
#define L (o<<1)
#define R (o<<1|1)
using namespace std;
typedef long long ll;
const int MAXN=550000;
const int INF=1E9;
int a[MAXN];

int read()
{
	int x=0, w=0; char ch=0;
	while (!isdigit(ch)) w|=ch=='-', ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return w?-x:x;
}
											//		小		大	
struct Node									//	   mn1		mx1	最值	
{											//	   mn2		mx2	次值 
	int l, r;								//	   cmn		cmx	最值个数	
	int mn1, mn2, cmn, mx1, mx2, cmx;  		//	   k1 		k2  最值修改值     k3  其他值修改
	ll sum;																						
	int add1, add2, add3;// add1, add2, add3 分别表示最小值、最大值和其他值的加减标记。
} tr[4*MAXN];
//区间合并 
void pushup(int o)//更新总和、最值、次值、最值个数 
{
	tr[o].sum=tr[L].sum+tr[R].sum;
	if (tr[L].mn1==tr[R].mn1){//最小值比较 
		tr[o].mn1=tr[L].mn1;	//更新最小值 
		tr[o].mn2=min(tr[L].mn2, tr[R].mn2);//更新次小值 
		tr[o].cmn=tr[L].cmn+tr[R].cmn;	//更新最小值个数 
	}
	else if (tr[L].mn1<tr[R].mn1){
		tr[o].mn1=tr[L].mn1;
		tr[o].mn2=min(tr[L].mn2, tr[R].mn1);
		tr[o].cmn=tr[L].cmn;
	}
	else{
		tr[o].mn1=tr[R].mn1;
		tr[o].mn2=min(tr[L].mn1, tr[R].mn2);
		tr[o].cmn=tr[R].cmn;
	}
	if (tr[L].mx1==tr[R].mx1){//最大值比较 
		tr[o].mx1=tr[L].mx1;	//更新最大值 
		tr[o].mx2=max(tr[L].mx2, tr[R].mx2);	//更新次大值 
		tr[o].cmx=tr[L].cmx+tr[R].cmx;//	更新最大值个数 
	}
	else if (tr[L].mx1>tr[R].mx1){
		tr[o].mx1=tr[L].mx1;
		tr[o].mx2=max(tr[L].mx2, tr[R].mx1);
		tr[o].cmx=tr[L].cmx;
	}
	else{
		tr[o].mx1=tr[R].mx1;
		tr[o].mx2=max(tr[L].mx1, tr[R].mx2);
		tr[o].cmx=tr[R].cmx;
	}
}
//更新结点 			最小	最大	其他 
void update(int o, int k1, int k2, int k3)// 作用标记并合并标记，一定要注意顺序
{
	//更新sum 
	if (tr[o].mn1==tr[o].mx1){// 只有一种值时，最大值等于最小值
		if (k1==k3) k1=k2; // 不应被其他值的标记作用
		else k2=k1;
		tr[o].sum+=1ll*k1*tr[o].cmn; 
	}
	else tr[o].sum+=1ll*k1*tr[o].cmn+1ll*k2*tr[o].cmx
	    +1ll*k3*(tr[o].r-tr[o].l+1-tr[o].cmn-tr[o].cmx);
	//处理数域重叠的问题：先对次小值处理    
	if (tr[o].mn2==tr[o].mx1) tr[o].mn2+=k2;// 次小值等于最大值，只有两种数，应该被最大值标记作用
	else if (tr[o].mn2!=INF) tr[o].mn2+=k3;// 否则应该被其他值标记作用
	// 对次大值同理
	if (tr[o].mx2==tr[o].mn1) tr[o].mx2+=k1;//次大值等于最小值 
	else if (tr[o].mx2!=-INF) tr[o].mx2+=k3;
	tr[o].mn1+=k1, tr[o].mx1+=k2;//处理最值 
	tr[o].add1+=k1, tr[o].add2+=k2, tr[o].add3+=k3;//处理过就打上标记 
}
// 下传标记
void pushdown(int o)
{
	int mn=min(tr[L].mn1, tr[R].mn1);// 找出最大值和最小值
	int mx=max(tr[L].mx1, tr[R].mx1);
	// 下传标记到左子树，若左子树中有最值则下传最值标记，否则下传其他值标记
	update(L, tr[L].mn1==mn?tr[o].add1:tr[o].add3,
	    tr[L].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
	// 右子树同理
	update(R, tr[R].mn1==mn?tr[o].add1:tr[o].add3,
	    tr[R].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
	tr[o].add1=tr[o].add2=tr[o].add3=0;
}
//建树 
void build(int o, int l, int r, int* a)
{
	tr[o].l=l, tr[o].r=r;
	tr[o].add1=tr[o].add2=tr[o].add3=0;//加法标志赋为0 
	if (l==r){
		tr[o].sum=tr[o].mn1=tr[o].mx1=a[l]; //最小值，最大值赋值 
		tr[o].mn2=INF, tr[o].mx2=-INF;//次小值初始化为最大值，次大值标记初始化为最小值 
		tr[o].cmn=tr[o].cmx=1;//最值个数 
		return;
	}
	int mid=l+r>>1;
	build(L, l, mid, a);
	build(R, mid+1, r, a);
	pushup(o);//区间合并 
}
//区间加k 
void modify1(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l) return;
	if (l<=tr[o].l&&tr[o].r<=r){ 
		update(o, k, k, k);//最大、最小、其他数都加k 
		return; 
	}
	pushdown(o);//下传标记 
	modify1(L, l, r, k), modify1(R, l, r, k);
	pushup(o);//区间合并 
}
//区间最大值修改
void modify2(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l||k<=tr[o].mn1) return;
	if (l<=tr[o].l&&tr[o].r<=r&&k<tr[o].mn2){ //最小值小于k,修改与最小值有关变量 
		update(o, k-tr[o].mn1, 0, 0);//最小值和sum加上这个k-tr[o].mn1，传入表达式，既修改的最小值又方便求和 
		return; 
	}
	pushdown(o);
	modify2(L, l, r, k), modify2(R, l, r, k);
	pushup(o);
}
//区间最小值修改 
void modify3(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l||k>=tr[o].mx1) return;
	if (l<=tr[o].l&&tr[o].r<=r&&k>tr[o].mx2){ //最大值大于k 
		update(o, 0, k-tr[o].mx1, 0); //最小值和sum加上这个k-tr[o].mx1
		return; 
	}
	pushdown(o);
	modify3(L, l, r, k), modify3(R, l, r, k);
	pushup(o);
}
//区间求和 
ll query4(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return 0;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
	pushdown(o);
	return query4(L, l, r)+query4(R, l, r);
}
//区间求最大值 
int query5(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return -INF;//注意这里的原数组中的数可以为负数，不能返回0 
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx1;
	pushdown(o);
	return max(query5(L, l, r), query5(R, l, r));
}
//区间求最小值 
int query6(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return INF;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mn1;
	pushdown(o);
	return min(query6(L, l, r), query6(R, l, r));
}

int main()
{
	int n, m;
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	build(1, 1, n, a);
	m=read();
	while (m--){
		int op=read(), l, r, k;
		switch (op){
			case 1://区间加k 
				l=read(), r=read(), k=read();
				modify1(1, l, r, k);
				break;
			case 2://把一个区间[L,R] 里小于k 的数变成k  
				l=read(), r=read(), k=read();
				modify2(1, l, r, k);
				break;
			case 3://把一个区间[L,R] 里大于k的数变成k
				l=read(), r=read(), k=read();
				modify3(1, l, r, k);
				break;
			case 4://求和 
				l=read(), r=read();
				printf("%lld\n", query4(1, l, r));
				break;
			case 5://求最大值 
				l=read(), r=read();
				printf("%d\n", query5(1, l, r));
				break;
			case 6://求最小值 
				l=read(), r=read();
				printf("%d\n", query6(1, l, r));
				break;
		}
	}
	return 0;
}
