
/*
���⣺�ַ���ɾ�������ַ�ʹ���Ϊ���Ĵ� 
	���������м�ƽ������н������£����ֲ���ȵ�ʱ��һ��Ҫɾ�����ߵ�ĳһ������dfs�ݹ鼴�� 
*/
#include<bits/stdc++.h>
//#define sc(n) scanf("%d",&n);
//#define scl(n) scanf("%lld",&n); 
using namespace std;
const int maxn=1e5;
char a[2005];

int dfs(int l,int r,int k)
{
//	if(k>2) return 0;
	if(l>=r) return 1;
	if(a[l]==a[r]) return dfs(l+1,r-1,k);
	if(k==2) return 0;//���е����˵��a[l]��=a[r]����ʱk==2���޽� 
	return dfs(l+1,r,k+1)||dfs(l,r-1,k+1);
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,a);
		if(dfs(0,n-1,0)) printf("Yes\n");
		else printf("No\n");
	}	
}
