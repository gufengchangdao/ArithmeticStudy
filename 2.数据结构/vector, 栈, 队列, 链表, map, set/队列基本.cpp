struct node
{
	int x,y;	
}; 

#include<queue>
node item={1,2};
queue<int>q;//���壬int,float,char�� 
q.push(item);//��item����
q.push((node){1,2});//Ч����ͬ��(node)������Ϊ��ǿ������ת�� 
q.front();//���ض���Ԫ��,���ǵ�һ���������
q.back();//���ض�βԪ��  
q.pop();//ɾ������Ԫ�� 
q.size(); 
q.empty();

priority_queue<int>q;//���ȶ��У���������Ԫ�شӴ�С���� 
priority_queue<int,vector<int>,greater<int>>q;//��С������� 
