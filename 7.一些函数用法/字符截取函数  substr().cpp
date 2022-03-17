//C++中substr函数的用法： 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a="zhangchao";
	cout<<a.substr()<<endl<<a.substr(0)<<endl<<a.substr(1)<<endl<<a.substr(2)<<endl<<a.substr(5)<<endl;
//		拷贝整个a			从第一个开始 		从a[1]开始								 
	cout<<endl<<a.substr(0,5)<<endl<<a.substr(1,5)<<endl<<a.substr(1,100)<<endl<<a.substr(5,2)<<endl;
//			从a[0]开始，截取5个字符 	从a[1]开始 			从a[1]开始，截取整个 	从a[5]开始 

}
/*
用途：一种构造string的方法，字符截取函数，可用于string类型的字符串从中间项开始比较 
形式：s.substr(pos); 
	  s.substr(pos, n)
解释：返回一个string，包含s中从pos开始的n个字符的拷贝
	（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s）
补充：若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；
	  若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾
a.substr(-1,3)	这几个都会出错 
a.substr(-1)
a.substr(20,1)
*/
