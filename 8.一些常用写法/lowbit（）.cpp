//lowbit(x)��x�Ķ����Ʊ��ʽ�����λ��1����Ӧ��ֵ

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
