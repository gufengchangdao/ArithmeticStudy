��Ȩ���鼯��
	һ���Ǹ������x,y,v��v��x��y����Թ�ϵ������ѯ��������������Թ�ϵ 
	��һ�㲢�鼯��һ��sum[i],Ϊ�ӽ��i�������ı�Ȩֵ�ĺͣ�Ҳ����˵sum[x]=(x,s[x]]�Ľ��ֵ�ĺ� 
	�����ڶ�����ϣ�ÿ�����ϵ�Ԫ�ض����Լ�Ԫ�ص�ǰ׺��sum 
	���ԱȽ�(ͬһ�������)�Ƚϣ�sum[x]-sum[y]
	�����ԱȽ�(����㲻ͬ)�ϲ���sum[xx]=-sum[x]+val+sum[y]
	������ѭ���Ĺ�ϵ�Ĳ��鼯��Ҫ�ڸ���sum��ʱ��ȡģ 
	
int findset(int x)
{
	if(x!=s[x]){
		int tem=s[x];
		s[x]=findset(s[x]);
		sum[x]+=sum[tem];//�ݹ����ɸ���㿪ʼ��ǰ׺�ͣ�tem����x�ĸ��ڵ� 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy)//�����ĸ������ͬ�������Ƴ�(x,y]��������� 
		if((sum[x]-sum[y])!=val) ans++;
	else{	//����㲻ͬ�������Ƴ������ܸ�������� 
		s[xx]=yy;
		sum[xx]=-sum[x]+val+sum[y];//���xx��yy�ı�Ȩֵ
	}//���ǹ涨ֻҪs[i]���ӵ�����㣬��Ҫ����sum[i],��Ϊ������findset��������x==s[x]���������sum 
}


