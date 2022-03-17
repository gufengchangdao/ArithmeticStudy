/*
https://www.nitacm.com/problem_show.php?pid=7541
���������������һ��ǰn������Ϊ1�����������Ƹ���㶼Ϊ���ӽ��֮�ͣ���ʾ���� 
����ans[i]Ϊ��ǰ�����������num��Ԫ�أ���������䳤��>num����ʾ������ߣ��������ұ� 
*/
#include<stdio.h>
#include<cmath> 
using namespace std;
const int maxn=10000;
int pre[maxn],ans[maxn],tree[4*maxn];
//tree��������ʵ�ֵ�������������Ҫ4����Ŀռ� 

void buildtree(int n,int last_left)
{
	int i;
	for(i=last_left;i<last_left+n;i++) 
		tree[i]=1;	//�ȸ������������һ�и�1�����n��������n��ţ 
	while(last_left!=1){
		for(int i=last_left/2;i<last_left;i++)
			tree[i]=tree[i*2]+tree[i*2+1];
		last_left=last_left/2;
	}
}
//��ѯ+ά��������ֵΪ��ǰ�����������num��Ԫ�� 
int query(int u,int num,int last_left)
{
	tree[u]--;//�Է��ʵ�������ά��ʣ�µ�ţ������ 
	if(tree[u]==0&&u>=last_left) return u;
	//�����������ָ������� 
	if(tree[u<<1]<num)
		return query((u<<1)+1,num-tree[u<<1],last_left);
	//�����������ָ����� 
	else
		return query(u<<1,num,last_left);
}
int main()
{
	int n,last_left;
	scanf("%d",&n);
	last_left=1<<(int(log(n)/log(2))+1);//��1����Ϊ11<<(int(log(n)/log(2)))��һ��װ���� 
	//���������һ�е������һ�������㷽��������n�����2��ָ�� 
	buildtree(n,last_left);
	for(int i=2;i<=n;i++) scanf("%d",&pre[i]);
	for(int i=n;i>=1;i--)//�Ӻ���ǰ�ƶ�ÿһ���� 
		ans[i]=query(1,pre[i]+1,last_left)-last_left+1;//���ﲻҪ���˼� 
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
