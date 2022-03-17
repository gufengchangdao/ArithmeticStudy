/*
P6242 ��ģ�塿�߶��� 3
�����к�������ʷ���ֵ�������
	������ʷ���Ӽ���Ǻ�������ʷ���Ӽ����
	����ʷ���Ӽ���ǡ�������ʾ���Ǵ���һ���´� add �����ڣ�����ӱ�Ǵﵽ�����ֵ
	��ʷ��ǵ����ã�
		����������ֵ��Сʱ���ڸ��²����д����k1�Ǹ�ֵ��ʹ�ñ��ֵ��С���޷��ж�ȡ��ʷ���ֵʱ
		ʹ���ĸ��׶εı�ǣ����´���ǵ�ʱ��ʹ����ʷ��Ǽ����ϸ��µı����ֵ�����Ǹ���� 
	������ʷ��ֵ��ǵĺϲ���
	���´����ʱ��������ʷ��ֵ=max(������ʷ��ֵ,���ӵ�ǰ��ֵ+���ӵ���ʷ���Ӽ����) 
	״̬�ϲ�ʱ��  ��ʷ��ֵ=max(��ʷ��ֵ,��ǰ��ֵ+��ʷ���Ӽ����)  
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
	int add1, add1_, add2, add2_; //���ֵ��ǣ���ʷ���Ӽ���ǣ�������ǣ�������ʷ���Ӽ���� 
} tr[4*MAXN];
//״̬�ϲ� ,��������Ǻ�l��r�������Ķ����� 
void pushup(int o)
{
	tr[o].sum=tr[L].sum+tr[R].sum;
	tr[o].mx_=max(tr[L].mx_, tr[R].mx_);//������ʷ���ֵ 
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
//�������� ���������ֵ������l��r�����Ķ����� 
void update(int o, int k1, int k1_, int k2, int k2_)
{
	tr[o].sum+=1ll*k1*tr[o].cnt+1ll*k2*(tr[o].r-tr[o].l+1-tr[o].cnt);
	tr[o].mx_=max(tr[o].mx_, tr[o].mx+k1_);//������ʷ���ֵ 
	tr[o].mx+=k1; 
	tr[o].add1_=max(tr[o].add1_, tr[o].add1+k1_);//������ʷ���ֵ��� 
	tr[o].add1+=k1;
	tr[o].add2_=max(tr[o].add2_, tr[o].add2+k2_);
	tr[o].add2+=k2;
	if (tr[o].se!=-INF) tr[o].se+=k2;//���´δ�ֵ��ʱ��Ҫ���ж�һ���Ƿ���ڴδ�ֵ
}
//����´� 
void pushdown(int o)
{
	int tmp=max(tr[L].mx, tr[R].mx);
	if (tr[L].mx==tmp)//�ж����ֵ�Ƿ����������� 
		update(L, tr[o].add1, tr[o].add1_, tr[o].add2, tr[o].add2_);
	else update(L, tr[o].add2, tr[o].add2_, tr[o].add2, tr[o].add2_);
//������ʷ���Ӽ�������ã�����ֵ����������������ʱ��ά������������ʷ���ֵ��Ҫ�õ�������ʷ���ֵ��	 
	if (tr[R].mx==tmp)//�ж����ֵ�Ƿ����������� 
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
//�����k 
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
//��� 
ll query3(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return 0;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
	pushdown(o);
	return query3(L, l, r)+query3(R, l, r);
}
//�����ֵ 
int query4(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return -INF;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
	pushdown(o);
	return max(query4(L, l, r), query4(R, l, r));
}
//����ʷ���ֵ 
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
			case 1://�����k 
				l=read(), r=read(), k=read();
				modify1(1, l, r, k);
				break;
			case 2:	//a[i]=min(a[i],k) 
				l=read(), r=read(), k=read();
				modify2(1, l, r, k);
				break;
			case 3://��� 
				l=read(), r=read();
				printf("%lld\n", query3(1, l, r));
				break;
			case 4://�����ֵ 
				l=read(), r=read();
				printf("%d\n", query4(1, l, r));
				break;
			case 5://����ʷ���ֵ 
				l=read(), r=read();
				printf("%d\n", query5(1, l, r));
				break;
		}
	}
	return 0;
}
