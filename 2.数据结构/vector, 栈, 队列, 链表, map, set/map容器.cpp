#include <map>//ͷ�ļ�
std:map<int, string>mp;//����һ����int��Ϊ����,��ӵ���������ָ��string��ָ��
//	 <��(key),ֵ(value)> 
//std:map<int, int>mp;
//map<string,int>mp;
//map<char,string>mp;

//����Ԫ�� 
mp[1]="zhangchao";//map���Ѿ���[]���������������أ���������ֱ�Ӷ���
mp.insert(pair<int, string>(3,"zhangchao");//����pair��pairͬmpͬ���ͣ���ʾ����3���ַ��� 

//���Ҳ���ȡ
string a=mp[1];//ֱ�ӻ�ȡ�����ǵ�map�����������������Զ�����һ��ʵ����ֵΪ��ʼ��ֵ
map<int,string>::iterator it=mp.find(1);//������Ŀ���� ��iteratorΪ�������ͣ�1ΪҪѰ�ҵļ� 
if(it==mp.end()){//mp.end()Ϊmap�����һ����Ŀ��������int a[n]��a[n] 
	//û�ҵ� 
}
else{
	//�ҵ�
	mp->first=...//�� 
	mp->second=...//ֵ 
}

//ɾ�� 
mp.erase()//ɾ��һ����Ŀ 
mp.erase(iterator first,iterator last)//ɾ��һ����Χ 
mp.erase(mp.begin(),mp.end());//��������Χɾ��
mp.clear();//Ч��ͬ�� 

iter=mp.find(x); mp.erase(iter);//������ɾ�� 
int n=mp.erase(x);//ɾ���ɹ�����1�����򷵻�0 



#include <unordered_map>
unorder_map//����map������unordered_map ���������� map ���������Դ洢�����ݽ�������,��map�� 
unordered_map<string,string> umap;//���� 
unordered_map<string,string> umap2(umap);//������unordermap������ԭ�е�unordermap
unordered_map<string,string>::iterator it;
unordered_map<string,string> umap2(++umap.begin(),umap.end());//ʹ�õ���������
									//����͸����˳��˵�һ����ֵ����������������ֵ�� 

//��ģ���Ա������
begin();//����ָ�������е�һ����ֵ�Ե������������
end() 	//����ָ�����������һ����ֵ��֮��λ�õ������������ע�������һ���ĺ���һ�� 
cbegin()	//�� begin() ������ͬ��ֻ������������������� const ���ԣ����÷������صĵ��������������޸������ڴ洢�ļ�ֵ�ԡ�
cend()	//�� end() ������ͬ��ֻ������������ϣ������� const ���ԣ����÷������صĵ��������������޸������ڴ洢�ļ�ֵ�ԡ�
empty()	//������Ϊ�գ��򷵻� true������ false��
size()	//���ص�ǰ�����д��м�ֵ�Եĸ�����
max_size()	//���������������ɼ�ֵ�Ե�����������ͬ�Ĳ���ϵͳ���䷵��ֵ�಻��ͬ��
operator[key]	//��ģ������������ [] ��������书���ǿ��������������Ԫ��������ֻҪ����ĳ����ֵ�Եļ� key���Ϳ��Ի�ȡ�ü���Ӧ��ֵ��
		//ע�⣬�����ǰ������û���� key Ϊ���ļ�ֵ�ԣ������ʹ�øü���ǰ�����в���һ���¼�ֵ�ԡ�
at(key)	//���������д洢�ļ� key ��Ӧ��ֵ����� key �����ڣ�����׳� out_of_range �쳣�� 
find(key)	//������ keyΪ���ļ�ֵ�ԣ�����ҵ����򷵻�һ��ָ��ü�ֵ�Ե��������������֮���򷵻�һ��ָ�����������һ����ֵ��֮��λ�õĵ���������� end() �������صĵ���������
count(key)	//�������в����� key ���ļ�ֵ�Եĸ�����
equal_range(key)	//����һ�� pair ��������� 2 �������������ڱ�����ǰ�����м�Ϊ key �ļ�ֵ�����ڵķ�Χ��
emplace()	//������������¼�ֵ�ԣ�Ч�ʱ� insert() �����ߡ�
emplace_hint()	//������������¼�ֵ�ԣ�Ч�ʱ� insert() �����ߡ�
insert() 	//������������¼�ֵ�ԡ�
erase()		//ɾ��ָ����ֵ�ԡ�
clear() 	//�����������ɾ�������д洢�����м�ֵ�ԡ�
swap()		//���� 2 �� unordered_map �����洢�ļ�ֵ�ԣ�ǰ���Ǳ��뱣֤�� 2 ��������������ȫ��ȡ�
bucket_count()	//���ص�ǰ�����ײ�洢��ֵ��ʱ��ʹ��Ͱ��һ�������������һ��Ͱ����������
max_bucket_count()	//���ص�ǰϵͳ�У�unordered_map �����ײ�������ʹ�ö���Ͱ��
bucket_size(n)	//���ص� n ��Ͱ�д洢��ֵ�Ե�������
bucket(key)		//������ key Ϊ���ļ�ֵ������Ͱ�ı�š�
load_factor()	//���� unordered_map �����е�ǰ�ĸ������ӡ��������ӣ�ָ���ǵĵ�ǰ�����д洢��ֵ�Ե�������size()����ʹ��Ͱ����bucket_count()���ı�ֵ���� load_factor() = size() / bucket_count()��
max_load_factor()	//���ػ������õ�ǰ unordered_map �����ĸ������ӡ�
rehash(n)		//����ǰ�����ײ�ʹ��Ͱ����������Ϊ n��
reserve()		//���洢Ͱ��������Ҳ���� bucket_count() �����ķ���ֵ������Ϊ��������count��Ԫ����������������ӣ����������������������������
hash_function()	//���ص�ǰ����ʹ�õĹ�ϣ�������� 
 
