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
	bool tag;	//tag��ʾ��û�����串�Ǳ��,��������Ϳ��Դ���cov��ʼ���ˣ�����cov�͵ó�ʼ��Ϊ����ȡ������ֵ�� 
	int mx, add, cov;	//��Ԫ��(add,cov) 
	int mx_, add_, cov_;	//��ʷ������串��cov_��Ϊ��Ӧ�������θ��ǵ���� 
} tr[4*MAXN];
//״̬�ϲ� 
void pushup(int o)
{
	tr[o].mx=max(tr[lc].mx, tr[rc].mx);
	tr[o].mx_=max(tr[lc].mx_, tr[rc].mx_);
}
//�������� 
void update(int o, int k, int k_)
{
	// ������ʷ���ֵ�͵�ǰ���ֵ������Ҫע��˳��,��Ϊ��ʷ��ֵ�͵�ǰ��ֵ�뵱ǰ��ʷ���Ӽ����֮�͵õ������ֵ�Ƚϵ� 
	tr[o].mx_=max(tr[o].mx_, tr[o].mx+k_);
	tr[o].mx+=k;
	if (!tr[o].tag){// ���û�����串�Ǳ�ǣ��������� add ���
		tr[o].add_=max(tr[o].add_, tr[o].add+k_);
		tr[o].add+=k;
	}
	else{  // �����串�Ǳ�ǵİѸ����ļӷ���Ǽӵ����串�Ǳ���� 
		tr[o].cov_=max(tr[o].cov_, tr[o].cov+k_);
		tr[o].cov+=k; 
	}
}
 // ���串��
void cover(int o, int k, int k_)//���串�Ǳ�� 
{
	tr[o].mx_=max(tr[o].mx_, k_);
	tr[o].mx=k;
	tr[o].cov_=max(tr[o].cov_, k_);//�൱�ڸ���ֵ 
	tr[o].cov=k;
	tr[o].tag=1;//���ϱ�ǣ���ʾ�������ѽ������串�ǹ��������串�Ǵ������ӽ�� 
}
//�´���� 
void pushdown(int o)
{
	if (tr[o].add){
		update(lc, tr[o].add, tr[o].add_);//�´�����ӱ�� 
		update(rc, tr[o].add, tr[o].add_);
		tr[o].add=tr[o].add_=0;
	}
	if (tr[o].tag){// ����� tag ��ʾ��ǰ�ڵ���û�����串�Ǳ��
		cover(lc, tr[o].cov, tr[o].cov_);
		cover(rc, tr[o].cov, tr[o].cov_);
		tr[o].tag=0;
		tr[o].cov_=INT_MIN;//��tag=0��cov���ó�ʼ����
	//	������ʷ��󸲸�ֵҪ��ʼ������������һ�����串�Ǽ̳�������������ȥ����һ������Ҳ�ǶԵ� 
	}
}

void build(int o, int l, int r, int* a)
{
	tr[o].l=l, tr[o].r=r;
	tr[o].add=tr[o].add_=tr[o].tag=0;//��ǳ�ʼ�� 
	tr[o].cov_=INT_MIN;	//��ǳ�ʼ��Ϊ��Сֵ����δ�ֵ��ʼ��Ϊ��Сֵͬ�� 
	if (l==r){ 
		tr[o].mx=tr[o].mx_=a[l]; 
		return; 
	}
	int mid=l+r>>1;
	build(lc, l, mid, a);
	build(rc, mid+1, r, a);
	pushup(o);
}
//��[x,y]�����ֵ 
int queryQ(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return INT_MIN;//����ͷ�����Сֵ 
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
	pushdown(o);
	return max(queryQ(lc, l, r), queryQ(rc, l, r));
}
//��������ʷ���ֵ 
int queryA(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return INT_MIN;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx_;
	pushdown(o);
	return max(queryA(lc, l, r), queryA(rc, l, r));
}
//����ӷ���[l,r]+k 
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
//���串�ǣ�[l,r]=k 
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
		scanf("%s", op);//����Ͷ�ȡһ���ַ���������棬%s��ȡ�Ͳ��ùܻ��з��� 
		switch (op[0]){ 
			case 'Q':	//��[x,y]�����ֵ 
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
�ؼ��� 
������ ���������ֵ����������ʷ���ֵ
	   �����k�����串�� 
����ѯ�ʣ����������ֵ��������ʷ���ֵ->mx��mx_ 
���������������k�����串��->�����Ԫ��(add,cov)��������ֵ����add,�ٱ��cov 
	�����k��(add+k,cov)	��add��add_����
	���串�ǣ�(add,cov+k) tag����ϣ���cov��cov_����  

����ֵ����ʷ������ֵ�ĸ������Ⱥ�˳�� 
	����ʷ������ֵ���뵱ǰ��ֵ���ϵ�ǰ��ʷ����Ǻ��ֵ�ȴ�С 
	����ֵ
�������ʹ�ú�Ҫ��ʼ��������tag��cov_��cov���ã���Ϊ��tag���жϣ�����cov_Ҫ��ʼ������Ϊ����
	����һ�����串�Ǽ̳������ʷ���Ľ��
*/
