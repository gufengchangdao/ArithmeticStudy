//ȡ����Ϸ 
/*
��һ�������У�ȡ��һ��λ�õ����󣬸�����Χ��8����������ȡ����ȡ�õ����ֵ 
��⣺״̬ѹ�� 
	����ÿһ�е�ÿһ�����еĺϷ��ԣ����Ϸ���ǣ��Ϸ�����������л�õ�Ȩֵ�� 
	һ��һ�б�����ÿ�б����������У�ÿ�����б�����һ�����У�����������е����Ž⣬̰�� 
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,m,ans=0;
int a[7][7],v[7][70],dp[7][70];

void init(int i,int j)
{
    if((j<<1)&j) {//�������ڣ����Ϸ��������Ǻ��˳� 
        v[i][j]=-1;
        return ;
    }
    for (int x=1;x<=m;x++)	//����������еĻ�õ�Ȩֵ�� 
        if(j&(1<<(x-1))) v[i][j]+=a[i][x];	 
}

int main()
{
	int t;
    scanf("%d",&t);
    while (t--){
        ans=0;
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        //����ÿһ�еĺϷ������Ȩֵ��        
        for (int i=1;i<=n;i++) 
            for (int j=0;j<(1<<m);j++)
                init(i,j);
                
        m=1<<m;
        for (int i=0;i<m;i++){//��һ�в��ÿ���ǰһ�У����ȴ��� 
        	dp[1][i]=v[1][i];
            ans=max(ans,dp[1][i]);
        }
        for (int i=2;i<=n;i++)
            for (int j=0;j<m;j++){//���и������� 
            	if(v[i][j]==-1) continue;//�������в��Ϸ� 
                for (int k=0;k<m;k++){//��������������� 
                	if(v[i-1][k]==-1) continue;//��һ�и������в��Ϸ� 
                    if(j&k) continue;//�������� 
                    if((j<<1)&k) continue;//����б�������� 
                    if((j>>1)&k) continue;//���ڲ���һ�������ж���������ʱ�����ƺ����ƶ�Ҫ 
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i][j]);//���������Ž�õ����� 
                }
            	ans=max(ans,dp[i][j]);//Ҳ��������ٱ������һ�е�dpֵ 
			}
        printf("%d\n",ans);
    }
    return 0;
}

