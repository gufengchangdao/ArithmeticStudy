#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define check(a)(a>=0&&a<maxn)//�ж��Ƿ���� 
using namespace std;
const int maxn=100001;
queue<int> q;
int step[maxn]={0};//��¼����ÿһλ�����ߵĲ�������ʼ��Ϊ0 
bool vis[maxn];//����Ƿ��߹� 
int n,k;

int bfs()
{
	int start,next;
	//��ȡ����� 
	q.push(n);
	vis[n]=true;
	//ѭ����BFS 
	while(!q.empty()){
		//��ȡ����λ�� 
		start=q.front();
		q.pop();
		
		for(int i=0;i<3;i++){
			//3���߷� 
			if(i==0) next=start-1;
			else if(i==1) next=start+1;
			else next=start*2;
			//�ж��Ƿ���߽���Ƿ��߹� 
			if(check(next)&&!vis[next]){
				q.push(next);//���� 
				vis[next]=true;//��� 
				step[next]=step[start]+1;//��¼ 
			if(next==k) return step[next];//ѭ�����ھ����ҵ����·�� 
			}
		}	
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	while(!q.empty()) q.pop();//���д���������� 
	memset(vis,false,sizeof(vis));//false��ʾι�߹���true�����Ѿ��߹� 
	if(n>=k) printf("%d\n",n-k);
	else printf("%d\n",bfs());
} 
