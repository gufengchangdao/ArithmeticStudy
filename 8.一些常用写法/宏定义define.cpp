 
//无参数宏定义 
#define A 5//正确
#define A=5//虽然语法正确，但预处理器会把A替换为 =5 ，a=A可以但a[A]不可以 
#define C "chian"//就相当于这个字符串
#define N (3*2)//宏定义只做简单的文本替换,故表达式要用括号括起来
//带参数宏定义 
#define swap(a,b){int temp=a;a=b;b=temp;}//语句用{} 
#define check(x,y) (x>=0&&y>=0)//判断用（）
#define max(a,b) (a>b?a:b)//这里的a,b为数，表达式的话要加括号
#define max (a,b) (a>b?a:b)//表达错误，标识符与参数表的左括号之间不能有空格，空格不能随便添 
//取消宏定义 
#undef A	//取消宏定义A 
#undef swap(a,b)	//取消宏定义swap(a,b) 


