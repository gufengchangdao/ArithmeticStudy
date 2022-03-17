//枚举类型 enum 
#include <stdio.h>
 
enum DAY	//声明枚举类型，类似多个define 
{
      MON=1, TUE=5, WED, THU, FRI, SAT, SUN	//注意没有分号 
} day;
int main()
{
	DAY a=WED;	//赋值
	int b=1;
	day=(DAY)b; //强制类型转换赋值 
	printf("%d\n",a);
	printf("%d",day);
}
/*
当一个变量只有几种可能的时候适用 
第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。
这里TUE赋值为5，后面的就会是6、7、8、9、10 
*/
