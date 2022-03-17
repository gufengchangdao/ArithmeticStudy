
#include<bits/stdc++.h>
#define check(a,b)(a>=0&&a<3&&b>=0&&b<3)//判断是否越界 
using namespace std;
const long MAX=362880;
int	begin[9],end[9];//开始与结束状态 
struct node{
	int dir[9];//每种状态 
	int toop;//记录最小步数 
};
long visted[MAX]={0};//标记 
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//0-n的阶乘 
//用康托展开 判重 ，3方格有9的阶乘大小的状态 
bool cantor(int str[],int n)//状态、元素个数 
{
	long result=0;//result记录时第多少种状态 
	for(int i=0;i<n;i++){	//判断比str[]小的排列的个数来判断排名 
		int sum=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j]) sum++;
		result+=sum*factory[n-i-1];//排名=比当前位小的数的个数*未固定的数的阶乘 
	}
	//判断该状态是否被标记过 
	if(!visted[result]){
		visted[result]=1;//标记并返回true 
		return 1;
	}
	else return 0;
}

int bfs()
{
	//处理起点 ：标记、路径初始化 、存入
	node start;
	queue<node>q;
	memcpy(start.dir,begin,sizeof(start.dir)); 
	start.toop=0;//路径为0 
	cantor(start.dir,9);//标记起点 
	q.push(start);
 
	while(!q.empty()){
		//读取队首结构体，判断是否满足条件，放这里是因为起点未判断是否满足条件 
		start=q.front(); q.pop();
		if(memcmp(start.dir,end,sizeof(end))==0) return start.toop;
		//一维变二维再回到一维，判断，存入、标记 
		int z,nz;//z为原来0的位置，nz为移动后0的位置 
		for(z=0;z<9;z++) 
			if(start.dir[z]==0) break;	//找0的位置 
		
		int x=z%3;//横坐标 
		int y=z/3;//列坐标 
		for(int i=0;i<4;i++){
			int newx=x+dir[i][0];
			int newy=y+dir[i][1];
			nz=newx+newy*3;
			
			if(check(newx,newy)){//判断是否越界 
				node newnode;
			memcpy(&newnode,&start,sizeof(node));//结构体复制用&、size(node) 
				swap(newnode.dir[z],newnode.dir[nz]);//变换到新的位置 
				newnode.toop++;//路径加一 
				if(cantor(newnode.dir,9))//如果未被标记就输入队列中 
					q.push(newnode);
			}
		}	
	}
	return -1;//所有路走完了也没发现符合目标状态的情况 
}

int main()
{
	for(int i=0;i<9;i++) scanf("%d",&begin[i]);
	for(int i=0;i<9;i++) scanf("%d",&end[i]);
	int num=bfs();
	if(num!=-1) printf("%d\n",num);
	else printf("Impossible\n");
}
