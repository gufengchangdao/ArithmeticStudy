//P2622 关灯问题II
/*
	n盏灯，m个按钮，形成一个m*n的矩阵，每个按钮施加给第j盏灯的效果由a[i][j]决定
		a[i][j]=1 亮变暗，其他不变；=-1 暗变亮，其他不变；=0 啥变化也没有，
		起初n盏灯全亮，求全灭的最小操作次数 n<=10 
	n<=10,要记录每个步骤的状态，已知灯只有两种状态，且n较小，可知用状态压缩，
		用二进制的方式表示灯的状态，用位运算对单个灯进行修改，用十进制数存储 

*/
#include<stdio.h>
#include<queue>
using namespace std;
bool vis[3000];
int n,m;
int a[105][15];	//原始数组 
struct node{
	int s,dis;	//分别为每个阶段的状态、操作数 
};

int bfs()
{
	queue<node>q;
	q.push((node){(1<<n)-1,0});	//直接存入数组，初始的时候n个灯全亮，即对应的二进制有n个1 
	
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		if(cur.s==0) return cur.dis;
		
		for(int i=1;i<=m;i++){//对每个按钮遍历 
			int next=cur.s;
//printf("取出%d ",next);
			for(int j=1;j<=n;j++){//对每个灯进行遍历 
				if(a[i][j]==1&&next&(1<<(j-1))) next^=1<<(j-1);//操作是1且第j盏灯是亮的，变亮
				else if(a[i][j]==-1&&!(next&(1<<(j-1)))) next^=1<<(j-1);//操作是-1且第j盏灯是灭的，变暗
	//关键步骤：1<<j-1是将1左移j-1位，则只有第j位为1，1^1=0 亮变暗, 1^0=1 暗变亮      
			}
			if(!vis[next]){
				vis[next]=1;
				q.push((node){next,cur.dis+1});
//printf(" 存入%d %d\n",next,cur.dis+1);
			}
		} 
	}
	return -1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);	
	printf("%d",bfs());
} 
