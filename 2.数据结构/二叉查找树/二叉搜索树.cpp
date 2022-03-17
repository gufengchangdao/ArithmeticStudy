#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
	int val;
	node *l,*r;
	node(int val,node *l=NULL,node *r=NULL)
	:val(val),l(l),r(r){}
};
void buildtree(node *&root,int num)//传入的是root的地址，故不需要返回根节点 
{
	if(root==NULL)
		root=new node(num);
	else{
		if(num>root->val) buildtree(root->r,num);
		else buildtree(root->l,num);
	}	
}
bool check(node *root,node *rom)//中序遍历比较是否一样 
{
	if(root!=NULL&&rom!=NULL){
		if(!check(root->l,rom->l)) return false;//因为最后一行是返回true，故只检测是否有不符合的 
//		else return false;
		if(root->val!=rom->val) return false;
		if(!check(root->r,rom->r)) return false;
	}
	else if(root!=NULL||rom!=NULL)
		return false;
	return true;
}
void deletetree(node *rom)
{
	if(rom==NULL) return;
	deletetree(rom->l);
	deletetree(rom->r);
	delete rom;
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n){
		char str[20];
		scanf("%s",str);
		int len=strlen(str);
		node *root=NULL;
		for(int i=0;i<len;i++)
			buildtree(root,str[i]-'0');
		for(int i=1;i<=n;i++){
			node *rom=NULL;
			scanf("%s",str);
			for(int i=0;i<len;i++)
				buildtree(rom,str[i]-'0');
			if(check(root,rom)) printf("YES\n");
			else printf("NO\n");
			deletetree(rom);		
		}
		 
	}
 } 
