#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		printf("%d\n",n*pow(2,m));
		printf("%.0f\n",n*pow(2,m));
		printf("%.0f\n",(int)n*pow(2,m));
	}
}

//%d���������0 
//%.0lf�������4 
//pow()���ص�ֵ������Ϊdouble��  ע�ⲻ����%d������
//����%dҲ���Լ�������ֵ����һ��int�͵ı�����ʵ������ǿ��ת�� 
