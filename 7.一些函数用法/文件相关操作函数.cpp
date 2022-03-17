//读取文件数据步骤：
	//定义文件指针
	//打开文件
	//文件处理 
	//关闭文件
文本文件
二进制文件：无法用记事本等工具建立或查看，因此比文本文件更安全，
	且读写效率更高，因为不必把数据和字符做转换 
顺序文件；数据记录长度不是完全一致的
随机文件：文件中单个记录的长度固定，访问速度快，可以调用一个用记录关键字做参数的函数计算某个记录
	相对于文件开头的位置 
一、定义文件指针
FILE *fp1,*fp2;

二、打开文件
fp1=fopen("text.txt","r");//调用成功,fp就指向fp1,否则返回为NULL
fp=fopen("c:\\temp.txt","r");//C语言中 '\'一般是转义字符的起始标志,单斜杠是没办法读入的，要"\\"
	//   "路径" + "文件名" + "." + "后缀"  , "文件打开模式"
fp=fopen("c:/temp.txt","r");//用'/'代替也可以 
fp=fopen("temp.txt","r");//可以用E:\\显示的指出绝对路径，若没有指出则默认当前路径，即与cpp在同一个目录下
if((fp1=fopen("text.txt","r"))==NULL){	//先判断一下 
	printf("Cannot open this file\n");
	exit(-1);//-1表示程序有误，不过这里没什么区别 
		//return(-1); 
		//return(0);return 是退出当前函数，返回函数值，把控制权交给调用函数
		//exit(0);exit用于结束正在运行的整个程序，它将参数返回给OS，把控制权交给操作系统
}

最常用的文件使用方式及其含义如下:
1,"r".为读而打开文本文件.(不存在则出错)
2,"w".为写而打开文本文件.(若不存在则新建,反之,则从文件起始位置写,原内容将被覆盖)
3,"a".为在文件后面添加数据而打开文本文件.(若不存在,则新建;反之,在原文件后追加)
4,"r+".为读和写而打开文本文件.(读时,从头开始;在写数据时,新数据只覆盖所占的空间,其后不变)
5,"w+".首先建立一个新文件,进行写操作,随后可以从头开始读.(若文件存在,原内容将全部消失)
6,"a+".功能与"a"相同;只是在文件尾部添加新的数据后,可以从头开始读.
7,"rb".为读而打开二进制文件.
8,"wb".为写而打开二进制文件.
9,"ab".为在文件后面添加数据而打开一个二进制文件.
10,"rb+".为读和写而打开二进制文件.只是在随后的读写时,可以由位置函数设置读和写的起始位置.
11,"wb+".功能与"w+"同.只是在随后的读写时,可以由位置函数设置读和写的起始位置.
12,"ab+".功能与"a+"相同;只是在文件尾部添加新数据之后,可以由位置函数设置开始读的起始位置.

三、关闭文件
if(fclose(fp1)){ //关闭成功返回0，否则为非0 
	printf("Can noy close the file!\n");
	exit(0);
} 
 
四、输入、输出函数 
文本文件存储的数据都是ACSII码字符文本

1.字符方式文件读写函数 getc()、putc() 逐个字符地进行文件读写 
char ch;
putc(ch,fp1);输出一个字符
	小心空格和换行的无意识插入 
	将字符ch写到文件指针fp所指的文件中去.当输出成功,putc函数返回所输出的字符;
		否则,返回一个EOF值.EOF是在stdio.h库函数文件中定义的符号常量,其值等于-1. 

int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("text.txt","w"))==NULL){
		printf("Cannot open this file\n");
		exit(0);
	}
	ch=getchar();
	while(ch!='@'){
		if(ch!='\n') putc(ch,fp);//这里读入换行的话就不输出到文件里 
		ch=getchar(); 
	}
	fclose(fp);
}	
ch=getc(fp1);//从fp1指定的文件中读取一个字符,并把它作为函数值返回
int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("text.txt","r"))==NULL){
		printf("Cannot open this file\n");
		exit(0);
	}
	ch=getc(fp);
	while(ch!=EOF){ //EOF的值为-1 
		putchar(ch); 
		ch=getc(fp);
	}
	fclose(fp);
}
	
//将源文件的内容复制到目标文件中	
void filecopy(FILE *fpin,FILE *fpout) 
{			//	源文件     目标文件 
	char ch;
	ch=getc(fpin);//每次调用函数后，fpin会自动向后移动一个位置 
	while(!feof(fpin)){	//判断文件是否结束 
		putc(ch,fpout);
		ch=getc(fpin);
	}
}
int main()
{
	FILE *fpin,*fpout;
	if((fpin=fopen("text1.txt","r"))==NULL){	//text1文件只读 
		printf("Cannot open this file\n");
		exit(0);
	}
	if((fpout=fopen("text2.txt","w"))==NULL){	//text2文件只写，这文件没有也会自己创建 
		printf("Cannot open this file\n");
		exit(0);
	}
	filecopy(fpin,fpout);//传入的时候文件指针不用加&
	fclose(fpin);
	fclose(fpout);
}

2.格式化文件读写函数 fscanf函数和fprintf函数
fscanf(fp,"%d%d",&a,&b);//fscanf返回的是实际读取的数据个数，出错或者到结尾返回EOF
fprintf(fp,"%d %d\n",a,b);  	

