//Kiki & Little Kiki 2 
/*
题意：m秒n个灯，每一秒n个灯都会变化，变化规则，如果第i-1个灯原本是亮的，则i状态反转(1变0，0变1)
	如果i-1是灭的则i不变化，第1个灯的左边是n，求m秒后n个的灯的情况 
	矩阵快速幂；由情况知第i个灯下一秒的转态只于i和i-1有关，并且每秒所有灯都会变化，构造转移矩阵 
								  light1							  			
								  light2
	例如对于第一个灯来说 [10001]* light3 =nowlight1			结果有3种：0、两个位置都为0，新1为灭	
								  light4							1、前1后0，前0后1，新1都为亮 
								  light5							2、前后都1，新1为灭 
				[10001]													故对2取模即可
				[11000]	
构造转移矩阵M:	[01100]
				[00110]
				[00011]	
*/																 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=103;
int len;
int res[N][N],mode[N][N],ans[N][N];
int temp[N][N];
const int mod=10000;

void multi(int a[][N],int b[][N],int x,int y)
{
	memset(temp,0,sizeof(temp));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<x;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%2;
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

signed main()
{
	int n,m;
	char tem[N];
	while(~scanf("%lld",&m)){
		
		scanf("%s",tem);
		len=strlen(tem);
		for(int i=0;i<len;i++) ans[i][0]=tem[i]-'0';
		memset(mode,0,sizeof(mode));
		for(int i=0;i<len;i++)
			if(i==0) mode[i][0]=1,mode[i][len-1]=1;
			else mode[i][i]=1,mode[i][i-1]=1;
		
		pow(mode,m);
//		for(int i=0;i<len;i++)
//			for(int j=0;j<len;j++) printf("%lld%c",res[i][j],j==len-1?'\n':' ');
		multi(res,ans,len,1); 
//		printf("\n");
//		for(int i=0;i<len;i++)
//			for(int j=0;j<len;j++) printf("%lld%c",res[i][j],j==len-1?'\n':' ');
		for(int i=0;i<len;i++) printf("%lld",res[i][0]&1);
		printf("\n");
	}
}

