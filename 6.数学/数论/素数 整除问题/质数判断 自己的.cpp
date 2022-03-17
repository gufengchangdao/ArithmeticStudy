#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if(n<4) return n>1;
	if(n%6!=1&&n%6!=5) return false;
	int temp=sqrt(n);
	for(int i=5;i<=temp;i+=6)
		if(n%i==0||n%(i+2)==0) return false;
	return true;	
}
int main()
{
	int n;
	while(scanf("%d",&n)){
		int good=isprime(n);
		printf("%d\n",good);
	}
 } 
