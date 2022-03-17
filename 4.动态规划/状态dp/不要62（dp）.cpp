#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[10][3];
void Init(){   
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=8;i++){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1]; 
        dp[i][1]=dp[i-1][0];     
        dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];  
    }
}
int Solve(int x){
    int digit[15];
    int cnt=0,tmp=x;
    while(tmp){
        digit[++cnt]=tmp%10;
        tmp/=10;
    }
    digit[cnt+1]=0;
    int flag=0,ans=0;
    for(int i=cnt;i>0;i--){
        ans+=digit[i]*dp[i-1][2];
        if(flag)  
            ans+=digit[i]*dp[i-1][0];
        else{
            if(digit[i]>4) 
                ans+=dp[i-1][0];
            if(digit[i]>6) 
                ans+=dp[i-1][1];
            if(digit[i+1]==6 && digit[i]>2)
                ans+=dp[i][1];
        }
        if(digit[i]==4 || (digit[i+1]==6 && digit[i]==2))
            flag=1;
    }
    return x-ans;
}
int main(){
    int a,b;
    Init();
    while(~scanf("%d%d",&a,&b)){
        if(a==0 && b==0)
            break;
        printf("%d\n",Solve(b+1)-Solve(a));
    }
    return 0;
}
