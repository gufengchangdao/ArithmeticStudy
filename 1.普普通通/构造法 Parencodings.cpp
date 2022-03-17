//Parencodings
/*
题意：对于一个由括号组成的合法(匹配的)字符串，给出p数组，求w数组 
	S				(((()()())))
	P-sequence	        4 5 6666
	W-sequence	    	1 1 1456
	P[i]是第i个右括号前面左括号的个数
	w[i]是与第i个右括号匹配的左括号到该右括号中右括号的个数
构造法：
	注意w,	如果两个括号匹配，那么两个括号之间的括号也应该匹配，所以统计区间左括号变为统计右括号 
	统计过的匹配的左括号就标记为-1，这样就能知道右括号与哪个左括号匹配了 
*/
#include<stdio.h>
#include<string.h>
const int maxn=105;
int p[maxn];
int a[maxn];	//构造括号数组，1为左括号，0为右括号 
int w[maxn];	

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		int k=1; 
		memset(w,0,sizeof(w));
		memset(a,0,sizeof(a));
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			for(int j=0;j<p[i]-p[i-1];j++) a[k++]=1;	//存入左括号 
			k++;	//跳过为0，即存入右括号 
		}
		
		int c=1;
		for(int i=1;i<k;i++)	
			if(a[i]==0)	//对右括号开始 
				for(int j=i-1;j>=1;j--){	//向前遍历，直到遇到对应左括号 
					if(a[j]) w[c]++;//	如果是左括号，计数 
					if(a[j]==1){	//如果左括号为1，说明a[j]与a[i]匹配，标记后退出 
						a[j]=-1;
						c++; 
						break;
					}
				} 	
		for(int i=1;i<c;i++) printf("%d%c",w[i],i==c-1?'\n':' ');	
	}
} 
