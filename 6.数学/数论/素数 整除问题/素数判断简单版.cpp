bool isprime(int n)
{
	if(n<2) return false;
	if(n!=2&&n%2==0) return true;
	for(i=3;i*i<=n;i+=2) //n如果小于9就会直接退出循环默认为素数 
		if(n%i==0) return false;
	return true;
 }
 
