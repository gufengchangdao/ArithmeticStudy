//打印n个数中前m大个数 

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
int a[MAXN];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));//先清空数组 
		for(int i=0;i<n;i++){
			int tem;
			scanf("%d",&tem);
			a[500000+tem]++;//倘若t为负数，就需要从中间开始，t+500000 
		}
		for(int i=MAXN-1;m>0;i--)//从大到小，以m>0作为循环出口，确保只输出m个 
			for(int j=1;j<=a[i]&&m>0;j++){
				printf("%d%c",i-500000,m>1?' ':'\n'); 
				m--;
			}
//			while(a[i]--){	//a[i]为0的时候就不会进行循环 
//				if(m>1) printf("%d ",i-500000);
//				else printf("%d\n",i-500000);
//				m--;
//			} 
	}
	return 0;
}
 
