//P2622 �ص�����II
/*
	nյ�ƣ�m����ť���γ�һ��m*n�ľ���ÿ����ťʩ�Ӹ���jյ�Ƶ�Ч����a[i][j]����
		a[i][j]=1 ���䰵���������䣻=-1 ���������������䣻=0 ɶ�仯Ҳû�У�
		���nյ��ȫ������ȫ�����С�������� n<=10 
	n<=10,Ҫ��¼ÿ�������״̬����֪��ֻ������״̬����n��С����֪��״̬ѹ����
		�ö����Ƶķ�ʽ��ʾ�Ƶ�״̬����λ����Ե����ƽ����޸ģ���ʮ�������洢 

*/
#include<stdio.h>
#include<queue>
using namespace std;
bool vis[3000];
int n,m;
int a[105][15];	//ԭʼ���� 
struct node{
	int s,dis;	//�ֱ�Ϊÿ���׶ε�״̬�������� 
};

int bfs()
{
	queue<node>q;
	q.push((node){(1<<n)-1,0});	//ֱ�Ӵ������飬��ʼ��ʱ��n����ȫ��������Ӧ�Ķ�������n��1 
	
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		if(cur.s==0) return cur.dis;
		
		for(int i=1;i<=m;i++){//��ÿ����ť���� 
			int next=cur.s;
//printf("ȡ��%d ",next);
			for(int j=1;j<=n;j++){//��ÿ���ƽ��б��� 
				if(a[i][j]==1&&next&(1<<(j-1))) next^=1<<(j-1);//������1�ҵ�jյ�������ģ�����
				else if(a[i][j]==-1&&!(next&(1<<(j-1)))) next^=1<<(j-1);//������-1�ҵ�jյ������ģ��䰵
	//�ؼ����裺1<<j-1�ǽ�1����j-1λ����ֻ�е�jλΪ1��1^1=0 ���䰵, 1^0=1 ������      
			}
			if(!vis[next]){
				vis[next]=1;
				q.push((node){next,cur.dis+1});
//printf(" ����%d %d\n",next,cur.dis+1);
			}
		} 
	}
	return -1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);	
	printf("%d",bfs());
} 
