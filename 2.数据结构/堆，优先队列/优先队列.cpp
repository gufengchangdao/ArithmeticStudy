//���ȼ����и����е�ʹ�÷�ʽ�����������ȼ������ڲ���Ԫ��ʱ
//�ڽ�Ԫ�ز����β��Ҫ���ݱȽ�ֵ�Ը�Ԫ�ؽ���λ�õĵ���
#include<bits/stdc++.h>
using namespace std;
struct student{
	int score,id;
	char name;
	//���ز����� '<'��Ӧless��'>'��Ӧgreater 
	bool operator <(const student &a){//����'<'��Ӧless�ĴӴ�С 
		return score<a.score||score==a.score&&id<a.id;//������ͬ��ʱ��id��С�������� 
	}
	/*
	//Ҳ�������� 
	bool operator >(student node1,student node2){//����'>'��Ӧgreater�Ĵ�С���� 
		return node1.score>node2.score;// > Ϊ��С���� < Ϊ�Ӵ�С 
	//	return node1.score<node2.score;
	}
	*/
};
int main()
{
	priority_queue<int>qu;
//	==priority_queue<int,vector<int>,less<int> >qu;//����>��>֮��һ��Ҫ�пո�> >������>> 
//	==priority_queue<int,vector<int> >qu;
//�ṹ�岻��ֱ�ӱȽϣ�ʹ�����ȶ��б������ز����� 
	priority_queue<student>que;
	priority_queue<student,vector<student>,greater<student> >qe; 
	student s[10];
	int a[10]={4,2,1,3,6,8,7,9,10,5};
	char b[10]={'a','b','c','d','e','f','g','h','i','j'};
	//��ͨ���ȶ��� 
	for(int i=0;i<10;i++) qu.push(a[i]);
	for(int i=0;i<10;i++){
		printf("%d\n",(int)qu.top());//������ǿ��ת����int�� 
		qu.pop();
	}
	printf("\n");
	//��ṹ������ȶ��� 
	for(int i=0;i<10;i++){
		s[i].score=a[i];
		s[i].name=b[i];
		que.push(s[i]);
	}
	for(int i=0;i<10;i++){
		cout<<que.top().score<<' '<<que.top().name<<endl;
		que.pop();
	}
	printf("\n");
	//��ṹ������ȶ���
	for(int i=0;i<10;i++){
		s[i].score=a[i];
		s[i].name=b[i];
		qe.push(s[i]);
	}
	for(int i=0;i<10;i++){
		cout<<qe.top().score<<' '<<qe.top().name<<endl;
		qe.pop();
	}
}
