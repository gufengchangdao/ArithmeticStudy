//BFS�����Ϊ'@'�����е�Ϊ'.'�����е�Ϊ'#',�������㿪ʼ�������ߵĵ�ĸ���num 

#include<bits/stdc++.h>
#define check(x,y)(x<xx&&x>=0&&y>=0&&y<yy)//�жϸõ��Ƿ�λ���Թ��ڣ���ȡ�Ǵ�0��ʼ�� 
using namespace std;
char room[23][23];//�����Թ� 
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//�ֱ��������¡����ҡ����� 
int xx,yy,num=0;//num��ʼ��Ϊ0 
struct node{	//�������� 
	int x,y;
}start;//���ס���һ������ 
//��ÿһ���������������ߣ������Ժ�ͱ�ǳɲ����е㣬�ö���ʵ�� 
void bfs(int dx,int dy)
{	//�������У��������(�������Ϊ'@',����'.'���������֮��Ҫ���Ϊ'#')
	queue<struct node>q;
	start.x=dx;
	start.y=dy;
	q.push(start);
	num=1;//������ټ��� 
	//BFS��ֱ����������������Ϊ����Ϊ��Ϊ���� 
	while(!q.empty()){
		//��ȡ�������꣬ɾ������Ԫ�� 
		start=q.front();
		q.pop();
		node next;
		for(int i=0;i<4;i++){	//��������Ѱ�ҿ��е� 
			next.x=start.x+dir[i][0];
			next.y=start.y+dir[i][1];
			if(check(next.x,next.y)&&room[next.x][next.y]=='.'){
				q.push(next);//���� 
				room[next.x][next.y]='#';//��� 
				num++;//���� 
			}
		}
	}
}
int main()
{
	int dx,dy;
	while(~scanf("%d%d",&xx,&yy)){	//�����Թ���С 
		getchar();//��ȡ���з� 
		if(xx==0&&yy==0) return 0; 
		for(int y=0;y<yy;y++) 
			for(int x=0;x<xx;x++){
				scanf("%c",&room[x][y]);
				if(x==xx-1) getchar();//��ȡ���з� 
				//��ȡ��ʱ��Ѱ����㣬dx��dy��¼��� 
				if(room[x][y]=='@'){
					dx=x;
					dy=y;
				}
			}
		bfs(dx,dy);
		printf("%d\n",num);
	} 
}
//�ڶ�ȡ�Թ���������ŵ�ʱ��ʹ��scanf()Ҳ���ȡ���з�������ʹ��getchar()
//							  ʹ��get()�㲻��Ҫʹ��getchar()��ȡ���з�
/* 
void dfs(int dx,int dy)
{
	room[dx][dy]='#';
	//��ӡ�߹���λ�ã�������֤�Ƿ���ȷ 
	num++;
	for(int i=0;i<4;i++){
		int newx=dx+dir[i][0];
		int newy=dy+dir[i][1];
		if(check(newx,newy)&&room[newx][newy]=='.'){
			dfs(newx,newy);
			//��ӡ���˵�λ�����꣬�۲�������
			//���һ�λ��num�����˵�1������������˵���� 
		}
	}
}
*/ 
