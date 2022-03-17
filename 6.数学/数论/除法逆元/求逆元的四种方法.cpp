逆元 
	如果 a*x=1(mod p) 成立，那么 x 是 a 在 mod m 的条件下的逆元
	用途：算a/b(mod p)，b太大了会爆掉double的精度 
	a/b(mod p)=a*inv[b](mod p)	inv[b]为b在mod p下的逆元

快速幂求逆元
	费马小定理
	a^(p-1)=1(mod p) p为素数并且a%p!=0
	inv[a]=a^(p-2)(mod p) ,用快速幂求 
ll quickpow(ll a,ll b)
{
	if(b<0) return 0;
	ll ans=1;
	a%=mod;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
} 
long long inv(ll a)
{
	return quickpow(a,mod-2);
} 

扩展欧里几得
	作用：如果a*x+b*y=m(mod p)有解，那么m一定为gcd(a,b)的倍数；
	求a的逆元：另b=p,则a*x+p*y=1(mod p) 前提为gcd(a,p)=1 
	已知gcd(a,b)=gcd(b,a%b);
	// 求x, y，使得ax + by = gcd(a, b)
	另gcd(a,b)=d,则ax+by=d，不断递归得到d，此时a=d,b=0,有解a*1+b*0=d
	返回上一层有b*x1+a%b*y1=d
				b*x1+(a-a/b*b)*y1=d
	 			a*y1+b*(x1-(a/b)*y1)=d
	 	所以x=y1  y=x1-(a/b)*y1，不断上一层返回，得到每一层的解 
	 
int exgcd(int a, int b, int &x, int &y)
{
    if (!b){
        x = 1; y = 0;
        return a;   //到达递归边界，a就是最大公约数 
    }
    int d = exgcd(b, a % b, x, y);先不断递归得到最大公约数d，不断向上一层返回 
    int temp=y;    //推出这一层的x，y
    y=x-(a/b)*y;
    x=temp;
    return d;
}
	 
欧拉函数：
	作用：求小于x的整数中与x互质的数的个数
	求逆元:a^f(p)=1(mod p) 有 inv[a]=a^(f(p)-1) 
	f(x)=x*(1-1.0/p1)*(1-1.0/p2)*(1-1.0/p3)...*(1-1.0/pn)	pi为x所有的质因子
	性质：对于质数p,f(p)=p-1 	1到n-1的数都与n互质 
	  	  质数p,n=p^k时，f(x)=p^k-p^(k-1) 	n只有一个质因子p，f(n)=n*(1-1/p)=p^k*(1-1/p)
		  欧拉函数是积性函数，但不是完全积性函数。若m,n互质，则f(m*n)=f(m)*f(n)
		  	特殊的，当m=2，n为奇数时,f(2*n)=f(n)
		  当n>2时,f(n)是偶数。
 		  小于n的数中，与n互质的数的总和为f(n)*(n/2)  (n>1)	 
 		  		与n互质的数除了m还有n-m，故与n互质的数的平均数为n/2，一共有f(n)个 
		  n的因数（包括1和它自己）的欧拉函数之和等于n。

递推公式求逆元：
	inv[1]=1;	适用于求连续的逆元 
	inv[i]=(p-p/i)*inv[p%i]%p	 
	
	推理：另t=p/i	k=p%i 
		t*i+k=0(mod p)
		-t*i=k;两边同时除以k*i
		-p/i*inv[p%i]=inv[i](mod p)
		(p-p/i)*inv[p%i]%p=inv[i]   
