//Tautology
/*
题意：p q r s t为逻辑变量，只能为真或为假， Kxy Axy Nx Cxy Exy 的真假都需要看x、y，给出字符串，问
	是否为真言式(恒为真) 
	构造法
		递归解决：从前向后遍历，遇到 KANCE就递归下一个，遇到pqrst直接返回真假 
		栈解决：从后向前，遇到pqrst就存入，遇到 KANCE就拿出来，把获得的值再存入，如果栈为空了，说
			明字符串不合法。合理情况下最后只剩一个真假值 
*/
#include<stdio.h>
#include<string.h>
const int maxn=105;
bool s[6];	//用来存p q r s t 的真假情况 
char a[maxn];
int cnt;	//递归时用的数组指针 

bool cal()
{
	char c=a[cnt];
	bool x,y;
	cnt++;
	switch(c){
		case 'p':return s[0];	//p q r s t直接返回对应变量的真假的情况即可 
		case 'q':return s[1];
		case 'r':return s[2];
		case 's':return s[3];
		case 't':return s[4];
		case 'N':return !cal();	//N,A,C,E,K都要看后面的字符 
		case 'K':x=cal();y=cal();return x&&y;
		case 'A':x=cal();y=cal();return x||y;
		case 'C':x=cal();y=cal();return x<=y;
		case 'E':x=cal();y=cal();return x==y;
		default :return 0;	//如果有不合理字符串，就返回假(虽然数据中可能没有这样的) 
	} 
}

int main()
{
	bool flag;
	while(~scanf("%s",a)&&a[0]!='0'){
		flag=1;
		
		for(int i=0;i<(1<<5);i++){//	对每一个字符串都遍历s的所有情况 
			cnt=0;
			memset(s,0,sizeof(s));
			for(int j=0;j<5;j++)
				if(i&(1<<j)) s[j]=1;
			if(!cal()){		 
				flag=0;break;
			}
		}
		if(flag) printf("tautology\n");
		else printf("not\n");
	}
}
