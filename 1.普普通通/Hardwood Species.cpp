#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	int cnt=0;
	string s;
	map<string,int> a;
	while(getline(cin,s)){//������EOF���� 
		a[s]++;
		cnt++;
	} 
	map<string,int>::iterator it;//������ 
	for(it=a.begin();it!=a.end();it++){
		cout<<it->first<<" "<<fixed<<setprecision(4)<<(double)it->second/cnt*100<<endl;
	}//it->firstΪstring���ַ�����it->secondΪint���� 
} 

