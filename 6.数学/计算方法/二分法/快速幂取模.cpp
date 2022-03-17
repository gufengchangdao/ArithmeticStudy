//快速幂取模 
ll PowerMod(ll a, ll b,ll mod)//计算a的b次方并取c模 
{
	if(b<0) return 0; 
    ll ans = 1;//作为答案 
    a=a%mod;//先计算一步，防止数据溢出 
    while(b){
        if(b&1) ans=(ans*a) % mod;//如果指数b是奇数的时候，化偶，b等于1的时候把a的b次方*ans（储存的数）赋给ans 
        b>>=1;//减少时间复杂度，a的b次方等于a*a的b/2次方 
        a=(a * a) % mod;
    }
    return ans;
}
ll inv(ll a)//求a的逆元 
{
	return PowerMod(a,mod-2);	
}
//数组储存结果,适用于底数a不变，指数b改变的多次计算，用数组记录计算结果 
ll mi[100];	//下标d的意义是指数b不断除以2除到1所除的次数，即2^x<b<2^(x+1) 下标d最大为x 
//	mi[1]=a^b%mod	mi[2]=a^(b/2)%mod	mi[3]=a^(b/4)%mod ...
ll powermod(ll a,ll b,ll mod,int d) //求a^b 这里a,b都大于0 
{ 
    if(b==1) return a; 	//递归边界 
    if(mi[d]!=0) return mi[d];		
	 
    ll s=(powermod(a,b/2,mod,d+1)*powermod(a,b/2,mod,d+1))%mod; 
    if(b&1) s=s*a%mod; //b是奇数的时候，s还少乘个a 
    return mi[d]=s; //路径压缩 
}
powermod(a%mod,b,mod,d); 

//取余计算： 
/*ab mod c=(a mod c)(b mod c)mod c  
(a + b) % p = (a % p + b % p) % p (1)
(a - b) % p = (a % p - b % p ) % p (2)   a小于b时 (a - b) % p=(a%p-b%p)+p
(a * b) % p = (a % p * b % p) % p (3)
a ^ b % p = ((a % p)^b) % p (4)
结合律:((a+b) % p + c) % p = (a + (b+c) % p) % p (5)
((a*b) % p * c)% p = (a * (b*c) % p) % p (6)

交换律:(a + b) % p = (b+a) % p (7)
(a * b) % p = (b * a) % p (8)

分配律:(a+b) % p = ( a % p + b % p ) % p (9)((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p (10)
