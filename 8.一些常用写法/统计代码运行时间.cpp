#include<stdio.h>
#include<ctime>
using namespace std;
int main()
{
	clock_t start,mind,end;//����ʱ����������� 
	start=clock();
	//���� 
	//mind=clock();
	// ������  
	end=clock();
	printf("%lf",(double)(end-start)/CLOCKS_PER_SEC);//��Ҫ����Ĳ��ִ�������ʱ�� 
}								 //���Լ����ÿ��������ʱ�Ӽ�ʱ��Ԫ 
 
/*int main()
{
	//����
	//������ 
	printf("%lf",(double)clock()/CLOCKS_PER_SEC);//����һ������ʱ�� 
}
*/ 
