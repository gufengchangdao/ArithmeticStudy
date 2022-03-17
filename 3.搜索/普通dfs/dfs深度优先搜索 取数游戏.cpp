//取数游戏 
//在一个矩阵中，取得一个位置的数后，该数周围的8个数都不能取，求取得的最大值 
//数据很少，因为相邻的数不能取，那么每次决策就会影响下次结果，从而导致贪心决策不能最优化 
//深度优先搜索dfs： 递归和回溯 
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dir[8][2]={-1,0,-1,1,-1,-1,0,1,0,-1,1,-1,1,0,1,1};
int ans,prem,n,m;
int v[8][8],mark[8][8];//mark记录周围8个位置有几个数 

void dfs(int x,int y)//递归所有情况 
{
	if(y>=m+1){	//先y后x 
		dfs(x+1,1);
		return; 
	}
	if(x==n+1){
		ans=max(ans,prem);
		return;
	}
	
	dfs(x,y+1);//不取的情况 
	
	if(!mark[x][y]){//满足情况并且取 
		prem+=v[x][y];
		for(int i=0;i<8;i++)
			mark[x+dir[i][0]][y+dir[i][1]]++;
		dfs(x,y+2);
		
		for(int i=0;i<8;i++)//回溯 
			mark[x+dir[i][0]][y+dir[i][1]]--;
		prem-=v[x][y];
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		memset(mark,0,sizeof(mark));
		ans=0;prem=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&v[i][j]);
		dfs(1,1);
		printf("%d\n",ans);
	}
}
