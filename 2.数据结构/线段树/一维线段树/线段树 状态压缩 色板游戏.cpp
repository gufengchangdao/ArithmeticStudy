//ɫ����Ϸ 
/*
����:len���ȵĻ��壬n����ɫ��op������
		���ֲ�����P���串��Ϊcal��C��ѯ�����ж�������ɫ
����������������򵥵ú�
���߶������Ļ��������ÿ���ڵ��¼��ɫ�������أ�״̬ѹ�� 
	����n<=30,�ʿ���״̬ѹ�����߶������ö����Ƶ�1��ʾ����������ɫ��0��ʾû��������ɫ������ | ����� 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
#define ri register int
#define L (o<<1)
#define R (o<<1|1)
#define ll long long
const int maxn=100005;

struct node{
	int l,r;
	ll v;
	int tag;	//��ɫ�����(���串�Ǳ��) 
}tr[maxn<<2];
//״̬�ϲ� 
void pushup(int o)
{
	tr[o].v=tr[L].v|tr[R].v;//�����ɫ���ಢ���ұ���ɫ���� 
}
//�������� 
void update(int o,int l,int r,int cal)
{
	tr[o].tag=cal;
	tr[o].v=(1<<(cal-1));	//vΪ�ұߵ�calλ��1���� 
}
//����´� 
void down(int o)
{
	if(tr[o].tag==-1) return;
	tr[L].tag=tr[o].tag; tr[R].tag=tr[o].tag;
	tr[L].v=(1<<(tr[o].tag-1)); tr[R].v=(1<<(tr[o].tag-1));
	tr[o].tag=-1;
}

void build(int o,int l,int r)
{
	
	tr[o].v=1;tr[o].tag=-1;tr[o].l=l;tr[o].r=r;//��ʼ��ʱ������������ɫ��Ϊ1 ����Ǹ�Ϊ0Ҳ���� 
	if(l==r) return;
	int mid=(l+r)>>1;
	build(L,l,mid);
	build(R,mid+1,r);
}
//���串�� 
void modify(int o,int l,int r,int cal)
{
//printf("%d %d %d\n",tr[o].l,tr[o].r,tr[o].v);
	if(tr[o].l>r||tr[o].r<l) return;
	if(tr[o].l>=l&&tr[o].r<=r){
		update(o,tr[o].l,tr[o].r,cal);
		return;
	}
	down(o);
	modify(L,l,r,cal);//ע�⣺l,r��Ҫ��ѯ�����䷶Χ����Ҫ�� 
	modify(R,l,r,cal);
	pushup(o);
}

ll query(int o,int l,int r)
{
//printf("%d %d %d\n",tr[o].l,tr[o].r,tr[o].v);
	if(tr[o].l>r||tr[o].r<l) return 0;//0����Ӱ��������������0���� 
	if(tr[o].l>=l&&tr[o].r<=r) return tr[o].v;
	down(o);
	return query(L,l,r)|query(R,l,r);
}

int main()
{
	int len,n,op,l,r,cal;
	char k;
	scanf("%d%d%d",&len,&n,&op);
	build(1,1,len);

	while(op--){
		scanf(" %c",&k);
		if(k=='C'){//���串�ǲ��� 
			scanf("%d%d%d",&l,&r,&cal);
			if(l>r) swap(l,r);//������l>r�Ŀ��ܣ�û����������д��� 
			modify(1,l,r,cal);
		}
		else{//�����ѯ���� 
			scanf("%d%d",&l,&r);
			if(l>r) swap(l,r);
			ll sum=query(1,l,r);
			int ans=0;
			for(int i=0;i<n;i++)	//ͳ����ɫ����Ĺؼ�����,iȡ[0,n) 
				if(sum&(1<<i)) ans++;
			printf("%d\n",ans);
		}
	}
} 
