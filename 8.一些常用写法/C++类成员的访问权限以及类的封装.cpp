C++���Ա�ķ���Ȩ���Լ���ķ�װ

public   protected  private �����ؼ��������Ƴ�Ա�����ͳ�Ա�����ķ���Ȩ�ޣ��ֱ��ʾ
���еġ��ܱ����ġ�  ˽�еģ�����Ϊ��Ա�����޶�������ν����Ȩ�ޣ��������ܲ���ʹ�ø����еĳ�Ա��
	������ڲ���������Ĵ����ڲ��������۳�Ա������Ϊ public��protected ���� private�����ǿ��Ի�
����ʵģ�û�з���Ȩ�޵����ơ�����Ȳ�д private Ҳ��д public����Ĭ��Ϊ private�� 
	������ⲿ��������Ĵ���֮�⣩��ֻ��ͨ��������ʳ�Ա������ͨ������ֻ�ܷ��� public ���Եĳ�Ա��
���ܷ��� private��protected ���Եĳ�Ա�� 
#include <iostream>
using namespace std;

//�������
class Student{
private:  //˽�е�
    char *m_name;
    int m_age;
    float m_score;

public:  //���е�
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
//��Ա�����Ķ���
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
    cout<<m_name<<"��������"<<m_age<<"���ɼ���"<<m_score<<endl;
}

int main(){
    //��ջ�ϴ�������
    Student stu;
    stu.setname("С��");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();
	//printf("%d",stu.m_age);����ֱ�ӷ��� 
    //�ڶ��ϴ�������
    Student *pstu = new Student;
    pstu -> setname("�");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();

    return 0;
}

��װ��
��ν��װ����ָ������������ڲ�ʵ�֣�ֻ���û��ṩ���õĳ�Ա������ 
	�����Ⱪ¶�Ľӿڣ���ͨ��������ʵĳ�Ա��������Ϊ public
	
����ͨ��������õĳ�Ա��������Ϊ public��һЩ���õĳ�Ա������
	��get��ͷ�ĺ������ڶ�ȡ��Ա������ֵ
	��set��ͷ�ĺ������ڸ���Ա������ֵ
	...
��ϣ���ⲿ֪��������ֻ�����ڲ�ʹ�õġ����߶��ⲿû��Ӱ��ĳ�Ա������������Ϊ private��
	ʵ����Ŀ�����еĳ�Ա�������ⲿ����ֱ�ӵ��õ� 
	ֻ�����ڲ�ʹ�õĳ�Ա������ֻ����Ա�������õĳ�Ա������
	...
����Ϊ protected �ĳ�Ա������Ҳ����ͨ��������ʣ������������������ڲ����Է���






