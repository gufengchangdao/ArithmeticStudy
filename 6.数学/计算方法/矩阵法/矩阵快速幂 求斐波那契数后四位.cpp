//Fibonacci
/*
	给出斐波那契数转移矩阵，求f[n]的后四位
	[1 1]*[f[n-1]]=[f[n]  ] 
	[1 0] [f[n-2]] [f[n-1]]
	M^(n-1)*[f[1]]=[f[n]  ]
			[f[0]] [f[n-1]]
*/
#include<stdio.h>
#include<cstring>
using namespace std;
int res[3][3],a[3][3],b[3][3];
int temp[3][3];
const int N=2;
const int mod=10000;

void multi(int a[][3],int b[][3])
{
	memset(temp,0,sizeof(temp));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<N;i++)	
		for(int j=0;j<N;j++) a[i][j]=temp[i][j];
}

void pow(int a[][3],int n)
{
	memset(res,0,sizeof res);
	for(int i=0;i<N;i++) res[i][i]=1;
	while(n){
		if(n&1) multi(res,a);
		n>>=1;
		multi(a,a); 
	}	
}

int main()
{
	int n;
	while(~scanf("%d",&n)&&n!=-1){
		a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;
		b[0][0]=1;b[1][0]=0;
		if(n==0) res[0][0]=0; 
		else{
			pow(a,n-1);
			multi(a,b);	
		}
		printf("%d\n",res[0][0]);
//		printf("%d %d\n%d %d\n\n",res[0][0],res[0][1],res[1][0],res[1][1]);
	}
}
