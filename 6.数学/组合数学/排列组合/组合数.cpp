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
	fac[0]=1;	//��׳� 
	for(int i=1;i<=maxn;i++) 
		fac[i]=fac[i-1]*i%mod;

	inv[maxn]=powermod(fac[maxn],mod-2);	//��׳���Ԫ 
	for(int i=maxn-1;i>=0;i--)	//ע������inv[0]=1����Ϊc(m,0)=1 
		inv[i]=inv[i+1]*(i+1)%mod;
}
//������� 
int C(int m,int n)
{
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
}
//ע�⣺����Ҫ�����ٿռ�������������������������Ĳ���m,n�ķ�Χ�Ƕ��� 
