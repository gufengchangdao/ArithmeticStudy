#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn=10005;
int len[maxn];
//�����ӳ��ȴӴ�С������ڱ�����ʱ�򵱳���С�ڵ�ǰѡ������mid��ʱ��Ϳ���ֱ���˳��� 
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
	int r=10000005;//�������ӵ���󳤶�*100 
	int l=0;
	int mid,c;
	while(l<=r){
		mid=(l+r)/2;
		if(mid==0) break;//r���ܷǳ�С��ʹ����󳤶�С��0.01 ����Ϊ0 
		c=0;
		for(int i=0;i<n&&len[i]>=mid;i++) c+=len[i]/mid;
		if(c>=k) l=mid+1;//�ұ߽�д�� 
		else r=mid-1;
	}
	printf("%.2f",r/100.0);
}
