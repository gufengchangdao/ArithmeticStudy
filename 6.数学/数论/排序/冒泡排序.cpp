//冒泡排序 
	for(i=0;i<n;i++) scanf("%d",a[i]);
	for(i=0;i<n-1;i++)	//一定要进行n-1次比较 
		for(j=0;j<n-i-1;j++)//每一次比较都把相比最大的往后移动 
			if(a[j]>a[j+1]){
				int swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}
	//优化版本
	for(i=0;i<n-1;i++){
		bool issored=true;
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1]){
				issored=false;
		 		int swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}
		if(issored) break;//如果未发生交换，则说明已经排好序了，退出即可 
	}
//例子：对结构体进行排序
//为了避免麻烦的操作，可定义的一个数组记录排序后的下标
	for(int i=0;i<10;i++) am[i]=i;//初始化排序的下标  
	for(int i=0;i<n-1;i++){
		int good=1; 
		for(int j=0;j<n-i-1;j++){
			if(strcmp(s[am[j]].birth,s[am[j+1]].birth)>0){
				good=0;
				int temp=am[j];//交换下标即可 
				am[j]=am[j+1];
				am[j+1]=temp;
			}
		}
		if(good) break;
	}
	for(int i=0;i<n;i++) //打印 
		printf("%s %s %s\n",s[am[i]].name,s[am[i]].birth,s[am[i]].phone);
	
