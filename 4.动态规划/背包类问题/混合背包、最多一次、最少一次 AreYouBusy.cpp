//AreYouBusy
/*
���⣺��n�鹤����ÿ�����������Ի������й���ʱ��ΪV,ÿ�鹤����Ҫ�����ѡ1��������ѡ1��������ѡ�� 
	����Ի�õ���������Ϊ���� 
	���������൱�ڶ��鱳��
	����ѡ1���� �ѵ�ǰ��ȫ����Ϊ��Сֵ�� 
	f[i][z]=max(max(f[i][z],f[i][z-w[j]]+v[j]),f[i-1][z-w[j]]+v[j]);
						��ǰ��Ĺ滮		��һ�ν��ת�Ʋ�ѡ��һ����Ʒ 
	����ѡ1���� �ڹ滮��ʱ��ֻѡ��ǰ��ѡ����һ�ν��ѡ��������ô��������ѡ0��1��״̬��ѡ0��1��״̬�Ƚ� 
	f[i][z]=max(f[i][z],f[i-1][z-w[j]]+v[j]);
				��ǰ���	��һ�ν��ת�Ʋ�ѡ��һ��(�ɿ��Բ�ѡ����Ϊf[i][z]�Ǽ̳���һ�ν��) 
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1<<29;
int w[105],v[105],f[105][105];
int main()
{
	int n,V,m,s,ans;
	while(~scanf("%d%d",&n,&V)){
		memset(f,0,sizeof(f));
		
		for(int i=1;i<=n;i++){
			scanf("%d%d",&m,&s);
			for(int j=1;j<=m;j++) scanf("%d%d",&w[j],&v[j]);
			if(s==2){//����ȡ 
				for(int j=0;j<=V;j++) //��ǰ���ʼ��
					f[i][j]=f[i-1][j];
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(f[i][z],f[i][z-w[j]]+v[j]);
			}
			else if(s==0){//����ȡ1�� 
				for(int j=0;j<=V;j++)//��ǰ���ʼ��
					f[i][j]=-maxn;//dp[0][j]�򱣳�0 
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(max(f[i][z],f[i][z-w[j]]+v[j]),f[i-1][z-w[j]]+v[j]);
					//f[i-1]��Ϊ�˰���һ�ν��ת�ƹ�����ͬʱ����ѡ��һ����ѡ��֮�;ͳ�Ϊ��f[i]
					//��֤����ѡ��һ��
			}
			else if(s==1){//���ȡһ�� 
				for(int j=0;j<=V;j++)  //��ǰ���ʼ��
					f[i][j]=f[i-1][j];
				for(int j=1;j<=m;j++)
					for(int z=V;z>=w[j];z--)
						f[i][z]=max(f[i][z],f[i-1][z-w[j]]+v[j]);
						//f[i-1]�ǲ���ģ�ֻҪf[i][j]ȡ��һ�ξͲ�����ȡ�ˣ���ȻҲ���Բ�ȡ
			}
		}
		ans=max(-1,f[n][V]);//û���������ֻ��������ȡ1���ﲻ���������ֵ��Ϊ���ģ���������������-1
		printf("%d\n",ans);
	}
} 
