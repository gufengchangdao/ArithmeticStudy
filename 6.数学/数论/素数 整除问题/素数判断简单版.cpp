bool isprime(int n)
{
	if(n<2) return false;
	if(n!=2&&n%2==0) return true;
	for(i=3;i*i<=n;i+=2) //n���С��9�ͻ�ֱ���˳�ѭ��Ĭ��Ϊ���� 
		if(n%i==0) return false;
	return true;
 }
 
