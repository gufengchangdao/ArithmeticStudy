#include<bits/stdc++.h>
using namespace std;
double c(int a,int b);
int main()
{
	int t,n,m,x,remain;
	double result;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&x);
		remain=n-x*m;
		result=c(m-1,remain+m-1);
		printf("%.0lf\n",result);
	}
}
double c(int a,int b)
{	double sum=1;
	for(double i=1;i<=a;i++)
	 sum*=((double)b-(double)a+i)/i;
	return sum;
}
