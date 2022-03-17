#define sc(a) scanf("%d",&a);
#define ll long long
typedef long long ll; 

ios::sync_with_stdio(false);//关闭流同步 

cin.tie(nullptr);//cin与cout是默认绑定的,这样增加了IO的负担，通过tie(nullptr)来解除 
	//cin和std :: cout之间的绑定，进一步加快执行效率, tie是将两个stream绑定的函数
	//在c++中，nullptr是空指针，NULL是整数0

#define rg register int
for(rg i=0;i<n;i++)
for(register int i=0;i<n;i++)//register 表示使用cpu内部寄存器（寄存器是中央处理器内的组成部分。
//寄存器是有限存贮容量的高速存贮部件）的变量，而平时的int是把变量放在内存中，存到寄存器中可以
//加快变量的读写速度 
