//C++��substr�������÷��� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a="zhangchao";
	cout<<a.substr()<<endl<<a.substr(0)<<endl<<a.substr(1)<<endl<<a.substr(2)<<endl<<a.substr(5)<<endl;
//		��������a			�ӵ�һ����ʼ 		��a[1]��ʼ								 
	cout<<endl<<a.substr(0,5)<<endl<<a.substr(1,5)<<endl<<a.substr(1,100)<<endl<<a.substr(5,2)<<endl;
//			��a[0]��ʼ����ȡ5���ַ� 	��a[1]��ʼ 			��a[1]��ʼ����ȡ���� 	��a[5]��ʼ 

}
/*
��;��һ�ֹ���string�ķ������ַ���ȡ������������string���͵��ַ������м��ʼ�Ƚ� 
��ʽ��s.substr(pos); 
	  s.substr(pos, n)
���ͣ�����һ��string������s�д�pos��ʼ��n���ַ��Ŀ���
	��pos��Ĭ��ֵ��0��n��Ĭ��ֵ��s.size() - pos�������Ӳ�����Ĭ�Ͽ�������s��
���䣺��pos��ֵ������string�Ĵ�С����substr�������׳�һ��out_of_range�쳣��
	  ��pos+n��ֵ������string�Ĵ�С����substr�����n��ֵ��ֻ������string��ĩβ
a.substr(-1,3)	�⼸��������� 
a.substr(-1)
a.substr(20,1)
*/
