#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    int n,r;//����nתΪr������ 
    while(scanf("%d%d",&n,&r)!=EOF){
        char ans[40];
        int size=0;	//ȷ��ÿ�δ�0��ʼ 
		int f = abs(n);//nΪ���������
        //ȡ�ࡢ��ֵ����� 
		do{	//��while�Ļ������㣬��Ϊ���n==0�Ļ����Ͳ���ѭ���ˣ���ʱ��Ҫ��if�жϲ�ת��     
            int x = f%r;
            ans[size++] = (x<10)? x+'0':x-10+'A';//x+'0'��Ҫ������ת��Ϊ�ַ���x-10+'A'�ǰ�A�ַ���ֵ����Ϊ10 
            f/= r;								   //xС��10�Ǹ������ַ�������10�Ǹ���ĸ 
        }while(f);
        if(n<0)
            ans[size++] = '-';	//���һ��������� 
        for(int i=size-1;i>=0;i--)	//������� 
            printf("%c",ans[i]);
        printf("\n");
    }
}
