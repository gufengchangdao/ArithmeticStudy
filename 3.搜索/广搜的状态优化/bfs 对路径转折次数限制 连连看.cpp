//������
/*
���⣺�����(x1,y1)��(x2,y2)Ҫ��
		������ֵ��ȣ�������ͬһ���� 
		���㶼��Ϊ0���������ֻ��0�ߵ��յ� 
		���ֻ��ת�����Σ��������β��� 
	���Ƿ�ɴ�
	bfs:�ṹ������trun��¼ת�۴�����������Ϊ-1�����롣��һ���������ʱ�򣬱����ĸ����򣬶���ÿ��
	�����ÿ���㣬ֻҪû����򲻿��ߣ������Ÿ÷��򲻶���������˶�ÿһ��forѭ������·������trun��1
	��ΪֻҪ���������ĵ�trunһ������С��ͬ����ĵ�Ҳ����Ϊ��ǹ����ᱻ������� 
	 
*/
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int map[1001][1001];
bool v[1001][1001];
int x1,y1,x2,y2;
bool flag;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//��������
struct node{
	int x;
	int y;
	int trun;
}start,endd;
queue<node> q;
 
bool judge(int x0,int y0)
{
	if(x0<0||x0>=n||y0<0||y0>=m)
		return true;
	if(x0==x2-1&&y0==y2-1) //�����յ� 
		return false;
	if(map[x0][y0]!=0)
		return true;
	return false;
}

void bfs(int x0,int y0)
{
	int i;
	while(!q.empty()) q.pop();
 
	start.x=x0;
	start.y=y0;
	start.trun=-1;//ע�⣺����¼Ϊ-1������"��ת"һ�� 
	v[x0][y0]=1;
	q.push(start);
 
	while(!q.empty()){
		start=q.front();q.pop();
		
		if(start.trun>=2) continue;
//	-1 δת��(���)  0 ת��1����  1 ת��������  2 ת��3����		
		for(i=0;i<4;i++){
			endd.x=start.x+dir[i][0];
			endd.y=start.y+dir[i][1];
			endd.trun=start.trun+1;
			
			while(judge(endd.x,endd.y)==0){//���Ÿ÷��򲻶����� 
				if(endd.x==x2-1&&endd.y==y2-1){
					flag=true;
					return;
				}
				if(v[endd.x][endd.y]==0){//ͬ����Ļ���Ϊ��ǲ����������trunû�д� 
					q.push(endd);
					v[endd.x][endd.y]=1;
				}
				endd.x+=dir[i][0];	//���Ÿ÷���������� 
				endd.y+=dir[i][1];			
			}
		}
	}
}
 
int main()
{
	int t;
	int i,j;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		for(i=0;i<n;i++)
            for(j=0;j<m;j++)
			    scanf("%d",&map[i][j]);
        scanf("%d",&t);
		while(t--){
            flag=false;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2&&y1==y2){//����յ���ͬ������
                printf("NO\n");
                continue;
            }
            if(map[x1-1][y1-1]!=map[x2-1][y2-1]||map[x1-1][y1-1]==0||map[x2-1][y2-1]==0){
                printf("NO\n");
                continue;
            }
			memset(v,0,sizeof(v));
			bfs(x1-1,y1-1);
			if(flag) printf("YES\n");
            else printf("NO\n");
		}
	}
	return 0;
}
