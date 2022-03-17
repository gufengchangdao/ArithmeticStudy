
把重复元素全部放到数组的后面。同时，unique只去除相邻的重复元素，所以，我们需要对数组Vector进行排序
（sort，默认从小到大），这样保证重复元素在相邻的位置。实际返回的是去重后的尾地址。
函数： 只有两个参数，且参数类型都是迭代器
unique(iterator it_1,iterator it_2);
作用范围为[it_1,it_2)
返回值是一个迭代器，它指向的是去重后容器中不重复序列的最后一个元素的下一个元素
	注意：a[1~n]时，m=unique(a+1,a+n+1)-a-1;	因为这里从a+1开始的，所以减(a+1) 
		  a[0~n]时，m=unique(a+1,a+n+1)-a; 	m都是去重后的长度 
用set也好用 

//举例 
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
 
    new_end = unique(it_1,it_2); //注意unique的返回值
    a.erase(new_end,it_2);
    cout<<"删除重复元素后的 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout<<endl;
 
} 
