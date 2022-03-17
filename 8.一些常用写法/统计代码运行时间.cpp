#include<stdio.h>
#include<ctime>
using namespace std;
int main()
{
	clock_t start,mind,end;//保存时间的数据类型 
	start=clock();
	//代码 
	//mind=clock();
	// 。。。  
	end=clock();
	printf("%lf",(double)(end-start)/CLOCKS_PER_SEC);//需要计算的部分代码运行时间 
}								 //除以计算机每秒所含的时钟计时单元 
 
/*int main()
{
	//代码
	//。。。 
	printf("%lf",(double)clock()/CLOCKS_PER_SEC);//程序一共运行时间 
}
*/ 
