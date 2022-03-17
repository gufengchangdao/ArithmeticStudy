//叶节点的结构体初始化，以及使用new进行动态内存分配和赋值 
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    //定义赋值函数，定义并赋值 
    TreeNode(int x)//定义x 
	: val(x),left(NULL),right(NULL) {}//默认节点的值x,左子节点右子节点为空
//	TreeNode(int x,TreeNode *left=NULL,TreeNode *right=NULL)//先定义和初始化一些变量	
//	: val(x),left(left),right(right){}//再把这些变量赋值给结构体中的变量 
};
int main(){
    TreeNode *p=new TreeNode(3);//分配结构体型的空间并把x初始化为3，返回指向该结构体的地址 
    cout<<(p->val)<<endl;
    return 0;
}
