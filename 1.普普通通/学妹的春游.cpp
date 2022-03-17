#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum,i,j,n;
	char a[1000000];
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		gets(a);
		sum=strlen(a);
		int k=0;
		for(j=0;j<sum;j++){
			if(a[j]=='(')
				k++;
			if(a[j]==')')
				k--;
			if(k<0)
				break;
		}
		if(k==0&&j==sum)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
