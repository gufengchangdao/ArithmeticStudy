字符串比较函数 
	//从左到右逐个字符进行比较（ASCII值），直到出现不同的字符或遇到'\0'为止。
	int k=strcmp(a,b); 
	int k=strncmp(a,b,4);//只比较前四个字符 
	int k=strncmp(a+i,b+j,4);//从a[i],b[j]开始比较 
