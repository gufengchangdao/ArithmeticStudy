//���ݷָ� 
/*
���⣺��n��ʽ�ӣ�Ҫô��a==b,Ҫôa!=b����n��ʽ��ԭ����ans�飬ÿ�����һ����ǰ���ʽ���Ƴ�ì�ܣ�����
	Ҫ���ҵ�k���ÿ��ĳ��� 
	���鼯��set���ò��鼯����ȹ�ϵ��set�治�ȹ�ϵ
	������s[maxn*2],����ȵĹ�ϵ�ô���maxn������ʾ��������Ϊÿ�γ�ʼ���ᳬʱ 	
*/
#include<bits/stdc++.h>
#define IT set<int>::iterator
using namespace std;
const int maxn=100005;
set<int> e[maxn];
int n;
int s[maxn];
int sum[maxn];//����� 

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
		if(a>b) swap(a,b); //С����aҪ�ӵ������b�� 
		a=findset(a);
		b=findset(b);
		if(op){						//a==b 
			if(a==b) continue;//�Ѿ���ͬһ�����ϻ�����ͬһ���� 
			if(e[b].find(a)!=e[b].end()){	//b�ĵ���������a 
				sum[++ans]=i;
				init();
			}
			else{	//a��b���ǵ��ˣ��ϲ� 
				for(IT it=e[a].begin();it!=e[a].end();it++){	
					e[b].insert(*it);	//a�ĵ���ȫ����b 
					e[*it].insert(b);	//a�ĵ��˵ĵ�����a���b 
					e[*it].erase(a);
				}
				e[a].clear();	//���a�ĵ��ˣ��ò��ţ�1 
				s[a]=b;//	a�ӵ�b�� 
			}	
		}
		else{	//a!=b 
			if(a==b){	//ì�� 
				sum[++ans]=i;
				init();
			}
			else{	//��Ϊ���� 
				e[a].insert(b);
				e[b].insert(a);
			}
		}
		
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d\n",sum[i]-sum[i-1]);
}
