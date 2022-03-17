sort(a,a+4);//对前4个排序 
sort(a,a+n,less<int>());//从小到大 
sort(a,a+n,greater<int>());//从大到小 

//自定义排序规则 
bool value1(int a,int b)//降序排序 
{
	return a>b;
}
bool value2(int a,int b)//按绝对值大小降序排序 
{
	return fabs(a)>fabs(b);
}

bool value3(int a,int b)//按绝对值大小降序排序 
{
	return a*a>b*b;
}
....
sort(a+0,a+n,value1);
//对结构体排序(可以利用结构体存储位置和大小，使排序后仍知道原位置)
//1. 
struct student{
	char name[20];
	int score;
}di[10];
bool compare(struct student* a,struct student* b)//定义两个指针 
{
	return a->score>b->score;//按从大到小比较分数 
}
//sort(di,di+10,compare); 
vector<struct student*>list;//创建动态结构体 
...
sort(list.begin(),list.end(),compare); 
//stable_sort(list.begin(),list.end(),compare);
//stable_sort()：对结构体排序时，若排序元素相同，保留原来的顺序
//2. 
struct student{
	char name[20];
	int score;
	bool operator <(const student &a)const{//运算符重载，const是表面对象不改变 
		return score>a.score;//从大到小 
	}
}mode[20];
sort(mode,mode+20);
