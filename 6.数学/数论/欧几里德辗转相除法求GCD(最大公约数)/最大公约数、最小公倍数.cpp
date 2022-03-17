//函数
#include<algorithm>
a=_gcd(x,y);//求最大公约数，x和y的类型应该一致、 

int gcd(int m,int n)//m要大于等于n 
{
   return !n?m:gcd(n, m%n);
}

int gcd(int m,int n)
{
	if(m%n==0) return n;
	return gcd(n,m%n);
}

m*n==gcd(m,n)*lcm(m,n) 
若d=gcd(m,n),若m=s*x+t*y（s、t为整数且并不都为正）此时m一定为d的倍数
gcd(x^a-1,x^b-1)=x^gcd(a,b)-1 
	推理：
		记T(t)=1+x+x^2+...+x^(t-1)
		x^a-1=(x-1)(1+x+x^2+...+x^(a-1))=(x-1)*T(a)
		gcd(x^a-1,x^b-1)=(x-1)*gcd(T(a),T(b))
			又因为 gcd(T(a),T(b))=T(gcd(a,b))
		gcd(x^a-1,x^b-1)=(x-1)*T(gcd(a,b))=x^gcd(a,b)-1
		
若c是a和b的任意一个不为d的公约数，则必有d%c==0(即为c|d)
gcd(m,n)==1，则m和n互素
如果m和n都为正整数，m>n,则gcd(m,n)==gcd(m+n,n)==gcd(m-n,n)// 大的 加减 小的 
