//��ȡһ���ַ���
//cin, �����ո���߻س�����ֹͣ
char a[50];
string a;
cin>>a;

//gets(),�������޶�ȡ���Իس�������ȡ��C�����еĺ�������C++�����л����bug��
char a[50];
gets(a);

//getline(),���������Ϊstring���ͣ���Ҫ����getline()����
string a;
getline(cin,a);

//cin.get(),cin.getline(),���Խ��տո����س���������
char a[50];
cin.get(a,50);
cin.getline(a,50);
