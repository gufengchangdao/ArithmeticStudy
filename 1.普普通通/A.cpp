#include<stdio.h>
using namespace std;
const int maxn=200005;
int a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=n-1;i>=0;i--){
			if(a[i]>=2){
				int j;
				for(j=1;j<a[i]&&i-j>=0;j++) a[i-j]=1;
				i=i-j;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]) printf("%d%c",1,i==n-1?'\n':' ');
			else printf("%d%c",0,i==n-1?'\n':' ');
		}
	}
}
