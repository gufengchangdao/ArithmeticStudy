/* 
链表A和链表B已经由小到大排好序，要求返回一个由大到小排序的合链表 
链表的归并排序 
*/
LinkList merge(LinkList A, LinkList B)
{
	int cnt=0;
	LinkList c[400];//临时数组 
	LinkList apr,ap=A->next,bp=B->next;
	while(ap&&bp){	//归并部分 
		if(bp->data>ap->data){
			c[cnt++]=ap;
			ap=ap->next;
		}	
		else{
			c[cnt++]=bp;
			bp=bp->next;
		}
	}
	while(ap){	//把剩下的一个链表数据全部存入 
		c[cnt++]=ap;
		ap=ap->next;
	}
	while(bp){
		c[cnt++]=bp;
		bp=bp->next;
	}
	apr=A;//构建链表 
	for(int i=cnt-1;i>=0;i--){
		apr->next=c[i];	
		apr=apr->next;
	}		
	apr->next=NULL;//注意这里容易出错 
	return A;
}
