//��ӡȫ���� 
#include<bits/stdc++.h>
using namespace std;
#define swap(a,b){int temp=a;a=b;b=temp;}//��swap�����������һ�� 
int a[]={1,2,3,4};
int num=0;//��¼ȫ���и��� 
void perm(int begin,int end)//begin��end�ֱ�Ϊ��߽���б߽� 
{
	int i;
	if(begin==end){		//�ݹ���� 
		for(i=0;i<=end;i++) printf("%d",a[i]);//��ӡ 
		printf("\n");
		num++;
	}
	else{  //ÿ�ΰѵ�һ�����ͺ����ÿ����������ȥ����һ������Ժ����n-1�������н�������...
		   //��һ�ν�������n�Σ�ȥ����һ�������ٽ�������n-1��...   ��n*(n-1)*(n-2)*...*1 
		for(i=begin;i<=end;i++){//����һ��ѭ�� 
			swap(a[begin],a[i]);//����begin��i 
			perm(begin+1,end);//��һ�ν�������뵽��һ�� 
			swap(a[begin],a[i]);//�ص���һ�㣬�ٽ����������ع�ԭ����׼����һ��begin��i+1���� 
		}
	}
}

int main()
{
	perm(0,3);
	printf("%d",num);		
} 
