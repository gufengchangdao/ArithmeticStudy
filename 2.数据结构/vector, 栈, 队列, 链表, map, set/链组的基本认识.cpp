#include<bits/stdc++.h>
using namespace std;
struct stud_node{
	int num;
	char name[20];
	int score;
	struct stud_node*next;//������һ�����ĵ�ַ 
};
struct stud_node*InsertDoc(struct stud_node*head,struct stud_node*stud);//������� 
struct stud_node*Create_Stu_Doc();//�½����� 
struct stud_node*DeleteDoc(struct stud_node*head,int num);//ɾ������ 
void print_Stu_Doc(struct stud_node*head);//�������� 
int main()
{
	
}

struct stud_node*Create_Stu_Doc()
{
	struct stud_node*head,*p;//p����Ҫ�洢������ 
	int num,score;
	char name[20];
	head=NULL; //�����Ժ������ֵ��Ҫ�ֶ���ֵ 
	scanf();//�������� 
	while(num!=0){//��������ѧ������ 
		p=(struct stud_node*)malloc(sizeof(struct stud_node));//�����Ժ���û���ڴ�ģ�Ҫ�ֶ�����һ���ڴ� 
		p->num=num;
		strcpy(p->name,name);
		p->score=score;
		head=InsertDoc(head,p);//�������� 
		scanf();
	}
	return head;//����ͷָ�� 
}
//�������
struct stud_node*InsertDoc(struct stud_node*head,struct stud_node*stud) 
{
	ptr2=head;
	ptr=stud;//studΪҪ����Ľṹָ�� 
	if(head==NULL){//ͷָ��Ϊ�յ�ʱ�� 
		head=ptr;
		head->next=NULL;//���鲻���Զ���NULl��������β�ڵ��ֶ�����NULL 
	}
	else{//ͷָ�벻Ϊ�յ�ʱ�� 
		while(ptr->num>ptr2->num&&ptr2->next!=NULL){//�����ƶ����飬ֱ���ҵ���Ӧλ�� 
			ptr1=ptr2;
			ptr2=ptr->next;
		}
		//Ҫô�����ڵ��м䣬Ҫô��β�� 
		if(ptr->num<=ptr2->num){//����ptr��������β���� 
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
struct stud_node*DeleteDoc(struct stud_node*head,int num)//ɾ������ 
{
	struct stud_node*ptr1,*ptr2;//ptr1Ϊǰ��ptr2Ϊ��
	 //Ŀ��Ϊͷ��� 
	if(num==head&&head!=NULL){
		ptr2=head;
		head=head->next;
		free(ptr2);//�ͷŶ�̬�洢 
		return head;
	}
	if(head==NULL) return NULL;
	//Ŀ�겻��ͷ��� 
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=NULL){//ѭ������ 
		if(ptr2->num==num){
			ptr1->next=ptr2->xext;
			free(ptr2);
		}
		else{//�����ƶ� 
			ptr1=ptr2;
			ptr2=ptr1->next;
		}
	}
	return head;
}

void print_Stu_Doc(struct stud_node*head)//�������� 
{
	struct stud_node*ptr;//����������forѭ����i 
	if(head==NULL){
		printf("kong");
		return;//ǿ�ƽ��� 
	}
	for(ptr=head;ptr!=NULL;ptr=ptr->next)//Ҫ��ɱ��������뱣֤β����ָ���ΪNULL,����Ҫ�ֶ����� 
		printf("%d\t%s\t%d\n",ptr->num,ptr->name,ptr->score); 
 } 

