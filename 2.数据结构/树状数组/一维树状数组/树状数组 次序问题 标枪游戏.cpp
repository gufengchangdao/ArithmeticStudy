//��ǹ��Ϸ
	//����״���鴦��������� 
	//���ݸ������࣬�����ܴ󡪡�>��ɢ�� 

#include <bits/stdc++.h>
using namespace std;
#define int long long	//����궨�������˼ 
const int N=100005;
int a[N],c[N],co[N];// a����Ϊԭ�����飬c����Ϊ��״���飬co����Ϊa���龭������ȥ�غ������ 
int n;

int lowbit(int i)
{
    return i&(-i);
}

void insert(int i,int x)
{
    while(i<=n){
        c[i]+=x;
        i+=lowbit(i);
    }
}

int getsum(int i)
{
    int sum=0;
    while(i>0){
        sum+=c[i];
        i-=lowbit(i);
    } 
    return sum;
}


signed main()	//int�Ѿ�����int�� 
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		co[i]=a[i];
	}
	int m=n,x=0,y=0;
	//��ɢ������a�����ɼ�¼���ݱ�Ϊ��¼���ݵ�ID 
	sort(co+1,co+n+1);
	m=unique(co+1,co+m+1)-co-1;//����Ҫ��ȥ1������˵û���ظ���ʱ��co+m+1-co=m+1����m������mҲûɶ�� 
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(co+1,co+m+1,a[i])-co;
		
	for(int i=1;i<=n;i++){
            insert(a[i],1);//����������⣬��ԭ���������Ĵ����1 
            if(i&1) x=x+2*getsum(a[i])-i;
			else y=y+2*getsum(a[i])-i;
        }
	if(x>y) printf("Calculus is hebei king!\n");
	else if(x==y) printf("hebei shuang king!\n");
	else printf("huaji is hebei king!\n");
}
