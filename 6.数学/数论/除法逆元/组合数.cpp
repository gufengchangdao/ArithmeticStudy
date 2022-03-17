#define int long long
int powermod(int a,int b)
{
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;	
	}
	return ans;
}

void init()
{
	fac[0]=1;	//求阶乘 
	for(int i=1;i<=maxn;i++) 
		fac[i]=fac[i-1]*i%mod;

	inv[maxn]=powermod(fac[maxn],mod-2);	//求阶乘逆元 
	for(int i=maxn-1;i>=0;i--)	//注意这里inv[0]=1，因为c(m,0)=1 
		inv[i]=inv[i+1]*(i+1)%mod;
}
//求组合数 
int C(int m,int n)
{
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
}
//注意：数组要开多少空间根据求的组合数，看组合数传入的参数m,n的范围是多少 
