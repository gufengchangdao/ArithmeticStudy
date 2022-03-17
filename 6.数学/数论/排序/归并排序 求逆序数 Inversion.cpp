//Inversion
/* 
���⣺��n���������k�β�����ÿ�β����ɽ������������������������������Ϊ���ٸ��� 
�鲢������״���顢�߶������������е����������� 
	���������������������ı���ֻ��0��-1���֣��������������ans<=kʱ������ɣ�������
	���������������� 
*/
#include <cstdio>
using namespace std;
#define int long long
const int maxn=100005;
int n, a[maxn], temp[maxn],ans;
//�鲢���� 
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
