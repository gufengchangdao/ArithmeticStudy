#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	vector<int>table;//���嶯̬���� 
	while(cin>>n>>m){
		table.clear();//������飬�൱�ڶ���Ϊ0 
		for(int i=0;i<2*n;i++) table.push_back(i);//������������ 
		int pos=0;
		
		for(int i=0;i<n;i++){//ɾ��n��������λ 
			pos=(pos-1+m)%table.size();//***Բ���Ǹ���������λ��Ҫȡ�࣬pos��0��ʼ������Ҫ��1*** 
			table.erase(table.begin()+pos);//ɾ��table[pos]��ɾ������Ϊ���Բ��������ݶ��ǻ�T 
		}
		int j=0;
		for(int i=0;i<2*n;i++){
			if(!(i%50)&&i) printf("\n");//50����ĸһ�� 
			if(i==table[j]&&j<table.size()){//��������δɾ����λ��������Ϊ���˵�λ�ã�ɾ������Ϊ���� 
				printf("G");
				j++;
			}
			else
				printf("B");
		} 
	printf("\n\n");
	}
	
	return 0;
}
