#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e2+5;
//node 
struct node{
	int top1;
	int top2;
	int dis;
};
//find寻找路径 
struct state{
	int top1;
	int top2;
	int op;
	int num;
}findd[maxn][maxn];
int v1,v2,L;
bool visited[maxn][maxn]={false};
char str[][10] = { "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",  "POUR(2,1)", "POUR(1,2)"};

void findpath(int x,int y)//第一次x，y为最终状态 
{
	int beftop1=findd[x][y].top1;
	int beftop2=findd[x][y].top2;
	if(findd[x][y].num==0){//到达初始状态 
		return;
	}
	findpath(beftop1,beftop2);
	printf("%s\n",str[findd[x][y].op]);
}

void bfs(int v1,int v2,int L)
{
	queue<node> q;
	memset(visited,false,sizeof(visited));//初始化 
	memset(findd,0,sizeof(findd));
	node next;
	next={0,0,0};
	q.push(next);
	visited[0][0]=true;
	
	while(!q.empty()){
		node start;//作为基础 
		start=q.front();
		q.pop();
		if(start.top1==L||start.top2==L){
			printf("%d\n",start.dis);
			findpath(start.top1,start.top2);
			return;
		} 
		for(int i=0;i<6;i++){
			switch(i){
				case 0:next.top1=v1;next.top2=start.top2;break;//1fill 		
			 	case 1:next.top2=v2;next.top1=start.top1;break;//2fill 
				case 2:next.top1=0;	next.top2=start.top2;break;
				case 3:next.top2=0;	next.top1=start.top1;break;
				case 4:{
						int temp=start.top1+start.top2-v1;
						if(temp>=0){//2还有剩余 
							next.top1=v1;
							next.top2=temp;			 	
			 			}
			 			else{//2没有剩余 
			 				next.top1=start.top1+start.top2;
							next.top2=0;	
						}
					}
					break;
				case 5:{
						int temp=start.top1+start.top2-v2;
						if(temp>=0){//1还有剩余 
							next.top2=v2;
							next.top1=temp;			 	
			 			}
			 			else{//1没有剩余 
			 				next.top2=start.top1+start.top2;
							next.top1=0;	
						}
					}
					break;
			}
			next.dis=start.dis+1;
			if(!visited[next.top1][next.top2]){//记下路径、标记、存入 
				findd[next.top1][next.top2].top1=start.top1;
				findd[next.top1][next.top2].top2=start.top2;
				findd[next.top1][next.top2].op=i;
				findd[next.top1][next.top2].num=start.dis+1;
				visited[next.top1][next.top2]=true;
				q.push(next);
			}
		}
	}
	printf("impossible\n"); 
}

int main()
{
	while(~scanf("%d%d%d",&v1,&v2,&L)){
		bfs(v1,v2,L);
	}
}
  
