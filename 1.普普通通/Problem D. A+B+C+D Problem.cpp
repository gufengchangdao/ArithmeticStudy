#include<bits/stdc++.h>
using namespace std;
long long A,B,C,D,x,y,z,i,j,l,k,sum;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&x,&y,&z);
		x=x*x*x%1000000007;y=y*y%1000000007;
			for(j=1;j<=B;j++)
				for(k=1;k<=C;k++)
					for(l=1;l<=D;l++)
						sum=(sum+x+j*y+k*z+l)%1000000007;
		sum=sum*(A+1)*A/2%1000000007;
		printf("%lld\n",sum);	
	}
	return 0;
}
