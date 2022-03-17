//Heritage from father
/*
题意： 计算1+3+6+10+15+...+n*(n+1)/2，并用科学计数法表示，保留三位有效数字，0<n<2<<31 
 	n*(n+1)/2=n*n-(n*(n-1)/2)=n*n-(-n*(n+1)/2+n)
	2*n*(n+1)=n*(n+1)*(2*n+1)/6+n*(n+1)/2
	保留三位有效数字并且n非常大，可以用double,可以表示17位，还是前面17位 
		
*/
#include<stdio.h>
#include<math.h>
int main()
{
 	int m,i;
 	double n,sum;
 	while(scanf("%lf",&n)!=-1,n){
       	sum=(n*(n+1)*(2*n+1)/6+n*(n+1)/2)/2;
 	 	m=(int)log10(sum);//log返回double，要强制类型转换 
 	 	for(i=1;i<=m;i++) sum*=0.1;
 	 	printf("%.2fE%d\n",sum,m);
 	}	
 	return 0;
}
