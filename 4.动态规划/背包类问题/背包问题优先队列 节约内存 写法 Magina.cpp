/*
����̫�� 
01������ʱ��;����кܶ�״̬��ʵ��û���õģ����ǿ��Բ���¼���İ���
��֦�������ȶ��С�����Ǯ�ݼ������Լ�����ʱ��������򣬽�Ǯ�ٵ���ʱ��࣬������״̬���������� 
��Ϊ��ͨ��Ĳ���һ��ѡ�����Ծͷֳɼ����������ò��鼯����ͨ�顢
�������㣺
����ͨ��->���鼯������ͬһ��ͨ���ڵ���Ʒ����ѡ�����ƶ��01���������ò��鼯һ������һ�����Ͽ� 
�������ر��->���ȶ��У���Ϊ���ݵĹ�ϵ�����ź���Ķ��п���ȥ����ʵ�õ���Ʒ�������Ա�����������г��ֵ���Ч�������ڴ��˷�
			->�������飬�������У�һ����һ���£����϶����ｫ�������Ʒ(ѡ�Ͳ�ѡ)�����¶��У����¶�����ȥ����ʵ�õ���Ʒ������϶��� 
��ÿ����ͨ��(01����)��ans,��ÿ����Ʒװ�벻װ������ֱ��¼��ȥ����ͨ����֦���ټ�������ֱ���õ����Ž� 
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=60;
const int INF=0x7fffffff;
int n,m,k,w[N],v[N],fa[N];
struct dat{
    int x,y;  //ʱ�䣬��Ǯ 
    bool operator < (const dat &rhs) const{
        return y<rhs.y || y==rhs.y && x>rhs.x;//y(��Ǯ)������ȼ��ߣ���ͬ��Ǯ��ʱ��̵����ȼ��� 
    }
};
priority_queue<dat> q1,q2;//�������зֱ���ѡ�Ͳ�ѡ���൱�ڹ������� 

int getfa(int x)//���鼯���Ҹ��ڵ� 
{ 
	return x==fa[x] ? x : fa[x]=getfa(fa[x]); 
}

int main()
{
    int T,kase=0; 
	scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) fa[i]=i;//���鼯�����ʼ�� 
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&w[i],&v[i],&k);
            for (int j=1;j<=k;j++) { 
                int x; 
				scanf("%d",&x);
                fa[getfa(x)]=getfa(i);//����x�ĸ��ڵ㲢����ӵ�i�ϣ��γ���iΪ���ڵ���� 
            }
        }
        
        int ans=INF;//�𰸳�ʼ��Ϊ���ֵ 
        for (int i=1;i<=n;i++) 
            if (fa[i]==i){  //һ����ͨ�����Ʒ��i�Ǹ��ڵ�  
                while (!q1.empty()) q1.pop();//��ʼ�� 
                while (!q2.empty()) q2.pop();
                q1.push((dat){0,0});//��ʼʲô��Ʒ��ûѡ 
                
                for (int j=1;j<=n;j++) {  //Ѱ��i�����е���Ʒ 
                    if (fa[j]!=i) continue;
                    while (!q1.empty()){//�ȱ����ϵģ�������Ĵ����µĶ��� 
                        dat u=q1.top(); q1.pop();
                        if (u.y>=m){ //��֦1��������Ʒ��Ǯֱ�Ӵ��ڵ�����Ҫֵ 
							ans=min(ans,u.x); 
							continue; 
						}  
                        if (u.x>=ans) continue;  //��֦2��������Ʒ����ʱ����ڵ���Ŀǰ�� 
                        q2.push(u);  //��ѡ 
                        int x=u.x+w[j],y=u.y+v[j];//ѡ������ʱ�䡢��Ǯ����  
                        if (y>=m){ //��֦1 
							ans=min(ans,x); 
							continue; 
						}  
                        if (x>=ans) continue;  //��֦2 
                        q2.push((dat){x,y});  //ѡ 
                    }
                    int Min=INF;
                    while (!q2.empty()){//�ٱ����µģ���ȥ��ʵ�õ�ʣ����Ʒ�����ϵ� 
                        dat u=q2.top(); q2.pop();
                        if (u.x<Min) q1.push(u),Min=u.x; //��֦3:Ǯ�ȱ�����ʱ��ȴ���ȱ��˶࣬������״̬û���� 
                    	//��Ϊ���ȶ�������Ʒ�ᰴ��Ǯ��С������������ u.x<Min˵���ǿ��ų�����Ʒ������ 
					}
                }
            }
        if (ans==INF) printf("Case %d: Poor Magina, you can't save the world all the time!\n",++kase);
        			//���ans=INF����ʾû�н�����Դﵽ�򳬹�m,�����ڽ� 
		else printf("Case %d: %d\n",++kase,ans);    
    }
    return 0;
}
