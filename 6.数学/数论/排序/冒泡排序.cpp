//ð������ 
	for(i=0;i<n;i++) scanf("%d",a[i]);
	for(i=0;i<n-1;i++)	//һ��Ҫ����n-1�αȽ� 
		for(j=0;j<n-i-1;j++)//ÿһ�αȽ϶���������������ƶ� 
			if(a[j]>a[j+1]){
				int swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}
	//�Ż��汾
	for(i=0;i<n-1;i++){
		bool issored=true;
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1]){
				issored=false;
		 		int swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}
		if(issored) break;//���δ������������˵���Ѿ��ź����ˣ��˳����� 
	}
//���ӣ��Խṹ���������
//Ϊ�˱����鷳�Ĳ������ɶ����һ�������¼�������±�
	for(int i=0;i<10;i++) am[i]=i;//��ʼ��������±�  
	for(int i=0;i<n-1;i++){
		int good=1; 
		for(int j=0;j<n-i-1;j++){
			if(strcmp(s[am[j]].birth,s[am[j+1]].birth)>0){
				good=0;
				int temp=am[j];//�����±꼴�� 
				am[j]=am[j+1];
				am[j+1]=temp;
			}
		}
		if(good) break;
	}
	for(int i=0;i<n;i++) //��ӡ 
		printf("%s %s %s\n",s[am[i]].name,s[am[i]].birth,s[am[i]].phone);
	
