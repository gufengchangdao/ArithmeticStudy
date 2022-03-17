/*
C语言是没有自己的窗口的，比如我们用printf函数在黑框上输出Hello World是其实是调用了windows的DOS交互
	窗口。我们在C语言程序中用system可以给操作系统发送指定，其作用与直接在DOS窗口发送指令进行交互效
	果是一样的。
system的参数是字符串,且命令不区分大小写 
int system( const char *command );
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	system("mode con lines=30 cols=100");//窗口高度宽度  
	system("color 0f");	//改变DOS窗口的颜色
//	用 system("color 0A"); 第一个是背景色代号，第二个是前景色代号。各颜色代码如下：
//　　	0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色 
//		A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色 
	system("date /T"); //打印一行年月日、星期，会自动换行，不用手动换行，没有/T就是修改电脑日期 
	system("time /T"); //打印时间 
//	system("copy bai.txt");	//显示文本文件的内容 
//	system("pause");	//按任意键继续，防止闪屏 
//	system("\"C:\\jbc\\最短路题目 别人的.exe\"");//运行可执行文件
//	C:\jbc
//	system("cls");	//清屏 
//	system("title 菜的抠脚");	//改变窗口的标题 
//	system("notepad");	//打开一个记事本(新的)
//	system("calc");	//打开计算器 
//	system("QQ"); //打开QQ
	/* 
	我们的电脑上存在一个格式为exe的notepad文件和计算器。并且系统 默认的为其配置了全局环境变量 。那
	么我们就可以在DOS发出指令，系统将会回应打开这个文件和计算器。只有 配置了全局环境变量的exe文件
	才能这样打开。QQ要预先配置好的配置全局环境变量(虽然我不会)
	*/
//	system("白.bat"); //bat批处理命令
	/*
	这里有一个文件名为 白.bat 的bat文件，与cpp放在一起的时候，在白用记事本打开编辑，每行一个命令，
		可以批量处理命令，注意编辑输入的只是双引号中的内容 
	*/
//	system("\"c:a.bat\""); 也可以是绝对路径，c:a.bat 
//	char cmd[20]="shutdown -s -t ",t[5]; 
//	puts("输入关机时间："); 
//	scanf("%s",t);
//	system(strcat(cmd,t));	//调用函数将关机命令和时间的字符串拼在一起,t秒后关闭计算机 
//	system("shutdown -s -t 60");	60秒后关闭计算机 
//	system("shutdown -p");	//立即关闭计算机，和system("shutdown -s -t 0")等效 
//	system("shutdown -l");	//注销计算机
//	system("del d:\123.txt");// 删除文件，文件路径为 d:\123.txt 
	return 0;
}



