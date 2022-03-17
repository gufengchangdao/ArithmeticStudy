#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int n,b,sum;
	scanf("%d\n",&n);
	while(n--){
		sum=0;
		gets(a);
		b=strlen(a);	//汉字由两个字节组成 
		for(int i=0;i<b;i++)
		if(a[i]<0)	//统计时判断a【i】是否小于零 
			sum++;
		printf("%d\n",sum/2);	//最后再除以2 
	}
	return 0;
}   
