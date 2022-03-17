//愤怒的小鸟 
/*
题意：弹弓从(0,0)发射小鸟，给出n个猪的位置，鸟的轨迹为y=a*x*x+b*x，其中a<0，问最少多少只小鸟
	可以打掉所有猪，(m请忽视) 
	动态规划、状态压缩
	抛物线的选择：只有x相同的时候只过一头猪，对于只能过一头猪的情况不计算抛物线，每次由两头猪和原点
		确定抛物线，还要检测其他猪是否在这个抛物线上
	优化：没有lowbit[i]的时候，要for循环一遍查找状态i没有过的点有关的线，这会有很多重复的操作，每次
		只查找没有过的点的最小序号，就会好很多 
	状态压缩过程：遍历所有的状态，因为i是由小到大，所以i|(1<<(j-1))和i|lines[j][k]都是大于等于i的，
		所以每一步的dp都是由前面的dp状态求出的，每次只要把与lowbit[i]相关的线加上就可以	 
	
*/
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
int lowbit[1<<20],line[20][20],dp[1<<20];//dp打完对应位置的猪最少消耗的鸟 
double x[20],y[20];

void init()
{
	int len=1<<18;
	for(int i=0;i<len;i++){
		int j=1;
		while(j<=18 && i&(1<<(j-1))) j++;
		lowbit[i]=j;//满足i&(1<<(j-1))=0的最小正整数j，则由i扩展的转移的所有线(所有解)最后都要经过j这个点 
				//大白话就是还未打掉的猪的最小序号，在后续遍历中，每次处理这个最小序号，得到后续解 
	}		
}

void equation(double &x,double &y,double a1,double b1,double c1,double a2,double b2,double c2)
{	//解方程
	y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	x=(c1-b1*y)/a1;
}

int main()
{
	init();
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		memset(dp,0x3f,sizeof(dp));//要想动态规划好，初始化一定要漂亮 
		dp[0]=0;	
		memset(line,0,sizeof(line));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf%lf",x+i,y+i);//x和y为数组，本身就是地址，不用&
	
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){//处理所有的抛物线 
				if(fabs(x[i]-x[j])<eps) continue;//对于横坐标相等的两点，没有同一个抛物线，只过一个猪的抛物线不记录 
				double a,b;
				equation(a,b,x[i]*x[i],x[i],y[i],x[j]*x[j],x[j],y[j]);//计算a,b 
				if(a>-eps) continue; //a>=0不符合题意 
				for(int k=1;k<=n;k++)//由三点确定抛物线后，判断其他猪是否在这条线上 
					if(abs(a*x[k]*x[k]+b*x[k]-y[k])<eps) line[i][j]|=(1<<(k-1));
				line[j][i]=line[i][j];	//由于两者相同，j就不遍历那么多了 
			}

		int len=1<<n;	
		for(int i=0;i<len;i++){	//i由小变大，不断得到后续解，对于每个状态i，都只考虑过lowbit[i]这个点的最小步骤 
			int j=lowbit[i];	
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1);//单独转移，要考虑不在抛物线上的点 
			for(int k=1;k<=n;k++)
				dp[i|line[j][k]]=min(dp[i|line[j][k]],dp[i]+1);//多点转移，所有经过lowunbit的抛物线
		}			
		printf("%d\n",dp[(1<<n)-1]);	
	}
	
}
