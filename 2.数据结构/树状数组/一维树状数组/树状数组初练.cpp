//树状数组：单点修改，区间查询 
//要是光求和且a[i]可以小于零，则a[i]值要改变的时候可以只修改c[i]，a[i]不用修改 
//https://www.nitacm.com/problem_show.php?pid=1157
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[50005],c[50005],ans[40005],n;//a[i]为原数组，c[i]为树状数组，ans[i]储存答案
//注意：原数组必须从下标1开始储存数值 
void check()//修改后用来检测的 
{
	printf("\n");
	for(int i=1;i<=n;i++) printf(" %d",a[i]);
	printf("\n");
}
int lowbit(int x)//求平衡因子 
{
	return x&(-x);	
}
int getsum(int i)//求a[i]中1~i的和 
{
	int ans=0;
	while(i>0){//a[i]数组是从1开始储存的 
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
void update(int i,int k)//a[i]+k,  除了a[i]，含有a[i]的c[j]都要改变  
{
	while(i<=n){
		c[i]=c[i]+k<0?0:c[i]+k;//这里c[i]>=0 
		i+=lowbit(i);
	}
}
int main()
{
	int t,x,y;
	string s;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			update(i,a[i]);//读入a[i]的时候，对应的c[j]也要改变 
		}
		int k=0;
		while(cin>>s&&s[0]!='E'){//从读入的字符串首字母判断操作要求 
			scanf("%d%d",&x,&y);
			switch(s[0]){
				case 'A':a[x]=a[x]+y;update(x,y);break;
				case 'S':a[x]=a[x]-y<0?0:a[x]-y;update(x,-y);break;
				default:ans[k++]=getsum(y)-getsum(x-1);break;
			}
		}
		printf("Case %d:\n",z);
		for(int i=0;i<k;i++) printf("%d\n",ans[i]);
	}
} 
