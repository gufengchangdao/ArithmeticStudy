/*
������������Ȩֵ�صķ�������ڵ���ĵط�������Ƶ��Խ�߱���Խ�� 
	һ���ַ�������Ϊ�����ڼ�������ö�����������ʾ����Ҫ��ÿһ���ַ������һ����������ʡ�ռ� 
	ԭ���룺ÿ���ַ�8 bit
	���ɣ�
		1.���ַ�����Ȩֵ(����Ƶ��)��С��������Խ��ǰ���Խ�ȴ���
		2.ȡ��ǰ�����ַ���Ȩֵ(����Ƶ��)��ӣ��õ�һ�����׽�㣬��ȨֵΪȨֵ֮�ͣ�������в�����
		3.���ϵ�����ֱ��ֻʣ��һ�����(�����) 
	�ŵ㣺�Ӹ��ڵ������������0��������1�������ַ��ı������Ҷ�ӽ���ϣ���֤�˲�����һ����������һ
	�������ǰ׺�ͣ��������ظ�
*/
//Entropy
//��һ���ַ�����ֻ�ü���ԭ����bit��С�����Ż���Ĵ�С������֮�� 
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<string>
#include<cstring>
#define ll long long
using namespace std;
int main()
{
	string s;
	priority_queue<int,vector<int>,greater<int> >q; 
	while(getline(cin,s)&&s!="END"){
		sort(s.begin(),s.end());
		int len=s.size(),t=1;
		ll ori=8*len,sum=0;	//oriΪԭ����
		 
		for(int i=1;i<len;i++){	//ͳ�Ƹ����ַ����ִ���������Ҳ������map	
			if(s[i]!=s[i-1]){
				q.push(t);
				t=1;
			}
			else t++;
		}
		q.push(t);	//ע��i��1��ʼ���൱��t�Ǽ�¼��s[i-1]�ĳ��ִ��� 
		
		while(q.size()>1){	//���� 
			int a=q.top();q.pop();
			int b=q.top();q.pop();
			sum+=a+b;	//����ֻ��ͳ�Ʊ����ܳ��ȣ�ÿ�κϲ������ᵼ���京�е������ַ����볤�ȼ�һ 
//			printf("+%d+%d\n\n",a,b);
			q.push(a+b);
		}
		if(sum==0) sum=q.top();//ע�⣺���ֻ��һ���ַ�����ÿ���ַ�����Ϊ1��ͳ��Ϊ���ִ��� 
		q.pop();
		printf("%lld %lld %.1f\n",ori,sum,ori*1.0/sum); 
	}
}
/*
��map������ִ�����
map<char,int>mp;
mp.clear();
for(auto i:mp) que.push(i.second); 
*/
