���⣺ 
n����Ʒ��mǮ��ÿ����Ʒֻ����һ����ÿ����Ʒ���м۸�p,����Ҫ��q,����(�����Լ��ļ�ֵ)v
������ӵ�е�Ǯ>=qʱ���ܹ������Ʒ��������ֵ,����q>=p 
�ص㣺����Ҫ��
����������Ʒa: p1 q1 ;b:p2 q2 ��Ҫ�� 
	��a��b��Ҫp1+q2 
	��b��a��Ҫp2+q1
	��a��bʱ��Ǯ����Ӧ��p1+q2>=p2+q1  ,�õ�q1-p1>=q2-p2  ����q-p�������� 
��Ϊdp�����У�dp[1][n]�Ƚ���һ����Ʒ�����꣬dp[2][n]�ڵ�һ����Ʒ������¿��ǵڶ�����Ʒ�����Եڶ���
��Ʒ����µ�һ����Ʒ������һ����Ʒ������µڶ�����Ʒ���൱���ȹ���ڶ�����Ʒ�ٹ����һ����Ʒ���ڶ�
����Ʒ�Ĺ�������Ӱ���һ����Ʒ�Ĺ���


#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int f[5005];
struct node{
	int p,q,v;
}goods[maxn];
bool cmp(node a,node b)
{
    return a.q-a.p < b.q-b.p;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&goods[i].p,&goods[i].q,&goods[i].v);
		}
		sort(goods+1,goods+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=goods[i].q;j--){	
				f[j]=max(f[j],f[j-goods[i].p]+goods[i].v);
			}
		}
		printf("%d\n",f[m]);
	}
}
