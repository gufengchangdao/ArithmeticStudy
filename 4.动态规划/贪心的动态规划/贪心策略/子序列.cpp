//������������еĳ��ȵķ����ͷ����� 
/*
��һ�����Զ�̬�滮
F[i]  ��ʾ�� A[i] Ϊ��β������������еĳ��ȣ���ΪF[i]���൱��ǰi������ɵ�������е����Ž⣬��F[i]<=F[i+1]
F[i]=F[i-1]������F[i]=F[i-1]+1
F[0]=0 �����𰸿������κν׶���ֻҪ���������һ�����������Ǳ�ת�Ʊ�ͳ�ƴ�

ȱ�㣺����ÿ��a[i]��Ҫ��[1,i-1]����һ�飬��С�ĳ���ÿ�ζ������ 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int//�ӿ�ѭ���Ķ��� 
const int maxn=1e5;
int a[maxn],f[maxn];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) scanf("%d",&a[i]);
	for(ri i=1;i<=n;i++){	//��ÿһ��a[i]����f[1~i-1]����һ��ŵó� 
		for(ri j=1;j<i;j++)
			if(a[j]<a[i]) f[i]=max(f[i],f[j]);
		f[i]++;//ԭ�������м���a[i]���ʳ��ȼ�һ 
		ans=max(ans,f[i]);//ans����ʡ���������f[n]�����ܱ�֤һa[n]��β��������� 
	}
	printf("%d\n",ans); 
}

/*
������ʹ����״����Ͷ�̬�滮 �������󷽰��ͷ����� 
�����������ʵ�ʾ���������ж���Ԫ�����ǵ��±��Ȩֵ����������
�������ýṹ�彫a�����ֵ�ͱ������һ�𣬰�ֵ��С������������ɢ������ 
�ٽ���һ���Ա��Ϊ�±�ά�����ȵ����ֵ����״���鼴�ɣ�ö��a����ʱ��Ԫ�ص����
�ҵ���֮ǰ��ű���С�ĳ�������״̬����
Ȼ����Ҳ������״�����С�
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ri register int//�ӿ�ѭ���Ķ��� 
const int maxn=1e5;
int f[maxn],n;//fΪ��״���飬�±�iΪԭ����ı�ţ�ֵΪ��i��β������� 
//�����ṹ������ʹ����ÿһ��Ԫ�ؿ��԰��������Ϣ����������״�������ʱ��������˳���˼�¼ǰ����
//�Լ��ۼƷ���������Ҫȥ�أ�
struct su{
	int v,id;
	//int ord;�󷽰�ʱ����¼��Ϊ���е�ĩβԪ��ʱ��ĳ���fmax,Ҫȥ�� 
	inline bool operator <(const su b){//��ֵ�Ӵ�С�������ڱ��� 
		if(v==b.v) return id>b.id;//������ŴӴ�С���Ա�֤����Ϊ����������
//����������ͬ�����ֱ�Ϊa[i],a[i+1]������ȴ���a[i],��a[i]�����,a[i+1]=a[i]+1����a[i]==a[i+1]ì��
		return v<b.v;
	}
}a[maxn];
//������״���顢������ֵ ,��[i,n]��fͬ��õ���ֵ�Ƚϲ��滻
inline void add(int i,int big){
	while(i<=n){
		f[i]=max(big,f[i]);
		i+=i&(-i);
	}
}
//��ͱ�Ϊ����ֵ ��Ѱ��[1,i]�еĵ�ǰ�����Ϊf[j]!=0�Ļ�˵����ԭ������a[j]<a[i],�����±�j<i��һ���������� 
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
	sort(a+1,a+n+1);//��a[i]��ֵ��С���� 
	for(ri i=1;i<=n;i++)
		add(a[i].id,ask(a[i].id)+1);//�Ȱ�ԭ�����i��f[1,i]���ҵ����һ������һ��ֵ��f[i,n];
		//ǰ�治��ɢ�Ļ���add�д����id�͵���a[i]��ֵ�ˣ�������̫�󲻺� 
	printf("%d\n",ask(n));//��ѯһ���֪������ 
} 

//������̰�ļӶ��ֲ���
/*
�� F[i] ��ʾ����Ϊ i ������������е�ĩβԪ�ص���Сֵ�����Ƿ�����������Ȩֵһ��������������
ϸ��һ�룬���������̰�ĵ����ɣ����������ǰ�˳��ö������ A ��
ÿһ�ζ� F[] ������ֲ��ң��ҵ�С��A[i]������F[j] ,�������� F[j+1]���¡�

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
	ans=1;f[1]=a[1];//Ŀǰ������г���Ϊ1��f[1]Ϊa[1] 
	for(ri i=2;i<=n;i++){
		l=1;r=ans;//ÿ�α���rȡans,��Ϊ��ǰ��󳤶� 
		//a[i]��f[l,r]�����ʱ������f[l]�����ұ�ʱ������f[r+1]�����м�ʱ�ҵ���a[i]�����Сf[l]������f[l] 
		while(l<=r){//�տ�ʼl==r�������˳� 
			mid=(l+r)>>1;//λ������ڳ˻� 
			if(a[i]<=f[mid]) r=mid-1;//Ҫ��֤ѭ���˳�ʱl��ȡ������a[i]<=f[l]�����ֵ 
		//	else if(a[i]==f[mid]) break;����һ��Ķ���Ҳ���� 
			else l=mid+1;
		}
		f[l]=a[i];
		if(l>ans) ans=l;
	}
	printf("%d\n",ans);
}

