//�ÿ���չ�� ���� ��3������9�Ľ׳˴�С��״̬ 
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//0-n�Ľ׳� 
bool cantor(int str[],int n)//״̬��Ԫ�ظ��� 
{
	long result=0;//result��¼ʱ�ڶ�����״̬ 
	for(int i=0;i<n;i++){	//�жϱ�str[]С�����еĸ������ж����� 
		int sum=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j]) sum++;
		result+=sum*factory[n-i-1];//����=�ȵ�ǰλС�����ĸ���*δ�̶������Ľ׳� 
	}
	//�жϸ�״̬�Ƿ񱻱�ǹ� 
	if(visted[result]) return 0;
	visted[result]=1;//��ǲ�����true 
	return 1;
}
/*
����ÿһ������str[]
���ڵ�һ������str[1~n)��str[0]С����sum[0]��	���һ����С��str[0]�����еĸ���Ϊsum[0]*(n-1)!
�̶�str[0]���ڶ�������str[2~n)��str[1]С����sum[1]������ڶ�����С��str[1]�����и���Ϊsum[1]*(n-2)!
...
��ǰ���е��ֵ�������Ϊsum[0]*(n-1)!+sum[1]*(n-2)!+...sum[k]*(n-1-k)!...+sum[n-1]*(0)! 
*/
