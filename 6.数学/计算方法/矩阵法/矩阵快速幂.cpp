矩阵快速幂是用来求解递推式的，所以第一步先要列出递推式:
随时间变化的n个量，每秒所有量都会按照一定规律变化
看似可以打表，但是数据范围太大，一般超大的数都是作为幂次
构造矩阵规律：M*a[n-1]=a[n],M必须全为常数，一般为maxn*maxn阶的，而a为maxn*1阶的 
[M]*a[n-1]=a[n]
a[n-1]中一般含有f[n-1]、f[n-2]和必要的常数 
[M]一般还有1、0和必要的常数 
struct mat//用矩阵存数组 
{
	int m[maxn][maxn];
	mat(){	//建立变量的时候就会运行，对矩阵初始化 
		memset(m,0,sizoef());
	}
};

 
int res[3][3],M[3][3],ans[3][3];
int temp[3][3];
int len=2;
const int N=2;
const int mod=10000; 
void multi(int a[][N],int b[][N],int x,int y)//a一般都作为N*N阶矩阵，N只是矩阵大小，不代表有效数据 
{											//	有效数据 a[x][len]*b[len][y]														
	memset(temp,0,sizeof(temp));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<len;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<x;i++)	
		for(int j=0;j<y;j++) a[i][j]=temp[i][j];
}

void pow(int a[][N],int n)//最后res数组就是答案 
{
	memset(res,0,sizeof res);
	for(int i=0;i<len;i++) res[i][i]=1;
	while(n){
		if(n&1) multi(res,a,len,len);
		n>>=1;
		multi(a,a,len,len); 
	}	
}
