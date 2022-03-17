//P2384 最短路
/*
题意：	 
	n个点的带权有向图，m条边，求1到n路径的边权之积最小值，取模 
	计算：在bfs的时候，dis存储log形式，防止溢出；找到最短路后，再沿路径计算答案 
	重点放下面 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define mod 9987
using namespace std;
struct edge{
    int to,next,w;
}e[1000005];
queue<int> q;
int first[1005],po[1005][2];
bool vis[1005]; 
int tot=0;
double dis[1005];

void addedge(int u,int v,int val)
{
    e[++tot].w=val;
    e[tot].to=v;
    e[tot].next=first[u];
    first[u]=tot;	//边 
}

int main()
{
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    memset(dis,127,sizeof(dis));	//初始化最大 
    dis[1]=0;
    q.push(1);//起点存入队列
	//遍历队列中所有的路，有更优解更新，当队列中没有存该顶点开始的路，就把该结点也存入 
    while(q.size()){
        int now=q.front();q.pop();
        vis[now]=0; 
        for(int i=first[now];i;i=e[i].next){	//遍历与now相连的所有边 
            int v=e[i].to;
            if(dis[v]>dis[now]+log(e[i].w)){	//找到更优解，即比先前经过该点的路径还短(或者没走过) 
                dis[v]=dis[now]+log(e[i].w);
                po[v][0]=now;	//保存路径，记录后点的前缀点now 
				po[v][1]=e[i].w;
                if(!vis[v]){	//第一次访问就存入队列，因为当前路径是当前最优解 
					vis[v]=1;
					q.push(v);
				}
            }
        }
    }
    //从终点倒推回起点 
    int ans=1,pos=n;
    while(pos!=1){
        ans=ans*po[pos][1]%mod;
        pos=po[pos][0];
    }
    printf("%d\n",ans);
    return 0;
}
/*
1.
bool vis[1005];
	拿出就取消标记，存入就标记,存入v并标记v表示存入的是以v为起点的一条路，标记是防止重复存入，由于
		非更优解顶点不会存入，所以程序会结束 
2.
e[tot].next=first[u];原本first[u]中是u与指向点的边的信息，现在e[tot]记录进去 
first[u]=tot;	再将u指向e[tot] 
例如 u->a  u->b			u->c  
		u->b->a 	    u->c->b->a	这样就把与u有关的边全部记录下来 
3.
po[v][0]=now;	由于搜索的时候是从起点到终点搜索的，所以保存路径只能记录顶点前驱	
	因此只能从终点找到起点 
*/

