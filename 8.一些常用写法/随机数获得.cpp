//srand函数是随机数发生器的初始化函数。
//void srand(unsigned seed); 
//它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的
//随机数，不同的种子会得到 固定 的 不同的随机数序列
//例如： 
/* 
 		 //通过srand（1）和srand（2）设置了不同的随机数种子 
srand(1);//不同的种子会得到 固定 的 不同的随机数序列，这里每次运行都会从41开始，在一次运行中数不断改变 
cout<<rand()<<endl;//41 
cout<<rand()<<endl;//18467 
cout<<rand()<<endl;
*/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));//通过srand（time（NULL））使得随机数种子随时间的变化而变化 
    int ans=rand()*123 %50;//rand()便是获得的”随机数“ ,这里123为随机数种子 
    printf("%d",ans);

}
/*
控住随机数的范围在[l,r]
rand()(*随机数种子)%(r-l+1)+l; //r-l+1==可取的整数个数，求余后加上基数就可以了
[l,r) rand()%(r-l)+l
(l,r] rand()%(r-l)+l+1 
rand()不需要参数，它会返回一个从0到最大随机数的任意整数,rand（）范围是[0,RAND_MAX]
[0.0,1.0] rand()/RAND_MAX
[0.0,1.0) rand()/(RAND_MAX+1)
(int)(10.0*rand() / (RAND_MAX + 1.0)) 取到的数字：0,1,2…9
强制类型转换  乘以10.0把 [0.0,1.0)范围的数变为0-9 
*/
