//Greg and Array
/*
���⣺��n��ԭ����a,m�������k��ѡ��ѡ����ǲ�����ŵ����䣬��������a���� 
	˫�ز�֣��Բ���ѡ������Ĳ�֡��ڶ�ԭ��������Ĳ��	
	�������Ӧ�����Ĳ�������num������a 
	
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const ll maxn=1e5+10; 
ll a[maxn],d[maxn]; //ԭ�����ԭ����Ĳ������ 
ll op[maxn][5];		//���� 
ll n,m,k;
ll cnt[maxn];	//�����Ĵ����Ĳ������ 
ll num[maxn];	//�����Ĵ��� 

int main()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];	 
	for(ll i=1;i<=m;i++)		//���������� 
		cin>>op[i][1]>>op[i][2]>>op[i][3];
	
	ll x,y;
	while(k--){		//���ߴ洢 �ȶ�Ҫִ�е����������������� 
		cin>>x>>y;
		cnt[x]++;
		cnt[y+1]--;
	}
	for(int i=1;i<=m;i++) num[i]=num[i-1]+cnt[i];
		
	for(ll i=1;i<=n+1;i++)		//�ٶ����������ݲ�� 
		d[i]=a[i]-a[i-1];		//��ֵ 
	for(ll i=1;i<=m;i++){		// 
		d[op[i][1]]+=op[i][3]*num[i];
		d[op[i][2]+1]-=op[i][3]*num[i];
	}
	for(ll i=1;i<=n;i++)
		a[i]=a[i-1]+d[i];
	for(ll i=1;i<=n;i++)
		cout<<a[i]<<' ';
//	cout<<a[n]<<endl;
 
	return 0;
}
