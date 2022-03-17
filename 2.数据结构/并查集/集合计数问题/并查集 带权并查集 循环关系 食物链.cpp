//ʳ���� 
/*
���⣺n�ֶ�����ж��ﶼ����a->b->c->a����������ѭ����1 x yΪx��y��ͬ�ࣻ2 x yΪx��y 
	����k��˵�����������˵��ì�ܣ�ì��������x��y���磻�Լ����Լ�����ǰ��Ļ�ì�� 
	Ȩֵ���鼯�������Ǽ򵥵���ͻ�����Ȩֵ��¼ʳ��������Թ�ϵ 
	��a->b��sum[a]=1	b->a��sum[a]=2�����Ծ���(-1+3)%3=2 a��bͬ�ࣺsum[a]=0 
	d-1->b b-1->c b-1->a ===�Ƴ�===>>>  d-0->a b-2->a c-1->a
	��֪��sum[b]=1%3=1	sum[c]=(sum[b]+1)%3=2  sum[d]=(sum[c]+1)%3=0,��֪d��a��ͬ�� 
	���ϣ�������ԭ������ȡģ3 
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
		sum[x]=(sum[x]+sum[tem])%3;//ע�� 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy){//ע�⣺������ű���Ҫ�ӣ����������else�ᱻ��Ϊ�ǰ�����if���� 
		if((sum[x]-sum[y]+3)%3!=val) ans++;//-sum[y]=-1,���Ǽ���3������2 
	}
	else{	//�����жϣ���� 
		s[xx]=yy;
		sum[xx]=(-sum[x]+val+sum[y])%3;//ע�� 
	}
}

int main()
{
	int op,a,b;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) s[i]=i;
	while(k--){
		scanf("%d%d%d",&op,&a,&b);
		if(a>n||b>n||(a==b&&op==2)) ans++;//ì�� 
		else unionset(a,b,op-1);//ע�⣺�����opҪ��1�����ú͹涨��һ�� 
	} 
	printf("%d\n",ans);
}
