
#include<bits/stdc++.h>
#define check(a,b)(a>=0&&a<3&&b>=0&&b<3)//�ж��Ƿ�Խ�� 
using namespace std;
const long MAX=362880;
int	begin[9],end[9];//��ʼ�����״̬ 
struct node{
	int dir[9];//ÿ��״̬ 
	int toop;//��¼��С���� 
};
long visted[MAX]={0};//��� 
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//0-n�Ľ׳� 
//�ÿ���չ�� ���� ��3������9�Ľ׳˴�С��״̬ 
bool cantor(int str[],int n)//״̬��Ԫ�ظ��� 
{
	long result=0;//result��¼ʱ�ڶ�����״̬ 
	for(int i=0;i<n;i++){	//�жϱ�str[]С�����еĸ������ж����� 
		int sum=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j]) sum++;
		result+=sum*factory[n-i-1];//����=�ȵ�ǰλС�����ĸ���*δ�̶������Ľ׳� 
	}
	//�жϸ�״̬�Ƿ񱻱�ǹ� 
	if(!visted[result]){
		visted[result]=1;//��ǲ�����true 
		return 1;
	}
	else return 0;
}

int bfs()
{
	//������� ����ǡ�·����ʼ�� ������
	node start;
	queue<node>q;
	memcpy(start.dir,begin,sizeof(start.dir)); 
	start.toop=0;//·��Ϊ0 
	cantor(start.dir,9);//������ 
	q.push(start);
 
	while(!q.empty()){
		//��ȡ���׽ṹ�壬�ж��Ƿ���������������������Ϊ���δ�ж��Ƿ��������� 
		start=q.front(); q.pop();
		if(memcmp(start.dir,end,sizeof(end))==0) return start.toop;
		//һά���ά�ٻص�һά���жϣ����롢��� 
		int z,nz;//zΪԭ��0��λ�ã�nzΪ�ƶ���0��λ�� 
		for(z=0;z<9;z++) 
			if(start.dir[z]==0) break;	//��0��λ�� 
		
		int x=z%3;//������ 
		int y=z/3;//������ 
		for(int i=0;i<4;i++){
			int newx=x+dir[i][0];
			int newy=y+dir[i][1];
			nz=newx+newy*3;
			
			if(check(newx,newy)){//�ж��Ƿ�Խ�� 
				node newnode;
			memcpy(&newnode,&start,sizeof(node));//�ṹ�帴����&��size(node) 
				swap(newnode.dir[z],newnode.dir[nz]);//�任���µ�λ�� 
				newnode.toop++;//·����һ 
				if(cantor(newnode.dir,9))//���δ����Ǿ���������� 
					q.push(newnode);
			}
		}	
	}
	return -1;//����·������Ҳû���ַ���Ŀ��״̬����� 
}

int main()
{
	for(int i=0;i<9;i++) scanf("%d",&begin[i]);
	for(int i=0;i<9;i++) scanf("%d",&end[i]);
	int num=bfs();
	if(num!=-1) printf("%d\n",num);
	else printf("Impossible\n");
}
