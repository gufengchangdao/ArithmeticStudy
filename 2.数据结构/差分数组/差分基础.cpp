#include<bits/stdc++.h>
#define ll long long
#define m=1e5*10
#define mem(a,b) memset(a,b,sizeof(a))	//定义memset的缩写 
using namespace std;
const int inf=0x3f3f3f3f;	//const是定义的意思 ,这里定义极大数 
const int mm=1e5+10;

int a[mm],b[mm];//a[mm]记录改变值 
int x,y;
int main()
{
    int n;
    while(scanf("%d",&n)&&n){ //输入n且n不为0就执行 
        mem(a,0);	//mem是memset的缩写 
        mem(b,0);
        
        for(int i=1;i<=n;i++){	 //将修改值储存起来 
            scanf("%d%d",&x,&y);
            b[x]++;		//b+=change 
            b[y+1]--;	// b-=change 
        }
        
        for(int i=1;i<=n;i++)	 //修改x到y的数 
            a[i]=a[i-1]+b[i];	//b[i]==b[x]时，每一项都会加上b[x]加上的数 
       
        for(int i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
