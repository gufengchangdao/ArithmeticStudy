C++类成员的访问权限以及类的封装

public   protected  private 三个关键字来控制成员变量和成员函数的访问权限，分别表示
公有的、受保护的、  私有的，被称为成员访问限定符。所谓访问权限，就是你能不能使用该类中的成员。
	在类的内部（定义类的代码内部），无论成员被声明为 public、protected 还是 private，都是可以互
相访问的，没有访问权限的限制。如果既不写 private 也不写 public，就默认为 private。 
	在类的外部（定义类的代码之外），只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，
不能访问 private、protected 属性的成员。 
#include <iostream>
using namespace std;

//类的声明
class Student{
private:  //私有的
    char *m_name;
    int m_age;
    float m_score;

public:  //共有的
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
//成员函数的定义
void Student::setname(char *name){
    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
    //在栈上创建对象
    Student stu;
    stu.setname("小明");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();
	//printf("%d",stu.m_age);不能直接访问 
    //在堆上创建对象
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();

    return 0;
}

封装：
所谓封装，是指尽量隐藏类的内部实现，只向用户提供有用的成员函数。 
	该向外暴露的接口（能通过对象访问的成员）都声明为 public
	
允许通过对象调用的成员函数声明为 public。一些有用的成员函数：
	以get开头的函数用于读取成员变量的值
	以set开头的函数用于给成员变量赋值
	...
不希望外部知道、或者只在类内部使用的、或者对外部没有影响的成员，都建议声明为 private。
	实际项目开发中的成员变量，外部不能直接调用的 
	只在类内部使用的成员函数（只被成员函数调用的成员函数）
	...
声明为 protected 的成员在类外也不能通过对象访问，但是在它的派生类内部可以访问






