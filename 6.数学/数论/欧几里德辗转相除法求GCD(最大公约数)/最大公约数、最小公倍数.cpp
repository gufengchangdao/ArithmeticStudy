//����
#include<algorithm>
a=_gcd(x,y);//�����Լ����x��y������Ӧ��һ�¡� 

int gcd(int m,int n)//mҪ���ڵ���n 
{
   return !n?m:gcd(n, m%n);
}

int gcd(int m,int n)
{
	if(m%n==0) return n;
	return gcd(n,m%n);
}

m*n==gcd(m,n)*lcm(m,n) 
��d=gcd(m,n),��m=s*x+t*y��s��tΪ�����Ҳ�����Ϊ������ʱmһ��Ϊd�ı���
gcd(x^a-1,x^b-1)=x^gcd(a,b)-1 
	����
		��T(t)=1+x+x^2+...+x^(t-1)
		x^a-1=(x-1)(1+x+x^2+...+x^(a-1))=(x-1)*T(a)
		gcd(x^a-1,x^b-1)=(x-1)*gcd(T(a),T(b))
			����Ϊ gcd(T(a),T(b))=T(gcd(a,b))
		gcd(x^a-1,x^b-1)=(x-1)*T(gcd(a,b))=x^gcd(a,b)-1
		
��c��a��b������һ����Ϊd�Ĺ�Լ���������d%c==0(��Ϊc|d)
gcd(m,n)==1����m��n����
���m��n��Ϊ��������m>n,��gcd(m,n)==gcd(m+n,n)==gcd(m-n,n)// ��� �Ӽ� С�� 
