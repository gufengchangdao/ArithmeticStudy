//��״���飺�����޸ģ������ѯ 
//Ҫ�ǹ������a[i]����С���㣬��a[i]ֵҪ�ı��ʱ�����ֻ�޸�c[i]��a[i]�����޸� 
//https://www.nitacm.com/problem_show.php?pid=1157
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[50005],c[50005],ans[40005],n;//a[i]Ϊԭ���飬c[i]Ϊ��״���飬ans[i]�����
//ע�⣺ԭ���������±�1��ʼ������ֵ 
void check()//�޸ĺ��������� 
{
	printf("\n");
	for(int i=1;i<=n;i++) printf(" %d",a[i]);
	printf("\n");
}
int lowbit(int x)//��ƽ������ 
{
	return x&(-x);	
}
int getsum(int i)//��a[i]��1~i�ĺ� 
{
	int ans=0;
	while(i>0){//a[i]�����Ǵ�1��ʼ����� 
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
void update(int i,int k)//a[i]+k,  ����a[i]������a[i]��c[j]��Ҫ�ı�  
{
	while(i<=n){
		c[i]=c[i]+k<0?0:c[i]+k;//����c[i]>=0 
		i+=lowbit(i);
	}
}
int main()
{
	int t,x,y;
	string s;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			update(i,a[i]);//����a[i]��ʱ�򣬶�Ӧ��c[j]ҲҪ�ı� 
		}
		int k=0;
		while(cin>>s&&s[0]!='E'){//�Ӷ�����ַ�������ĸ�жϲ���Ҫ�� 
			scanf("%d%d",&x,&y);
			switch(s[0]){
				case 'A':a[x]=a[x]+y;update(x,y);break;
				case 'S':a[x]=a[x]-y<0?0:a[x]-y;update(x,-y);break;
				default:ans[k++]=getsum(y)-getsum(x-1);break;
			}
		}
		printf("Case %d:\n",z);
		for(int i=0;i<k;i++) printf("%d\n",ans[i]);
	}
} 
