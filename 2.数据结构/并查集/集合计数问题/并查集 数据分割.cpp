//数据分割 
/*
题意：有n个式子，要么是a==b,要么a!=b，这n个式子原本有ans组，每组最后一个由前面的式子推出矛盾，现在
	要你找到k组的每组的长度 
	并查集、set：用并查集存相等关系，set存不等关系
	本来想s[maxn*2],不相等的关系用大于maxn的数表示，但是因为每次初始化会超时 	
*/
#include<bits/stdc++.h>
#define IT set<int>::iterator
using namespace std;
const int maxn=100005;
set<int> e[maxn];
int n;
int s[maxn];
int sum[maxn];//储存答案 

void init()
{
	for(int i=1;i<maxn;i++){
		e[i].clear();
		s[i]=i;
	}
}

int findset(int x)
{
	if(x==s[x]) return x;
	return s[x]=findset(s[x]);	
}

int main()
{
	int ans=0,a,b,op;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&op);
		if(a>b) swap(a,b); //小的数a要接到大的数b上 
		a=findset(a);
		b=findset(b);
		if(op){						//a==b 
			if(a==b) continue;//已经在同一颗树上或者是同一个数 
			if(e[b].find(a)!=e[b].end()){	//b的敌人里面有a 
				sum[++ans]=i;
				init();
			}
			else{	//a与b不是敌人，合并 
				for(IT it=e[a].begin();it!=e[a].end();it++){	
					e[b].insert(*it);	//a的敌人全部给b 
					e[*it].insert(b);	//a的敌人的敌人由a变成b 
					e[*it].erase(a);
				}
				e[a].clear();	//清空a的敌人，用不着；1 
				s[a]=b;//	a接到b上 
			}	
		}
		else{	//a!=b 
			if(a==b){	//矛盾 
				sum[++ans]=i;
				init();
			}
			else{	//互为敌人 
				e[a].insert(b);
				e[b].insert(a);
			}
		}
		
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d\n",sum[i]-sum[i-1]);
}
