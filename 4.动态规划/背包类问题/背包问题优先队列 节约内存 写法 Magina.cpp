/*
数据太大 
01背包的时候就觉得有很多状态其实是没有用的，我们可以不记录它的啊！
剪枝：用优先队列。按金钱递减排序，以及花费时间递增排序，金钱少但是时间多，这样的状态可以舍弃。 
因为联通块的才能一起选，所以就分成几部分做，用并查集求联通块、
本题亮点：
由联通块->并查集，不在同一联通块内的物品不能选，类似多个01背包，利用并查集一个集合一个集合看 
由数据特别大->优先队列，因为数据的关系，用排好序的队列可以去除不实用的物品，还可以避免数组遍历中出现的无效遍历和内存浪费
			->滚动数组，两个队列，一个老一个新，在老队列里将不错的物品(选和不选)存入新队列，在新队列里去除不实用的物品后存入老队列 
对每个联通块(01背包)求ans,将每个物品装与不装的情况分别记录进去，再通过剪枝减少计算量，直到得到最优解 
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=60;
const int INF=0x7fffffff;
int n,m,k,w[N],v[N],fa[N];
struct dat{
    int x,y;  //时间，金钱 
    bool operator < (const dat &rhs) const{
        return y<rhs.y || y==rhs.y && x>rhs.x;//y(金钱)大的优先级高，相同金钱下时间短的优先级高 
    }
};
priority_queue<dat> q1,q2;//两个队列分别是选和不选，相当于滚动数组 

int getfa(int x)//并查集查找根节点 
{ 
	return x==fa[x] ? x : fa[x]=getfa(fa[x]); 
}

int main()
{
    int T,kase=0; 
	scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) fa[i]=i;//并查集数组初始化 
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&w[i],&v[i],&k);
            for (int j=1;j<=k;j++) { 
                int x; 
				scanf("%d",&x);
                fa[getfa(x)]=getfa(i);//查找x的根节点并将其接到i上，形成以i为根节点的树 
            }
        }
        
        int ans=INF;//答案初始化为最大值 
        for (int i=1;i<=n;i++) 
            if (fa[i]==i){  //一个联通块的物品，i是根节点  
                while (!q1.empty()) q1.pop();//初始化 
                while (!q2.empty()) q2.pop();
                q1.push((dat){0,0});//初始什么物品都没选 
                
                for (int j=1;j<=n;j++) {  //寻找i集合中的物品 
                    if (fa[j]!=i) continue;
                    while (!q1.empty()){//先遍历老的，将不错的存入新的队列 
                        dat u=q1.top(); q1.pop();
                        if (u.y>=m){ //剪枝1，单个物品金钱直接大于等于需要值 
							ans=min(ans,u.x); 
							continue; 
						}  
                        if (u.x>=ans) continue;  //剪枝2，单个物品所需时间大于等于目前答案 
                        q2.push(u);  //不选 
                        int x=u.x+w[j],y=u.y+v[j];//选，所需时间、金钱增加  
                        if (y>=m){ //剪枝1 
							ans=min(ans,x); 
							continue; 
						}  
                        if (x>=ans) continue;  //剪枝2 
                        q2.push((dat){x,y});  //选 
                    }
                    int Min=INF;
                    while (!q2.empty()){//再遍历新的，除去不实用的剩下物品存入老的 
                        dat u=q2.top(); q2.pop();
                        if (u.x<Min) q1.push(u),Min=u.x; //剪枝3:钱比别人少时间却还比别人多，这样的状态没有用 
                    	//因为优先队列里物品会按金钱由小到大排序，遇到 u.x<Min说明是可排除的物品，不买 
					}
                }
            }
        if (ans==INF) printf("Case %d: Poor Magina, you can't save the world all the time!\n",++kase);
        			//如果ans=INF，表示没有结果可以达到或超过m,不存在解 
		else printf("Case %d: %d\n",++kase,ans);    
    }
    return 0;
}
