#include<bits/stdc++.h>
using namespace std;
struct per{//�����ṹ���� 
	int pro,id;//���ȼ���ID 
}s;
bool operator<(const per&x,const per&y)//���� "<" �������������ȼ�
{
	if(x.pro==y.pro) return x.id>y.id;//���ȼ���ͬʱ��С�������� 
	else return x.pro<y.pro;//��ͬʱ�Ӵ�С 
}

int main()
{
	int a,n,i,t,pro;
	char str[5];
	while(~scanf("%d",&t)){
		int id=1;
		priority_queue<per>q[4];//���� 
		while(t--){		
			scanf("%s%d",str,&i);
			if(!strcmp(str,"IN")){//�ж϶�����ַ� 
				scanf("%d",&pro);
				s.id=id++;
				s.pro=pro;
				q[i].push(s);
			}
			else{
				if(!q[i].empty()){
					s=q[i].top();
					q[i].pop();
					printf("%d\n",s.id);
				}
				else printf("EMPTY\n");
			}
		}
	}
}
