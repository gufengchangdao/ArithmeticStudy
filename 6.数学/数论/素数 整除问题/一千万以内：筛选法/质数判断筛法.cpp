诶氏筛法
从2开始把质数的倍数筛去
缺点：同一个合数可能会多次重复筛去 
const int maxn=1e5;
int prime[maxn];
bool ispri[maxn];//给筛去的合数判否 
void sieve()
{
	int k=0;
	memset(ispri,-1,sizeof(ispri));//赋值，这里是把ispri初始化为true
	ispri[1]=false;
	for(int i=2;i<maxn;i++){
		if(ispri[i]){
			prime[k++]=i;//记录质数 
			for(int j=i*i;j<maxn;j+=i) ispri[j]=false;//把质数的倍数全部筛去
				//j从i*i开始,因为2*i、3*i、...(i-1)*i都在先前被筛去了，另外maxn太大的时候，i*i会爆掉，用ll 
		}
	}	
}

线性筛(欧拉筛)： 每个数都由他的最小质因数判掉，就不会判重了 
const int maxn=1e5;
int prime[maxn];
bool ispri[maxn];
void sieve()
{ 
	int k=0,temp;
	memset(ispri,-1,sizeof(ispri));
	ispri[1]=false;
	for(int i=2;i<maxn;i++){
		if(ispri[i]) prime[k++]=i;
		
		for(int j=0;j<k;j++){//j遍历已经存好的质数，因为只有k个，这里无论i是否为质数都要遍历 
			temp=i*prime[j];//prime里存的素数当作要消去的合数的最小质因子，可知i>=prime[j],prime[j]为temp的最小质因子 
			if(temp>=maxn) break;//判断数是否越界 
			ispri[temp]=false; 
			if(i%prime[j]==0) break;//去重的关键，表示i的因数中含有该质数，
										//不截止下一个temp就不会由最小质因数判去了 
		}
	}
}
/* 
已知任何数
i=p1^a1*p2^a2*p3^a3...*pi^ai;//pi为质数，且pi<p(i+1)
j由最小质数开始遍历，可知i%prime[j]==0时prime[j]==p1,即为i的最小质因子
当i%prime[j]==0不退出有i=k*prime[j],  temp=i*prime[j+1]=prime[j]*(k*prime[j+1]),
这时会把temp筛去，但当i=k*prime[j+1]时，会再次筛去 
*/ 
