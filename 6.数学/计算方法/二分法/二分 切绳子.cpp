#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int len[maxn];

bool compare(int x,int y)
{
	return x>y;
}

signed main()
{
	int t,n,k,sum;
	scanf("%lld",&t);
	while(t--){
		
		sum=0;
		scanf("%lld%lld",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%lld",len+i);
			sum+=len[i];
		}
		sort(len,len+n,compare);
		int Min=0;
		int Max=sum/k;
		int mid;
		while(Min<Max){
			mid=(Min+Max+1)>>1;
			int p=0;
			for(int i=0;i<n&&len[i]>=mid;i++)
				p+=len[i]/mid;
			if(p<k) Max=mid-1;
			else Min=mid;	
		}
		printf("%lld\n",Min);
	}
}
