//读取一行字符串
//cin, 遇到空格或者回车键即停止
char a[50];
string a;
cin>>a;

//gets(),可以无限读取，以回车结束读取，C语言中的函数，在C++中运行会产生bug。
char a[50];
gets(a);

//getline(),若定义变量为string类型，则要考虑getline()函数
string a;
getline(cin,a);

//cin.get(),cin.getline(),可以接收空格，遇回车结束输入
char a[50];
cin.get(a,50);
cin.getline(a,50);
