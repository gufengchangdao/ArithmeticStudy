#include<bits/stdc++.h>
using namespace std;
struct stud_node{
	int num;
	char name[20];
	int score;
	struct stud_node*next;//赋予下一个结点的地址 
};
struct stud_node*InsertDoc(struct stud_node*head,struct stud_node*stud);//插入操作 
struct stud_node*Create_Stu_Doc();//新建链表 
struct stud_node*DeleteDoc(struct stud_node*head,int num);//删除操作 
void print_Stu_Doc(struct stud_node*head);//遍历操作 
int main()
{
	
}

struct stud_node*Create_Stu_Doc()
{
	struct stud_node*head,*p;//p存入要存储的数据 
	int num,score;
	char name[20];
	head=NULL; //定义以后是随机值，要手动赋值 
	scanf();//读入数据 
	while(num!=0){//输入所有学生数据 
		p=(struct stud_node*)malloc(sizeof(struct stud_node));//定义以后是没有内存的，要手动申请一个内存 
		p->num=num;
		strcpy(p->name,name);
		p->score=score;
		head=InsertDoc(head,p);//插入链组 
		scanf();
	}
	return head;//返回头指针 
}
//插入操作
struct stud_node*InsertDoc(struct stud_node*head,struct stud_node*stud) 
{
	ptr2=head;
	ptr=stud;//stud为要插入的结构指针 
	if(head==NULL){//头指针为空的时候 
		head=ptr;
		head->next=NULL;//链组不会自动添NULl，必须在尾节点手动设置NULL 
	}
	else{//头指针不为空的时候 
		while(ptr->num>ptr2->num&&ptr2->next!=NULL){//不断移动链组，直到找到对应位置 
			ptr1=ptr2;
			ptr2=ptr->next;
		}
		//要么在两节点中间，要么在尾部 
		if(ptr->num<=ptr2->num){//插入ptr并将他首尾相连 
			if(ptr2==head) head=ptr;
			else ptr1->next=ptr;
			ptr->next=ptr2; 
		}
		else{
			ptr2->next=ptr;
			ptr->next=NULL;
		}
	}
	return head;
}
struct stud_node*DeleteDoc(struct stud_node*head,int num)//删除操作 
{
	struct stud_node*ptr1,*ptr2;//ptr1为前，ptr2为后
	 //目标为头结点 
	if(num==head&&head!=NULL){
		ptr2=head;
		head=head->next;
		free(ptr2);//释放动态存储 
		return head;
	}
	if(head==NULL) return NULL;
	//目标不是头结点 
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=NULL){//循环出口 
		if(ptr2->num==num){
			ptr1->next=ptr2->xext;
			free(ptr2);
		}
		else{//不断移动 
			ptr1=ptr2;
			ptr2=ptr1->next;
		}
	}
	return head;
}

void print_Stu_Doc(struct stud_node*head)//遍历操作 
{
	struct stud_node*ptr;//作用类似于for循环的i 
	if(head==NULL){
		printf("kong");
		return;//强制结束 
	}
	for(ptr=head;ptr!=NULL;ptr=ptr->next)//要完成遍历，必须保证尾结点的指向的为NULL,这需要手动设置 
		printf("%d\t%s\t%d\n",ptr->num,ptr->name,ptr->score); 
 } 

