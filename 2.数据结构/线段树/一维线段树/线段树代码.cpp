/*
线段树的单点查询、单点修改、区间查询、区间修改共同点：
1. 判断：是否找到有效区间(叶子结点、子区间)、无效区间(跑到所需区间外了),处理并返回 
2. 懒标记下传：判断之后下传 
3. 查找：(判断之后)查找左右子结点 
4. 状态合并：每次修改完子结点后就要更新父节点信息，信息量大可以装进函数里 
*/
#include<cstdio>
using namespace std;
int n,p,a,b,m,x,y,ans;
struct node
{
    int l,r,w,f;//f是加法的懒标记，初始化都为0 
}tree[400001];	//法1：4倍空间、法2：利用dfs顺序储存，2倍空间 
inline void build(int k,int ll,int rr)//建树 
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
//标记下传
inline void down(int k) 
{
    tree[k*2].f+=tree[k].f;
    tree[k*2+1].f+=tree[k].f;
    tree[k*2].w+=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
		//这里之所以不用自己的标记是因为自己的标记之前就有值，而这段标记不是自己该加的 
    tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
    tree[k].f=0;
}
//单点查询
inline void pask(int k)
{
    if(tree[k].l==tree[k].r)
    {
        ans=tree[k].w;
        return ;
    }
    if(tree[k].f) down(k);//可以把这里的判断放到down函数的开头 
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) pask(k*2);//可以把这里的判断放到函数开头判断是否出界 
    else pask(k*2+1);
}
//单点修改 
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
//区间查询 
inline void qask(int k)//可以设为有返回值的函数，有效区间就返回，函数最后返回左节点和右结点返回值之和 
{
	//if(k>n*4) return;既可以根据结点下标剪枝，又可以根据结点的区间剪枝，毕竟 x>0,无效数据的l=0，不可能记录进去 
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
inline void qchange(int k)//区间修改 
{
	//if(k>n*4) return;既可以根据结点下标剪枝，又可以根据结点的区间剪枝，毕竟 x>0,无效数据的l=0，不可能记录进去 
	if(y<tree[k].l || tree[k].r<x) return;
    if(tree[k].l>=a&&tree[k].r<=b)
    {
        tree[k].w+=(tree[k].r-tree[k].l+1)*y;//这里相当于每个数都加上y 
        tree[k].f+=y;//加上懒标记，表示这段区间进行修改过 
        return;
    }
    if(tree[k].f) down(k);//如果这段区间进行修改过，那个子区间也要进行修改，同时再把这段区间懒标记清0 
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) qchange(k*2);
    if(b>m) qchange(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
int main()
{
    scanf("%d",&n);//n个节点 
    build(1,1,n);//建树 
    scanf("%d",&m);//m种操作 
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p);
        ans=0;
        if(p==1)
        {
            scanf("%d",&x);
            pask(1);//单点查询,输出第x个数 
            printf("%d",ans);
        } 
        else if(p==2)
        {
            scanf("%d%d",&x,&y);
            pchange(1);//单点修改 
        }
        else if(p==3)
        {
            scanf("%d%d",&a,&b);//区间查询 
            qask(1);
            printf("%d\n",ans);
        }
        else
        {
             scanf("%d%d%d",&a,&b,&y);//区间修改 
             qchange(1);
        }
    }
}
