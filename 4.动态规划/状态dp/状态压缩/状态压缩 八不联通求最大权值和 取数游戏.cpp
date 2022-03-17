//取数游戏 
/*
在一个矩阵中，取得一个位置的数后，该数周围的8个数都不能取，求取得的最大值 
题解：状态压缩 
	考虑每一行的每一种序列的合法性，不合法标记，合法则求出该序列获得的权值和 
	一行一行遍历，每行遍历所有序列，每种序列遍历上一行序列，求出该种序列的最优解，贪心 
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,m,ans=0;
int a[7][7],v[7][70],dp[7][70];

void init(int i,int j)
{
    if((j<<1)&j) {//左右相邻，不合法情况，标记后退出 
        v[i][j]=-1;
        return ;
    }
    for (int x=1;x<=m;x++)	//处理该种排列的获得的权值和 
        if(j&(1<<(x-1))) v[i][j]+=a[i][x];	 
}

int main()
{
	int t;
    scanf("%d",&t);
    while (t--){
        ans=0;
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        //计算每一行的合法情况的权值和        
        for (int i=1;i<=n;i++) 
            for (int j=0;j<(1<<m);j++)
                init(i,j);
                
        m=1<<m;
        for (int i=0;i<m;i++){//第一行不用考虑前一行，优先处理 
        	dp[1][i]=v[1][i];
            ans=max(ans,dp[1][i]);
        }
        for (int i=2;i<=n;i++)
            for (int j=0;j<m;j++){//该行该种排列 
            	if(v[i][j]==-1) continue;//该种排列不合法 
                for (int k=0;k<m;k++){//遍历上行所有情况 
                	if(v[i-1][k]==-1) continue;//上一行该种排列不合法 
                    if(j&k) continue;//上下相邻 
                    if((j<<1)&k) continue;//上下斜方向相邻 
                    if((j>>1)&k) continue;//由于不是一个数，判断两个数的时候左移和右移都要 
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i][j]);//由上行最优解得到该行 
                }
            	ans=max(ans,dp[i][j]);//也可以最后再遍历最后一行的dp值 
			}
        printf("%d\n",ans);
    }
    return 0;
}

