类 
	类与结构体区别不多，基本上功能都有，主要区别为 
struct作为数据结构的实现体，它默认的数据访问控制是public的，
而class作为对象的实现体，它默认的成员变量访问控制是private的

class Student{	class 关键字  Student	类的名称,为了区分首字母一般大写 
public:
    //成员变量	 
    char *m_name;成员变量常用m_开头，便于和成员函数的形参区分 
    int m_age;
    float m_score;
	
    //成员函数
    /*
	void say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }
    */
    void say();在类中声明函数 
	 void setname(char *name);
};
void Student::say()在类外定义函数 ，加上inline就会变成内联函数 
{
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<score<<endl;
}
void Student:: void setname(char *name)
{
	m_name=name;//便于区分 
}
	内联函数和外联函数： 
对于频繁调用的小函数，使用内敛可以提高运行速度
函数代码较长，使用内联会导致内存消耗较高；函数内有循环时不适用 
	在类中定义函数会自动成为内联函数，在类体外定义的不会 。其中::为域解析符（也称作用域运算符或
作用域限定符），用来连接类名和函数名并且必须将类的定义和成员函数的定义都放在同一个头文件中（或者
同一个源文件中）	

	类的成员：成员变量、成员函数 
	类只是一个模板，编译后不占用内存空间，所以在定义类时不能对成员变量进行初始化，因为没有地方存
储数据。只有在创建对象以后才会给成员变量分配内存，这个时候就可以赋值了。

Student zhangchao;	在栈上创建对象，也可以class Student zhangchao; 
Student allstu[100];	栈上创建 
zhangchao.age=20;	赋值 
Student *stu=new Student;	堆上申请内存，需要指针指向 
Student *stu=&zhangchao;	指针指向类
	使用 new 在堆上创建出来的对象是匿名的，没法直接使用，必须要用一个指针指向它
	new和delete只能在堆上操作，及时删除无用对象，防止无用内存堆积
	
stu->age=20;
stu->say();
	类的成员函数的特定：是类的成员，作用范围由类来定，而普通函数是独立的，作用范围为全局	
delete stu;养成好习惯 
 
一般将类的声明放在头文件中，而将成员函数的定义放在源文件中
 
