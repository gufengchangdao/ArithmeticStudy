//ö������ enum 
#include <stdio.h>
 
enum DAY	//����ö�����ͣ����ƶ��define 
{
      MON=1, TUE=5, WED, THU, FRI, SAT, SUN	//ע��û�зֺ� 
} day;
int main()
{
	DAY a=WED;	//��ֵ
	int b=1;
	day=(DAY)b; //ǿ������ת����ֵ 
	printf("%d\n",a);
	printf("%d",day);
}
/*
��һ������ֻ�м��ֿ��ܵ�ʱ������ 
��һ��ö�ٳ�Ա��Ĭ��ֵΪ���͵� 0������ö�ٳ�Ա��ֵ��ǰһ����Ա�ϼ� 1��
����TUE��ֵΪ5������ľͻ���6��7��8��9��10 
*/
