����һ��C++�ַ���
	string s;    //����һ�����ַ���s
    string s(str) //�������캯�� ����str�ĸ���Ʒ
    string s(str,pos) //���ַ���str�ڡ�ʼ��λ��pos���Ĳ��ֵ����ַ����ĳ�ֵ
    string s(str,pos,len) //���ַ���str�ڡ�ʼ��pos�ҳ��ȶ���len���Ĳ�����Ϊ�ַ����ĳ�ֵ
    string s(c) //��C�ַ�����Ϊs�ĳ�ֵ
    string s(c,len) //��C�ַ���ǰlen���ַ���Ϊ�ַ���s�ĳ�ֵ
    string s(len,c) //����һ���ַ���������len��c�ַ�
    string s(beg,end) //������beg;end(������end)�ڵ��ַ���Ϊ�ַ���s�ĳ�ֵ
    s.~string() //���������ַ����ͷ��ڴ�

�ַ�����������
 =,assign()     //������ֵ
	string s,str="iamangel";
	s.assign(str); //��˵
	s.assign(str,1,3);//��str[1]��ʼ������Ϊ3���ַ�������s,���ǰѡ�ama�������ַ���
	s.assign(str,2,string::npos);//���ַ���str������ֵ2��ʼ����β����s
	s.assign("gaint"); //��˵
	s.assign("nico",10);//�Ѵӵ�һ����ʼ����Ϊ10���ַ��������ѡ�n�� ��I�� ��c�� ��o�� ��/0�������ַ���
	s.assign(5,'x');//�����x�����ַ�������s="xxxxx" 
	
swap()     //���������ַ���������

+=,append(),push_back() //��β������ַ�

����ַ��� 
	s.erase() //ɾ���ַ�
	s.clear() //ɾ��ȫ���ַ�
	s=""; 

�����ַ� 
	string s,str="iamangel";
	s+=str;//�Ӹ��ַ���
	s+="my name is jiayp";//�Ӹ�C�ַ���
	s+='a';//�Ӹ��ַ��������š�˫���Ŷ����� 
	s.append(str);	//����str 
	s.append(str,1,3);//�������� ͬǰ��ĺ�������assign�Ľ���
	s.append(str,2,string::npos);//��������
	s.append("my name is jiayp");
	s.append("nico",5);
	s.append(5,'x');
	s.push_back('a');//�ѵ����ַ�����β���������ֻ�����ӵ����ַ���STL��Ϥ����������ܼ�
	s.insert(0,"zhangchao");//����s[0]�ĺ��棬insert֧��������λ�üӣ�ע�⣬�����ǵ����ַ�ҲҪ��˫���� 
    s.insert(1,str);	//����s[1]�ĺ��� 


==,!=,<,<=,>,>=,compare()    //�Ƚ��ַ��������ڷ���1�����ڷ���0��С�ڷ���-1 
	string s1="zhangchao",s2="hello";
	s1.compare("hello word"); s��1"hello world"�Ƚ� 
	s1.compare(s2);			 s1��s2�Ƚ� 
	s1.compare(2,3,s2,2,4); (pos1,len1,s2,pos2,len2) 
				//��s1��s1[po1]��ʼ����Ϊlen1���ַ�����s2[po2]��ʼ����Ϊlen2���ַ����Ƚ� 
	s1.compare(2,3,"hello",2,4);	"a"��"llo"�Ƚ� 
	s1.compare(0,3,"hello",4);	Ĭ��Ϊǰ��λ ��"zha"��"hell"�Ƚ� 

ɾ������
	s.erase(5);	//��s[5]��ʼ���ɾ�� 
	s.erase(5,9);	//��s[5]��ʼɾ��9���ַ� 
	s.erase(); 	//����ַ���

�ַ����滻����
	s.replace(1,3,"name");�Ѵ�1��ʼ����Ϊ3���ַ����滻Ϊ"name" 
 
�����ַ�����
	s.size()
	s.length()   

	max_size() //�����ַ��Ŀ���������
	empty()    //�ж��ַ����Ƿ�Ϊ��
	capacity() //�������·���֮ǰ���ַ�����
	reserve() //����һ�����ڴ�������һ���������ַ�
	
[ ], at() //��ȡ��һ�ַ�
	string Str("string");
	cout<<Str[3];      //ok
	cout<<Str.at(3);    //ok
	cout<<Str[100]; //���±�>=s.length()��ʱ�� ������δ�������Ϊ,��Ч
//	Str.at(100);    //���ú�[]һ������������ʱ������ throw out_of_range�쳣����ʾ���� 
//	Str[Str.length()];    //δ������Ϊ����Ч���������Str��const string ���͵�ʱ�򣬷���'/0'
//	Cstr.at(str.length()); //�쳣�� ���Str��const string ���͵�ʱ�򣬲��᷵��'/0'

	>>,getline() //��stream��ȡĳֵ
	<<    //��ıֵд��stream
	copy() //��ĳֵ��ֵΪһ��C_string
	c_str() //��������C_string����
	data() //���������ַ�������ʽ����

�ַ���ȡ����
	a.substr()  ��������a
	a.substr(1) ��a[1]��ʼ
	a.substr(0,5) ��a[0]��ʼ����ȡ5���ַ�
	a.substr(pos,len) ��ȡ��s[pos,pos+len)���ַ���
		ע�⣺pos����s�ĳ��Ȼ�����쳣������len+pos����s���Ȳ����쳣��ֻ���pos��ʼ��ȡ�� 


v)���Һ���
	s.find();���� 

	begin() end() //�ṩ����STL�ĵ�����֧��
	rbegin() rend() //���������
	get_allocator() //����������

