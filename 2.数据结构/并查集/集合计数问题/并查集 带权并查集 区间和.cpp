//How Many Answers Are Wrong
/*
���⣺1~n�����䣬m����֪����ͣ�������ǰ���������Ƴ�������Ϳ��ܺͺ�������ĸ�����ĺͲ�ͬ�����
	���������ж���
	��Ȩ���鼯:ÿ����㵽�������Ȩֵ���������������� 
	����ì�ܵ�ǰ�����ܹ����Ѹ�����������������������ڸ��������ì�ܣ�������n��Ϊ����㣬��ֻ
		Ҫl��r�ĸ��ڵ���ͬ����������
	ע�⣺���и�����[l,r]������������ͣ��Ǳ����䣬������l�͵�r���������ܻ�ͼ������ת��Ϊ(l-1,r] 
		sum[l-1]����[l,r]������ͣ�l-1��r�����ߵı�Ȩֵ 
		  sum[x] 				sum[xx]=-sum[x]+cal+sum[y]
		x----->xx
	val	| 	   |  sum[xx]
		y----->yy
		 sum[y]
*/
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=200005;
int s[maxn],sum[maxn];//sum[i]�Ǵ�i�����������������бߵı�Ȩֵ֮�ͣ�����ǰ׺�� 
int ans;

int findset(int x)
{
	if(x!=s[x]){
		int tem=s[x];
		s[x]=findset(s[x]);
		sum[x]+=sum[tem];//�ݹ����ɸ���㿪ʼ��ǰ׺�ͣ�tem����x�ĸ��ڵ� 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy)//�����ĸ������ͬ�������Ƴ�(x,y]��������� 
		if((sum[x]-sum[y])!=val) ans++;
	else{	//����㲻ͬ�������Ƴ������ܸ�������� 
		s[xx]=yy;
		sum[xx]=-sum[x]+val+sum[y];//���xx��yy�ı�Ȩֵ
	}//���ǹ涨ֻҪs[i]���ӵ�����㣬��Ҫ����sum[i],��Ϊ������findset��������x==s[x]���������sum 
}

int main()
{
	int m,n,l,r,val;
	while(~scanf("%d%d",&n,&m)){
		ans=0;
		memset(sum,0,sizeof(sum));
		for(int i=0;i<=n;i++) s[i]=i;//���0��ʼ 
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&l,&r,&val);//��Ŀ�и���l���ϸ�С�ڵ���r 
			unionset(l-1,r,val);//ע����l-1	
		}
		printf("%d\n",ans);
		
	}
	
}
 
