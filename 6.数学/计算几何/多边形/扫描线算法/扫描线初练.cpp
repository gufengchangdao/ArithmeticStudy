#include<bits/stdc++.h>
using namespace std;
const int maxn=222;
double x[maxn];//��¼ĳ��������µױ߸���
int cnt[maxn<<2];
double sum[maxn<<2];//��¼ĳ��������µױ��ܳ���

//�Ժ�������Ϊ�߶�(����),�Ժ������߶ν���ɨ��
//ɨ���������ÿ�θ����µױ��ܳ��Ⱥ��µױ߸���,��������� 
struct node
{
    double l,r,h;//�������꣬�߶�
    int d;//�����λ�߻�����λ��
    node() {}
    node(double l,double r,double h,int d):l(l),r(r),h(h),d(d) {}
    bool operator < (const node &a)const{	
        return h<a.h;	//��ɨ���߰��߶���С�������� 
    }
} line[maxn];
 
void pushup(int i,int l,int r)
{
   	if(cnt[i])	//��ʾ�����������߶γ��ȿ�����Ϊ�ױ� 
    	sum[i]=x[r+1]-x[l];///ע�� 
   	else
   	    sum[i]=sum[i<<1]+sum[i<<1|1];//���Ҷ��ӳ���֮�� 
}
//���µױ߳��� 
void update(int ql,int qr,int v,int i,int l,int r)	//iΪ����� 
{				
    if(ql<=l && qr>=r){//Ҫ������������� 
       	cnt[i]+=v; //�����µױߵĸ��� 
       	pushup(i,l,r);//���µױ߳� 
       	return ;
    }
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,v,i<<1,l,m);//���뺯���������[l,m+1],�ص� 
    if(qr>m) update(ql,qr,v,i<<1|1,m+1,r);//����[m+1,r+1] 
    pushup(i,l,r);//״̬�ϲ� 
}
 
int main()
{
    int q;
    int kase=0;
    while(cin>>q&&q){
    	//��ʼ�� 
        memset(cnt,0,sizeof(cnt));//�൱��build�����н���Ǻ͵ױ߳���ʼ��Ϊ0 
        memset(sum,0,sizeof(sum));
        int n=0,m=0;
        //��ȡ���� 
        for(int i=1; i<=q; i++){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x[++n]=x1;
            x[++n]=x2;
            line[++m]=node(x1,x2,y1,1);//��λ�߱�λ1 
            line[++m]=node(x1,x2,y2,-1);//��λ�߱�Ϊ-1 
        }
        //����ȥ�� 
        sort(x+1,x+1+n);
        sort(line+1,line+1+m);
        int k=1;
        k=unique(x+1,x+n+1)-x-1;//ֱ����STL�е�unique������
        
        double ans=0.0;
        for(int i=1; i<m; i++){
            int l=lower_bound(x+1,x+k+1,line[i].l)-x;//��ɢ������ֲ����±� 
            int r=lower_bound(x+1,x+k+1,line[i].r)-x; 
            if(l<r) update(l,r-1,line[i].d,1,1,k-1); //���ǰ�������l==r����Ϊһ���㣬�����뺯�� 
            ans+=sum[1]*(line[i+1].h-line[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++kase,ans);
    }
}
/*
����ע����ɨ���߶�ʱr-1
���������r�����Ǹ��µױ߳���ʱ�򣬾�ֻ�����[l,mid]��[mid+1,r]����������[mid,mid+1]��Ӧ�ĵױ߳�
ʹ��r-1ʱ����������������ұ߽�kҲ��һ�������Ĳ��䣬����sum[i]��ʱ��Ϊx[r+1]-x[l];
�����Ϳ��԰�[mid,mid+1]�ǲ��ֵױ߳��ǵ����㣬ͬʱ�������[k-1,k]�ⲿ������ 
*/ 
