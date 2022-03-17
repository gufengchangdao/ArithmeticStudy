//连连看
/*
题意：从起点(x1,y1)到(x2,y2)要求
		两点数值相等，不能是同一个点 
		两点都不为0，且起点能只走0走到终点 
		最多只能转折两次，超过两次不行 
	求是否可达
	bfs:结构体中用trun记录转折次数，起点次数为-1，存入。对一个点遍历的时候，遍历四个方向，对于每个
	方向的每个点，只要没出界或不可走，都沿着该方向不断搜索，因此对每一个for循环找新路，都有trun加1
	因为只要是搜索过的点trun一定是最小，同方向的点也会因为标记过不会被存入队列 
	 
*/
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int map[1001][1001];
bool v[1001][1001];
int x1,y1,x2,y2;
bool flag;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//方向数组
struct node{
	int x;
	int y;
	int trun;
}start,endd;
queue<node> q;
 
bool judge(int x0,int y0)
{
	if(x0<0||x0>=n||y0<0||y0>=m)
		return true;
	if(x0==x2-1&&y0==y2-1) //到达终点 
		return false;
	if(map[x0][y0]!=0)
		return true;
	return false;
}

void bfs(int x0,int y0)
{
	int i;
	while(!q.empty()) q.pop();
 
	start.x=x0;
	start.y=y0;
	start.trun=-1;//注意：起点记录为-1，让他"多转"一次 
	v[x0][y0]=1;
	q.push(start);
 
	while(!q.empty()){
		start=q.front();q.pop();
		
		if(start.trun>=2) continue;
//	-1 未转过(起点)  0 转过1次了  1 转过两次了  2 转过3次了		
		for(i=0;i<4;i++){
			endd.x=start.x+dir[i][0];
			endd.y=start.y+dir[i][1];
			endd.trun=start.trun+1;
			
			while(judge(endd.x,endd.y)==0){//对着该方向不断搜索 
				if(endd.x==x2-1&&endd.y==y2-1){
					flag=true;
					return;
				}
				if(v[endd.x][endd.y]==0){//同方向的会因为标记不会遍历，故trun没有错 
					q.push(endd);
					v[endd.x][endd.y]=1;
				}
				endd.x+=dir[i][0];	//沿着该方向继续搜索 
				endd.y+=dir[i][1];			
			}
		}
	}
}
 
int main()
{
	int t;
	int i,j;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		for(i=0;i<n;i++)
            for(j=0;j<m;j++)
			    scanf("%d",&map[i][j]);
        scanf("%d",&t);
		while(t--){
            flag=false;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2&&y1==y2){//起点终点相同，不行
                printf("NO\n");
                continue;
            }
            if(map[x1-1][y1-1]!=map[x2-1][y2-1]||map[x1-1][y1-1]==0||map[x2-1][y2-1]==0){
                printf("NO\n");
                continue;
            }
			memset(v,0,sizeof(v));
			bfs(x1-1,y1-1);
			if(flag) printf("YES\n");
            else printf("NO\n");
		}
	}
	return 0;
}
