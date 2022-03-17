#include<bits/stdc++.h>
using namespace std;
struct per{//创建结构遍历 
	int pro,id;//优先级和ID 
}s;
bool operator<(const per&x,const per&y)//重载 "<" 操作符定义优先级
{
	if(x.pro==y.pro) return x.id>y.id;//优先级相同时从小到大排序 
	else return x.pro<y.pro;//不同时从大到小 
}

int main()
{
	int a,n,i,t,pro;
	char str[5];
	while(~scanf("%d",&t)){
		int id=1;
		priority_queue<per>q[4];//定义 
		while(t--){		
			scanf("%s%d",str,&i);
			if(!strcmp(str,"IN")){//判断读入的字符 
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
