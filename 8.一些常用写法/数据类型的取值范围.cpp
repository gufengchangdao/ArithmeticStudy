int 10^9	//不超过32位整数(二进制数) 
unsigned int 10^9
long long 10^18
unsigned long long 10^19
double //超级大，准确到前17位，精确到小数点后6位，四舍五入 

//注意：
int a,b;
long long sum;
sum=a*b;//a和b都是int型的，相乘以后转化为int型的再传给sum，故若a*b大于10^9就会爆掉 
sum=1ll*a*b;//用1ll*a将a转化为long long 型就可以了
 
//介绍int型
#include<climits>
//有两个常量：
	INT_MAX=2147483647 
	INT_MIN=-2147483648
//在limits.h中有如下定义
	#define INT_MAX 2147483647
	#define INT_MIN (-INT_MAX - 1)
INT_MAX+1=INT_MIN //类似于取余一样 
INT_MAX+INT_MAX=-2
 
