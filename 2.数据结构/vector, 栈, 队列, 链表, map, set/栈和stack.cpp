//ջ 
/*
#include<stack>
stack<int>s;//����ջ��������int,char,float�� 
s.push(item);//��item�ŵ�ջ�� 
s.top();//����ջ��Ԫ��
s.pop();//ɾ��ջ��Ԫ�أ��Ҳ��᷵�أ�һ���ȷ���ջ��Ԫ����ɾ�� 
s.size();//����ջ��Ԫ�ظ��� 
s.empty();//ջΪ�գ�����true�����򷵻�false 
*/ 
#include<bits/stdc++.h>
#include<stack> 
using namespace std;
int main()
{
	int t;
	char ch;
	scanf("%d",&t);
	getchar();
	while(t--){
		stack<char>s;//����ջ 
		while(true){//���ڲ�֪��һ�����ж��ٸ����ʣ����Խ������������� 
			ch=getchar();
			if(ch==' '||ch=='\n'||ch==EOF){//����������һ�����ʵĽ�����һ�еĽ������������ݵĽ��� 
				
				while(!s.empty()){		//������������� 
					printf("%c",s.top());
					s.pop();
				}
				
				if(ch=='\n'||ch==EOF) break;//��һ�н��������������ݽ�����ѭ������ 
				printf(" ");
			}
			
			else s.push(ch);//�������� 
		}
	printf("\n");
	}
} 
