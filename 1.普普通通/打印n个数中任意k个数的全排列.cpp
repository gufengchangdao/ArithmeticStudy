 //��ӡn����������k��������� (�����ռ�)
#include<bits/stdc++.h>
using namespace std;
int n,k;
void subset(int n)
{
	for(int i=0;i<(1<<n);i++){//i:0-2^n,ÿ��i��Ӧһ�����
		int num=0,kk=i;
		while(kk){	//��i+1����ϵĶ����������ж��ٸ�1�������ж��ٸ�Ԫ�� 
			kk=kk&(kk-1);//ÿִ��һ�ζ�������kk�Ķ������������һ��1 
			num++;//���� 
		} 
		if(num==k){
			for(int j=0;j<n;j++)//j:0-n,jΪÿ�������Ԫ�ض�Ӧ���±� 
				if(i&(1<<j)) printf("%d ",j);
			printf("\n");
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	subset(n);
 } 
