//All X
/*
���� 10^1+10^2+...+10^k,����k�ǳ��� 
���÷��ε�˼�룬�������������������Ĵ𰸣� ������10^1+10^2+...+10^k����������10^x 
���� 10^1+...+10^k=(10^1+...+10^(k/2))*10^(k/2)+10^1+...+10^(k/2); һ��Ϊ����k���Ϊ�������ٸ�10^k 
���� 10^x=10^(x/2) һ��Ϊ����x���Ϊ�������ٸ�10
�����±�d��ʾÿ��״̬��return mi[d]��·��ѹ�� 
*/
#include<cstdio> 
#include<iostream> 
#include<cstring> 
#define ll long long 
using namespace std; 
int cas; 
ll x,m,mod,c,ans; 
ll mi[105],sum[105]; 
//�������㷨 
ll quick(ll k,int d) //��10^k
{ 
    if(k==1) return 10; 
    if(mi[d]!=-1) return mi[d];
	 
    ll s=(quick(k/2,d+1)*quick(k/2,d+1))%mod; 
    if(k%2==1) s=(s*10)%mod; 
    return mi[d]=s; 
} 

ll solve(ll k,int d) //��10^1+...+10^k 
{ 
    if(k==1) return 10; //��ֵ 
    if(sum[d]!=-1) return sum[d]; 	
	ll s=((solve(k/2,d+1)*quick(k/2,d+1))%mod+solve(k/2,d+1))%mod; //�û������㷨���ݹ��� 
    if(k%2==1) s=(s+quick(k,d))%mod; //k��������ʱ�򣬻���һ��10^k 
    return sum[d]=s; 	//�ϲ�������	������������Ϊ27����������ͬ�Ĳ��� 
} 

int main() 
{ 
    cin>>cas; 
    for(int i=1;i<=cas;i++){ 
        memset(sum,-1,sizeof(sum)); 
        memset(mi,-1,sizeof(mi)); 
        scanf("%lld%lld%lld%lld",&x,&m,&mod,&c); 
        m--; 
        ans=solve(m,1)+1; 
        ans=(ans*x)%mod; 
        printf("Case #%d:\n",i); 
        if(ans%mod==c) printf("Yes\n");
		else printf("No\n"); 
    } 
    return 0; 
} 
