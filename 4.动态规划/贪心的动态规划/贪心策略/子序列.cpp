//求最长上升子序列的长度的方案和方案数 
/*
法一：线性动态规划
F[i]  表示以 A[i] 为结尾的最长上身子序列的长度，因为F[i]就相当于前i个数组成的最长子序列的最优解，故F[i]<=F[i+1]
F[i]=F[i-1]，或者F[i]=F[i-1]+1
F[0]=0 ，而答案可以是任何阶段中只要长度最长的那一个，所以我们边转移边统计答案

缺点：对于每个a[i]都要在[1,i-1]遍历一遍，较小的长度每次都会遍历 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int//加快循环的读入 
const int maxn=1e5;
int a[maxn],f[maxn];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) scanf("%d",&a[i]);
	for(ri i=1;i<=n;i++){	//对每一个a[i]都把f[1~i-1]遍历一遍才得出 
		for(ri j=1;j<i;j++)
			if(a[j]<a[i]) f[i]=max(f[i],f[j]);
		f[i]++;//原来的序列加上a[i]，故长度加一 
		ans=max(ans,f[i]);//ans不能省，不能输出f[n]，不能保证一a[n]结尾的子序列最长 
	}
	printf("%d\n",ans); 
}

/*
法二：使用树状数组和动态规划 ，可以求方案和方案数 
最长上升子序列实质就是求最多有多少元素它们的下标和权值都单调递增
我们利用结构体将a数组的值和编号捆在一起，按值大小将数组排序，离散化处理 
再建立一个以编号为下标维护长度的最大值的树状数组即可，枚举a数组时按元素的序号
找到它之前序号比他小的长度最大的状态更新
然后将它也加入树状数组中。
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int//加快循环的读入 
const int maxn=1e5;
int f[maxn],n;//f为树状数组，下标i为原数组的编号，值为以i结尾的最长长度 
//构建结构体数组使其中每一个元素可以包含多个信息，这样在树状数组更新时可以做到顺便兼顾记录前驱，
//以及累计方案数（需要去重）
struct su{
	int v,id;
	//int ord;求方案时，记录作为序列的末尾元素时最长的长度fmax,要去重 
	inline bool operator <(const su b){//将值从大到小排序，用于遍历 
		if(v==b.v) return id>b.id;//按照序号从大到小可以保证所求为上升子序列
//假设两个相同的数分别为a[i],a[i+1]，如果先处理a[i],则a[i]求出后,a[i+1]=a[i]+1，与a[i]==a[i+1]矛盾
		return v<b.v;
	}
}a[maxn];
//更新树状数组、更新最值 ,将[i,n]的f同获得的最值比较并替换
inline void add(int i,int big){
	while(i<=n){
		f[i]=max(big,f[i]);
		i+=i&(-i);
	}
}
//求和变为求最值 ，寻找[1,i]中的当前最长，因为f[j]!=0的话说明在原数组中a[j]<a[i],并且下标j<i，一定满足条件 
inline int ask(int i)
{
	int ans=0;
	while(i>0){
		ans=max(ans,f[i]);
		i-=i&(-i);
	}
	return ans;	
}

int main()
{
	scanf("%d",&n);
	for(ri i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+n+1);//将a[i]按值大小排序 
	for(ri i=1;i<=n;i++)
		add(a[i].id,ask(a[i].id)+1);//先按原来编号i在f[1,i]中找到最长的一条，加一后赋值给f[i,n];
		//前面不离散的话，add中存入的id就得是a[i]的值了，计算量太大不好 
	printf("%d\n",ask(n));//查询一遍就知道答案了 
} 

//法三：贪心加二分查找
/*
设 F[i] 表示长度为 i 的最长上升子序列的末尾元素的最小值，我们发现这个数组的权值一定单调不降（仔
细想一想，这就是我们贪心的来由）。于是我们按顺序枚举数组 A ，
每一次对 F[] 数组二分查找，找到小于A[i]的最大的F[j] ,并用它将 F[j+1]更新。

*/ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int
const int maxn=1e5+5;
int a[maxn],f[maxn];

int main()
{
	int ans,n,l,r,mid;
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=1;f[1]=a[1];//目前最大序列长度为1，f[1]为a[1] 
	for(ri i=2;i<=n;i++){
		l=1;r=ans;//每次遍历r取ans,即为当前最大长度 
		//a[i]在f[l,r]的左边时，更新f[l]，在右边时，建立f[r+1]，在中间时找到比a[i]大的最小f[l]并更新f[l] 
		while(l<=r){//刚开始l==r，不能退出 
			mid=(l+r)>>1;//位运算快于乘积 
			if(a[i]<=f[mid]) r=mid-1;//要保证循环退出时l能取得满足a[i]<=f[l]的最大值 
		//	else if(a[i]==f[mid]) break;换成一般的二分也可以 
			else l=mid+1;
		}
		f[l]=a[i];
		if(l>ans) ans=l;
	}
	printf("%d\n",ans);
}

