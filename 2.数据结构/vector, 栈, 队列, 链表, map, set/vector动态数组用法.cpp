vector-----��̬���� 

//���� 
	//����int������ 
	vector<int>a;//Ĭ�ϳ�ʼ����aΪ�� 
	vector<int>b(a);//��a����b 
	vector<int>a(100);//a��100��ֵΪ0��Ԫ�� 
	vector<int>a(100,6);//a��100��ֵΪ6��Ԫ�� 
	//string������ 
	vector<string>a(10,"null");//a��10��ֵΪnull��Ԫ�� 
	vector<string>a(100,"hello");//a��100��ֵΪhello��Ԫ�� 
	vector<string>b(a.begin(),a.end());//b����a 
	//�ṹ������ 
	struct point {int x,y;};
	vector<point>a;//a�������������� 

//����
	a.push_back(100);//β�����Ԫ��ֵΪ100���� 
	int size=a.size();//����Ԫ�ظ��� 
	bool isempty=a.empty();//�ж��Ƿ�Ϊ�� 
	cout<<a[0]<<endl;//��ӡ��һ��Ԫ�� 
	a.insert(a.begin()+i,k);//�ڵ�i��Ԫ��ǰ�����k
	a.insert(a.begin()+1,6); 
	a.push_back(8);//β�������ֵ8 
	a.insert(a.end(),10,5);//β�����10��5 
	a.pop_back();//ɾ��ĩβԪ�� 
	a.erase(a.begin()+i,a.begin()+j);//ɾ�����䡾i��j-1����Ԫ�� 
	a.erase(a.begin()+2);//ɾ����3��Ԫ��,��ִ��ɾ��������a[2]�Ժ��Ԫ�ض�����ǰ�ƶ�һ�� 
					//ע��a.erase(2);�Ǵ���� 
	a.resize(n)//�����С��Ϊn 
	a.clear();//��� 
	reverse(a.begin(),a.end());//reverse����������ת���� 
	sort(a.begin(),a.end());//sort��С�������� 
	 
	 

