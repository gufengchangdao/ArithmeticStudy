//�ṹ�� 
struct time
{	//������Ա���� 
    int year;
    int month;
    int day;
    //������Ա���� 
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
//�ṹ���Ƕ�� 
struct student
{
    char name[10];
    int num;
    struct time birthday;
};
//�ṹ��ļ̳� 
struct data: time
{
	char thing[80];
};

//��������student�ĳ��������գ��ɱ�ʾΪ��student1.brithday.year��
//brithday��student�ĳ�Ա��year��brithday�ĳ�Ա��

//�ṹ��ĸ�ֵ 
//1.��˳�� 
student student1={"zhangchao",10,2001,9,3};//�ṹ�����ֻ���ڴ�����ʱ�����������ֵ
//���Ѿ������ñ�����Ͳ�����ô��ֵ��ֻ��student1.name[10]=.... 
//2.���帳ֵ 
student student2;
student2=student1;
//����memset(&student2,&student1,sizeof(student));

//�ṹ���ָ��
student *him=&student2;//������ָ��student2 
//����*him==student2
him->name;//���� 
int swap(const student*s){//ʹ��ָ����� 
	return 2*s->num;	  //const��ҪҲ���� ��const���Է�ֹ�ṹ���Ա��ֵ�ı�
}
int swap(student s){//ʹ�ýṹ����գ��βεĸı䲻Ӱ��ʵ�� 
	return 2*s->num;
student swap(student s){//ʹ�ýṹ����գ����ҷ��ؽṹ�� 
	return s;	  
}
int ans=swap(&student1);//���ݵ�ַ 
 

