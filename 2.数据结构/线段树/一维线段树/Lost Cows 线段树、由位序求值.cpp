/*
https://www.nitacm.com/problem_show.php?pid=7541
Ѱ��ansҪ��n��ʼ����Ѱ�ң�pre[i]+1����ans[i]�� ��С���������е�λ�� 
�Ӹ���㿪ʼ����Ҫ������λ�������������������ĳ��ȱȽϣ�С�������������������ϣ�
�������������ϣ���������ʱ��Ҫ��λ���ȥ�������ĳ��� 
ÿ��һ����㣬�������ĳ��ȼ�һ���൱��ans[i]ȡ������ans[i]��ص�tree[i]���ȶ�Ҫ��1
�ص㣺����ֵΪ��ǰ�����������num��Ԫ��  
*/
#include<stdio.h>
using namespace std;
const int maxn=10000;
struct node{
	int l,r,len;//��len������������ָ��� 
}tree[4*maxn];//������4��������Ϊ�߶����Ŀռ���Ҫ 
int pre[maxn],ans[maxn];
//���� 
void buildtree(int left,int right,int u)
{
	tree[u].l=left;
	tree[u].r=right;
	tree[u].len=right-left+1;//���½��u��ֵ 
	if(left==right) return;//�ݹ鵽Ҷ������ 
	buildtree(left,(left+right)>>1,u<<1);//�ݹ������� 
	buildtree(((left+right)>>1)+1,right,(u<<1)+1);//�ݹ���������	
}//ע��+�����ȼ��������ơ����ƣ����Ų���ʡ
//��ѯ+ά�����Է��ʵ�������ά��len,�����������len��1 
int query(int u,int num)
{
	tree[u].len--;
	if(tree[u].l==tree[u].r) return tree[u].l;
	//���1�����������ڵ�ţ���������������������ѯ�����Ĳ��� 
	if(tree[u<<1].len<num) 
		return query((u<<1)+1,num-tree[u<<1].len);
	//���2�����������ڵ�ţ����������������ѯ�������� 
	if(tree[u<<1].len>=num)
		return query(u<<1,num);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	pre[1]=0;
	for(int i=2;i<=n;i++) scanf("%d",&pre[i]);
	buildtree(1,n,1);
	for(int i=n;i>=1;i--)//�Ӻ���ǰ�ƶϳ�ÿ�����һ������ 
		ans[i]=query(1,pre[i]+1);//��ans[i]С������pre[i]��,��ans[i]�ǵ�pre[i]+1С������Ѱ�ҵ�kСֵ 
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;	
} 
