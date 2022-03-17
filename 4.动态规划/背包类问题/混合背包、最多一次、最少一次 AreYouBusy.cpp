//AreYouBusy
/*
题意：有n组工作，每个工作都可以获得满足感工作时间为V,每组工作有要求，最多选1件、最少选1件、任意选， 
	求可以获得的满足感最多为多少 
	多组任务，相当于多组背包
	至少选1件： 把当前组全部赋为最小值， 
	f[i][z]=max(max(f[i][z],f[i][z-w[j]]+v[j]),f[i-1][z-w[j]]+v[j]);
						当前组的规划		上一次结果转移并选择一件物品 
	至多选1件： 在规划的时候只选择当前不选与上一次结果选，无论怎么遍历都是选0，1的状态与选0、1的状态比较 
	f[i][z]=max(f[i][z],f[i-1][z-w[j]]+v[j]);
				当前结果	上一次结果转移并选择一件(可可以不选，因为f[i][z]是继承上一次结果) 
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1<<29;
int w[105],v[105],f[105][105];
int main()
{
	int n,V,m,s,ans;
	while(~scanf("%d%d",&n,&V)){
		memset(f,0,sizeof(f));
		
		for(int i=1;i<=n;i++){
			scanf("%d%d",&m,&s);
			for(int j=1;j<=m;j++) scanf("%d%d",&w[j],&v[j]);
			if(s==2){//自由取 
				for(int j=0;j<=V;j++) //当前组初始化
					f[i][j]=f[i-1][j];
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(f[i][z],f[i][z-w[j]]+v[j]);
			}
			else if(s==0){//至少取1次 
				for(int j=0;j<=V;j++)//当前组初始化
					f[i][j]=-maxn;//dp[0][j]则保持0 
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(max(f[i][z],f[i][z-w[j]]+v[j]),f[i-1][z-w[j]]+v[j]);
					//f[i-1]是为了把上一次结果转移过来的同时必须选择一个，选择之和就成为了f[i]
					//保证至少选择一个
			}
			else if(s==1){//最多取一次 
				for(int j=0;j<=V;j++)  //当前组初始化
					f[i][j]=f[i-1][j];
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(f[i][z],f[i-1][z-w[j]]+v[j]);
						//f[i-1]是不变的，只要f[i][j]取过一次就不会再取了，当然也可以不取
			}
		}
		ans=max(-1,f[n][V]);//没有完成任务只会在至少取1个达不到的情况，值都为负的，做输出调整，输出-1
		printf("%d\n",ans);
	}
} 
