//���Ů���� 
/*
�������㣺
	ͬʱ������ֵ���� 
		�ͻ�����ֵ����ֵ����ֵ��������ֵ���޸�ֵ 6������ 
		��ֻ��1��2������ʱ�򣬱�������ͬ����������ص������޸ĵ�ʱ��Ҫ���� 
	ͬʱ����ֵ��������Ͳ���	 
		��ֵ����ֻ��ı�һЩ"��ֵ"������Ͳ�����ı���������
		Ϊ�����֣�������������ǣ���Сֵ�����ֵ��ǡ�����ֵ��� 
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
											//		С		��	
struct Node									//	   mn1		mx1	��ֵ	
{											//	   mn2		mx2	��ֵ 
	int l, r;								//	   cmn		cmx	��ֵ����	
	int mn1, mn2, cmn, mx1, mx2, cmx;  		//	   k1 		k2  ��ֵ�޸�ֵ     k3  ����ֵ�޸�
	ll sum;																						
	int add1, add2, add3;// add1, add2, add3 �ֱ��ʾ��Сֵ�����ֵ������ֵ�ļӼ���ǡ�
} tr[4*MAXN];
//����ϲ� 
void pushup(int o)//�����ܺ͡���ֵ����ֵ����ֵ���� 
{
	tr[o].sum=tr[L].sum+tr[R].sum;
	if (tr[L].mn1==tr[R].mn1){//��Сֵ�Ƚ� 
		tr[o].mn1=tr[L].mn1;	//������Сֵ 
		tr[o].mn2=min(tr[L].mn2, tr[R].mn2);//���´�Сֵ 
		tr[o].cmn=tr[L].cmn+tr[R].cmn;	//������Сֵ���� 
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
	if (tr[L].mx1==tr[R].mx1){//���ֵ�Ƚ� 
		tr[o].mx1=tr[L].mx1;	//�������ֵ 
		tr[o].mx2=max(tr[L].mx2, tr[R].mx2);	//���´δ�ֵ 
		tr[o].cmx=tr[L].cmx+tr[R].cmx;//	�������ֵ���� 
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
//���½�� 			��С	���	���� 
void update(int o, int k1, int k2, int k3)// ���ñ�ǲ��ϲ���ǣ�һ��Ҫע��˳��
{
	//����sum 
	if (tr[o].mn1==tr[o].mx1){// ֻ��һ��ֵʱ�����ֵ������Сֵ
		if (k1==k3) k1=k2; // ��Ӧ������ֵ�ı������
		else k2=k1;
		tr[o].sum+=1ll*k1*tr[o].cmn; 
	}
	else tr[o].sum+=1ll*k1*tr[o].cmn+1ll*k2*tr[o].cmx
	    +1ll*k3*(tr[o].r-tr[o].l+1-tr[o].cmn-tr[o].cmx);
	//���������ص������⣺�ȶԴ�Сֵ����    
	if (tr[o].mn2==tr[o].mx1) tr[o].mn2+=k2;// ��Сֵ�������ֵ��ֻ����������Ӧ�ñ����ֵ�������
	else if (tr[o].mn2!=INF) tr[o].mn2+=k3;// ����Ӧ�ñ�����ֵ�������
	// �Դδ�ֵͬ��
	if (tr[o].mx2==tr[o].mn1) tr[o].mx2+=k1;//�δ�ֵ������Сֵ 
	else if (tr[o].mx2!=-INF) tr[o].mx2+=k3;
	tr[o].mn1+=k1, tr[o].mx1+=k2;//������ֵ 
	tr[o].add1+=k1, tr[o].add2+=k2, tr[o].add3+=k3;//������ʹ��ϱ�� 
}
// �´����
void pushdown(int o)
{
	int mn=min(tr[L].mn1, tr[R].mn1);// �ҳ����ֵ����Сֵ
	int mx=max(tr[L].mx1, tr[R].mx1);
	// �´���ǵ�����������������������ֵ���´���ֵ��ǣ������´�����ֵ���
	update(L, tr[L].mn1==mn?tr[o].add1:tr[o].add3,
	    tr[L].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
	// ������ͬ��
	update(R, tr[R].mn1==mn?tr[o].add1:tr[o].add3,
	    tr[R].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
	tr[o].add1=tr[o].add2=tr[o].add3=0;
}
//���� 
void build(int o, int l, int r, int* a)
{
	tr[o].l=l, tr[o].r=r;
	tr[o].add1=tr[o].add2=tr[o].add3=0;//�ӷ���־��Ϊ0 
	if (l==r){
		tr[o].sum=tr[o].mn1=tr[o].mx1=a[l]; //��Сֵ�����ֵ��ֵ 
		tr[o].mn2=INF, tr[o].mx2=-INF;//��Сֵ��ʼ��Ϊ���ֵ���δ�ֵ��ǳ�ʼ��Ϊ��Сֵ 
		tr[o].cmn=tr[o].cmx=1;//��ֵ���� 
		return;
	}
	int mid=l+r>>1;
	build(L, l, mid, a);
	build(R, mid+1, r, a);
	pushup(o);//����ϲ� 
}
//�����k 
void modify1(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l) return;
	if (l<=tr[o].l&&tr[o].r<=r){ 
		update(o, k, k, k);//�����С������������k 
		return; 
	}
	pushdown(o);//�´���� 
	modify1(L, l, r, k), modify1(R, l, r, k);
	pushup(o);//����ϲ� 
}
//�������ֵ�޸�
void modify2(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l||k<=tr[o].mn1) return;
	if (l<=tr[o].l&&tr[o].r<=r&&k<tr[o].mn2){ //��СֵС��k,�޸�����Сֵ�йر��� 
		update(o, k-tr[o].mn1, 0, 0);//��Сֵ��sum�������k-tr[o].mn1��������ʽ�����޸ĵ���Сֵ�ַ������ 
		return; 
	}
	pushdown(o);
	modify2(L, l, r, k), modify2(R, l, r, k);
	pushup(o);
}
//������Сֵ�޸� 
void modify3(int o, int l, int r, int k)
{
	if (tr[o].l>r||tr[o].r<l||k>=tr[o].mx1) return;
	if (l<=tr[o].l&&tr[o].r<=r&&k>tr[o].mx2){ //���ֵ����k 
		update(o, 0, k-tr[o].mx1, 0); //��Сֵ��sum�������k-tr[o].mx1
		return; 
	}
	pushdown(o);
	modify3(L, l, r, k), modify3(R, l, r, k);
	pushup(o);
}
//������� 
ll query4(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return 0;
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
	pushdown(o);
	return query4(L, l, r)+query4(R, l, r);
}
//���������ֵ 
int query5(int o, int l, int r)
{
	if (tr[o].l>r||tr[o].r<l) return -INF;//ע�������ԭ�����е�������Ϊ���������ܷ���0 
	if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx1;
	pushdown(o);
	return max(query5(L, l, r), query5(R, l, r));
}
//��������Сֵ 
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
			case 1://�����k 
				l=read(), r=read(), k=read();
				modify1(1, l, r, k);
				break;
			case 2://��һ������[L,R] ��С��k �������k  
				l=read(), r=read(), k=read();
				modify2(1, l, r, k);
				break;
			case 3://��һ������[L,R] �����k�������k
				l=read(), r=read(), k=read();
				modify3(1, l, r, k);
				break;
			case 4://��� 
				l=read(), r=read();
				printf("%lld\n", query4(1, l, r));
				break;
			case 5://�����ֵ 
				l=read(), r=read();
				printf("%d\n", query5(1, l, r));
				break;
			case 6://����Сֵ 
				l=read(), r=read();
				printf("%d\n", query6(1, l, r));
				break;
		}
	}
	return 0;
}
