#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    struct tm *p;
    time_t t = time(0);
    p = localtime(&t);	//ʹ��t��ֵ�����tm�ṹ����Ϣ����������ָ�� 
    printf("%d��%d��%d�� %d:%d:%d\n",1900+p->tm_year, 1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
    system("pause");
	return 0;
}
/*
time_t �������;��������洢��1970�굽���ھ����˶����룬Ҫ�����ȷһ�㣬�����ýṹstruct timeval��
	����ȷ��΢���ֱ�Ӵ洢�����յ���һ���ṹ��
struct tm
{    
	int tm_sec;  //�룬������Χ0-59�� ��������61    
	int tm_min;  //���ӣ�0-59   
	int tm_hour; //Сʱ�� 0-23 
	int tm_mday; //�գ���һ�����еĵڼ��죬1-31 
	int tm_mon;  //�£� ��һ������0-11 1+p->tm_mon;   
	int tm_year;  //�꣬ ��1900�����Ѿ������� 1900�� p->tm_year; 
	int tm_wday; //���ڣ�һ���еĵڼ��죬 ������������0-6 
	int tm_yday; //�ӽ���1��1�յ�Ŀǰ����������Χ0-365 
	int tm_isdst; //�չ��Լʱ������ 
};
*/


