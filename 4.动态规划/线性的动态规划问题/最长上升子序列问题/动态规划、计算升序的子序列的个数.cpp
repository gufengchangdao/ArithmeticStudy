 //输入一行16进制数，求升序的子序列的个数，例如
//001A:0,	1,01,	A,0A,1A,01A    规律写出来了、
//逐位查找、动态规划 
#include<bits/stdc++.h>
using namespace std;
char a[1000005];//原数组 
int aa[1000005];//新数组对原数组进行改良 
int dp[20];// 
int main()
{
	long long sum=0;
	scanf("%s",a+1);
	int len=strlen(a+1);//从a[1]开始计算 
	for(int i=1;i<=len;i++){//十进制数表示，消去字符 
		if(a[i]>='0'&&a[i]<='9') aa[i]=a[i]-'0';
		else aa[i]=a[i]-'A'+10;  
	}
	//从左到右逐位看 
	for(int i=1;i<=len;i++){ 
		dp[aa[i]]=1;//两个作用：本身是一个，对重复的数重置并重新计算 
		for(int j=0;j<aa[i];j++)//注意j的取值是0<=j<aa[i] 
			dp[aa[i]]+=dp[j];
	}
/*	
	dp[aa[i]]=1;对于同一个数先后都出现过，取较后面的那个数计算，这时保证解最多，故不能用dp[aa[i]]！=0来判重
	j从0到17循环一遍，与比aa[i]小的j对应的数进行累加，即
	dp[n]=dp[n-1]+dp[n-2]+......+dp[1]+dp[0] 
*/ 
	for(int i=0;i<18;i++) sum+=dp[i];
	printf("%lld\n",sum);
} 
