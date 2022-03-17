#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,up;
	string s;
	while(~scanf("%d",&n)){
		map<string,int>shop;
		for(int i=1;i<=n;i++) cin>>s; 
		scanf("%d",&m);
		while(m--){
			for(int i=1;i<=n;i++){
				cin>>up>>s;
				shop[s]+=up;
			}
			int rank=1;
			map<string,int>::iterator it;
			for(it=shop.begin();it!=shop.end();it++)
				if(it->second>shop["memory"]) rank++;
			printf("%d\n",rank);
		}
	}
	return 0;
}
