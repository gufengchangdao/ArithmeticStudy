#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool good;//�ж��Ƿ��������������Ѿ����� 
int n;
void dfs(unsigned long long sum,int k)//����unsigned���Դ���20λ���������ܵĳ��������������� 
{
	if(good) return;//����1���������������Ѿ����� 
	if(sum%n==0){
		printf("%llu\n",sum);
		good=true; 
		return;//����2������������������ 
	}
	if(k==20) return;//����3����ǰ�ݹ�״̬������������������ֹ���
	//�ݹ飬�ں������1����0 
	dfs(sum*10,k+1);
	dfs(sum*10+1,k+1);
} 

int main()
{
	while(~scanf("%d",&n)&&n){
		good=false;//goodΪȫ�ֱ�����ÿ�ζ�ȡn��Ҫ���¸�ֵ 
		dfs(1,1);
	}
}
