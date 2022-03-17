//博弈+动态规划 
//sum[i][j]为i到j所有数的总和，dp[i][j]为i到j采用最优方案后取得和的最大值
// dp[i][j]=sum[i][j]-min(dp[i+1][j],dp[i][j-1])，偶数的一段数，前者最优==总和-后者最小值的最优方案 
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
        dp[i][i]=a[i];//初始化 
        sum[i][i]=a[i];
    }
    for(int i=0;i<n;i++)//正序计算 
        for(int j=i+1;j<n;j++){//j要保证大于（等于也没错）i 
            sum[i][j]=sum[i][j-1]+a[j];
        }
    for(int i=n-1;i>=0;i--)//倒叙计算。求最优解，从要处理的数据最少的开始，即从结果出发 
        for(int j=i+1;j<n;j++){
            dp[i][j]=sum[i][j]-min(dp[i+1][j],dp[i][j-1]);//动态规划 
        }
    printf("%d %d\n",dp[0][n-1],sum[0][n-1]-dp[0][n-1]);//前者从0到n-1的最优方案，后者为总和与其差 
}
