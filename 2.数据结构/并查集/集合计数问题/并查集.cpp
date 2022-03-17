//���鼯����һЩ��N��Ԫ�صļ���Ӧ�������У�����ͨ�����ڿ�ʼʱ��ÿ��Ԫ�ع���һ����Ԫ�صļ��ϣ�
//Ȼ��һ��˳������ͬһ���Ԫ�����ڵļ��Ϻϲ������Ҫ��������һ��Ԫ�����ĸ������С�
//���鼯��һ�����͵����ݽṹ�����ڴ���һЩ���ཻ���ϣ�disjoint sets���ĺϲ�����ѯ���⡣ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1050;
int s[maxn+1];//s[i]���ڵ�i���˴��ڵ�s[i]��������
int height[maxn];//����ÿ���������ĸ߶ȣ��������к��������ĸ�������ʼ������ 
//��ʼ�� 
void initset(int num)//��ʼÿ���˶�Ӧһ������
{
	for(int i=1;i<=num;i++){
		s[i]=i;
		height[i]=0;//����Ϊ0 
	}
}
 
//����
/* 
int findset(int x)//����x���ļ���,������x�ĸ��ڵ�
{
	return x==s[x]?x:findset(s[x]);
}

int findset(int x)//�Ż�������һ�ξ��޸����нڵ㡣·��ѹ���ݹ�棬���ǵݹ���ù���ᱬջ 
{
	if(x!=s[x]) s[x]=findset(s[x]);//�õݹ飬����һ��ֱ�ӰѼ����ڵ����н��ȫ��ָ����ڵ� 
	return s[x];
}
*/
int findset(int x)//�Ż���·��ѹ�� 
{
	int r=x;
	while(s[r]!=r) r=s[r];//�ҵ������ 
	int i=x,temp;	//�Ѽ����ڵ����н��ȫ��ָ����ڵ� 
	while(i!=r){	//ѭ������Ϊ��x�ڵ㵽���ڵ� 
		temp=s[i];	//����ڵ�Ԫ����Ϊs[i]����һ���ڵ�Ԫ�� 
		s[i]=r;
		i=temp;
	}
	return r; 
} 
//�ϲ� 
void unionset(int x,int y)//��x����y���ڵļ���s[y]����ʱx������s[x],��x���ڵ�s[x]���������� 
{
	x=findset(x);//���ҵ�x���ڵĴ󼯺� 
	y=findset(y);//��y
	if(height[x]==height[y]){//������һ���ߣ�y������x���ϣ�x���߶ȼ�һ 
		height[x]+=1;	
		s[y]=x;//����x==s[x],y==s[y],����������ͳһ����������ļ����ڡ�
	} 
	else{//�ѵ������������ϣ��������ĸ߶����ӣ���ʱ���ĸ߶Ȳ���� 
		if(height[x]<height[y]) s[x]=y;//x���� 
		else s[y]=x;//y���� 
	}	
}

int main()
{
	int t,x,y,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		initset(n);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			unionset(x,y);
		} 
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]==i) ans++;//ͳ�����ĸ��� 
		printf("%d\n",ans);
	}
} 
