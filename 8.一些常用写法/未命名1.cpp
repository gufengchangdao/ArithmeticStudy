
class Student{	class �ؼ���  Student	�������,Ϊ����������ĸһ���д 
public:
    //��Ա����	 
    char *name;
    int age;
    float score;

    //��Ա����
    void say(){
        cout<<name<<"��������"<<age<<"���ɼ���"<<score<<endl;
    }
};
	��ĳ�Ա����Ա��������Ա���� 
	��ֻ��һ��ģ�壬�����ռ���ڴ�ռ䣬�����ڶ�����ʱ���ܶԳ�Ա�������г�ʼ������Ϊû�еط���
�����ݡ�ֻ���ڴ��������Ժ�Ż����Ա���������ڴ棬���ʱ��Ϳ��Ը�ֵ�ˡ�

Student zhangchao;	��������Ҳ����class Student zhangchao; 
Student allstu[100];
zhangchao.age=20;	��ֵ 
Student *stu=new Student;	�����ڴ� 
Student *stu=&zhangchao;	ָ��ָ����
	ʹ�� new �ڶ��ϴ��������Ķ����������ģ�û��ֱ��ʹ�ã�����Ҫ��һ��ָ��ָ����
	new��deleteֻ���ڶ��ϲ�������ʱɾ�����ö��󣬷�ֹ�����ڴ�ѻ�
	
 

 






