/*
哈夫曼树：把权值重的放在离根节点近的地方，出来频率越高编码越短 
	一串字符串，因为数据在计算机中用二进制数来表示，需要把每一个字符编码成一个二进制数省空间 
	原编码：每个字符8 bit
	规律：
		1.将字符按照权值(出现频率)从小到大排序，越到前面的越先处理
		2.取出前两个字符的权值(出现频率)相加，得到一个父亲结点，其权值为权值之和，加入队列并排序
		3.不断调整，直到只剩下一个结点(根结点) 
	优点：从根节点出发，向左是0，向右是1，所有字符的编码放在叶子结点上，保证了不存在一个编码是另一
	个编码的前缀和，即不会重复
*/
//Entropy
//给一行字符串，只用计算原来的bit大小，和优化后的大小，两者之比 
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
		ll ori=8*len,sum=0;	//ori为原来的
		 
		for(int i=1;i<len;i++){	//统计各个字符出现次数，这里也可以用map	
			if(s[i]!=s[i-1]){
				q.push(t);
				t=1;
			}
			else t++;
		}
		q.push(t);	//注意i从1开始，相当于t是记录的s[i-1]的出现次数 
		
		while(q.size()>1){	//建树 
			int a=q.top();q.pop();
			int b=q.top();q.pop();
			sum+=a+b;	//这题只用统计编码总长度，每次合并，都会导致其含有的所有字符编码长度加一 
//			printf("+%d+%d\n\n",a,b);
			q.push(a+b);
		}
		if(sum==0) sum=q.top();//注意：如果只有一种字符，则每个字符长度为1，统计为出现次数 
		q.pop();
		printf("%lld %lld %.1f\n",ori,sum,ori*1.0/sum); 
	}
}
/*
用map储存出现次数：
map<char,int>mp;
mp.clear();
for(auto i:mp) que.push(i.second); 
*/
