#include<stdlib.h>//调用exit、fopen和fclose函数
#include<stdio.h> 
int main()
{
	int num,name[30],sco,av=0;
	FILE *fp; 
	if((fp=fopen("text.txt","w+"))==NULL){//如果找不到则返回给fp NULL 
		printf("NO\n");
		exit(-1);//-1表示程序有误，不过这里没什么区别 
	}
	fprintf(fp,"fprintf:刚开始来个数：%d\n",5);
	fprintf(fp,"putc:再来个字符：");
	char ch='z';
	putc(ch,fp); 
	putc('\n',fp);
	if(fclose(fp)){ //关闭成功返回0，否则为非0 
		printf("Can noy close the file!\n");
		exit(0);
	}	 
}

