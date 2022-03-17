//233 Matrix
/*
���⣺����һ�����󣬾���ĵ�0�У�a[0][1]=233,a[0][2]=2333,a[0][3]=23333...�����ǵ�0��������������
	����n,m,a[1][0]��...��a[n][0]��������Ҫ��a[n][m]��ȡģ��a[i][j]=a[i-1][j]+a[i][j-1] 
	��������ݣ���֪m<=10^9�����Ʋ�mӦΪ�ݴΣ��ʹ������ʱӦ��һ��һ���� 
		��֪�ڵ�0�У�ÿһ�ж���f[n]=10*f[n-1]+3 ,����ans������Ӧ����23��3
	[10 0 0 0 0 1]	[23]	[233  		 ]						[10 0 0 0 0 1]			[23]
	[0  0 0 0 0 1]	[3 ]	[3			 ]						[10 1 1 0 0 1]			[x1] 
	[10 1 1 0 0 1]* [x1] =	[x1+233		 ]	Ϊ�˼��㷽�㣬M��Ϊ [10 1 1 1 0 1], ans��Ϊ [x2]
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
 
void multi(int a[][maxn],int b[][maxn],int x,int y)//aһ�㶼��ΪN*N�׾���Nֻ�Ǿ����С����������Ч���� 
{											//	��Ч���� a[x][len]*b[len][y]														
	memset(temp,0,sizeof(temp));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<len;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<x;i++)	
		for(int j=0;j<y;j++) a[i][j]=temp[i][j];
}

void pow(int a[][maxn],int n)//���res������Ǵ� 
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
		//��ʼ������ 
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
