/* 
����A������B�Ѿ���С�����ź���Ҫ�󷵻�һ���ɴ�С����ĺ����� 
����Ĺ鲢���� 
*/
LinkList merge(LinkList A, LinkList B)
{
	int cnt=0;
	LinkList c[400];//��ʱ���� 
	LinkList apr,ap=A->next,bp=B->next;
	while(ap&&bp){	//�鲢���� 
		if(bp->data>ap->data){
			c[cnt++]=ap;
			ap=ap->next;
		}	
		else{
			c[cnt++]=bp;
			bp=bp->next;
		}
	}
	while(ap){	//��ʣ�µ�һ����������ȫ������ 
		c[cnt++]=ap;
		ap=ap->next;
	}
	while(bp){
		c[cnt++]=bp;
		bp=bp->next;
	}
	apr=A;//�������� 
	for(int i=cnt-1;i>=0;i--){
		apr->next=c[i];	
		apr=apr->next;
	}		
	apr->next=NULL;//ע���������׳��� 
	return A;
}
