�鲢����
	�����Ǻϲ� 
ԭ�����ϰ����ж��֣�ֱ���ֵ�ֻ������������֪��������ÿһ�������������֣�����������һ���Ѿ�
	�ֱ��ź��򣬲��Ͻ��бȽϣ���С��װ����ʱ����temp��������������ƽ�������������棬���ӶȺ�
	����һ��

void mergesort(int l, int r, int *A){
	//�ݹ���ֲ��� 
	if (l >= r) return;
	int mid = (l + r) >> 1;
	mergesort(l, mid, A); 
	mergesort(mid + 1, r, A);
	//�ϲ�����	
	int i = l, j = mid + 1, cnt= 0;
	while(i<=mid&&j<= r){	
		if (A[i] <= A[j]) temp[cnt++] = A[i++];
		else{
			temp[cnt++] = A[j++];
		//	ans+=mid-i+1;	//ans���������������� 
		}
	}
	while(i <= mid) temp[cnt++] = A[i++];//�Ƚ���һ�������У���ʣ�µ������е������� 
	while(j<= r) temp[cnt++] = A[j++];
	for (i=0;i<cnt;i++) A[i+l] = temp[i];//����ԭ���� 
} 
 
