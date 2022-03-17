//标枪游戏
	//用树状数组处理次序问题 
	//数据个数不多，但数很大——>离散化 

#include <bits/stdc++.h>
using namespace std;
#define int long long	//这个宏定义很有意思 
const int N=100005;
int a[N],c[N],co[N];// a数组为原来数组，c数组为树状数组，co数组为a数组经过排序去重后的数组 
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


signed main()	//int已经不是int了 
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		co[i]=a[i];
	}
	int m=n,x=0,y=0;
	//离散化处理，a数组由记录数据变为记录数据的ID 
	sort(co+1,co+n+1);
	m=unique(co+1,co+m+1)-co-1;//这里要减去1，比如说没有重复的时候，co+m+1-co=m+1不是m，不过m也没啥用 
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(co+1,co+m+1,a[i])-co;
		
	for(int i=1;i<=n;i++){
            insert(a[i],1);//处理次序问题，对原数组所处的次序加1 
            if(i&1) x=x+2*getsum(a[i])-i;
			else y=y+2*getsum(a[i])-i;
        }
	if(x>y) printf("Calculus is hebei king!\n");
	else if(x==y) printf("hebei shuang king!\n");
	else printf("huaji is hebei king!\n");
}
