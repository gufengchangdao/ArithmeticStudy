//Radar Installation
/*
题意：在x轴上方是海，下方是岸，海上有n个岛，雷达只能建在岸上，有效半径为d，求覆盖所有岛最少需要多
	少个雷达，存在覆盖不到的情况时输出-1 
数据处理：求以每个岛为中心，半径为d的圆与x轴的交点，得到的区间[l,r]便是雷达的可放区域 
	贪心求解：将数据按r从小到大排序，对于区间重叠的岛不用管，不重叠的则加上 
*/
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d,ans,t=0;
struct node{
	double l,r;
	bool operator <(const node &a)const {
		//if(r==a.r) return l<a.l;用不着 
		return r<a.r;
	}
}e[maxn];

int main()
{
	while(~scanf("%d%d",&n,&d)&&(n||d)){
		bool can=1;
		
		double x,y;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			double tem=sqrt(fabs(1.0*d*d-y*y));
			e[i].l=x-tem,e[i].r=x+tem;	//计算交点横坐标 
			if(y>d) can=0;	//处理没有解的情况 
		}
		if(!can){
			printf("Case %d: -1\n",++t);
			continue;
		}
		sort(e,e+n);
		ans=1;
		double r=e[0].r;
		for(int i=1;i<n;i++){
			if(e[i].l>r) r=e[i].r,ans++;	//寻找区间不重复的区间个数 	
		}
		printf("Case %d: %d\n",++t,ans);
	}
}
