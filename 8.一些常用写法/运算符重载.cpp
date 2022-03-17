struct node{  //定义一个结构体node（节点）
   	int x;
   	int y;
   	int len;   //node中有3个成员变量x,y,len
   	bool operator <(const node &a)const {//重载<操作符。可以对两个node使用<操作符进行比较
 					//括号里的const表示a参数对象不会被修改，后面的const表明调用函数对象不会被修改  
    	return len<a.len;
   	}
};

bool operator <(const node &a)const{
	if(len==a.len) return x<a.x;//当len相等的时候按x排序 
	else return len<a.len;
}

struct mode{
	char name[25];
	bool operator <(const mode &b)const {
		return strcmp(name,b.name)<=0;
	}
}stu[105];
sort(stu,stu+n);//将名字按字典序排序 
//重载运算符：
//C++中预定义的运算符的操作对象只能是基本数据类型。但实际上，对于许多用户自定义类型（例如类），
//也需要类似的运算操作。这时就必须在C++中重新定义这些运算符，赋予已有运算符新的功能，使它能够用于
//特定类型执行特定的操作。运算符重载的实质是函数重载，它很好
//一般格式跟普通函数一样：
//<返回类型说明符> operator <运算符符号>(<参数表>){ <函数体> }
//例如关系运算符：
	bool operator == (const &A){
		return ...;
	} 
	//函数声明： 
    bool operator != (const A& );
    bool operator < (const A& );
    bool operator <= (const A& );
    bool operator > (const A& );
    bool operator >= (const A& ); 
