#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i){
		vec.push_back(i);
	}
	random_shuffle(vec.begin(), vec.end());
	for (int i = 0; i < 10; ++i){
		cout << vec[i] << " ";
	}
}
/*
�������ܣ�
    ��[first,last)��Ԫ�ش���������š�N��Ԫ�ص����з�ʽ����N!�֣�random_shuffle�����һ�����ȷֲ���
	����κ�һ�����б�ѡ�еĸ���Ϊ1/N!��
*/
