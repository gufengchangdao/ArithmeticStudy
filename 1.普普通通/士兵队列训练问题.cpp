//�����list 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		list<int>mylist;//�������� 
		list<int>::iterator it;//��������� ��it����ָ�� 
		for(int i=1;i<=n;i++) mylist.push_back(i);//ģ���� 
		int k=2;
		sort(mylist.begin(),mylist.end());
		while(mylist.size()>3){
			int m=0;//it��m��ƥ��� 
			for(it=mylist.begin();it!=mylist.end();){
				if(++m%k==0) it=mylist.erase(it);//ɾ������һ����㶥���ԭ����λ�ã���ɾ����it++�Ĺ��� 
				else it++;
			}
			k=k==2?3:2;//����ɾ2ɾ3		
		}
		for(it=mylist.begin();it!=mylist.end();it++){//������� 
			if(it!=mylist.begin()) printf(" ");
			printf("%d",*it);
		}
		printf("\n");
	}
} 
