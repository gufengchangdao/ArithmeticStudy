//Consumer
/*
题意：买商品，但是商品需要袋子装，每种商品所用袋子不同，袋子有价格且要先买，问最大价值 
有依赖背包：买商品需要买袋子，且多个类型的商品，相当于多组背包，遍历每个袋子中可以装的商品
	对于每组，先买袋子，买了袋子对商品遍历，最后再与上一组(相当于当前组不买)比较得到当前组答案 
	注意：存在背包不可能的情况，即买不到的情况，f初始化为-1，但是初始条件f[0][]要为0 
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int f[55][100005];
int n,V,fw,m;
int main ()
{
	scanf("%d %d",&n,&V);
	memset(f,-1,sizeof(f));   //有依赖关系，要赋初值-1
	memset(f[0],0,sizeof(f[0]));
	for(int k=1;k<=n;k++){
		scanf("%d %d",&fw,&m);//fw为钱
		//买这组 
		for(int j=fw;j<=V;j++)
			f[k][j]=f[k-1][j-fw];  //先让i层买盒子，因为盒子没有价值，所以直接等于上一层的花费+盒子钱
		for(int j=0;j<m;j++){   //在已花费盒子钱的基础上，此时再对dp[i]层做01背包，即i层一个盒子多种物品的最大价值        
			int c,w;
			scanf("%d %d",&c,&w); //费用和价值 
			for(int j=V;j>=c;j--){
				if(f[k][j-c]!=-1)  //注意依赖背包有不可能的情况，这里即k买不到盒子和这个物品，不能装物品
						//等于-1的时候表示，这种情况不存在 
					f[k][j]=max(f[k][j],f[k][j-c]+w);  
			}
		}
 		for(int j=0;j<=V;j++)
				f[k][j]=max(f[k-1][j],f[k][j]);  //不要忘了考虑不选当前组的情况（不是必选）
		}
		printf("%d\n",f[n][V]);
	return 0;
}
