//优先级队列跟对列的使用方式的区别是优先级队列在插入元素时
//在将元素插入队尾后还要根据比较值对该元素进行位置的调整
#include<bits/stdc++.h>
using namespace std;
struct student{
	int score,id;
	char name;
	//重载操作符 '<'对应less，'>'对应greater 
	bool operator <(const student &a){//重载'<'对应less的从大到小 
		return score<a.score||score==a.score&&id<a.id;//分数相同的时候按id从小到大排序 
	}
	/*
	//也可以这样 
	bool operator >(student node1,student node2){//重载'>'对应greater的从小到大 
		return node1.score>node2.score;// > 为从小到大， < 为从大到小 
	//	return node1.score<node2.score;
	}
	*/
};
int main()
{
	priority_queue<int>qu;
//	==priority_queue<int,vector<int>,less<int> >qu;//这里>与>之间一定要有空格，> >区别于>> 
//	==priority_queue<int,vector<int> >qu;
//结构体不能直接比较，使用优先队列必须重载操作符 
	priority_queue<student>que;
	priority_queue<student,vector<student>,greater<student> >qe; 
	student s[10];
	int a[10]={4,2,1,3,6,8,7,9,10,5};
	char b[10]={'a','b','c','d','e','f','g','h','i','j'};
	//普通优先队列 
	for(int i=0;i<10;i++) qu.push(a[i]);
	for(int i=0;i<10;i++){
		printf("%d\n",(int)qu.top());//必须用强制转换（int） 
		qu.pop();
	}
	printf("\n");
	//存结构体的优先队列 
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
	//存结构体的优先队列
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
