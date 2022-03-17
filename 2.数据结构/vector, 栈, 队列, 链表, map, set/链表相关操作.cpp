#include<stdio.h>
#include<stdlib.h>//malloc(),free(),exit()
//新建结点
struct node *AppendNode(struct node *head)//返回值为结构体指针类型 
{
    node *p = NULL, *pr = head;//初始化为空指针 
    int data;
    p = (node *)malloc(sizeof(struct node));//为新的结构体申请内存，p指向新内存 
//    if (p == NULL){        //判断是否申请成功 
//       printf("No enough memory to allocate\n");
//        exit(0);
//    }
    //添加进链尾 
    if (head == NULL) //判断原链表是否为空 
        head = p;        
    else{                
        while(pr->next != NULL) 
            pr = pr->next;        
        pr->next = p;           
    }
    //输入数据
    scanf("%d", &data);  
    p->data = data;     
    p->next = NULL;        //将新建的结点置为表尾 
    return head;        //返回新链表的头指针 
}
//新建，从后往前,倒叙输入 
{
    int n;
    node *head=NULL, *p;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        p = (List)malloc(sizeof(struct Node));//p为新创建的结点 
        scanf("%d",&p->data);
        p->next = head; //第一次，p的下一项是空，head指向p；不断循环，从后往前,与head->next=p不同 
		head = p;		//新的指向旧的 
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}
//新建，构建链表
struct ListNode *readlist()
{
	int n;
	struct ListNode *p,*pr,*head=NULL;
	while(1){
		p=(struct ListNode *)malloc(sizeof(struct ListNode));
		scanf("%d",&p->data);
		if(p->data==-1) break;//输入结束的条件 
		p->next=NULL;
		if(!head) head=p;
		else pr->next=p;
		pr=p; 
	}
	return head;
}
//新建，带有头结点的链表，优点：新建的时候不用if else 判断head是否为空 
struct ListNode *readlist()
{
    typedef struct ListNode *list;
    list head,p,pr;
    head=(list)malloc(sizeof(struct ListNode));//head是有数据的(指的是next的指针赋了值)，要申请内存 
    head->next=NULL; 
    pr=head;
    while(1){
        p=(list)malloc(sizeof(struct ListNode));
        scanf("%d",&p->data);
        if(p->data==-1) break;
        p->next=NULL;
        pr->next=p;//不需要判断pr是否为空，pr初始值head不是空 
        pr=p;
    }
    return head;//看题目要求，返回head或者head->next 
} 
//插入结点 
//1.插在链首
//2.插在中间，新节点指向下一结点，上一结点指向新节点 
//3.插在链尾 
//删除结点 
struct node *DeleteNode (struct node *head, int nodeData)
{
    struct node *p = head, *pr = head;//一前一后结点 
    if (head == NULL){		//链表为空
        printf("Linked table is empty!\n");
        return 0;//返回0 
    }
    //链表不为空  
    while (nodeData != p->data && p->next != NULL){//遍历寻找，p不是且p后面还有结点，
										//当没有结点时，若存在，只能是指向链尾巴的p，故判断p即可 
        pr = p;          
        p = p->next;
    }
    if (nodeData == p->data){//找到 
        if (p == head)//删除链首，此时用不着pr 
            head = p->next;
        else	//删除中间，要删除结点的上一结点指向删除结点的下一结点 
            pr->next = p->next;
        free(p); 	//注意，删除结点后也仍然占着内存，必须释放内存 
    }
    else	//要删除的结点不存在 
        printf("This Node has not been found");
    return head;
}
//删除和新建结点， 这个函数是把旧链表中的奇数整到新建的结点中，还要保证*L指向新的旧链表的头结点 
struct ListNode *getodd( struct ListNode **L )//传入一个二级指针
{
    typedef struct ListNode *list;	//别名简化代码 
    list p,pr2;  //旧的指针 
    list head,pr1,q;  //新建的指针 
    p=(*L)->next; //注意，使用*L的时候必须加括号，因为优先级较低 
    pr2=*L;  
    head=(list)malloc(sizeof(struct ListNode));	//带有头结点的头插法 
    head->next=NULL;
    pr1=head;
    while(p){	 
        if(p->data&1){	
            q=(list)malloc(sizeof(struct ListNode));	//处理新结点 
            q->data=p->data;
            q->next=NULL;
			pr1->next=q;
            pr1=q;
            
            pr2->next=p->next;//处理旧结点，改变pr2的指向，注意这里并没有改变pr2的值 
            free(p);
            p=pr2;	//p要重新赋值 
        }
        pr2=p; 
        p=p->next;
    }
    *L=(*L)->next; //改变*L的头结点 
    return head->next;	//传入head的头结点 
}
  
//打印数据 ：while、if、递归 
void DisplyNode (struct node *head)
{
	printf("%d\n",head->data);
	if(head->next!=NULL) DisplyNode(head->next);
}
//释放存储 
void DeletMemory(struct node *head)
{
	if(head->next!=NULL) DeletMemory(head->next);//递归找到链尾开始释放 
	free(head);
}  

