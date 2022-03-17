//n=dk*b^k+d(k-1)*b^(k-1)+d(k-1)*b^(k-1)+...+d1*b+d0; 

//用数组储存每一位，倒叙输出 
	while(~scanf("%d",&n)){
		int a[20];
		int q=n,k=0;
		while(q!=0){
			a[k++]=q%4;
			q=q/4;
		}
		for(int i=k-1;i>=0;i--)
			printf("%d",a[i]);
	}
}

//利用递归，先递归到最高位，再不断输出 
void print(int n){
	if(n<k){	 
		if(n>9) //以A为10 
			printf("%c",n+'A'-10);
		else 
			printf("%d",n);		
	}
	else{//输出不止一位 
		print(n/k);//一直递归到最高位，从最高位开始输出 
		print(n%k);//前一位输出后将x取余再继续输出 
	}
} 