3.字符串方式文件读写函数 fgets函数和fputs函数
fgets(str,n,fp);从fp所指文件中读入n-1个字符放入str为起始地址的空间内， 
	达到指定个数、遇到换行符或一个EOF结束本次读操作，在字符串后面自动添加'\0' 
fputs(str,fp);把字符串str输出到文件中
这里的str可以是字符数组名，字符型指针变量，字符串常量，字符串的'\0'不写入文件，执行成功会返回所
	写的最后一个字符，否则返回EOF 
注意:为了便于读入,在输出字符串时,应当人为的加诸如"\n"这样的字符串.

int main()
{
	char a[15],c;
	char *b="zhang chao";//表示b指向这个字符串的首地址 
	FILE *fp;
	if((fp=fopen("text.txt","w+"))==NULL){	//读写 
		printf("Cannot open this file\n");
		exit(0);
	}
	fputs(b,fp);	//把b输出到文件中 
	rewind(fp);		//rewind将文件指针重新指向一个流的开头
	fgets(a,15,fp);	//把文件中的14个字符输入到数组a中，第15位补'\0' 
	printf("%s",a);
	fclose(fp);
}

4.数据块方式文件读写函数 fread()、fwrite()
可以读写一组数据，一般是一个数组元素、一个结构体变量的值，多用于读写二进制文件 
fread(buffer,size,count,fp);从二进制文件中读入一个数据块到变量中,返回的是成功有效的读取的item元素的个数 
fwrite(buffer,size,count,fp); 向二进制文件中写入一个数据块 
	buffer为一个指针，在fread中表示存放数据的首地址，在fwrite中表示存放输出数据的首地址
 	size表示数据块的字节数，count表示要读写的数据块数，fp表示文件指针 

int t=0;将文件中将每个结构体数据存入结构体数组中 
while(!feof(fp)){
	fread(&str[i],sizeof(struct node),1,fp);
	t++;
}

五、其他相关函数
每一次成功操作都会改变文件指针的位置
与文件定位有关的函数：rewind()、fseek()、ftell()
重定位文件首函数rewind()
	rewind(fp);  
	重新指向读写文件的首地址,注意：首地址不是指文件的开头 
	w、r方式打开的返回文件开头 
	a 方式打开的返回原文件后面，即原文件末尾
	建议不要随便用rewind(),并且操作一次文件就打开、关闭各执行一次 
指针移动控制函数fseek()
	fseek(fp,offset,from)
	offset表示移动偏移量，应该为long型数据，使用常量是，应加上'L',可正可负，正表示向后偏移，负表
	示向前偏移，from表示从哪个位置开始偏移，文件首部、当前位置、文件尾部
								对应常数：     0         1          2 
								对应常量： SEEK_SET    SEEK_CUR	 SEEK_END
	fseek(fp,20L,0)将文件位置指针移动到离文件首20字节处 
	fseek(fp,-20L,SEEK_END) 将文件位置指针移动到离文件尾部前20字节处 
获取指针当期位置指针ftell()
	ftell()获取相对于文件开头的位移量，文件出错的时候返回-1L，也可以用来测量一个文件的长度 
	int len=ftell(fp);//返回给定流 stream 的当前文件位置,按字节算的
	fseek(fp,0,SEEK_SET);
	int len=ftell(fp);//len=0
	fseek(fp,0,SEEK_END);
	int len=ftell(fp);//len=文件中所有字节之和

检测文件指针状态的函数：feof()、ferror()、clearerr()
文件末尾检测函数feof()
	feof(fp);判读文件是否读到了文件结束的位置,是返回1，否返回0 
	if(fp!=EOF)	EOF可以作为文本文件的结束 标志,但不能作为二进制文件的结束符.
	if(!feof(fp)) feof函数既可以判断二进制文件,又可以判断文本文件.	
读写错误检查函数ferror()
	检查文件在用各种输入输出函数进行读写时是否出错 
	ferror(fp); 未出错返回0，否则有错
出错标记清除函数clearerr()
	clearerr(fp);清除出错标志和文件结束标志，使它们值为0

注意，关于用while(!feof(fp))从文件中读入数据会出现的问题 
	fgetc()读取文件的最后一个字符以后，C语言的feof()函数依然返回0，表明没有到达文件结尾；只有当fgetc()向后再读取一个字符（即越过最后一个字符），feof()才会返回一个非零值，表示到达文件结尾。
	所以，按照上面这样写法，如果一个文件含有n个字符，那么while循环的内部操作会运行n+1次。
	while(!feof(fp)){
		//因为不能完全依赖feof判断文件是否到结尾，所以用fgetc的返回值来判断，
		//当读取到结尾时，feof实际并没有获得到达结尾的信息，所以这里用fgetc继续读取一个字符，来判断是否结束
		//如果不是-1（结尾），那么回退一个文件位置，如果是-1，退出
		c = fgetc(fp);
		if (c != -1)
			fseek(fp, -1, 1);
		else break;
	...
	}
	int a=fscanf()
	if(a==-1) break;//fscanf返回的是实际读取的数据个数，出错或者到结尾返回EOF

	int a=fread()
	if(a==0) break;//返回0表示读取数量不够size字节，究竟是多少不知道
	
	int a=fread(&log,size,1,fp);//课本上采用的，先读入一个，每次在循环末尾才再读入一个 
	while(!feof(fp)){
		...//操作 
		fread(&log,size,1,fp);
	}

/*	 
试用：
	cpp:文件一些函数的测试 
*/ 
	
