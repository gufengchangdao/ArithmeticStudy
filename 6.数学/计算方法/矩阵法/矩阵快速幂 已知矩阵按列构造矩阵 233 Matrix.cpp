//233 Matrix
/*
题意：给出一个矩阵，矩阵的第0行，a[0][1]=233,a[0][2]=2333,a[0][3]=23333...，但是第0列是由条件给出
	给出n,m,a[1][0]、...、a[n][0]都给出，要求a[n][m]并取模，a[i][j]=a[i-1][j]+a[i][j-1] 
	矩阵快速幂：已知m<=10^9，故推测m应为幂次，故构造矩阵时应该一列一列来 
		已知在第0行，每一列都是f[n]=10*f[n-1]+3 ,所以ans矩阵中应该有23和3
	[10 0 0 0 0 1]	[23]	[233  		 ]						[10 0 0 0 0 1]			[23]
	[0  0 0 0 0 1]	[3 ]	[3			 ]						[10 1 1 0 0 1]			[x1] 
	[10 1 1 0 0 1]* [x1] =	[x1+233		 ]	为了计算方便，M改为 [10 1 1 1 0 1], ans改为 [x2]
	[10 1 1 1 0 1]	[x2]	[x1+x2+233   ]						[10 1 1 1 1 1]			[x3]
	[10 1 1 1 1 1]	[x3]	[x1+x2+x3+233]						[0  0 0 0 0 1]			[3 ]
	
*/
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int maxn=13;
int res[maxn][maxn],M[maxn][maxn],ans[maxn][maxn];
int temp[maxn][maxn];
int len=maxn;
const int mod=10000007; 
 
void multi(int a[][maxn],int b[][maxn],int x,int y)//a一般都作为N*N阶矩阵，N只是矩阵大小，不代表有效数据 
{											//	有效数据 a[x][len]*b[len][y]														
	memset(temp,0,sizeof(temp));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<len;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<x;i++)	
		for(int j=0;j<y;j++) a[i][j]=temp[i][j];
}

void pow(int a[][maxn],int n)//最后res数组就是答案 
{
	memset(res,0,sizeof res);
	for(int i=0;i<len;i++) res[i][i]=1;
	while(n){
		if(n&1) 
			multi(res,a,len,len);
		n>>=1;
		multi(a,a,len,len); 
	}	
}

signed main()
{
	int n,m;
	while(~scanf("%lld%lld",&n,&m)){
		//初始化矩阵 
		len=n+2;
		ans[0][0]=23;ans[n+1][0]=3;
		for(int i=1;i<=n;i++) scanf("%lld",&ans[i][0]);
		memset(M,0,sizeof(M));
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++){
				if(j<=i&&i!=0&&i!=n+1) M[i][j]=1;
				if(j==0&&i!=n+1) M[i][j]=10;
				else if(j==n+1) M[i][j]=1;
			}
			
		pow(M,m);
		multi(res,ans,n+2,1);
		printf("%lld\n",res[n][0]);
	}
}
