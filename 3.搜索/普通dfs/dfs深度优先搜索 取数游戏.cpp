//ȡ����Ϸ 
//��һ�������У�ȡ��һ��λ�õ����󣬸�����Χ��8����������ȡ����ȡ�õ����ֵ 
//���ݺ��٣���Ϊ���ڵ�������ȡ����ôÿ�ξ��߾ͻ�Ӱ���´ν�����Ӷ�����̰�ľ��߲������Ż� 
//�����������dfs�� �ݹ�ͻ��� 
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dir[8][2]={-1,0,-1,1,-1,-1,0,1,0,-1,1,-1,1,0,1,1};
int ans,prem,n,m;
int v[8][8],mark[8][8];//mark��¼��Χ8��λ���м����� 

void dfs(int x,int y)//�ݹ�������� 
{
	if(y>=m+1){	//��y��x 
		dfs(x+1,1);
		return; 
	}
	if(x==n+1){
		ans=max(ans,prem);
		return;
	}
	
	dfs(x,y+1);//��ȡ����� 
	
	if(!mark[x][y]){//�����������ȡ 
		prem+=v[x][y];
		for(int i=0;i<8;i++)
			mark[x+dir[i][0]][y+dir[i][1]]++;
		dfs(x,y+2);
		
		for(int i=0;i<8;i++)//���� 
			mark[x+dir[i][0]][y+dir[i][1]]--;
		prem-=v[x][y];
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		memset(mark,0,sizeof(mark));
		ans=0;prem=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&v[i][j]);
		dfs(1,1);
		printf("%d\n",ans);
	}
}
