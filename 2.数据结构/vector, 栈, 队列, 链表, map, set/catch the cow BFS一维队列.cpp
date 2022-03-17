#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define check(a)(a>=0&&a<maxn)//判断是否出界 
using namespace std;
const int maxn=100001;
queue<int> q;
int step[maxn]={0};//记录到了每一位置所走的步数并初始化为0 
bool vis[maxn];//标记是否走过 
int n,k;

int bfs()
{
	int start,next;
	//读取、标记 
	q.push(n);
	vis[n]=true;
	//循环，BFS 
	while(!q.empty()){
		//读取队首位置 
		start=q.front();
		q.pop();
		
		for(int i=0;i<3;i++){
			//3种走法 
			if(i==0) next=start-1;
			else if(i==1) next=start+1;
			else next=start*2;
			//判断是否出边界和是否走过 
			if(check(next)&&!vis[next]){
				q.push(next);//读入 
				vis[next]=true;//标记 
				step[next]=step[start]+1;//记录 
			if(next==k) return step[next];//循环出口就是找到最短路径 
			}
		}	
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	while(!q.empty()) q.pop();//队列创建后先清空 
	memset(vis,false,sizeof(vis));//false表示喂走过，true代表已经走过 
	if(n>=k) printf("%d\n",n-k);
	else printf("%d\n",bfs());
} 
