//������ȡģ 
ll PowerMod(ll a, ll b,ll mod)//����a��b�η���ȡcģ 
{
	if(b<0) return 0; 
    ll ans = 1;//��Ϊ�� 
    a=a%mod;//�ȼ���һ������ֹ������� 
    while(b){
        if(b&1) ans=(ans*a) % mod;//���ָ��b��������ʱ�򣬻�ż��b����1��ʱ���a��b�η�*ans���������������ans 
        b>>=1;//����ʱ�临�Ӷȣ�a��b�η�����a*a��b/2�η� 
        a=(a * a) % mod;
    }
    return ans;
}
ll inv(ll a)//��a����Ԫ 
{
	return PowerMod(a,mod-2);	
}
//���鴢����,�����ڵ���a���䣬ָ��b�ı�Ķ�μ��㣬�������¼������ 
ll mi[100];	//�±�d��������ָ��b���ϳ���2����1�����Ĵ�������2^x<b<2^(x+1) �±�d���Ϊx 
//	mi[1]=a^b%mod	mi[2]=a^(b/2)%mod	mi[3]=a^(b/4)%mod ...
ll powermod(ll a,ll b,ll mod,int d) //��a^b ����a,b������0 
{ 
    if(b==1) return a; 	//�ݹ�߽� 
    if(mi[d]!=0) return mi[d];		
	 
    ll s=(powermod(a,b/2,mod,d+1)*powermod(a,b/2,mod,d+1))%mod; 
    if(b&1) s=s*a%mod; //b��������ʱ��s���ٳ˸�a 
    return mi[d]=s; //·��ѹ�� 
}
powermod(a%mod,b,mod,d); 

//ȡ����㣺 
/*ab mod c=(a mod c)(b mod c)mod c  
(a + b) % p = (a % p + b % p) % p (1)
(a - b) % p = (a % p - b % p ) % p (2)   aС��bʱ (a - b) % p=(a%p-b%p)+p
(a * b) % p = (a % p * b % p) % p (3)
a ^ b % p = ((a % p)^b) % p (4)
�����:((a+b) % p + c) % p = (a + (b+c) % p) % p (5)
((a*b) % p * c)% p = (a * (b*c) % p) % p (6)

������:(a + b) % p = (b+a) % p (7)
(a * b) % p = (b * a) % p (8)

������:(a+b) % p = ( a % p + b % p ) % p (9)((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p (10)
