#include<stdlib.h>//����exit��fopen��fclose����
#include<stdio.h> 
int main()
{
	int num,name[30],sco,av=0;
	FILE *fp; 
	if((fp=fopen("text.txt","w+"))==NULL){//����Ҳ����򷵻ظ�fp NULL 
		printf("NO\n");
		exit(-1);//-1��ʾ�������󣬲�������ûʲô���� 
	}
	fprintf(fp,"fprintf:�տ�ʼ��������%d\n",5);
	fprintf(fp,"putc:�������ַ���");
	char ch='z';
	putc(ch,fp); 
	putc('\n',fp);
	if(fclose(fp)){ //�رճɹ�����0������Ϊ��0 
		printf("Can noy close the file!\n");
		exit(0);
	}	 
}

