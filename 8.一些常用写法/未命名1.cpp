
class Student{	class 关键字  Student	类的名称,为了区分首字母一般大写 
public:
    //成员变量	 
    char *name;
    int age;
    float score;

    //成员函数
    void say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }
};
	类的成员：成员变量、成员函数 
	类只是一个模板，编译后不占用内存空间，所以在定义类时不能对成员变量进行初始化，因为没有地方存
储数据。只有在创建对象以后才会给成员变量分配内存，这个时候就可以赋值了。

Student zhangchao;	创建对象，也可以class Student zhangchao; 
Student allstu[100];
zhangchao.age=20;	赋值 
Student *stu=new Student;	申请内存 
Student *stu=&zhangchao;	指针指向类
	使用 new 在堆上创建出来的对象是匿名的，没法直接使用，必须要用一个指针指向它
	new和delete只能在堆上操作，及时删除无用对象，防止无用内存堆积
	
 

 






