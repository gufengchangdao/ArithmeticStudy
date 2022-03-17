声明一个C++字符串
	string s;    //生成一个空字符串s
    string s(str) //拷贝构造函数 生成str的复制品
    string s(str,pos) //将字符串str内“始于位置pos”的部分当作字符串的初值
    string s(str,pos,len) //将字符串str内“始于pos且长度顶多len”的部分作为字符串的初值
    string s(c) //将C字符串作为s的初值
    string s(c,len) //将C字符串前len个字符作为字符串s的初值
    string s(len,c) //生成一个字符串，包含len个c字符
    string s(beg,end) //以区间beg;end(不包含end)内的字符作为字符串s的初值
    s.~string() //销毁所有字符，释放内存

字符串操作函数
 =,assign()     //赋以新值
	string s,str="iamangel";
	s.assign(str); //不说
	s.assign(str,1,3);//把str[1]开始，长度为3的字符串赋给s,就是把”ama”赋给字符串
	s.assign(str,2,string::npos);//把字符串str从索引值2开始到结尾赋给s
	s.assign("gaint"); //不说
	s.assign("nico",10);//把从第一个开始长度为10的字符串赋，把’n’ ‘I’ ‘c’ ‘o’ ‘/0’赋给字符串
	s.assign(5,'x');//把五个x赋给字符串，即s="xxxxx" 
	
swap()     //交换两个字符串的内容

+=,append(),push_back() //在尾部添加字符

清空字符串 
	s.erase() //删除字符
	s.clear() //删除全部字符
	s=""; 

增加字符 
	string s,str="iamangel";
	s+=str;//加个字符串
	s+="my name is jiayp";//加个C字符串
	s+='a';//加个字符，单引号、双引号都可以 
	s.append(str);	//加入str 
	s.append(str,1,3);//不解释了 同前面的函数参数assign的解释
	s.append(str,2,string::npos);//不解释了
	s.append("my name is jiayp");
	s.append("nico",5);
	s.append(5,'x');
	s.push_back('a');//把单个字符加在尾部这个函数只能增加单个字符对STL熟悉的理解起来很简单
	s.insert(0,"zhangchao");//加在s[0]的后面，insert支持在任意位置加，注意，即便是单个字符也要用双引号 
    s.insert(1,str);	//加在s[1]的后面 


==,!=,<,<=,>,>=,compare()    //比较字符串，大于返回1，等于返回0，小于返回-1 
	string s1="zhangchao",s2="hello";
	s1.compare("hello word"); s与1"hello world"比较 
	s1.compare(s2);			 s1与s2比较 
	s1.compare(2,3,s2,2,4); (pos1,len1,s2,pos2,len2) 
				//即s1从s1[po1]开始长度为len1的字符串与s2[po2]开始长度为len2的字符串比较 
	s1.compare(2,3,"hello",2,4);	"a"与"llo"比较 
	s1.compare(0,3,"hello",4);	默认为前四位 ，"zha"与"hell"比较 

删除函数
	s.erase(5);	//从s[5]开始向后删除 
	s.erase(5,9);	//从s[5]开始删除9个字符 
	s.erase(); 	//清空字符串

字符串替换函数
	s.replace(1,3,"name");把从1开始长度为3的字符串替换为"name" 
 
返回字符数量
	s.size()
	s.length()   

	max_size() //返回字符的可能最大个数
	empty()    //判断字符串是否为空
	capacity() //返回重新分配之前的字符容量
	reserve() //保留一定量内存以容纳一定数量的字符
	
[ ], at() //存取单一字符
	string Str("string");
	cout<<Str[3];      //ok
	cout<<Str.at(3);    //ok
	cout<<Str[100]; //当下标>=s.length()的时候， 会引起未定义的行为,无效
//	Str.at(100);    //作用和[]一样，但超出的时候会出现 throw out_of_range异常，显示错误 
//	Str[Str.length()];    //未定义行为，无效，但是如果Str是const string 类型的时候，返回'/0'
//	Cstr.at(str.length()); //异常， 如果Str是const string 类型的时候，不会返回'/0'

	>>,getline() //从stream读取某值
	<<    //将谋值写入stream
	copy() //将某值赋值为一个C_string
	c_str() //将内容以C_string返回
	data() //将内容以字符数组形式返回

字符截取函数
	a.substr()  拷贝整个a
	a.substr(1) 从a[1]开始
	a.substr(0,5) 从a[0]开始，截取5个字符
	a.substr(pos,len) 截取到s[pos,pos+len)的字符串
		注意：pos超过s的长度会出现异常，但是len+pos超过s长度不会异常，只会从pos开始截取完 


v)查找函数
	s.find();不会 

	begin() end() //提供类似STL的迭代器支持
	rbegin() rend() //逆向迭代器
	get_allocator() //返回配置器

