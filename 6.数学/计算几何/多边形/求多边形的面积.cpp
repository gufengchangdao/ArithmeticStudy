//�����ε������
//˳ʱ���Ϊ��������ʱ���Ϊ�� 
//2*s==xi*y(i+1)-x(i+1)*yi    i��1��n��x[n+1]=x[1]   y[n+1]=y[1] 
//ע��s/2��s*0.5�ǲ�ͬ�ģ���sΪ����,ǰ��Ϊ���ͣ�����ΪС�� 
#include<stdio.h>
#include<math.h>
using namespace std;
long long x[1005],y[1005];
int main()
{
	int t,n;
	long long ans;
	scanf("%d",&t);
	while(t--){
		ans=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
		x[n+1]=x[1];y[n+1]=y[1]; 
		for(int i=1;i<=n;i++){
			ans=ans+x[i]*y[i+1]-x[i+1]*y[i];	
		}
		printf("%lld\n",abs(ans/2));
	}	
} 
