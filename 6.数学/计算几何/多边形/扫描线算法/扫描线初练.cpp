#include<bits/stdc++.h>
using namespace std;
const int maxn=222;
double x[maxn];//记录某个区间的下底边个数
int cnt[maxn<<2];
double sum[maxn<<2];//记录某个区间的下底边总长度

//以横坐标作为线段(区间),对横坐标线段进行扫描
//扫描的作用是每次更新下底边总长度和下底边个数,增加新面积 
struct node
{
    double l,r,h;//左右坐标，高度
    int d;//标记上位边还是下位边
    node() {}
    node(double l,double r,double h,int d):l(l),r(r),h(h),d(d) {}
    bool operator < (const node &a)const{	
        return h<a.h;	//将扫描线按高度由小到大排序 
    }
} line[maxn];
 
void pushup(int i,int l,int r)
{
   	if(cnt[i])	//表示该区间整个线段长度可以作为底边 
    	sum[i]=x[r+1]-x[l];///注意 
   	else
   	    sum[i]=sum[i<<1]+sum[i<<1|1];//左右儿子长度之和 
}
//更新底边长度 
void update(int ql,int qr,int v,int i,int l,int r)	//i为根结点 
{				
    if(ql<=l && qr>=r){//要求区间的子区间 
       	cnt[i]+=v; //更新下底边的个数 
       	pushup(i,l,r);//更新底边长 
       	return ;
    }
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,v,i<<1,l,m);//进入函数计算的是[l,m+1],重点 
    if(qr>m) update(ql,qr,v,i<<1|1,m+1,r);//计算[m+1,r+1] 
    pushup(i,l,r);//状态合并 
}
 
int main()
{
    int q;
    int kase=0;
    while(cin>>q&&q){
    	//初始化 
        memset(cnt,0,sizeof(cnt));//相当于build，所有结点标记和底边长初始化为0 
        memset(sum,0,sizeof(sum));
        int n=0,m=0;
        //读取数据 
        for(int i=1; i<=q; i++){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x[++n]=x1;
            x[++n]=x2;
            line[++m]=node(x1,x2,y1,1);//下位边标位1 
            line[++m]=node(x1,x2,y2,-1);//上位边标为-1 
        }
        //排序去重 
        sort(x+1,x+1+n);
        sort(line+1,line+1+m);
        int k=1;
        k=unique(x+1,x+n+1)-x-1;//直接用STL中的unique函数。
        
        double ans=0.0;
        for(int i=1; i<m; i++){
            int l=lower_bound(x+1,x+k+1,line[i].l)-x;//离散化后二分查找下标 
            int r=lower_bound(x+1,x+k+1,line[i].r)-x; 
            if(l<r) update(l,r-1,line[i].d,1,1,k-1); //如果前面求出的l==r，即为一个点，不进入函数 
            ans+=sum[1]*(line[i+1].h-line[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++kase,ans);
    }
}
/*
这里注意下扫描线段时r-1
如果还是用r，我们更新底边长的时候，就只会更新[l,mid]和[mid+1,r]，而忽视了[mid,mid+1]对应的底边长
使用r-1时候，我们让总区间的右边界k也减一，其他的不变，在求sum[i]的时候，为x[r+1]-x[l];
这样就可以把[mid,mid+1]那部分底边长记到左结点，同时还不会把[k-1,k]这部分忘掉 
*/ 
