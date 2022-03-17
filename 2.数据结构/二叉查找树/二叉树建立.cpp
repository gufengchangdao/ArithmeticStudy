#include<bits/stdc++.h>
using namespace std; 
const int N=1010;
int pre[N],in [N],post[N];//先序、中序、后续
int k;//记录节点个数
struct node{
    int value;
    node *l,*r;//左节点、右节点
    node(int value=0,node *l=NULL,node *r=NULL)//给创建的结构体变量赋值，默认节点的值0,左子节点右子节点为空 
    :value(value),l(l),r(r){}//给结构体变量赋值 
};
//建树，t的值不断增加，先序一个一个看。
//在中序中，找到先序的值(当前根节点)，值左边的数在左子树，右边的数在右子树上，l,r不断在中序上保证边界 
void buildtree(int l,int r,int &t, node *&root) 
{
    int flag=-1;//标志位，寻找根节点 
    for(int i=l;i<=r;i++)//先序遍历的第一个数是根节点，在中序中从l找到r 
        if(in[i]==pre[t])//找到根节点在中序遍历对应的位置
        {
            flag=i;break;//如果找到了则记下中序遍历的根节点的序号
        }
    if(flag==-1) return;//结束 
    root=new node(in[flag]);//建立新节点
    t++;//找第二个节点开始的树，其实这里的第二个节点是指第二层的节点
    if(flag>l)buildtree(l,flag-1,t,root->l);//对于中序来说，根节点flag左边还有节点，建立左子树
    if(flag<r)buildtree(flag+1,r,t,root->r);//根节点flag右边还有节点，建立右子树
}
/* 
//可以通过先序遍历和中序遍历来检测树是否正确 
void preorder(node *root)//求先序序列 满足“根左右”的原则
{
    if(root!=NULL){
        post[k++]=root->value;//那么输出当前节点的值
        preorder(root->l);//接着是对左边的树进行遍历
        preorder(root->r);//接着是对右边的树进行遍历
    }
}
void inorder(node *root)//求中序序列 满足“左根右”的原则
{
    if(root!=NULL){//因为是左根右的原则，所以应一直向下探索直到没有左孩子为止
        inorder(root->l);
        post[k++]=root->value;//接着是根节点
        inorder(root->r);
    }
}
*/ 
void postorder(node *root)//求后序序列 满足“左右根”的原则
{
    if(root!=NULL){
        postorder(root->l);
        postorder(root->r);
        post[k++]=root->value;//先左后右再返回根 
    }
}
void remove_tree(node *root)//因为是用new的方式开辟内存所有要用delete删除树
{
    if(root==NULL)return ;//因为只能从上往下删除，采用左右根的方式删除节点 
    remove_tree(root->l);
    remove_tree(root->r);
    delete root;
}
int main()
{
    int n;
    while(~scanf("%d",&n)){//输入节点个数
        for(int i=1;i<=n;i++)scanf("%d",&pre[i]);//输入先序遍历的节点排序
        for(int i=1;i<=n;i++)scanf("%d",&in[i]);//输入中序遍历的节点排序
        node *root;//定义根节点
        int t=1;//一开始的节点层数是1
        buildtree(1,n,t,root);//从第1个节点开始建树
        k=1;//对节点数目重置 
        postorder(root);//对建好的树进行后序遍历
        for(int i=1;i<k;i++)
			printf("%d%c",post[i],i==k-1?'\n':' ');
        remove_tree(root);
    }
    return 0;
}

//数组存储二叉树 
void createtree(int *tree,int a[],int len)
{
	int flag=1; 
	tree[1]=a[1];//先建立根节点 
	for(int i=2;i<len;i++){ 
		flag=1;
		while(tree[flag]!=0){//先更换下标，这里需要所有数据不为0 
			if(data[i]<tree[flag]) flag=2*flag;
			else flag=2*flag+1;
			tree[flag]=a[i];
		}
	}
}

//先序遍历，自己写的待检测 
void preorder(int *tree,int t,int len)
{
	//for(int i=1;i<=len;i++) printf("%d ",tree[i]);
	if(tree[t]==0) return;//顺序存储就不用加，按二叉搜索树存储就要加，还得保证所有数据不为0 
	printf("%d ",tree[t]);
	if(t*2<=len) printree(tree,t*2,len);
	if(t*2+1<=len) printree(tree,t*2+1,len);
}




