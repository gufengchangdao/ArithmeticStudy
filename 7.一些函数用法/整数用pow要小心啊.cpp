#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		printf("%d\n",n*pow(2,m));
		printf("%.0f\n",n*pow(2,m));
		printf("%.0f\n",(int)n*pow(2,m));
	}
}

//%d——结果：0 
//%.0lf——结果4 
//pow()返回的值的类型为double型  注意不能用%d！！！
//想用%d也可以计算结果赋值给另一个int型的变量，实现类型强制转换 
