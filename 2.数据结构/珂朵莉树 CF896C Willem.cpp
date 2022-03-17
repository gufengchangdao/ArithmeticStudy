/*
ʲôʱ�����������
	�������������ӹ�ϵ����������ǲ��й�ϵ,����set�����㣬����߽�l��Ϊ�±� 
	��ƽһ�����䣬ʹһ���������ڵĶ������һ������֤���������
��������� 
	�����
	���丳ֵ
	�����kС
	�������ݴκ�
�������㣺
	mutable
		mutable��������˼�ǡ��ɱ�ģ��ױ�ġ�����constant����C++�е�const���Ƿ���ʡ�
		��mutable���εı���������Զ���ڿɱ��״̬����ʹ��һ��const�����С�
	��set�����㣬���Ұ�����߽�l������������lower_bound����������߽�	 
	��������������ܽ����䰴�Լ�����Ͽ�
	���õ�����������������ô������ݽṹ������vector<pair...>���������������k����� 
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
	mutable LL v; //�������ֵ��Ҫע�����mutable���ױ䲻���ġ�����v�����Σ�ʹ�����ǿ�����add����
				//	���޸�v��ֵ��û���������λ���add�����ﵼ��CE�� 
	node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
	bool operator<(const node& o) const{
		return l < o.l;	//���Ҫ��set�а���l����Ͳ��� 
	}
};
//������ȡģ 
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
//�����������ԭ������posλ�õĽڵ�ֳ������֣�[l,pos-1]��[pos,r] 
set<node> s;//����set�������������Ҳ���� 
IT split(int pos)//������ؼ��Ĵ��� 
{
	IT it = s.lower_bound(node(pos));//�ҵ��׸�l(��߽�)��С��pos�Ľڵ�
	if (it != s.end() && it->l == pos) return it;//�������pos��߽磬��ʾ����Ͽ� 
	--it;//��1����ǰ�ң���ʱit->l < pos <= it->r 
	int L = it->l, R = it->r;
	LL V = it->v;
	s.erase(it);//ɾ��ԭ�����䲢�ֳ����� 
	s.insert(node(L, pos-1, V));
	return s.insert(node(pos, R, V)).first;//����set�����غ��εĵ�����
		//��������pair<iterator,bool> insert (const value_type& val)�ķ���ֵ 
}
//�����޸� 
void add(int l, int r, LL val)
{
	IT itr = split(r+1),itl = split(l);//���ֲ���ǰӦ����split(r+1)��split(l)����Ȼ�������֪��Ϊɶ 
	for (; itl != itr; ++itl) itl->v += val;
}
//��ƽ������ֱ�ӽ�[l,r]��ֵȫ��Ϊval������mapԪ�ظ�����û����������T�� 
void assign(int l, int r, LL val)
{
	IT itr = split(r+1),itl = split(l); 
	s.erase(itl, itr);
	s.insert(node(l, r, val));
}
//���[l,r]��k����� 
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
	return -1;//û�е�K����� 
}
//���[l,r]����ÿ�����ֵ�x�η��ĺ�ģy��ֵ
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
		s.insert(node(i,i,a[i]));//��ʼ�� 
	}
	s.insert(node(n+1, n+1, 0));//��������д����r����Ϊn+1����Ӧ�ô���n+1 
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
		//���� 
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
