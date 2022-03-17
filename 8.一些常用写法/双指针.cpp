struct node{
	int data;
	node *next;
};

//判断链表是否有环 
bool iscycle(node *head)
{
	node *fast=head,*slow=head;//一个快指针，一个慢指针 
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;//快的每次前进两步，慢点每次前进一步 
		slow=slow->next;
		if(fast==slow) return true;//快的与慢的相遇时表示链表有环 
	}
	return false;
}

//已知链表有环，返回这个环的起始位置
//类型脑筋急转弯，fast与slow相遇时fast前进2k,则slow前进k,fast比slow多一个环,环长k。设环起点到相遇
//点为n，则对于slow有 非环部分+n==k，slow从n出发前进非环部分的距离便到环的起始位置 
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

//寻找链表的中点
node *slow=head, *fast=head;
while(fast!=null&&fast.next!=null){
    fast=fast.next.next;
    slow=slow.next;
}
return slow;//slow在中间位置，当链表长度为奇数时slow在中间；为偶数时在中间靠右

//寻找链表的倒数第k个元素(假设k小于链表长度)
node *slow=head, *fast=head;
while(k-->0) fast=fast.next;//fast先前进k步 
while(fast!=NULL){//注意，fast出发的第一步便是第二个结点，所以这里的出口为fast!=NULL 
    slow=slow.next;
    fast=fast.next;
}
return slow;

//二分查找
.... 
 
