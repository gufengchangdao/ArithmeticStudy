//n=dk*b^k+d(k-1)*b^(k-1)+d(k-1)*b^(k-1)+...+d1*b+d0; 

//�����鴢��ÿһλ��������� 
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

//���õݹ飬�ȵݹ鵽���λ���ٲ������ 
void print(int n){
	if(n<k){	 
		if(n>9) //��AΪ10 
			printf("%c",n+'A'-10);
		else 
			printf("%d",n);		
	}
	else{//�����ֹһλ 
		print(n/k);//һֱ�ݹ鵽���λ�������λ��ʼ��� 
		print(n%k);//ǰһλ�����xȡ���ټ������ 
	}
} 
