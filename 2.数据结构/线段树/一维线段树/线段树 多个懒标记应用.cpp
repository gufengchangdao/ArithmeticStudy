/*
�߶���ģ�壺����ӷ�������˷��������ѯ 
https://www.luogu.com.cn/problem/P3373
����ӷ�������˷����������ʵ�� 
�������㣺
	ͬʱ��Ҫ�ӷ��ͳ˷���������ǣ��ڱ���´��У�
	ֵ�ĸ��£� 
		���ӵ�ֵ=���ӵ�ֵ*���׵ĳ˷����+���ӵ����䳤��*���׵ļӷ����
	��ǵĸ��£�
		���ӵļӷ����=���ӵļӷ����*���׵ĳ˷����+���׵ļӷ����
		���ӵĳ˷����=���ӵĳ˷����*���׵ĳ˷���� 
*/
#include<bits/stdc++.h>
#define L (k<<1)
#define R (k<<1|1) 
#define ll long long
using namespace std;
struct node{
	int l,r;
	ll v,f,a;	//fΪ�˷�����ǣ�aΪ�ӷ������ 
}tree[400005];
int n,m,x,y,rat,op;
ll ans,mod;
/*
void check(int k)//��������û�õĺ�����ʵ�ڴ𰸴���Ͳ��ϼ�� 
{
	if(k>n*4) return;
	printf("tree[%d]=%d\n",k,tree[k].v);
	check(k*2);
	check(k*2+1);	
}
*/
void build(int l,int r,int k)
{
	tree[k].l=l;tree[k].r=r;tree[k].f=1;tree[k].a=0;//�ӷ��ͳ˷�����ǵĳ�ʼ����ͬ 
	if(l==r){
		scanf("%lld",&tree[k].v);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,L);
	build(mid+1,r,R);
	tree[k].v=(tree[L].v+tree[R].v)%mod;	
}

void down(int k)//����´����ص� 
{
	tree[L].f=tree[L].f*tree[k].f%mod;//���³˷���� 
	tree[R].f=tree[R].f*tree[k].f%mod;
	tree[L].a=(tree[L].a*tree[k].f+tree[k].a)%mod;//���¼ӷ���� 
	tree[R].a=(tree[R].a*tree[k].f+tree[k].a)%mod;
	tree[L].v=(tree[L].v*tree[k].f%mod+tree[k].a*(tree[L].r-tree[L].l+1)%mod)%mod;//����ֵ 
	tree[R].v=(tree[R].v*tree[k].f%mod+tree[k].a*(tree[R].r-tree[R].l+1)%mod)%mod;
	tree[k].a=0;tree[k].f=1;//�����ӽ���ͳ�ʼ��	
} 
//����˷� 
void qchange(int k)
{
	//if(k>n*4) return;�ȿ��Ը��ݽ���±��֦���ֿ��Ը��ݽ��������֦���Ͼ� x>0,��Ч���ݵ�l=0�������ܼ�¼��ȥ 
	if(y<tree[k].l || tree[k].r<x) return;
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].v=tree[k].v*rat%mod;
		tree[k].f=tree[k].f*rat%mod;//�����޸Ĺ������䲻����������� 
		tree[k].a=tree[k].a*rat%mod;//�ӷ������ҲҪ�ı� 
		return;
	}
	if(tree[k].f!=1||tree[k].a)//��Ȼ����ֱ���´��������ж�һ�����´����� 
		down(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) qchange(L);
	if(y>mid) qchange(R);
	tree[k].v=(tree[L].v+tree[R].v)%mod; 
}
//����ӷ� 
void add(int k)
{
	//if(k>n*4) return;
	if(y<tree[k].l || tree[k].r<x) return;
	if(tree[k].l>=x&&tree[k].r<=y){
		tree[k].v=(tree[k].v+rat*(tree[k].r-tree[k].l+1)%mod)%mod;
		tree[k].a=(tree[k].a+rat)%mod;//ֻ���޸ļӷ���ǾͿ����� 
		return;
	}
	if(tree[k].f!=1||tree[k].a) down(k);
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid) add(L);
	if(y>mid) add(R);
	tree[k].v=(tree[L].v+tree[R].v)%mod; 
}
//������� 
void sum(int k)
{
	//if(!tree[k].v) return;
	if(y<tree[k].l || tree[k].r<x)
        return;
	if(tree[k].l>=x&&tree[k].r<=y){
        ans=(ans+tree[k].v)%mod;
        return;
    }
    if(tree[k].f!=1||tree[k].a) down(k);
    int mid=(tree[k].l+tree[k].r)>>1;
    if(x<=mid) sum(L);
    if(y>mid) sum(R);
}

int main()
{
	
	scanf("%d%d%d",&n,&m,&mod);
	build(1,n,1);
//	check(1);
	while(m--){
		ans=0;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&x,&y,&rat);
			qchange(1);			
		}
		else if(op==2){
			scanf("%d%d%d",&x,&y,&rat);
			add(1);		
		}
		else{
			scanf("%d%d",&x,&y);
			sum(1);
			printf("%lld\n",ans);
		}	
	}	
} 
