#include<bits/stdc++.h>
using namespace std;
#define lson i<<1,l,m
#define rson i<<1|1,m+1,r
const int maxn=222;
double x[maxn];
int cnt[maxn<<2];
double sum[maxn<<2];

struct node
{
    double l,r,h;//�������꣬�߶�
    int d;//�����λ�߻�����λ��
    node() {}
    node(double l,double r,double h,int d):l(l),r(r),h(h),d(d) {}
    bool operator < (const node &a)const
    {
        return h<a.h;
    }
} line[maxn];
 
void pushup(int i,int l,int r)
{
   if(cnt[i])
   {
       sum[i]=x[r+1]-x[l];
   }
   else
   {
       sum[i]=sum[i<<1]+sum[i<<1|1];
   }
}
 
void update(int ql,int qr,int v,int i,int l,int r)
{
    if(ql<=l && qr>=r)
    {
       cnt[i]+=v;
       pushup(i,l,r);
       return ;
    }
 
    int m=(l+r)>>1;
    if(ql<=m)update(ql,qr,v,lson);
    if(qr>m)update(ql,qr,v,rson);
    pushup(i,l,r);
}
 
int main()
{
    int q;
    int kase=0;
    while(cin>>q&&q)
    {
        memset(cnt,0,sizeof(cnt));//�൱��build
        memset(sum,0,sizeof(sum));//�൱��build
        int n=0,m=0;
        for(int i=1; i<=q; i++)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x[++n]=x1;
            x[++n]=x2;
            line[++m]=node(x1,x2,y1,1);
            line[++m]=node(x1,x2,y2,-1);
        }
 
        sort(x+1,x+1+n);
        sort(line+1,line+1+m);
        int k=1;
        k=unique(x+1,x+n+1)-x-1;//ֱ����STL�е�unique������
        double ans=0.0;
        for(int i=1; i<m; i++)
        {
 
            int l=lower_bound(x+1,x+k+1,line[i].l)-x;
            int r=lower_bound(x+1,x+k+1,line[i].r)-x;
            r--;
            if(l<=r)update(l,r,line[i].d,1,1,k-1);
            ans+=sum[1]*(line[i+1].h-line[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++kase,ans);
    }
}
