//N�ʺ����� 
#include<bits/stdc++.h>
using namespace std;
int n,tot=0;	//tot��¼��n�ʺ����ָ��� 
int col[12]={0};	//��¼�ʺ�λ�ã�col[n]Ϊ��n�е�col[n]��
//�ж��Ƿ�������� 
bool check(int c,int r)	//cΪ��  rΪ�� 
{
	for(int i=0;i<r;i++)	// 
		if(col[i]==c||(abs(col[i]-c)==abs(i-r)))	//�Ƿ���ͬһ�л��ߴ��ڶԽ���λ�� 
			return false;
	return true;
} 

void dfs(int r)	//һ��һ�еݹ� 
{
	if(r==n){	//�ݹ����,��Ϊ��dfs(0)��ʼ�ģ��ʵ�n�в���forѭ�� 
		tot++;	//��¼��ָ��� 
		return;
	}
	for(int c=0;c<n;c++)	//Ѱ�ң��������������ƶ� 
		if(check(c,r)){
			col[r]=c;	//��� 
			dfs(r+1);
		}
}

int main()
{
	int ans[12]={0};//��¼n�ʺ����ָ��� 
	//�ȴ������ᳬʱ 
	for(n=1;n<=10;n++){	//��ʾ1��10�ʺ� 
		memset(col,0,sizeof(col));
		tot=0;
		dfs(0);
		ans[n]=tot;
	}
	while(cin>>n){
		if(n==0) return 0;
		cout<<ans[n]<<endl;
	}
	return 0;
}
