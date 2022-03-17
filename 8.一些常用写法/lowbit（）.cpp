//lowbit(x)是x的二进制表达式中最低位的1所对应的值

#include <bits/stdc++.h>
using namespace std;
 
int lowbit(int i)
{
    return i&(-i);
}

int main()
{
	for(int i=0;i<=15;i++)
		printf("%d : %d\n",i,lowbit(i));
}
