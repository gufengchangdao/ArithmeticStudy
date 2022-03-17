#include<bits/stdc++.h>
using namespace std;
int die(int n,char a,char b,char c); 
int sum=0;
int main()
{
	int n;
	scanf("%d",&n);
	die(n,'a','b','c');
	printf("%d",sum);
	return 0;
}
int die(int n,char a,char b,char c)
{
	if(n==1){
	printf("%c>>%c\n",a,b,sum++);
	}
	else{
		die(n-1,a,c,b);
		printf("%c>>%c\n",a,b,sum++);
		die(n-1,c,b,a);
	}
 } 
