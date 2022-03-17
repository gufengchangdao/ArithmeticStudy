//Inversion
/* 
题意：有n个数，最多k次操作，每次操作可交换相邻两个数，问最后逆序数最少为多少个？ 
归并排序（树状数组、线段树）：求数列的逆序数个数 
	交换相邻两个，逆序数改变量只有0和-1两种，因此逆序数个数ans<=k时可以完成，否则不能
	求逆序数个数即可 
*/
#include <cstdio>
using namespace std;
#define int long long
const int maxn=100005;
int n, a[maxn], temp[maxn],ans;
//归并排序 
void mergesort(int l, int r, int *A){
	if (l >= r) return ;
	int mid = (l + r) >> 1;
	mergesort(l, mid, A); 
	mergesort(mid + 1, r, A);
	int i = l, j = mid + 1, cnt= 0;
	while(i<=mid&&j<= r){
		if (A[i] <= A[j]) temp[cnt++] = A[i++];
		else{
			temp[cnt++] = A[j++];
			ans+=mid-i+1;
		}
	}
	while(i <= mid) temp[cnt++] = A[i++];
	while(j<= r) temp[cnt++] = A[j++];
	for (i=0;i<cnt;i++) A[i+l] = temp[i];
} 
 
signed main() 
{
	int n,k;
	while(~scanf("%lld%lld",&n,&k)){
		ans=0;	
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

		mergesort(1, n, a);
//	for(int i=1;i<=10;i++) printf("%lld ",a[i]);
//	printf("\n");
		if(ans<=k) printf("0\n");
		else printf("%lld\n",ans-k);
	}
}
