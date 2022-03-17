//Greg and Array
/*
题意：有n个原数组a,m个操作项，k次选择，选择的是操作序号的区间，求操作后的a数组 
	双重差分，对操作选项区间的差分、在对原数组操作的差分	
	先求出对应操作的操作次数num，再求a 
	
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const ll maxn=1e5+10; 
ll a[maxn],d[maxn]; //原数组和原数组的差分数组 
ll op[maxn][5];		//操作 
ll n,m,k;
ll cnt[maxn];	//操作的次数的差分数组 
ll num[maxn];	//操作的次数 

int main()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];	 
	for(ll i=1;i<=m;i++)		//输入任务组 
		cin>>op[i][1]>>op[i][2]>>op[i][3];
	
	ll x,y;
	while(k--){		//离线存储 先对要执行的任务区间与次数差分 
		cin>>x>>y;
		cnt[x]++;
		cnt[y+1]--;
	}
	for(int i=1;i<=m;i++) num[i]=num[i-1]+cnt[i];
		
	for(ll i=1;i<=n+1;i++)		//再对任务与数据差分 
		d[i]=a[i]-a[i-1];		//赋值 
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
