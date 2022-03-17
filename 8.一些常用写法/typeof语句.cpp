#include<stdio.h>
typedef struct{
	int x;
	int y;
}node;//给结构类型赋予名字node，注意node不是结构变量的名字 

int main()
{
	node student;
	student.x=5;
	student.y=6;
	printf("%d %d",student.x,student.y);
}
//typedef用来给数据类型定义一个新的名字
//typedef 老的类型名 新的类型名 
//如typedef long long ll;
 
