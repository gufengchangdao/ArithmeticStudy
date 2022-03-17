欧拉函数：
	作用：求小于x的整数中与x互质的数的个数
	求逆元:a^f(p)=1(mod p) 有 inv[a]=a^(f(p)-1) 
	f(x)=x*(1-1.0/p1)*(1-1.0/p2)*(1-1.0/p3)...*(1-1.0/pn)	pi为x所有的质因子
	性质：1.对于质数p,f(p)=p-1 	1到n-1的数都与n互质 
	  	  2.质数p,n=p^k时，f(x)=p^k-p^(k-1) 	n只有一个质因子p，f(n)=n*(1-1/p)=p^k*(1-1/p)
		  3.欧拉函数是积性函数，但不是完全积性函数。
		  		若m,n互质，则f(m*n)=f(m)*f(n)
		  		特殊的，当m=2，n为奇数时,f(2*n)=f(n)
		  4.当n>2时,f(n)是偶数。
 		  5.小于n的数中，与n互质的数的总和为f(n)*(n/2)  (n>1)	 
 		  		与n互质的数除了m还有n-m，故与n互质的数的平均数为n/2，一共有f(n)个 
		  6. n的因数（包括1和它自己）的欧拉函数之和等于n。
		  7. m和n互质，则m^f(n)=1(mod n)
		  8.对于质数p
		  		若n mod p==0    f(n*p)=f(n)*p		
				  n mod p!=0	f(n*p)=f(n)*f(p)=f(n)*(p-1) 
		  
求欧拉函数
void euler()	//这里用到了诶氏筛法，从小遍历，遇到质数就把含该质数的合数都运算一次 
{
	e[1]=0;
	for(int i=2;i<maxn;i++){
		if(!e[i])	//i为质数,第一次遍历时没赋过值的表示为质数 
			for(int j=i;j<maxn;j+=i){	//以i为倍数的合数，对要E[j]*(1-1/i)的操作  
				if(!e[j]) e[j]=j;	//合数要初始化  
				e[j]=e[j]/i*(i-1);	//套公式 	
			}
	}
}
求单个 
int euler(int x)
{
	if(x<1) return 0;
    int res=x;
    for(int i=2;i*i<=x;++i){//找x的质因子，故遍历因子i到sqrt(x)即可 
        if(x%i==0){	//这里的i一定为质因子
            res=res/i*(i-1);
            while(x%i==0) x/=i;	//把x中该i的质因子全消去 
        }
    }
    if(x>1) res=res/x*(x-1);	//x如果不等于1的话，表明x还有一个质因子
		//如果x单纯由一个质数组成，最后x=1,多个的时候，循环退出的时候x必定等于一个质数 
    return res;
}

int euler(int x)
{
	if(x<1) return 0;
	int ans=1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			x/=i;
			ans*=(i-1);
			while(x%i==0){
				ans*=i;
				x/=i;	
			}
		}
	}
	if(x>1) ans*=(x-1);
	return ans;	
}
/*
从1开始的原理：
	f(x)=x*(1-1.0/p1)*(1-1.0/p2)*(1-1.0/p3)...*(1-1.0/pn)
	=x * (p1-1)/p1 * (p2-1)/p2 * (p3-1)/p3 *...* (pn-1)/pn
	x完全就可以用p1、p2、...、pn这几个质因子组成，k1次方、k2次方、k3次方...
	=x*((p1-1)*p1^(k1-1))/(p1^k1)+...	用分母把x消去，得到的等式就是分子从1不断乘
	以(pi-1)*(pi^(ki-1)) ,因此对第二次多个pi因子时，第一个ans*(pi-1),还有的话就ans*pi 
*/
