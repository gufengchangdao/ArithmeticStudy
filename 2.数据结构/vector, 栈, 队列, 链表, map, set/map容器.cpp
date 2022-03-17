#include <map>//头文件
std:map<int, string>mp;//定义一个用int作为索引,并拥有相关联的指向string的指针
//	 <键(key),值(value)> 
//std:map<int, int>mp;
//map<string,int>mp;
//map<char,string>mp;

//插入元素 
mp[1]="zhangchao";//map类已经对[]操作符进行了重载，可以这样直接定义
mp.insert(pair<int, string>(3,"zhangchao");//插入pair，pair同mp同类型，表示插入3个字符串 

//查找并获取
string a=mp[1];//直接获取，但是当map不存在这个键，则会自动插入一个实例，值为初始化值
map<int,string>::iterator it=mp.find(1);//定义条目变量 ，iterator为数据类型，1为要寻找的键 
if(it==mp.end()){//mp.end()为map的最后一个条目，类似于int a[n]的a[n] 
	//没找到 
}
else{
	//找到
	mp->first=...//键 
	mp->second=...//值 
}

//删除 
mp.erase()//删除一个条目 
mp.erase(iterator first,iterator last)//删除一个范围 
mp.erase(mp.begin(),mp.end());//迭代器范围删除
mp.clear();//效果同上 

iter=mp.find(x); mp.erase(iter);//迭代器删除 
int n=mp.erase(x);//删除成功返回1，否则返回0 



#include <unordered_map>
unorder_map//无序map容器，unordered_map 容器不会像 map 容器那样对存储的数据进行排序,比map快 
unordered_map<string,string> umap;//创建 
unordered_map<string,string> umap2(umap);//创建新unordermap并复制原有的unordermap
unordered_map<string,string>::iterator it;
unordered_map<string,string> umap2(++umap.begin(),umap.end());//使用迭代器复制
									//这里就复制了除了第一个键值外对外的所有其他键值对 

//类模板成员方法：
begin();//返回指向容器中第一个键值对的正向迭代器。
end() 	//返回指向容器中最后一个键值对之后位置的正向迭代器，注意是最后一个的后面一个 
cbegin()	//和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()	//和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
empty()	//若容器为空，则返回 true；否则 false。
size()	//返回当前容器中存有键值对的个数。
max_size()	//返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[key]	//该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。
		//注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。
at(key)	//返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。 
find(key)	//查找以 key为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（如果 end() 方法返回的迭代器）。
count(key)	//在容器中查找以 key 键的键值对的个数。
equal_range(key)	//返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
emplace()	//向容器中添加新键值对，效率比 insert() 方法高。
emplace_hint()	//向容器中添加新键值对，效率比 insert() 方法高。
insert() 	//向容器中添加新键值对。
erase()		//删除指定键值对。
clear() 	//清空容器，即删除容器中存储的所有键值对。
swap()		//交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()	//返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()	//返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
bucket_size(n)	//返回第 n 个桶中存储键值对的数量。
bucket(key)		//返回以 key 为键的键值对所在桶的编号。
load_factor()	//返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
max_load_factor()	//返回或者设置当前 unordered_map 容器的负载因子。
rehash(n)		//将当前容器底层使用桶的数量设置为 n。
reserve()		//将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。
hash_function()	//返回当前容器使用的哈希函数对象。 
 
