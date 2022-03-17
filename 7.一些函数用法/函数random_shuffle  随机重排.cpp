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
函数功能：
    将[first,last)的元素次序随机重排。N个元素的排列方式共有N!种，random_shuffle会产生一个均匀分布，
	因此任何一个排列被选中的概率为1/N!。
*/
