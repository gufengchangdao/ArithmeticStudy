#include<graphics.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
	initgraph(600, 600);	//��һ�����ڣ�600*600
	_getch();	//�øú�������һ���ַ�ʱ ���� enter ����������
	closegraph();	//�رմ���
	return 0;
}
