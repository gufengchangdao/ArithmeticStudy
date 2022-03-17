#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	int cnt=0;
	string s;
	map<string,int> a;
	while(getline(cin,s)){//输入以EOF结束 
		a[s]++;
		cnt++;
	} 
	map<string,int>::iterator it;//迭代器 
	for(it=a.begin();it!=a.end();it++){
		cout<<it->first<<" "<<fixed<<setprecision(4)<<(double)it->second/cnt*100<<endl;
	}//it->first为string的字符串，it->second为int的数 
} 

