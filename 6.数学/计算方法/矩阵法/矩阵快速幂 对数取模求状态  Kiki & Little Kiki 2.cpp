//Kiki & Little Kiki 2 
/*
���⣺m��n���ƣ�ÿһ��n���ƶ���仯���仯���������i-1����ԭ�������ģ���i״̬��ת(1��0��0��1)
	���i-1�������i���仯����1���Ƶ������n����m���n���ĵƵ���� 
	��������ݣ������֪��i������һ���תֻ̬��i��i-1�йأ�����ÿ�����еƶ���仯������ת�ƾ��� 
								  light1							  			
								  light2
	������ڵ�һ������˵ [10001]* light3 =nowlight1			�����3�֣�0������λ�ö�Ϊ0����1Ϊ��	
								  light4							1��ǰ1��0��ǰ0��1����1��Ϊ�� 
								  light5							2��ǰ��1����1Ϊ�� 
				[10001]													�ʶ�2ȡģ����
				[11000]	
����ת�ƾ���M:	[01100]
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

void pow(int a[][N],int n)//���res������Ǵ� 
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

