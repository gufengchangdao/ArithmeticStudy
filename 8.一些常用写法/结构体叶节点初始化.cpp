//Ҷ�ڵ�Ľṹ���ʼ�����Լ�ʹ��new���ж�̬�ڴ����͸�ֵ 
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    //���帳ֵ���������岢��ֵ 
    TreeNode(int x)//����x 
	: val(x),left(NULL),right(NULL) {}//Ĭ�Ͻڵ��ֵx,���ӽڵ����ӽڵ�Ϊ��
//	TreeNode(int x,TreeNode *left=NULL,TreeNode *right=NULL)//�ȶ���ͳ�ʼ��һЩ����	
//	: val(x),left(left),right(right){}//�ٰ���Щ������ֵ���ṹ���еı��� 
};
int main(){
    TreeNode *p=new TreeNode(3);//����ṹ���͵Ŀռ䲢��x��ʼ��Ϊ3������ָ��ýṹ��ĵ�ַ 
    cout<<(p->val)<<endl;
    return 0;
}
