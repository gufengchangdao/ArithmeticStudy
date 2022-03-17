/*
什么时候用珂朵莉树
	其他树都是主从关系，珂朵莉树是并列关系,他用set储存结点，用左边界l作为下标 
	推平一段区间，使一整段区间内的东西变得一样。保证数据随机。
该题操作： 
	区间加
	区间赋值
	区间第k小
	求区间幂次和
本题亮点：
	mutable
		mutable的中文意思是“可变的，易变的”，跟constant（既C++中的const）是反义词。
		被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中。
	用set储存结点，并且按照左边界l进行排序，利用lower_bound函数查找左边界	 
	分离区间操作，能将区间按自己所需断开
	利用迭代器遍历区间和利用大量数据结构，例如vector<pair...>用于排序后搜索第k大的数 
*/ 
#include<bits/stdc++.h>
#define IT set<node>::iterator
using namespace std;
typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int maxn = 1e5 + 7;
int n, m;
LL seed, vmax;
LL a[maxn];

struct node
{
	int l,r;
	mutable LL v; //该区间的值需要注意的是mutable，易变不定的。它对v的修饰，使得我们可以在add操作
				//	中修改v的值。没有它的修饰会在add函数里导致CE。 
	node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
	bool operator<(const node& o) const{
		return l < o.l;	//结点要在set中按照l排序和查找 
	}
};
//快速幂取模 
LL pow(LL a, LL b, LL mod)
{
	LL res = 1;
	LL ans = a % mod;
	while (b){
		if (b&1) res = res * ans % mod;
		ans = ans * ans % mod;
		b>>=1;
	}
	return res;
}
//分离操作：将原来含有pos位置的节点分成两部分：[l,pos-1]和[pos,r] 
set<node> s;//不用set，用数组和链表也可以 
IT split(int pos)//本题最关键的代码 
{
	IT it = s.lower_bound(node(pos));//找到首个l(左边界)不小于pos的节点
	if (it != s.end() && it->l == pos) return it;//如果存在pos左边界，表示无需断开 
	--it;//减1，往前找，此时it->l < pos <= it->r 
	int L = it->l, R = it->r;
	LL V = it->v;
	s.erase(it);//删除原来区间并分成两份 
	s.insert(node(L, pos-1, V));
	return s.insert(node(pos, R, V)).first;//存入set并返回后半段的迭代器
		//这里利用pair<iterator,bool> insert (const value_type& val)的返回值 
}
//区间修改 
void add(int l, int r, LL val)
{
	IT itr = split(r+1),itl = split(l);//各种操作前应该先split(r+1)后split(l)，不然会出错，不知道为啥 
	for (; itl != itr; ++itl) itl->v += val;
}
//推平操作，直接将[l,r]的值全变为val，减少map元素个数，没有他，将会T掉 
void assign(int l, int r, LL val)
{
	IT itr = split(r+1),itl = split(l); 
	s.erase(itl, itr);
	s.insert(node(l, r, val));
}
//输出[l,r]第k大的数 
LL ranks(int l, int r, int k)
{
	vector<pair<LL, int> > vp;
	vp.clear();
	IT itr = split(r+1),itl = split(l);	
	for (; itl != itr; ++itl)
		vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
	sort(vp.begin(), vp.end());
	for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it){
		k -= it->second;
		if (k <= 0) return it->first;
	}
	return -1;//没有第K大的数 
}
//输出[l,r]区间每个数字的x次方的和模y的值
LL sum(int l, int r, int ex, int mod)
{
	IT itr = split(r+1),itl = split(l); 
	LL res = 0;
	for (; itl != itr; ++itl)
		res = (res + (LL)(itl->r - itl->l + 1) * pow(itl->v, LL(ex), LL(mod))) % mod;
	return res;
}

LL rnd()
{
	LL ret = seed;
	seed = (seed * 7 + 13) % MOD7;
	return ret;
}

int main()
{
	cin>>n>>m>>seed>>vmax;
	for (int i=1; i<=n; ++i){
		a[i] = (rnd() % vmax) + 1;
		s.insert(node(i,i,a[i]));//初始化 
	}
	s.insert(node(n+1, n+1, 0));//分离操作中传入的r可能为n+1，故应该存在n+1 
	int lines = 0;
	for (int i =1; i <= m; ++i){
		int op = int(rnd() % 4) + 1;
		int l = int(rnd() % n) + 1;
		int r = int(rnd() % n) + 1;	
		if (l > r) 
			swap(l,r);
		int x, y;
		if (op == 3)
			x = int(rnd() % (r-l+1)) + 1;
		else
			x = int(rnd() % vmax) +1;
		if (op == 4)
			y = int(rnd() % vmax) + 1;
		//操作 
		if (op == 1)
			add(l, r, LL(x));
		else if (op == 2)
			assign(l, r, LL(x));
		else if (op == 3)
			cout<<ranks(l,r,x)<<endl;
		else
			cout<<sum(l,r,x,y)<<endl;
	}
	return 0;
}
