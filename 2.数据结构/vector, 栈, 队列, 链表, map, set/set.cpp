会排序和去重 
set<Type>a;//定义
begin()--返回指向第一个元素的迭代器
c++ stl容器set成员函数:end()--返回指向最后一个元素下一个位置的迭代器 
a.insert(item);//把item放入set 
a.erase(item);//删除元素item 
a.clear();
a.empty();
a.size();
a.find(k);//返回一个迭代器，指向键值k 
if(a.find(k)!=a.end()){
	//存在 
} 
else{
	//如果不存在，会返回a.end() 
}
a.lower_bound(k);//返回一个迭代器，指向键值不小于k的第一个元素 
a.upper_bound(k);//返回一个迭代器， 指向键值不大于k的第一个元素
//输出 
for(set<int>::iterator it = s.begin(); it != s.end(); it++)//定义前向迭代器遍历输出，由小到大 
{
   	printf("%d ",*it);
}
for(set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)//定义反向迭代器遍历输出，由大到小 
{
 	printf("%d ",*rit);
} 
