//给出矩阵格式和矩阵每行的和r[i]和美列的和c[i]，写出满足条件的行列式 

#include<bits/stdc++.h>
using namespace std;
#define ri register int
int n,m,room[105][105],r[105],c[105],good;

void dfs(int x,int y)
{
	if(x>n||y>m) return;
	if(x==n&&y==m){
//		if(r[x]!=c[y]) good=0;
		 room[x][y]=r[x];
		return;
	}
	if(r[x]==c[y]){
		room[x][y]=r[x];
		dfs(x+1,y+1);
	}
	else if(r[x]>c[y]){
		room[x][y]=c[y];
		r[x]-=c[y];
		dfs(x,y+1);
	}
	else{
		room[x][y]=r[x];
		c[y]-=r[x];
		dfs(x+1,y);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		
	good=1;
	int rsum=0,csum=0;
	memset(room,0,sizeof(room));
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;i++){
			scanf("%d",&r[i]);
			rsum+=r[i];
		}
		for(ri i=1;i<=m;i++){
			scanf("%d",&c[i]);
			csum+=c[i];
		}
		if(rsum!=csum) printf("No solution\n");
		else{
			dfs(1,1);
			if(!good) printf("No solution\n");//多余 
			else{
				for(ri i=1;i<=n;i++)
					for(ri j=1;j<=m;j++) printf("%d%c",room[i][j],j==m?'\n':' ');
			}
		}
	}
} 
