//结构体 
struct time
{	//创建成员变量 
    int year;
    int month;
    int day;
    //创建成员函数 
	void init()
	{
		year=1900;
		month=1;
		day=1;	
	}
	void update(int x)
	{
		year=x;
	} 
};
//结构体的嵌套 
struct student
{
    char name[10];
    int num;
    struct time birthday;
};
//结构体的继承 
struct data: time
{
	char thing[80];
};

//若想引用student的出生年月日，可表示为；student1.brithday.year；
//brithday是student的成员；year是brithday的成员；

//结构体的赋值 
//1.按顺序 
student student1={"zhangchao",10,2001,9,3};//结构体变量只有在创建的时候才能这样赋值
//当已经创建好变量后就不能这么赋值，只能student1.name[10]=.... 
//2.整体赋值 
student student2;
student2=student1;
//或者memset(&student2,&student1,sizeof(student));

//结构体的指针
student *him=&student2;//创建并指向student2 
//满足*him==student2
him->name;//引用 
int swap(const student*s){//使用指针接收 
	return 2*s->num;	  //const不要也可以 ，const可以防止结构体成员的值改变
}
int swap(student s){//使用结构体接收，形参的改变不影响实参 
	return 2*s->num;
student swap(student s){//使用结构体接收，并且返回结构体 
	return s;	  
}
int ans=swap(&student1);//传递地址 
 

