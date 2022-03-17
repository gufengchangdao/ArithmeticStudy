/*
Dijkstra算法
	基于贪心的思想，使每个被访问的结点都是离起点最短的 
	把所有顶点分为：已选顶点集合 		未选顶点集合
	
更新三个结点信息							初始化 
	vis[] 是否被访问						false 
	dis[] 起点到每个结点的距离信息			INF 
	parent[] 存每个结点被访问时的父亲结点	-1
三个操作 
update
	当每加入一个新的结点，则更新所有位于未选顶点集合中且与改顶点相连的顶点距离信息
	具体：当新节点的距离加边的权值小于对应结点当前的距离时，则更新对应结点距离和父亲数组的信息
scan  
	扫描距离信息，找到所有未选顶点中距离最小的那个顶点，贪心思想，
add
	添加进已选顶点，作为新的结点
由于每次都是选的最短的那条边，所以遍历到每个结点都代表着该路径是起点到该路径的最短路径，遍历n次，
	就会把所有未选结点都装入已选结点 
*/
	 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
struct node{
	int next;
	int len;
	int cost;
};
vector<node>edge[maxn];	//用edge来表示每条边 
int dis[maxn];
int cost[maxn];
bool vis[maxn];

int main()
{
	int n,m,s,d;	
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		for(int i=1;i<=n;i++)	//这里的点为1~n 
			edge[i].clear();
		memset(dis,-1,sizeof(dis));	
		memset(vis,0,sizeof(vis));
		
		for(int i=1;i<=m;i++){
			int u,v,l,w;
			scanf("%d%d%d%d",&u,&v,&l,&w);	//u--v的长度l,花费c  
			node tem={v,l,w};	 
			edge[u].push_back(tem);	//无向图，u->v存入
			tem.next=u;			
			edge[v].push_back(tem);	//v->u存入 
		}
		
		scanf("%d%d",&s,&d);	//起点s 终点d 
		dis[s]=0;	//起点距离为0 
		vis[s]=1;	//标记 
		
		int newp=s;	//当前已选顶点集合的"头" 
		for(int i=1;i<=n;i++){	//遍历n次，因为每遍历一次都标记一个，n次正好全部顶点
		//update	更新"头"的周边顶点 
			for(int j=0;j<edge[newp].size();j++){
				int next=edge[newp][j].next;
				int len=edge[newp][j].len;
				int cos=edge[newp][j].cost;
				if(vis[next]) continue;	//已经标记过的邻点已经是最优解了 
				if(dis[next]==-1||dis[next]>dis[newp]+len||(dis[next]==dis[newp]+len&&cost[next]>cost[newp]+cos)){
					dis[next]=dis[newp]+len;	//存在更优解时更新 
					cost[next]=cost[newp]+cos;	
				}
			}
			//scan 寻找临边最短的顶点，也可能是某一条边遍历到头了，找到新的最短且未访问的点  
			int Min=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(dis[j]==-1) continue;	//-1表示newP与i不相连 
				if(Min>dis[j]) Min=dis[j],newp=j;	
			}
			//add 添加进已选顶点，作为新的结点，新结点的距离在update的时候更新过了，不用变
			vis[newp]=true; 
		}
		printf("%d %d\n",dis[d],cost[d]);
	}	
}


