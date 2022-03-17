#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    struct tm *p;
    time_t t = time(0);
    p = localtime(&t);	//使用t的值来填充tm结构体信息，并返回其指针 
    printf("%d年%d月%d日 %d:%d:%d\n",1900+p->tm_year, 1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
    system("pause");
	return 0;
}
/*
time_t 这种类型就是用来存储从1970年到现在经过了多少秒，要想更精确一点，可以用结构struct timeval，
	它精确到微妙。而直接存储年月日的是一个结构：
struct tm
{    
	int tm_sec;  //秒，正常范围0-59， 但允许至61    
	int tm_min;  //分钟，0-59   
	int tm_hour; //小时， 0-23 
	int tm_mday; //日，即一个月中的第几天，1-31 
	int tm_mon;  //月， 从一月算起，0-11 1+p->tm_mon;   
	int tm_year;  //年， 从1900至今已经多少年 1900＋ p->tm_year; 
	int tm_wday; //星期，一周中的第几天， 从星期日算起，0-6 
	int tm_yday; //从今年1月1日到目前的天数，范围0-365 
	int tm_isdst; //日光节约时间的旗标 
};
*/


