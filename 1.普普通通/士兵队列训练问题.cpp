//链表和list 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		list<int>mylist;//定义链表 
		list<int>::iterator it;//定义迭代器 ，it类似指针 
		for(int i=1;i<=n;i++) mylist.push_back(i);//模拟编号 
		int k=2;
		sort(mylist.begin(),mylist.end());
		while(mylist.size()>3){
			int m=0;//it与m是匹配的 
			for(it=mylist.begin();it!=mylist.end();){
				if(++m%k==0) it=mylist.erase(it);//删除后下一个结点顶替的原来的位置，有删除、it++的功能 
				else it++;
			}
			k=k==2?3:2;//不断删2删3		
		}
		for(it=mylist.begin();it!=mylist.end();it++){//遍历编号 
			if(it!=mylist.begin()) printf(" ");
			printf("%d",*it);
		}
		printf("\n");
	}
} 
