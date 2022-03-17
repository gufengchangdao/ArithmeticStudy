#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    int n,r;//数字n转为r进制数 
    while(scanf("%d%d",&n,&r)!=EOF){
        char ans[40];
        int size=0;	//确保每次从0开始 
		int f = abs(n);//n为负数的情况
        //取余、赋值、相除 
		do{	//用while的话不方便，因为如果n==0的话，就不会循环了，此时还要有if判断并转化     
            int x = f%r;
            ans[size++] = (x<10)? x+'0':x-10+'A';//x+'0'是要把整形转化为字符；x-10+'A'是把A字符的值定义为10 
            f/= r;								   //x小于10是个数字字符，大于10是个字母 
        }while(f);
        if(n<0)
            ans[size++] = '-';	//最后一项添个负号 
        for(int i=size-1;i>=0;i--)	//倒叙输出 
            printf("%c",ans[i]);
        printf("\n");
    }
}
