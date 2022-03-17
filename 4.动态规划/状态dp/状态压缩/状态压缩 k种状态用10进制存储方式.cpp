/*
��֤��ʮ������n�洢���ɸ������r�ֹ��ɵ�״̬ 
������8��״̬��3������3 7 2����ͨ��Ϊ372���԰˽��ƻ�Ϊʮ���ƵĻ���3*8^2+7*8^1+2*8^0=250,����С�� 
	�ÿ����ݴ洢 r�η��Ľ������ȡģ����С�ı���
	��kλת��mi��int m=n/powermod(r,k-1)%r;		��kλ��r������m 
			n+powermod(r,k-1)*(mi-m)			n-r^m+r^mi	
*/			 
#include<stdio.h>
#include<math.h>
using namespace std;
int mi[1000]={1};	//mi[i]�洢a^i�Ľ����С�ı�����ע�⣺a^0=1�����һ��Ҫ��ֵ 

int powermod(int a,int b) //��a^b ����a,b������0 
{ 
    if(b==1) return a; 	//�ݹ�߽� 
    if(mi[b]!=0) return mi[b];		
	 
    int s=(powermod(a,b/2)*powermod(a,b/2)); 
    if(b&1) s=s*a; //b��������ʱ��s���ٳ˸�a 
    return mi[b]=s; //·��ѹ�� 
}

int main()
{
	int n,r;
			
	while(printf("ʮ���Ƶ�����Ҫת���Ľ��ƣ�\n")&&scanf("%d%d",&n,&r)!=EOF){
        char ans[40];
        int size=0; 
		int f = abs(n);
        //ȡ�ࡢ��ֵ����� 
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
        //�ؼ����� 
        printf("Ҫ�޸ĵ�λ�����޸�ֵ��\n");
    	scanf("%d %d",&k,&mi);
    	int m=n/powermod(r,k-1)%r;//ȡ����һλ��m 
    	printf("ת�����ʮ��������\n%d\n\n",n+powermod(r,k-1)*(mi-m));	//�ټ�����һλ 
	}
}
