//贪心算法.活动安排问题 
//最多能看完多少节目 
#include<stdio.h>
#include<cstring>
#include<algorithm>//sort 
using namespace std;
struct node{
	int start,//开始时间 
		end;//结束时间 
}record[105];
bool cmp(const node &a,const node &b){
	return a.end<b.end;
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n){
		node mem={0,0};
		memset(record,0,sizeof(record));
		for(int i=0;i<n;i++)
			scanf("%d%d",&record[i].start,&record[i].end);
		sort(record,record+n,cmp);//将结构体按结束时间从小到大排序 
		int count=0;
		int last=-1;
		for(int i=0;i<n;i++){
			if(record[i].start>=last){// 后一个起始时间大于等于前一个终止时间 
				count++;
				last=record[i].end;//记录前一个活动的终止时间 
			} 
		}
		printf("%d\n",count);
		
		
	}
}
//选择贪心策略
//最早开始时间		不行 
//最早结束时间		可以可以把活动分成一个个部分，局部解组合为最优解 
//用时最短			不行 

 
