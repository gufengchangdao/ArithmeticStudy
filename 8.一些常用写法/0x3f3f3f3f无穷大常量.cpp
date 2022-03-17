#include<bits/stdc++.h>
#include<string>
 long long int a[10];
using namespace std;
int main()
{
	memset(a,0x3f,sizeof(a));
	printf("%lld",a[0]);
} 
/*
0x3f3f3f3f是一个很有用的数值，它是满足以下两个条件的最大整数。

1、整数的两倍不超过 0x7f7f7f7f，即int能表示的最大正整数。
2、整数的每8位（每个字节）都是相同的。
       我们在程序设计中经常需要使用 memset(a, val, sizeof a) 初始化一个数组a，该语句把数
值 val（0x00~0xFF）填充到数组a 的每个字节上，所以用memset只能赋值出“每8位都相同”的 int。
当需要把一个数组中的数值初始化成正无穷时，为了避免加法算术上溢出或者繁琐的判断，我们经常
用 memset(a, 0x3f, sizeof(a)) 给数组赋 0x3f3f3f3f的值来代替。 */ 
