struct node{  //����һ���ṹ��node���ڵ㣩
   	int x;
   	int y;
   	int len;   //node����3����Ա����x,y,len
   	bool operator <(const node &a)const {//����<�����������Զ�����nodeʹ��<���������бȽ�
 					//�������const��ʾa�������󲻻ᱻ�޸ģ������const�������ú������󲻻ᱻ�޸�  
    	return len<a.len;
   	}
};

bool operator <(const node &a)const{
	if(len==a.len) return x<a.x;//��len��ȵ�ʱ��x���� 
	else return len<a.len;
}

struct mode{
	char name[25];
	bool operator <(const mode &b)const {
		return strcmp(name,b.name)<=0;
	}
}stu[105];
sort(stu,stu+n);//�����ְ��ֵ������� 
//�����������
//C++��Ԥ�����������Ĳ�������ֻ���ǻ����������͡���ʵ���ϣ���������û��Զ������ͣ������ࣩ��
//Ҳ��Ҫ���Ƶ������������ʱ�ͱ�����C++�����¶�����Щ���������������������µĹ��ܣ�ʹ���ܹ�����
//�ض�����ִ���ض��Ĳ�������������ص�ʵ���Ǻ������أ����ܺ�
//һ���ʽ����ͨ����һ����
//<��������˵����> operator <���������>(<������>){ <������> }
//�����ϵ�������
	bool operator == (const &A){
		return ...;
	} 
	//���������� 
    bool operator != (const A& );
    bool operator < (const A& );
    bool operator <= (const A& );
    bool operator > (const A& );
    bool operator >= (const A& ); 
