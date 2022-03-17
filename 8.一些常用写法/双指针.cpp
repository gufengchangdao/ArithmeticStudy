struct node{
	int data;
	node *next;
};

//�ж������Ƿ��л� 
bool iscycle(node *head)
{
	node *fast=head,*slow=head;//һ����ָ�룬һ����ָ�� 
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;//���ÿ��ǰ������������ÿ��ǰ��һ�� 
		slow=slow->next;
		if(fast==slow) return true;//�������������ʱ��ʾ�����л� 
	}
	return false;
}

//��֪�����л����������������ʼλ��
//�����Խת�䣬fast��slow����ʱfastǰ��2k,��slowǰ��k,fast��slow��һ����,����k���軷��㵽����
//��Ϊn�������slow�� �ǻ�����+n==k��slow��n����ǰ���ǻ����ֵľ���㵽������ʼλ�� 
node *detectcycle(node *head)
{
	node *fast=head,*slow=head;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next; 
		slow=slow->next;
		if(fast==slow) break;
	}
	slow=head;
	while(slow!=fast){
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

//Ѱ��������е�
node *slow=head, *fast=head;
while(fast!=null&&fast.next!=null){
    fast=fast.next.next;
    slow=slow.next;
}
return slow;//slow���м�λ�ã���������Ϊ����ʱslow���м䣻Ϊż��ʱ���м俿��

//Ѱ������ĵ�����k��Ԫ��(����kС��������)
node *slow=head, *fast=head;
while(k-->0) fast=fast.next;//fast��ǰ��k�� 
while(fast!=NULL){//ע�⣬fast�����ĵ�һ�����ǵڶ�����㣬��������ĳ���Ϊfast!=NULL 
    slow=slow.next;
    fast=fast.next;
}
return slow;

//���ֲ���
.... 
 
