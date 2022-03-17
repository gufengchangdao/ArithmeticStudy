#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool good;//判断是否满足条件的数已经出现 
int n;
void dfs(unsigned long long sum,int k)//利用unsigned可以储存20位数，尽可能的出现满足条件的数 
{
	if(good) return;//出口1：满足条件的数已经出现 
	if(sum%n==0){
		printf("%llu\n",sum);
		good=true; 
		return;//出口2：满足条件的数出现 
	}
	if(k==20) return;//出口3：当前递归状态无满足条件的数，防止溢出
	//递归，在后面添加1或者0 
	dfs(sum*10,k+1);
	dfs(sum*10+1,k+1);
} 

int main()
{
	while(~scanf("%d",&n)&&n){
		good=false;//good为全局变量，每次读取n都要重新赋值 
		dfs(1,1);
	}
}
