//P2384 ���·
/*
���⣺	 
	n����Ĵ�Ȩ����ͼ��m���ߣ���1��n·���ı�Ȩ֮����Сֵ��ȡģ 
	���㣺��bfs��ʱ��dis�洢log��ʽ����ֹ������ҵ����·������·������� 
	�ص������ 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define mod 9987
using namespace std;
struct edge{
    int to,next,w;
}e[1000005];
queue<int> q;
int first[1005],po[1005][2];
bool vis[1005]; 
int tot=0;
double dis[1005];

void addedge(int u,int v,int val)
{
    e[++tot].w=val;
    e[tot].to=v;
    e[tot].next=first[u];
    first[u]=tot;	//�� 
}

int main()
{
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    memset(dis,127,sizeof(dis));	//��ʼ����� 
    dis[1]=0;
    q.push(1);//���������
	//�������������е�·���и��Ž���£���������û�д�ö��㿪ʼ��·���ͰѸý��Ҳ���� 
    while(q.size()){
        int now=q.front();q.pop();
        vis[now]=0; 
        for(int i=first[now];i;i=e[i].next){	//������now���������б� 
            int v=e[i].to;
            if(dis[v]>dis[now]+log(e[i].w)){	//�ҵ����Ž⣬������ǰ�����õ��·������(����û�߹�) 
                dis[v]=dis[now]+log(e[i].w);
                po[v][0]=now;	//����·������¼����ǰ׺��now 
				po[v][1]=e[i].w;
                if(!vis[v]){	//��һ�η��ʾʹ�����У���Ϊ��ǰ·���ǵ�ǰ���Ž� 
					vis[v]=1;
					q.push(v);
				}
            }
        }
    }
    //���յ㵹�ƻ���� 
    int ans=1,pos=n;
    while(pos!=1){
        ans=ans*po[pos][1]%mod;
        pos=po[pos][0];
    }
    printf("%d\n",ans);
    return 0;
}
/*
1.
bool vis[1005];
	�ó���ȡ����ǣ�����ͱ��,����v�����v��ʾ���������vΪ����һ��·������Ƿ�ֹ�ظ����룬����
		�Ǹ��Žⶥ�㲻����룬���Գ������� 
2.
e[tot].next=first[u];ԭ��first[u]����u��ָ���ıߵ���Ϣ������e[tot]��¼��ȥ 
first[u]=tot;	�ٽ�uָ��e[tot] 
���� u->a  u->b			u->c  
		u->b->a 	    u->c->b->a	�����Ͱ���u�йصı�ȫ����¼���� 
3.
po[v][0]=now;	����������ʱ���Ǵ���㵽�յ������ģ����Ա���·��ֻ�ܼ�¼����ǰ��	
	���ֻ�ܴ��յ��ҵ���� 
*/

