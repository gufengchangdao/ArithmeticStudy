//̰���㷨.��������� 
//����ܿ�����ٽ�Ŀ 
#include<stdio.h>
#include<cstring>
#include<algorithm>//sort 
using namespace std;
struct node{
	int start,//��ʼʱ�� 
		end;//����ʱ�� 
}record[105];
bool cmp(const node &a,const node &b){
	return a.end<b.end;
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n){
		node mem={0,0};
		memset(record,0,sizeof(record));
		for(int i=0;i<n;i++)
			scanf("%d%d",&record[i].start,&record[i].end);
		sort(record,record+n,cmp);//���ṹ�尴����ʱ���С�������� 
		int count=0;
		int last=-1;
		for(int i=0;i<n;i++){
			if(record[i].start>=last){// ��һ����ʼʱ����ڵ���ǰһ����ֹʱ�� 
				count++;
				last=record[i].end;//��¼ǰһ�������ֹʱ�� 
			} 
		}
		printf("%d\n",count);
		
		
	}
}
//ѡ��̰�Ĳ���
//���翪ʼʱ��		���� 
//�������ʱ��		���Կ��԰ѻ�ֳ�һ�������֣��ֲ������Ϊ���Ž� 
//��ʱ���			���� 

 
