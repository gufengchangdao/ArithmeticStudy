��Ԫ 
	��� a*x=1(mod p) ��������ô x �� a �� mod m �������µ���Ԫ
	��;����a/b(mod p)��b̫���˻ᱬ��double�ľ��� 
	a/b(mod p)=a*inv[b](mod p)	inv[b]Ϊb��mod p�µ���Ԫ

����������Ԫ
	����С����
	a^(p-1)=1(mod p) pΪ��������a%p!=0
	inv[a]=a^(p-2)(mod p) ,�ÿ������� 
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

��չŷ�Ｘ��
	���ã����a*x+b*y=m(mod p)�н⣬��ômһ��Ϊgcd(a,b)�ı�����
	��a����Ԫ����b=p,��a*x+p*y=1(mod p) ǰ��Ϊgcd(a,p)=1 
	��֪gcd(a,b)=gcd(b,a%b);
	// ��x, y��ʹ��ax + by = gcd(a, b)
	��gcd(a,b)=d,��ax+by=d�����ϵݹ�õ�d����ʱa=d,b=0,�н�a*1+b*0=d
	������һ����b*x1+a%b*y1=d
				b*x1+(a-a/b*b)*y1=d
	 			a*y1+b*(x1-(a/b)*y1)=d
	 	����x=y1  y=x1-(a/b)*y1��������һ�㷵�أ��õ�ÿһ��Ľ� 
	 
int exgcd(int a, int b, int &x, int &y)
{
    if (!b){
        x = 1; y = 0;
        return a;   //����ݹ�߽磬a�������Լ�� 
    }
    int d = exgcd(b, a % b, x, y);�Ȳ��ϵݹ�õ����Լ��d����������һ�㷵�� 
    int temp=y;    //�Ƴ���һ���x��y
    y=x-(a/b)*y;
    x=temp;
    return d;
}
	 
ŷ��������
	���ã���С��x����������x���ʵ����ĸ���
	����Ԫ:a^f(p)=1(mod p) �� inv[a]=a^(f(p)-1) 
	f(x)=x*(1-1.0/p1)*(1-1.0/p2)*(1-1.0/p3)...*(1-1.0/pn)	piΪx���е�������
	���ʣ���������p,f(p)=p-1 	1��n-1��������n���� 
	  	  ����p,n=p^kʱ��f(x)=p^k-p^(k-1) 	nֻ��һ��������p��f(n)=n*(1-1/p)=p^k*(1-1/p)
		  ŷ�������ǻ��Ժ�������������ȫ���Ժ�������m,n���ʣ���f(m*n)=f(m)*f(n)
		  	����ģ���m=2��nΪ����ʱ,f(2*n)=f(n)
		  ��n>2ʱ,f(n)��ż����
 		  С��n�����У���n���ʵ������ܺ�Ϊf(n)*(n/2)  (n>1)	 
 		  		��n���ʵ�������m����n-m������n���ʵ�����ƽ����Ϊn/2��һ����f(n)�� 
		  n������������1�����Լ�����ŷ������֮�͵���n��

���ƹ�ʽ����Ԫ��
	inv[1]=1;	����������������Ԫ 
	inv[i]=(p-p/i)*inv[p%i]%p	 
	
	������t=p/i	k=p%i 
		t*i+k=0(mod p)
		-t*i=k;����ͬʱ����k*i
		-p/i*inv[p%i]=inv[i](mod p)
		(p-p/i)*inv[p%i]%p=inv[i]   
