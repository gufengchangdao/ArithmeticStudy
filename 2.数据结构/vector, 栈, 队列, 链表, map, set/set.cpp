�������ȥ�� 
set<Type>a;//����
begin()--����ָ���һ��Ԫ�صĵ�����
c++ stl����set��Ա����:end()--����ָ�����һ��Ԫ����һ��λ�õĵ����� 
a.insert(item);//��item����set 
a.erase(item);//ɾ��Ԫ��item 
a.clear();
a.empty();
a.size();
a.find(k);//����һ����������ָ���ֵk 
if(a.find(k)!=a.end()){
	//���� 
} 
else{
	//��������ڣ��᷵��a.end() 
}
a.lower_bound(k);//����һ����������ָ���ֵ��С��k�ĵ�һ��Ԫ�� 
a.upper_bound(k);//����һ���������� ָ���ֵ������k�ĵ�һ��Ԫ��
//��� 
for(set<int>::iterator it = s.begin(); it != s.end(); it++)//����ǰ������������������С���� 
{
   	printf("%d ",*it);
}
for(set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)//���巴�����������������ɴ�С 
{
 	printf("%d ",*rit);
} 
