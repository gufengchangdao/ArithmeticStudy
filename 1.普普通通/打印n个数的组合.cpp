//打印组合 (不含空集)
#include<bits/stdc++.h>
using namespace std;
void subset(int n)
{
	for(int i=0;i<(1<<n);i++){//i:0-2^n,每个i对应一种组合 
		for(int j=0;j<n;j++)//j:0-n,j为每种组合中元素对应的下标 
			if(i&(1<<j)) printf("%d ",j);
		printf("\n");
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	subset(n);
 } 
/* 
对于n=3有：
有i等于 0		1		2		3		4		5		6		7 		i:0-2^n
二进制	000		001		010		011		100		101		110		111
有j等于	空集    0       1 		1.0 	2		2.0		2.1		2.1.0	j:0-n 
j对应的2^j 		1		2		2.1		4		4.1		4.2		4.2.1
二进制			001		010	  010 001  100	 100 001  100 010	100 010 001
子集的数量为2^n,二进制数的数量为2^n   即每个子集对应一个二进制数 
 */
