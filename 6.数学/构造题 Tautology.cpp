//Tautology
/*
���⣺p q r s tΪ�߼�������ֻ��Ϊ���Ϊ�٣� Kxy Axy Nx Cxy Exy ����ٶ���Ҫ��x��y�������ַ�������
	�Ƿ�Ϊ����ʽ(��Ϊ��) 
	���취
		�ݹ�������ǰ������������ KANCE�͵ݹ���һ��������pqrstֱ�ӷ������ 
		ջ������Ӻ���ǰ������pqrst�ʹ��룬���� KANCE���ó������ѻ�õ�ֵ�ٴ��룬���ջΪ���ˣ�˵
			���ַ������Ϸ���������������ֻʣһ�����ֵ 
*/
#include<stdio.h>
#include<string.h>
const int maxn=105;
bool s[6];	//������p q r s t �������� 
char a[maxn];
int cnt;	//�ݹ�ʱ�õ�����ָ�� 

bool cal()
{
	char c=a[cnt];
	bool x,y;
	cnt++;
	switch(c){
		case 'p':return s[0];	//p q r s tֱ�ӷ��ض�Ӧ��������ٵ�������� 
		case 'q':return s[1];
		case 'r':return s[2];
		case 's':return s[3];
		case 't':return s[4];
		case 'N':return !cal();	//N,A,C,E,K��Ҫ��������ַ� 
		case 'K':x=cal();y=cal();return x&&y;
		case 'A':x=cal();y=cal();return x||y;
		case 'C':x=cal();y=cal();return x<=y;
		case 'E':x=cal();y=cal();return x==y;
		default :return 0;	//����в������ַ������ͷ��ؼ�(��Ȼ�����п���û��������) 
	} 
}

int main()
{
	bool flag;
	while(~scanf("%s",a)&&a[0]!='0'){
		flag=1;
		
		for(int i=0;i<(1<<5);i++){//	��ÿһ���ַ���������s��������� 
			cnt=0;
			memset(s,0,sizeof(s));
			for(int j=0;j<5;j++)
				if(i&(1<<j)) s[j]=1;
			if(!cal()){		 
				flag=0;break;
			}
		}
		if(flag) printf("tautology\n");
		else printf("not\n");
	}
}
