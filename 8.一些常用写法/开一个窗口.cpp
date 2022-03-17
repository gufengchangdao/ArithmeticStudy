#include<graphics.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
	initgraph(600, 600);	//开一个窗口，600*600
	_getch();	//用该函数读入一个字符时 不用 enter 代码会继续跑
	closegraph();	//关闭窗口
	return 0;
}
