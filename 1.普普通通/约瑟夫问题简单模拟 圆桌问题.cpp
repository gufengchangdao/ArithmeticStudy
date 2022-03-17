#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	vector<int>table;//定义动态数组 
	while(cin>>n>>m){
		table.clear();//清空数组，相当于都设为0 
		for(int i=0;i<2*n;i++) table.push_back(i);//遍历输入数据 
		int pos=0;
		
		for(int i=0;i<n;i++){//删除n个坏人座位 
			pos=(pos-1+m)%table.size();//***圆桌是个环，查找位置要取余，pos从0开始，所以要减1*** 
			table.erase(table.begin()+pos);//删除table[pos]，删除操作为线性操作，数据多是会T 
		}
		int j=0;
		for(int i=0;i<2*n;i++){
			if(!(i%50)&&i) printf("\n");//50个字母一行 
			if(i==table[j]&&j<table.size()){//遍历，若未删除的位置数字则为好人的位置，删除的则为坏人 
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
