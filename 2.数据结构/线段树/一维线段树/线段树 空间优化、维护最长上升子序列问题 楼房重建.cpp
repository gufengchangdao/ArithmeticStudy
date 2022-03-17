/*
https://www.luogu.com.cn/problem/P4198
这题是求楼房最高点与原点所在直线的斜率的最长上升子序列
建树
	由于n大，用DFS的顺序储存树，DFS序作下标，空间为2*n 
	所以k的左孩子是k+1，右孩子是k+左孩子区间长度*2
维护信息
	区间总长度 sum
	区间左端点开始的最长上升子序列长度 len
	最长上升子序列的最大值 max_xl,最小值 min_xl
修改
	叶子节点len=1，max_xl,min_xl都=斜率
信息合并	
	每次看两个子区间，左子区间一定用上，关键看右子区间
1、右子区间上升序列最小值>左子区间上升序列最大值，右子区间都能用得上
2、右子区间上升序列最大值<=左子区间上升序列最大值，右子区间没用
3、右子区间上升序列最大值<左子区间上升序列最大值，但>最小值，在右子区间里找有多少能用得上
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cnt,x,y,f;
struct node
{
    int l,r;
    int sum,len;	//sum为区间长度，用于求右子区间下标，len为该区间从l处可以看见的房子 
    double max_xl,min_xl;
}e[200001];
inline void build(int l,int r)
{
    cnt++;
    e[cnt].l=l;e[cnt].r=r;
    e[cnt].sum=r-l+1;	//sum表示楼房总数 
    if(l==r) return;
    int mid=l+r>>1;
    build(l,mid);build(mid+1,r);
}
inline void query(int k,double g)//在区间k里找>g的序列
{
    if(e[k].max_xl<=g) return;//最大的都别人的小，没希望了 
    if(e[k].min_xl>g) f+=e[k].len;//最小的都比别人大，有效的len都加上 
    else{	//有大有小 
        double mid=e[k+1].max_xl;//k的左区间上升序列最大值
        if(g<mid){	//这里只要满足g<mid就会一直在左子区间找 
            query(k+1,g);
            f+=e[k].len-e[k+1].len;//这里加上k的右子区间的贡献 
            //不是直接加上右子区间上升序列。因为在合并时右子区间不一定全部被合并
            //即e[k].len<=e[k+1].len+e[k+e[k+1].sum*2] 
//g<左区间的最大值，那么k的右子区间对答案都有贡献，全都加上，继续在左子区间找
        }
        else  query(k+e[k+1].sum*2,g);
        //query(e[k].sum&1?e[k].sum+k+1:e[k].sum+k,g);这样也可以 
    }
}
inline void up(int k)//信息合并，由左子树和右子树得本结点 
{
    int l=k+1,r=k+e[k+1].sum*2;
    if(e[r].min_xl>e[l].max_xl){	//右子树最小的斜率也比左子树最大的斜率大 
        e[k].len=e[l].len+e[r].len;	//可视的楼都加上 
        if(e[k].len==1) e[k].max_xl=e[k].min_xl=e[r].max_xl;//左边可能没有房子
//情况1、3中，min_xld的更新要先判断区间上升序列长度是否为1，否则由于左子区间为0，min_xl会误更新为0 
        else{
            e[k].max_xl=e[r].max_xl;//更新斜率最值 
            e[k].min_xl=e[l].min_xl;
        }
    }
    else if(e[r].max_xl<=e[l].max_xl){//右子树最大的斜率也比左子树最大的斜率小，一个房子也看不见 
        e[k].len=e[k+1].len; 
        e[k].max_xl=e[k+1].max_xl;
        e[k].min_xl=e[k+1].min_xl;
    }
    else{//右子树最大比左子树最大大，同时最小的比最大的小，右边房子有比左边最高房子高的有低的 
        f=0;//探讨右边的有效len,f为k的右子区间对答案有贡献的长度
        query(k+e[k+1].sum*2,e[k+1].max_xl);//在k的右子区间里找>k的左子区间上升序列最大值的序列长度
        if(f>0){	//右边房子有能看见的，有解才更新 
            e[k].len=e[k+1].len+f;//左区间的数加上在右子区间找到的有效个数 
            if(e[k].len==1) e[k].max_xl=e[k].min_xl=e[k+e[k+1].sum*2].max_xl;//左边可能没有房子 
            else{	//更新最值,如果f<0，则最大斜率和最小斜率不变 
                e[k].max_xl=e[k+e[k+1].sum*2].max_xl;
                e[k].min_xl=e[k+1].min_xl;
            }                
        }
    }	 
}
//维护 
inline void change(int k)
{
    if(e[k].l==e[k].r)	//遍历到叶子结点 
    {
        e[k].len=1;//叶子结点，对于每一个叶子节点，从这段区间头可以看到的楼房数量一定为1 
        e[k].max_xl=e[k].min_xl= double (y) / x;//最大、最小斜率自然也相同 
        return;    
    }
    int mid=e[k].l+e[k].r>>1;
    if(x<=mid) change(k+1);
    else change(k+e[k+1].sum*2);
    up(k);    //每次运行这一步的时候，k的子节点已经维护过值了，这时更新斜率最值和len 
}
int main()
{
    scanf("%d%d",&n,&m);
    build(1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        change(1);
        printf("%d\n",e[1].len);
    }
}

