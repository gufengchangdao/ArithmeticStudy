//用康托展开 判重 ，3方格有9的阶乘大小的状态 
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//0-n的阶乘 
bool cantor(int str[],int n)//状态、元素个数 
{
	long result=0;//result记录时第多少种状态 
	for(int i=0;i<n;i++){	//判断比str[]小的排列的个数来判断排名 
		int sum=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j]) sum++;
		result+=sum*factory[n-i-1];//排名=比当前位小的数的个数*未固定的数的阶乘 
	}
	//判断该状态是否被标记过 
	if(visted[result]) return 0;
	visted[result]=1;//标记并返回true 
	return 1;
}
/*
对于每一个排列str[]
对于第一个数在str[1~n)比str[0]小的有sum[0]个	则第一个数小于str[0]的排列的个数为sum[0]*(n-1)!
固定str[0]，第二个数在str[2~n)比str[1]小的有sum[1]个，则第二个数小于str[1]的排列个数为sum[1]*(n-2)!
...
当前排列的字典序排名为sum[0]*(n-1)!+sum[1]*(n-2)!+...sum[k]*(n-1-k)!...+sum[n-1]*(0)! 
*/
