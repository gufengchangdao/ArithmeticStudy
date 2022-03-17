//Floyd�㷨:��̬�滮 
/*
������ڵ�A������ڵ�B�����·�������2�ֿ��ܣ�1��ֱ�Ӵ�A��B��2�Ǵ�A�������ɸ��ڵ㵽B
����ÿһ���ڵ�K�����Ǽ��dis(AK) + dis(KB) < dis(AB)�Ƿ���������������֤����A��K�ٵ�B��·��
	��Aֱ�ӵ�B��·���̣����Ǳ����� dis(AB) = dis(AK) + dis(KB)������һ���������Ǳ��������нڵ�K��
	dis(AB)�м�¼�ı���A��B�����·���ľ��롣 

��ʼ����
	dis[][]	�ñ߳���ʼ��
	path[i][j]	��j����ʼ��(���ߵĺ�׺) �������i��ʼ���Ļ�����ᵹ��洢 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
const int Inf=0x3f3f3f3f;
int dis[maxn][maxn];
int path[maxn][maxn];
int n,m,s,d;

void floyd() 
{
	//��ʼ�� ·��path 
    for(int i=1; i<=n ; i++){
    	for(int j=1; j<= n; j++){
   	      	if(dis[i][j]==Inf){
   	           	path[i][j] = -1;//��ʾ  i -> j ��ͨ 
   	      	}
		  	else{
               	path[i][j] = j;// ��ʾ i -> j ǰ��Ϊ i
          	}
   		}
    }
    
    for(int k=1; k<=n; k++)	//n�ķ�ΧΪ1~n ��k��������Χ����������İ�i��j�����·��ȷ�������ˣ���
				//��������ڸ��̵�·��ʱ���Ѿ����ٻ�����ˡ� 
        for(int i=1; i<=n; i++)
          	for(int j=1; j<=n; j++)
            	if(!(dis[i][k]==Inf||dis[k][j]==Inf)&&dis[i][j] > dis[i][k] + dis[k][j]) {
              		//��������תվk���б����������Ž� 
					dis[i][j] = dis[i][k] + dis[k][j];
              		//path[i][k] = i;//ɾ��
              		path[i][j] = path[k][j];//��¼��׺��� 
            	}
}

void printPath(int from, int to) 
{
    printf("%d-",from);
    while(path[from][to]!=to) {
    	printf("%d-",path[from][to]);
    //    System.out.print(path[from][to] +"");
        to = path[from][to];
    }
    printf("%d\n",to);
}

int main()
{	
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		memset(dis,0x3f,sizeof(dis));	
		
		for(int i=1;i<=m;i++){
			int u,v,l,w,tem;
			scanf("%d%d%d%d",&u,&v,&l);	//u--v�ĳ���l  
			dis[u][v]=l;	
			dis[v][u]=l; 
		}
		
		scanf("%d%d",&s,&d);	//���s �յ�d 
		floyd();
		printPath(s,d);
		printf("dis:%d\n",dis[s][d]);
	}	
}


