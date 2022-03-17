#include<stdio.h>
#include<math.h>
int main(){ 
	printf("%f\n",log(10)); //以e为底的对数函数 
	printf("%f\n",log10(100)); //log()、log2()、log10()是固有函数 
	printf("%f\n",log2(8));
	printf("%f\n",log(8)/log(2)); //计算log2^8,运用换底公式
	printf("%f\n",exp(1)); //计算自然常数e,exp（n）值为e^n次方
	printf("%f\n",log(exp(5)));
	return 0;
}

返回类型为double型，也可以强制类型转换为int型
常用：计算sum有多少位：(int)log10(sum) 
