//Heritage from father
/*
���⣺ ����1+3+6+10+15+...+n*(n+1)/2�����ÿ�ѧ��������ʾ��������λ��Ч���֣�0<n<2<<31 
 	n*(n+1)/2=n*n-(n*(n-1)/2)=n*n-(-n*(n+1)/2+n)
	2*n*(n+1)=n*(n+1)*(2*n+1)/6+n*(n+1)/2
	������λ��Ч���ֲ���n�ǳ��󣬿�����double,���Ա�ʾ17λ������ǰ��17λ 
		
*/
#include<stdio.h>
#include<math.h>
int main()
{
 	int m,i;
 	double n,sum;
 	while(scanf("%lf",&n)!=-1,n){
       	sum=(n*(n+1)*(2*n+1)/6+n*(n+1)/2)/2;
 	 	m=(int)log10(sum);//log����double��Ҫǿ������ת�� 
 	 	for(i=1;i<=m;i++) sum*=0.1;
 	 	printf("%.2fE%d\n",sum,m);
 	}	
 	return 0;
}
