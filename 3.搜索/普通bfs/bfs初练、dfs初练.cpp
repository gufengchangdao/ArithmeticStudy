//BFS：起点为'@'，可行点为'.'不可行点为'#',计算从起点开始可以行走的点的个数num 

#include<bits/stdc++.h>
#define check(x,y)(x<xx&&x>=0&&y>=0&&y<yy)//判断该点是否位于迷宫内，读取是从0开始的 
using namespace std;
char room[23][23];//创建迷宫 
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//分别向左、向下、向右、向上 
int xx,yy,num=0;//num初始化为0 
struct node{	//定义坐标 
	int x,y;
}start;//队首、下一个坐标 
//在每一点向上下左右行走，读入以后就标记成不可行点，用队列实现 
void bfs(int dx,int dy)
{	//创建队列，读入起点(这里起点为'@',不是'.'，否则读入之后要标记为'#')
	queue<struct node>q;
	start.x=dx;
	start.y=dy;
	q.push(start);
	num=1;//读入后再计数 
	//BFS，直到满足条件，这里为队列为空为出口 
	while(!q.empty()){
		//读取队首坐标，删除队首元素 
		start=q.front();
		q.pop();
		node next;
		for(int i=0;i<4;i++){	//上下左右寻找可行点 
			next.x=start.x+dir[i][0];
			next.y=start.y+dir[i][1];
			if(check(next.x,next.y)&&room[next.x][next.y]=='.'){
				q.push(next);//读入 
				room[next.x][next.y]='#';//标记 
				num++;//计数 
			}
		}
	}
}
int main()
{
	int dx,dy;
	while(~scanf("%d%d",&xx,&yy)){	//读入迷宫大小 
		getchar();//读取换行符 
		if(xx==0&&yy==0) return 0; 
		for(int y=0;y<yy;y++) 
			for(int x=0;x<xx;x++){
				scanf("%c",&room[x][y]);
				if(x==xx-1) getchar();//读取换行符 
				//读取的时候寻找起点，dx、dy记录起点 
				if(room[x][y]=='@'){
					dx=x;
					dy=y;
				}
			}
		bfs(dx,dy);
		printf("%d\n",num);
	} 
}
//在读取迷宫的坐标符号的时候，使用scanf()也会读取换行符，必须使用getchar()
//							  使用get()便不需要使用getchar()读取换行符
/* 
void dfs(int dx,int dy)
{
	room[dx][dy]='#';
	//打印走过的位置，用来验证是否正确 
	num++;
	for(int i=0;i<4;i++){
		int newx=dx+dir[i][0];
		int newy=dy+dir[i][1];
		if(check(newx,newy)&&room[newx][newy]=='.'){
			dfs(newx,newy);
			//打印回退的位置坐标，观察回退情况
			//最后一次会从num最大回退到1的情况，即回退到起点 
		}
	}
}
*/ 
