//Gorgeous Sequence
/*
�������͵Ŀ������˻����
�������㣺
	����Ϊ��������ֵ�������޸�min(a[i],k),����Ҫ
	maΪ���ֵ��seΪ�δ�ֵ��cntΪ���ֵ������fΪ��ֵ����ǣ�������ֵ�޸Ĺ��ͼ��ϱ�ǣ����ڱ���´� 
 	��Ҫ�޸ĵ�kֵ�����������
		k>ma	�����޸ģ��˳� 
		ma>k>se	ֻ���޸���ֵ������cnt��sum 
		se>=k 	Ѱ���ӽ�㣬����k=se�����޷��޸ĺ��޷����Ҳ��Ҫ 
	״̬�ϲ���ʽ��̫��������д�˸��������ѵ����ʽ��̫��������д��������͵�ʽ��Ҳ����������ll 
*/	 
#include<bits/stdc++.h>
using namespace std;
#define L (k<<1)
#define R (k<<1|1)
typedef long long ll;
const int maxn=1100000;
struct node{
	int l,r,ma,se,cnt;
	int f;	//fΪ�������ֵ��ǣ���¼�޸�֮ǰ�����ֵ 
	ll sum;
}tree[maxn*4];

int read()
{
	int x=0; char ch=0;
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return x;
}
//����´� 
inline void down(int k)//�������ֵ��ǣ��޸Ķ��ӽ�����ֵ���͡���� 
{
	if(~tree[k].f){//������ֵ��ǵĽ�㣬˵����ֵ�޸Ĺ����ҵ����޸ĵ��ӽ�� 
		if(tree[L].ma>tree[k].f){//�жϸ��ڵ�����ֵ���ĸ����ӵ� 
			tree[L].sum+=tree[L].cnt*(1ll*tree[k].f-tree[L].ma);//�漰������� 
			tree[L].ma=tree[L].f=tree[k].f;
		}
		if(tree[R].ma>tree[k].f){
			tree[R].sum+=tree[R].cnt*(1ll*tree[k].f-tree[R].ma);
			tree[R].ma=tree[R].f=tree[k].f;
		}
		tree[k].f=-1;//��ձ��		
	} 
}
//״̬�ϲ� 
void combine(int k)//���ö��ӽ�㣬�޸ĸ��׽��ĺ͡���ֵ���δ�ֵ����ֵ������ 
{
	tree[k].sum=tree[L].sum+tree[R].sum;
	if (tree[L].ma==tree[R].ma){	//���ҽ����ֵ��ͬʱ 
		tree[k].ma=tree[L].ma;
		tree[k].se=max(tree[L].se, tree[R].se);
		tree[k].cnt=tree[L].cnt+tree[R].cnt;
	} 
	else if (tree[L].ma>tree[R].ma){	//������ֵ�� 
		tree[k].ma=tree[L].ma;
		tree[k].se=max(tree[L].se, tree[R].ma);//�Ƚϵ�������Ĵδ�ֵ���ҽ������ֵ 
		tree[k].cnt=tree[L].cnt;
	}
	else{//	�ҽ����ֵ�� 
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
		tree[k].se=-1;//��С��Ҳ��0���ʴδ�ֵ��Ϊ-1 
		tree[k].cnt=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,L);
	build(mid+1,r,R);
	combine(k); 
}
//��ֵ�޸Ĳ�����min(max,k)
void modify(int k,int l,int r,int dat)
{
	if(tree[k].l>r||tree[k].r<l||tree[k].ma<=dat) return;// ��� 1:k�������ֵ���߳��磬�����޸� 
	if(tree[k].l>=l&&tree[k].r<=r&&tree[k].se<dat){// ��� 2��k�����ֵ�ʹδ�ֵ֮��
		tree[k].sum+=tree[k].cnt*(1ll*dat-tree[k].ma);//�漰�˷�����ȡll�ͻ�𰸴��� 
		tree[k].ma=tree[k].f=dat;	//�޸���ֵ��� 
		return;
	}
	//��� 3��kС�ڵ��ڴδ�ֵ����Ҫ�������ӽ���м���Ѱ�� 
	down(k);//���ϵ��� 
	modify(L,l,r,dat);modify(R,l,r,dat);
	combine(k);//���µ��� 
}
//���������ֵ 
int getmax(int l,int r,int k)//���õݹ���ֵ 
{
	if(tree[k].l>r||tree[k].r<l) return 0;
	if(tree[k].l>=l&&tree[k].r<=r) return tree[k].ma;
	down(k);
	return max(getmax(l,r,L),getmax(l,r,R));
}
//������� 
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
				printf("%lld\n",getsum(l,r,1));//�������Ϊll�� 
			}
		}
	}
}

