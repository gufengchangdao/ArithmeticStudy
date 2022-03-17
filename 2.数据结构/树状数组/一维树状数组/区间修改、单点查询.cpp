/*
�����޸ġ������ѯ
���ò������c[i]=a[i]-a[i-1],��֪a[n]=c[n]+c[n-1]+...+c[1]
������״���鵥���޸ĺ���ǰ׺�͵�����
�ɽ���ֵ�������Ϊ��״���飬�����޸�ʱ�޸Ĳ������Ķ˵㣬�����ѯ��ʱ�����ǰ׺��
�������ﲻ��Ҫ����ԭ���� 
*/
#include<stdio.h>
using namespace std;
const int maxn=500005;
int n,m,tree[maxn];
//�����޸� 
void add(int i,int k)
{
	while(i<=n){
		tree[i]+=k;
		i+=i&(-i);
	}	
}
//��ǰ׺�� 
int query(int i)
{
	int ans=0;
	while(i>0){
		ans+=tree[i];
		i-=i&(-i);
	}
	return ans;	
}

int main()
{
	int x=0,y,op,l,r,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&y);
		add(i,y-x);//�ؼ����ڣ����������ǰ��֮�� 
		x=y;
	}
	while(m--){
		scanf("%d",&op);
		if(op==1){//�����޸� 
			scanf("%d%d%d",&l,&r,&k);
			add(l,k);
			add(r+1,-k);
		}
		else{//��ѯ���� 
			scanf("%d",&k);
			printf("%d\n",query(k));
		}
	}	
} 
