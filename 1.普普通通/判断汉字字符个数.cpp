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
		b=strlen(a);	//�����������ֽ���� 
		for(int i=0;i<b;i++)
		if(a[i]<0)	//ͳ��ʱ�ж�a��i���Ƿ�С���� 
			sum++;
		printf("%d\n",sum/2);	//����ٳ���2 
	}
	return 0;
}   
