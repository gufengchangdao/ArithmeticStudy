//����������ı��ļ���һЩ���� 
#include<stdlib.h>//����exit��fopen��fclose����
#include<stdio.h> 
int main()
{
	int num,name[30],sco,av=0;
	FILE *fp; 
	
	if((fp=fopen("text.txt","w+"))==NULL){
		printf("NO\n");
		exit(-1);//-1��ʾ�������󣬲�������ûʲô���� 
	}
	
	fprintf(fp,"fprintf:�տ�ʼ��������%d\n",5);
	
	fprintf(fp,"putc:�������ַ���");
	char ch='z';
	putc(ch,fp); 
	putc('\n',fp);
	
	char op1[40]={"fputs:"},*op2="���ɶҲ������",op3[3]="\n";
	fputs(op1,fp);
	fputs(op2,fp);
	fputs(op3,fp);

	rewind(fp);
	char que1[40];
	fscanf(fp,"%s",que1);
	printf("%s\n",que1);
	
	char que2[40],tem;
	int cnt=0;
	tem=getc(fp);//ǰ���Ѿ��������ˣ��Ե�������з� 
	tem=getc(fp);
	while(tem!='\n'){
		que2[cnt++]=tem;
		tem=getc(fp);
	}
	for(int i=0;i<cnt;i++) putchar(que2[i]);
	putchar('\n');
	
	char que3[21];
	fgets(que3,21,fp);//�����й���20���ֽڣ���21���ö���20���ֽ� 
	printf("%s\n",que3);
	
	printf("��ȡ��ǰ��λ�ã�%d\n",ftell(fp)); 
	
	rewind(fp);
	printf("��rewind�������ؿ�ͷ��%d\n",ftell(fp));
	
	fseek(fp,2L,0); 
	printf("�ӿ�ͷ����ƫ��2��%d\n",ftell(fp));
	printf("�ӵ�ǰλ��������ַ������������ַ���");
	putchar(getc(fp));putchar('\n'); 
	
	fseek(fp,10L,1);
	printf("�ӵ�ǰ����ƫ��10�����ֶ���1�ɣ�%d\n",ftell(fp));
	
	fseek(fp,0,2);
	printf("ָ���ļ�ĩβ��%d\n",ftell(fp));
	
	printf("��ferror���һ�£�");	 
	if(!ferror(fp)) printf("��ϲ�㣬��Ķ�д���޴����������\n"); 
	
	if(fclose(fp)){ //�رճɹ�����0������Ϊ��0 
		printf("Can noy close the file!\n");
		exit(0);
	}	 
}

