#include<stdio.h>
#include<stdlib.h>//malloc(),free(),exit()
//�½����
struct node *AppendNode(struct node *head)//����ֵΪ�ṹ��ָ������ 
{
    node *p = NULL, *pr = head;//��ʼ��Ϊ��ָ�� 
    int data;
    p = (node *)malloc(sizeof(struct node));//Ϊ�µĽṹ�������ڴ棬pָ�����ڴ� 
//    if (p == NULL){        //�ж��Ƿ�����ɹ� 
//       printf("No enough memory to allocate\n");
//        exit(0);
//    }
    //��ӽ���β 
    if (head == NULL) //�ж�ԭ�����Ƿ�Ϊ�� 
        head = p;        
    else{                
        while(pr->next != NULL) 
            pr = pr->next;        
        pr->next = p;           
    }
    //��������
    scanf("%d", &data);  
    p->data = data;     
    p->next = NULL;        //���½��Ľ����Ϊ��β 
    return head;        //�����������ͷָ�� 
}
//�½����Ӻ���ǰ,�������� 
{
    int n;
    node *head=NULL, *p;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        p = (List)malloc(sizeof(struct Node));//pΪ�´����Ľ�� 
        scanf("%d",&p->data);
        p->next = head; //��һ�Σ�p����һ���ǿգ�headָ��p������ѭ�����Ӻ���ǰ,��head->next=p��ͬ 
		head = p;		//�µ�ָ��ɵ� 
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}
//�½�����������
struct ListNode *readlist()
{
	int n;
	struct ListNode *p,*pr,*head=NULL;
	while(1){
		p=(struct ListNode *)malloc(sizeof(struct ListNode));
		scanf("%d",&p->data);
		if(p->data==-1) break;//������������� 
		p->next=NULL;
		if(!head) head=p;
		else pr->next=p;
		pr=p; 
	}
	return head;
}
//�½�������ͷ���������ŵ㣺�½���ʱ����if else �ж�head�Ƿ�Ϊ�� 
struct ListNode *readlist()
{
    typedef struct ListNode *list;
    list head,p,pr;
    head=(list)malloc(sizeof(struct ListNode));//head�������ݵ�(ָ����next��ָ�븳��ֵ)��Ҫ�����ڴ� 
    head->next=NULL; 
    pr=head;
    while(1){
        p=(list)malloc(sizeof(struct ListNode));
        scanf("%d",&p->data);
        if(p->data==-1) break;
        p->next=NULL;
        pr->next=p;//����Ҫ�ж�pr�Ƿ�Ϊ�գ�pr��ʼֵhead���ǿ� 
        pr=p;
    }
    return head;//����ĿҪ�󣬷���head����head->next 
} 
//������ 
//1.��������
//2.�����м䣬�½ڵ�ָ����һ��㣬��һ���ָ���½ڵ� 
//3.������β 
//ɾ����� 
struct node *DeleteNode (struct node *head, int nodeData)
{
    struct node *p = head, *pr = head;//һǰһ���� 
    if (head == NULL){		//����Ϊ��
        printf("Linked table is empty!\n");
        return 0;//����0 
    }
    //����Ϊ��  
    while (nodeData != p->data && p->next != NULL){//����Ѱ�ң�p������p���滹�н�㣬
										//��û�н��ʱ�������ڣ�ֻ����ָ����β�͵�p�����ж�p���� 
        pr = p;          
        p = p->next;
    }
    if (nodeData == p->data){//�ҵ� 
        if (p == head)//ɾ�����ף���ʱ�ò���pr 
            head = p->next;
        else	//ɾ���м䣬Ҫɾ��������һ���ָ��ɾ��������һ��� 
            pr->next = p->next;
        free(p); 	//ע�⣬ɾ������Ҳ��Ȼռ���ڴ棬�����ͷ��ڴ� 
    }
    else	//Ҫɾ���Ľ�㲻���� 
        printf("This Node has not been found");
    return head;
}
//ɾ�����½���㣬 ��������ǰѾ������е����������½��Ľ���У���Ҫ��֤*Lָ���µľ������ͷ��� 
struct ListNode *getodd( struct ListNode **L )//����һ������ָ��
{
    typedef struct ListNode *list;	//�����򻯴��� 
    list p,pr2;  //�ɵ�ָ�� 
    list head,pr1,q;  //�½���ָ�� 
    p=(*L)->next; //ע�⣬ʹ��*L��ʱ���������ţ���Ϊ���ȼ��ϵ� 
    pr2=*L;  
    head=(list)malloc(sizeof(struct ListNode));	//����ͷ����ͷ�巨 
    head->next=NULL;
    pr1=head;
    while(p){	 
        if(p->data&1){	
            q=(list)malloc(sizeof(struct ListNode));	//�����½�� 
            q->data=p->data;
            q->next=NULL;
			pr1->next=q;
            pr1=q;
            
            pr2->next=p->next;//����ɽ�㣬�ı�pr2��ָ��ע�����ﲢû�иı�pr2��ֵ 
            free(p);
            p=pr2;	//pҪ���¸�ֵ 
        }
        pr2=p; 
        p=p->next;
    }
    *L=(*L)->next; //�ı�*L��ͷ��� 
    return head->next;	//����head��ͷ��� 
}
  
//��ӡ���� ��while��if���ݹ� 
void DisplyNode (struct node *head)
{
	printf("%d\n",head->data);
	if(head->next!=NULL) DisplyNode(head->next);
}
//�ͷŴ洢 
void DeletMemory(struct node *head)
{
	if(head->next!=NULL) DeletMemory(head->next);//�ݹ��ҵ���β��ʼ�ͷ� 
	free(head);
}  

