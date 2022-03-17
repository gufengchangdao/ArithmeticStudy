#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn=10005;
int len[maxn];
//把绳子长度从大到小排序后在遍历的时候当长度小于当前选定长度mid的时候就可以直接退出了 
bool compare(int a,int b)
{
	return a>b;
}

int main()
{
	int n,k;
	double tem;
	int sum;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lf",&tem);
		len[i]=tem*100;
		sum+=len[i];
	}
	sort(len,len+n+1,compare);
	int r=10000005;//单个绳子的最大长度*100 
	int l=0;
	int mid,c;
	while(l<=r){
		mid=(l+r)/2;
		if(mid==0) break;//r可能非常小，使得最后长度小于0.01 ，即为0 
		c=0;
		for(int i=0;i<n&&len[i]>=mid;i++) c+=len[i]/mid;
		if(c>=k) l=mid+1;//右边界写法 
		else r=mid-1;
	}
	printf("%.2f",r/100.0);
}
