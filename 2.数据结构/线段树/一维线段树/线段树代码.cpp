/*
�߶����ĵ����ѯ�������޸ġ������ѯ�������޸Ĺ�ͬ�㣺
1. �жϣ��Ƿ��ҵ���Ч����(Ҷ�ӽ�㡢������)����Ч����(�ܵ�������������),�������� 
2. ������´����ж�֮���´� 
3. ���ң�(�ж�֮��)���������ӽ�� 
4. ״̬�ϲ���ÿ���޸����ӽ����Ҫ���¸��ڵ���Ϣ����Ϣ�������װ�������� 
*/
#include<cstdio>
using namespace std;
int n,p,a,b,m,x,y,ans;
struct node
{
    int l,r,w,f;//f�Ǽӷ�������ǣ���ʼ����Ϊ0 
}tree[400001];	//��1��4���ռ䡢��2������dfs˳�򴢴棬2���ռ� 
inline void build(int k,int ll,int rr)//���� 
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r)
    {
        scanf("%d",&tree[k].w);
        return;
    }
    int m=(ll+rr)>>1;
    build(k*2,ll,m);
    build(k*2+1,m+1,rr);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
//����´�
inline void down(int k) 
{
    tree[k*2].f+=tree[k].f;
    tree[k*2+1].f+=tree[k].f;
    tree[k*2].w+=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
		//����֮���Բ����Լ��ı������Ϊ�Լ��ı��֮ǰ����ֵ������α�ǲ����Լ��üӵ� 
    tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
    tree[k].f=0;
}
//�����ѯ
inline void pask(int k)
{
    if(tree[k].l==tree[k].r)
    {
        ans=tree[k].w;
        return ;
    }
    if(tree[k].f) down(k);//���԰�������жϷŵ�down�����Ŀ�ͷ 
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) pask(k*2);//���԰�������жϷŵ�������ͷ�ж��Ƿ���� 
    else pask(k*2+1);
}
//�����޸� 
inline void pchange(int k)
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].w+=y;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) pchange(k*2);
    else pchange(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w; 
}
//�����ѯ 
inline void qask(int k)//������Ϊ�з���ֵ�ĺ�������Ч����ͷ��أ�������󷵻���ڵ���ҽ�㷵��ֵ֮�� 
{
	//if(k>n*4) return;�ȿ��Ը��ݽ���±��֦���ֿ��Ը��ݽ��������֦���Ͼ� x>0,��Ч���ݵ�l=0�������ܼ�¼��ȥ 
	if(y<tree[k].l || tree[k].r<x) return;
    if(tree[k].l>=a&&tree[k].r<=b) 
    {
        ans+=tree[k].w;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) qask(k*2);
    if(b>m) qask(k*2+1);
}
inline void qchange(int k)//�����޸� 
{
	//if(k>n*4) return;�ȿ��Ը��ݽ���±��֦���ֿ��Ը��ݽ��������֦���Ͼ� x>0,��Ч���ݵ�l=0�������ܼ�¼��ȥ 
	if(y<tree[k].l || tree[k].r<x) return;
    if(tree[k].l>=a&&tree[k].r<=b)
    {
        tree[k].w+=(tree[k].r-tree[k].l+1)*y;//�����൱��ÿ����������y 
        tree[k].f+=y;//��������ǣ���ʾ�����������޸Ĺ� 
        return;
    }
    if(tree[k].f) down(k);//��������������޸Ĺ����Ǹ�������ҲҪ�����޸ģ�ͬʱ�ٰ���������������0 
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) qchange(k*2);
    if(b>m) qchange(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
int main()
{
    scanf("%d",&n);//n���ڵ� 
    build(1,1,n);//���� 
    scanf("%d",&m);//m�ֲ��� 
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p);
        ans=0;
        if(p==1)
        {
            scanf("%d",&x);
            pask(1);//�����ѯ,�����x���� 
            printf("%d",ans);
        } 
        else if(p==2)
        {
            scanf("%d%d",&x,&y);
            pchange(1);//�����޸� 
        }
        else if(p==3)
        {
            scanf("%d%d",&a,&b);//�����ѯ 
            qask(1);
            printf("%d\n",ans);
        }
        else
        {
             scanf("%d%d%d",&a,&b,&y);//�����޸� 
             qchange(1);
        }
    }
}
