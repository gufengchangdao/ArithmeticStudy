//����+��̬�滮 
//sum[i][j]Ϊi��j���������ܺͣ�dp[i][j]Ϊi��j�������ŷ�����ȡ�ú͵����ֵ
// dp[i][j]=sum[i][j]-min(dp[i+1][j],dp[i][j-1])��ż����һ������ǰ������==�ܺ�-������Сֵ�����ŷ��� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105],sum[105][105],dp[105][105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp[i][i]=a[i];//��ʼ�� 
        sum[i][i]=a[i];
    }
    for(int i=0;i<n;i++)//������� 
        for(int j=i+1;j<n;j++){//jҪ��֤���ڣ�����Ҳû��i 
            sum[i][j]=sum[i][j-1]+a[j];
        }
    for(int i=n-1;i>=0;i--)//������㡣�����Ž⣬��Ҫ������������ٵĿ�ʼ�����ӽ������ 
        for(int j=i+1;j<n;j++){
            dp[i][j]=sum[i][j]-min(dp[i+1][j],dp[i][j-1]);//��̬�滮 
        }
    printf("%d %d\n",dp[0][n-1],sum[0][n-1]-dp[0][n-1]);//ǰ�ߴ�0��n-1�����ŷ���������Ϊ�ܺ������ 
}
