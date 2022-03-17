//食物链 
/*
题意：n种动物，所有动物都满足a->b->c->a这样的三角循环，1 x y为x和y是同类；2 x y为x吃y 
	给出k个说法，求多少种说法矛盾，矛盾条件：x、y出界；自己吃自己；与前面的话矛盾 
	权值并查集，但不是简单的求和或者求差，权值记录食物链的相对关系 
	设a->b；sum[a]=1	b->a；sum[a]=2，被吃就是(-1+3)%3=2 a与b同类：sum[a]=0 
	d-1->b b-1->c b-1->a ===推出===>>>  d-0->a b-2->a c-1->a
	可知：sum[b]=1%3=1	sum[c]=(sum[b]+1)%3=2  sum[d]=(sum[c]+1)%3=0,可知d和a是同类 
	综上：就是在原操作上取模3 
*/
#include<stdio.h>
using namespace std;
const int maxn= 50005;
int s[maxn],sum[maxn];
int ans=0,n,k;

int findset(int x)
{
	if(x!=s[x]){
		int tem=s[x];
		s[x]=findset(s[x]);
		sum[x]=(sum[x]+sum[tem])%3;//注意 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy){//注意：这个括号必须要加，否则下面的else会被认为是包含在if里面 
		if((sum[x]-sum[y]+3)%3!=val) ans++;//-sum[y]=-1,但是加上3后变成了2 
	}
	else{	//不能判断，添加 
		s[xx]=yy;
		sum[xx]=(-sum[x]+val+sum[y])%3;//注意 
	}
}

int main()
{
	int op,a,b;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) s[i]=i;
	while(k--){
		scanf("%d%d%d",&op,&a,&b);
		if(a>n||b>n||(a==b&&op==2)) ans++;//矛盾 
		else unionset(a,b,op-1);//注意：这里的op要减1后正好和规定的一样 
	} 
	printf("%d\n",ans);
}
