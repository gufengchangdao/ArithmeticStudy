sort(a,a+4);//��ǰ4������ 
sort(a,a+n,less<int>());//��С���� 
sort(a,a+n,greater<int>());//�Ӵ�С 

//�Զ���������� 
bool value1(int a,int b)//�������� 
{
	return a>b;
}
bool value2(int a,int b)//������ֵ��С�������� 
{
	return fabs(a)>fabs(b);
}

bool value3(int a,int b)//������ֵ��С�������� 
{
	return a*a>b*b;
}
....
sort(a+0,a+n,value1);
//�Խṹ������(�������ýṹ��洢λ�úʹ�С��ʹ�������֪��ԭλ��)
//1. 
struct student{
	char name[20];
	int score;
}di[10];
bool compare(struct student* a,struct student* b)//��������ָ�� 
{
	return a->score>b->score;//���Ӵ�С�ȽϷ��� 
}
//sort(di,di+10,compare); 
vector<struct student*>list;//������̬�ṹ�� 
...
sort(list.begin(),list.end(),compare); 
//stable_sort(list.begin(),list.end(),compare);
//stable_sort()���Խṹ������ʱ��������Ԫ����ͬ������ԭ����˳��
//2. 
struct student{
	char name[20];
	int score;
	bool operator <(const student &a)const{//��������أ�const�Ǳ�����󲻸ı� 
		return score>a.score;//�Ӵ�С 
	}
}mode[20];
sort(mode,mode+20);
