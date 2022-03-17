//检测作用于文本文件的一些函数 
#include<stdlib.h>//调用exit、fopen和fclose函数
#include<stdio.h> 
int main()
{
	int num,name[30],sco,av=0;
	FILE *fp; 
	
	if((fp=fopen("text.txt","w+"))==NULL){
		printf("NO\n");
		exit(-1);//-1表示程序有误，不过这里没什么区别 
	}
	
	fprintf(fp,"fprintf:刚开始来个数：%d\n",5);
	
	fprintf(fp,"putc:再来个字符：");
	char ch='z';
	putc(ch,fp); 
	putc('\n',fp);
	
	char op1[40]={"fputs:"},*op2="最后啥也不来了",op3[3]="\n";
	fputs(op1,fp);
	fputs(op2,fp);
	fputs(op3,fp);

	rewind(fp);
	char que1[40];
	fscanf(fp,"%s",que1);
	printf("%s\n",que1);
	
	char que2[40],tem;
	int cnt=0;
	tem=getc(fp);//前面已经换过行了，吃掉这个换行符 
	tem=getc(fp);
	while(tem!='\n'){
		que2[cnt++]=tem;
		tem=getc(fp);
	}
	for(int i=0;i<cnt;i++) putchar(que2[i]);
	putchar('\n');
	
	char que3[21];
	fgets(que3,21,fp);//第三行共有20个字节，填21正好读入20个字节 
	printf("%s\n",que3);
	
	printf("读取当前的位置：%d\n",ftell(fp)); 
	
	rewind(fp);
	printf("用rewind函数返回开头：%d\n",ftell(fp));
	
	fseek(fp,2L,0); 
	printf("从开头向右偏移2：%d\n",ftell(fp));
	printf("从当前位置输出个字符，即第三个字符：");
	putchar(getc(fp));putchar('\n'); 
	
	fseek(fp,10L,1);
	printf("从当前向右偏移10，发现多了1吧：%d\n",ftell(fp));
	
	fseek(fp,0,2);
	printf("指向文件末尾：%d\n",ftell(fp));
	
	printf("用ferror检测一下：");	 
	if(!ferror(fp)) printf("恭喜你，你的读写毫无错误，你真棒！\n"); 
	
	if(fclose(fp)){ //关闭成功返回0，否则为非0 
		printf("Can noy close the file!\n");
		exit(0);
	}	 
}

