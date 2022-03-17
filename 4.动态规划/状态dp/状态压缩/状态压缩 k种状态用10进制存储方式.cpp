/*
验证用十进制数n存储若干个最多有r种构成的状态 
比如有8种状态的3个变量3 7 2，普通存为372，以八进制化为十进制的话：3*8^2+7*8^1+2*8^0=250,数变小了 
	用快速幂存储 r次方的结果，不取模，但小心爆掉
	第k位转化mi：int m=n/powermod(r,k-1)%r;		第k位的r进制数m 
			n+powermod(r,k-1)*(mi-m)			n-r^m+r^mi	
*/			 
#include<stdio.h>
#include<math.h>
using namespace std;
int mi[1000]={1};	//mi[i]存储a^i的结果，小心爆掉，注意：a^0=1，这个一定要赋值 

int powermod(int a,int b) //求a^b 这里a,b都大于0 
{ 
    if(b==1) return a; 	//递归边界 
    if(mi[b]!=0) return mi[b];		
	 
    int s=(powermod(a,b/2)*powermod(a,b/2)); 
    if(b&1) s=s*a; //b是奇数的时候，s还少乘个a 
    return mi[b]=s; //路径压缩 
}

int main()
{
	int n,r;
			
	while(printf("十进制的数和要转换的进制：\n")&&scanf("%d%d",&n,&r)!=EOF){
        char ans[40];
        int size=0; 
		int f = abs(n);
        //取余、赋值、相除 
		do{	    
            int x = f%r;
            ans[size++] = (x<10)? x+'0':x-10+'A';
            f/= r;					 
        }while(f);
        if(n<0)
            ans[size++] = '-';
        for(int i=size-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
        int k,mi;
        //关键部分 
        printf("要修改的位数和修改值：\n");
    	scanf("%d %d",&k,&mi);
    	int m=n/powermod(r,k-1)%r;//取出这一位数m 
    	printf("转换后的十进制数：\n%d\n\n",n+powermod(r,k-1)*(mi-m));	//再加上这一位 
	}
}
