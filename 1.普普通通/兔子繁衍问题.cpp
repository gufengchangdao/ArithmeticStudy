#include<stdio.h>
int a[10000]={1,1};
int main()
{
	int i=1,sum=2,n;
	scanf("%d",&n);
	if(n==1||n==2)
		printf("1");
	else{
		while(a[i]<n){
			i++;
			a[i]=a[i-1]+a[i-2];
		}
		printf("%d",i+1);
	}
	return 0;
}
