//Floyd算法:动态规划 
/*
从任意节点A到任意节点B的最短路径不外乎2种可能，1是直接从A到B，2是从A经过若干个节点到B
对于每一个节点K，我们检查dis(AK) + dis(KB) < dis(AB)是否成立，如果成立，证明从A到K再到B的路径
	比A直接到B的路径短，我们便设置 dis(AB) = dis(AK) + dis(KB)，这样一来，当我们遍历完所有节点K，
	dis(AB)中记录的便是A到B的最短路径的距离。 

初始化：
	dis[][]	用边长初始化
	path[i][j]	用j来初始化(即边的后缀) ，如果用i初始化的话，便会倒叙存储 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
const int Inf=0x3f3f3f3f;
int dis[maxn][maxn];
int path[maxn][maxn];
int n,m,s,d;

void floyd() 
{
	//初始化 路径path 
    for(int i=1; i<=n ; i++){
    	for(int j=1; j<= n; j++){
   	      	if(dis[i][j]==Inf){
   	           	path[i][j] = -1;//表示  i -> j 不通 
   	      	}
		  	else{
               	path[i][j] = j;// 表示 i -> j 前驱为 i
          	}
   		}
    }
    
    for(int k=1; k<=n; k++)	//n的范围为1~n ，k必须在外围，否则会过早的把i到j的最短路径确定下来了，而
				//当后面存在更短的路径时，已经不再会更新了。 
        for(int i=1; i<=n; i++)
          	for(int j=1; j<=n; j++)
            	if(!(dis[i][k]==Inf||dis[k][j]==Inf)&&dis[i][j] > dis[i][k] + dis[k][j]) {
              		//两点与中转站k都有边连接且有优解 
					dis[i][j] = dis[i][k] + dis[k][j];
              		//path[i][k] = i;//删掉
              		path[i][j] = path[k][j];//记录后缀结点 
            	}
}

void printPath(int from, int to) 
{
    printf("%d-",from);
    while(path[from][to]!=to) {
    	printf("%d-",path[from][to]);
    //    System.out.print(path[from][to] +"");
        to = path[from][to];
    }
    printf("%d\n",to);
}

int main()
{	
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		memset(dis,0x3f,sizeof(dis));	
		
		for(int i=1;i<=m;i++){
			int u,v,l,w,tem;
			scanf("%d%d%d%d",&u,&v,&l);	//u--v的长度l  
			dis[u][v]=l;	
			dis[v][u]=l; 
		}
		
		scanf("%d%d",&s,&d);	//起点s 终点d 
		floyd();
		printPath(s,d);
		printf("dis:%d\n",dis[s][d]);
	}	
}


