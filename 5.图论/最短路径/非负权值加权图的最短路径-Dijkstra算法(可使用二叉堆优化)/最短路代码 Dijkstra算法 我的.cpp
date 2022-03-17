/*
Dijkstra�㷨
	����̰�ĵ�˼�룬ʹÿ�������ʵĽ�㶼���������̵� 
	�����ж����Ϊ����ѡ���㼯�� 		δѡ���㼯��
	
�������������Ϣ							��ʼ�� 
	vis[] �Ƿ񱻷���						false 
	dis[] ��㵽ÿ�����ľ�����Ϣ			INF 
	parent[] ��ÿ����㱻����ʱ�ĸ��׽��	-1
�������� 
update
	��ÿ����һ���µĽ�㣬���������λ��δѡ���㼯��������Ķ��������Ķ��������Ϣ
	���壺���½ڵ�ľ���ӱߵ�ȨֵС�ڶ�Ӧ��㵱ǰ�ľ���ʱ������¶�Ӧ������͸����������Ϣ
scan  
	ɨ�������Ϣ���ҵ�����δѡ�����о�����С���Ǹ����㣬̰��˼�룬
add
	��ӽ���ѡ���㣬��Ϊ�µĽ��
����ÿ�ζ���ѡ����̵������ߣ����Ա�����ÿ����㶼�����Ÿ�·������㵽��·�������·��������n�Σ�
	�ͻ������δѡ��㶼װ����ѡ��� 
*/
	 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
struct node{
	int next;
	int len;
	int cost;
};
vector<node>edge[maxn];	//��edge����ʾÿ���� 
int dis[maxn];
int cost[maxn];
bool vis[maxn];

int main()
{
	int n,m,s,d;	
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		for(int i=1;i<=n;i++)	//����ĵ�Ϊ1~n 
			edge[i].clear();
		memset(dis,-1,sizeof(dis));	
		memset(vis,0,sizeof(vis));
		
		for(int i=1;i<=m;i++){
			int u,v,l,w;
			scanf("%d%d%d%d",&u,&v,&l,&w);	//u--v�ĳ���l,����c  
			node tem={v,l,w};	 
			edge[u].push_back(tem);	//����ͼ��u->v����
			tem.next=u;			
			edge[v].push_back(tem);	//v->u���� 
		}
		
		scanf("%d%d",&s,&d);	//���s �յ�d 
		dis[s]=0;	//������Ϊ0 
		vis[s]=1;	//��� 
		
		int newp=s;	//��ǰ��ѡ���㼯�ϵ�"ͷ" 
		for(int i=1;i<=n;i++){	//����n�Σ���Ϊÿ����һ�ζ����һ����n������ȫ������
		//update	����"ͷ"���ܱ߶��� 
			for(int j=0;j<edge[newp].size();j++){
				int next=edge[newp][j].next;
				int len=edge[newp][j].len;
				int cos=edge[newp][j].cost;
				if(vis[next]) continue;	//�Ѿ���ǹ����ڵ��Ѿ������Ž��� 
				if(dis[next]==-1||dis[next]>dis[newp]+len||(dis[next]==dis[newp]+len&&cost[next]>cost[newp]+cos)){
					dis[next]=dis[newp]+len;	//���ڸ��Ž�ʱ���� 
					cost[next]=cost[newp]+cos;	
				}
			}
			//scan Ѱ���ٱ���̵Ķ��㣬Ҳ������ĳһ���߱�����ͷ�ˣ��ҵ��µ������δ���ʵĵ�  
			int Min=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(dis[j]==-1) continue;	//-1��ʾnewP��i������ 
				if(Min>dis[j]) Min=dis[j],newp=j;	
			}
			//add ��ӽ���ѡ���㣬��Ϊ�µĽ�㣬�½��ľ�����update��ʱ����¹��ˣ����ñ�
			vis[newp]=true; 
		}
		printf("%d %d\n",dis[d],cost[d]);
	}	
}


