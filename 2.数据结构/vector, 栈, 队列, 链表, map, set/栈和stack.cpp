//栈 
/*
#include<stack>
stack<int>s;//定义栈，可以是int,char,float等 
s.push(item);//把item放到栈顶 
s.top();//返回栈顶元素
s.pop();//删除栈顶元素，且不会返回，一般先返回栈顶元素再删除 
s.size();//返回栈中元素个数 
s.empty();//栈为空，返回true，否则返回false 
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
		stack<char>s;//创建栈 
		while(true){//由于不知道一行里有多少个单词，所以结束条件在里面 
			ch=getchar();
			if(ch==' '||ch=='\n'||ch==EOF){//输入条件：一个单词的结束、一行的结束、所有数据的结束 
				
				while(!s.empty()){		//输出完所有数据 
					printf("%c",s.top());
					s.pop();
				}
				
				if(ch=='\n'||ch==EOF) break;//若一行结束，或所有数据结束，循环结束 
				printf(" ");
			}
			
			else s.push(ch);//输入数据 
		}
	printf("\n");
	}
} 
