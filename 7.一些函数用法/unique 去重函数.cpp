
���ظ�Ԫ��ȫ���ŵ�����ĺ��档ͬʱ��uniqueֻȥ�����ڵ��ظ�Ԫ�أ����ԣ�������Ҫ������Vector��������
��sort��Ĭ�ϴ�С���󣩣�������֤�ظ�Ԫ�������ڵ�λ�á�ʵ�ʷ��ص���ȥ�غ��β��ַ��
������ ֻ�������������Ҳ������Ͷ��ǵ�����
unique(iterator it_1,iterator it_2);
���÷�ΧΪ[it_1,it_2)
����ֵ��һ������������ָ�����ȥ�غ������в��ظ����е����һ��Ԫ�ص���һ��Ԫ��
	ע�⣺a[1~n]ʱ��m=unique(a+1,a+n+1)-a-1;	��Ϊ�����a+1��ʼ�ģ����Լ�(a+1) 
		  a[0~n]ʱ��m=unique(a+1,a+n+1)-a; 	m����ȥ�غ�ĳ��� 
��setҲ���� 

//���� 
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
 
int main()
{
 
    vector<int> a ={1,3,3,4,5,6,6,7};
    vector<int>::iterator it_1 = a.begin();
    vector<int>::iterator it_2 = a.end();
    vector<int>::iterator new_end;
 
    new_end = unique(it_1,it_2); //ע��unique�ķ���ֵ
    a.erase(new_end,it_2);
    cout<<"ɾ���ظ�Ԫ�غ�� a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout<<endl;
 
} 
