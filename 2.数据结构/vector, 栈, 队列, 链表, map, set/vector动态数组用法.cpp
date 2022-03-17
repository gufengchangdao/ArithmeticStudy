vector-----动态数组 

//定义 
	//定义int型数组 
	vector<int>a;//默认初始化，a为空 
	vector<int>b(a);//用a定义b 
	vector<int>a(100);//a有100个值为0的元素 
	vector<int>a(100,6);//a有100个值为6的元素 
	//string型数组 
	vector<string>a(10,"null");//a有10个值为null的元素 
	vector<string>a(100,"hello");//a有100个值为hello的元素 
	vector<string>b(a.begin(),a.end());//b复制a 
	//结构型数组 
	struct point {int x,y;};
	vector<point>a;//a可以来储存坐标 

//操作
	a.push_back(100);//尾部添加元素值为100的数 
	int size=a.size();//计算元素个数 
	bool isempty=a.empty();//判断是否为空 
	cout<<a[0]<<endl;//打印第一个元素 
	a.insert(a.begin()+i,k);//在第i的元素前面插入k
	a.insert(a.begin()+1,6); 
	a.push_back(8);//尾部添加数值8 
	a.insert(a.end(),10,5);//尾部添加10个5 
	a.pop_back();//删除末尾元素 
	a.erase(a.begin()+i,a.begin()+j);//删除区间【i，j-1】的元素 
	a.erase(a.begin()+2);//删除第3个元素,当执行删除操作后，a[2]以后的元素都会向前移动一步 
					//注意a.erase(2);是错误的 
	a.resize(n)//数组大小变为n 
	a.clear();//清空 
	reverse(a.begin(),a.end());//reverse（）函数翻转数组 
	sort(a.begin(),a.end());//sort从小到大排序 
	 
	 

