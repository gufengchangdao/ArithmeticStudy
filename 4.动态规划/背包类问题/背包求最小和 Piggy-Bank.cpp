//����������ҳ�����������ȷ����Ǯ�������ͽ��
/*
ֻ��Ҫ��dp[1~n]ȫ����ֵΪ���ֵ������ʱѡ����С�ļ��ɣ���dp[V]�������ֵʱ��˵��������������� 
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=5e8;
int v[505],w[505],dp[10005];
int main()
{
	int t,e,f,n,V;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&e,&f);
		V=f-e;
		for(int i=1;i<=V;i++) dp[i]=100000000;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
		for(int i=1;i<=n;i++)
			for(int j=w[i];j<=V;j++){
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]); 
			}
			if(dp[V]==100000000) printf("This is impossible.\n");
			//dp[V]=min(dp[V],dp[V-w[i]]+v[i])ʱ�������ڽ��֮��ΪV-w[i]���������ʱ��û�н� 
			else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
	}
}
/*
Captain on the bridge
*/
