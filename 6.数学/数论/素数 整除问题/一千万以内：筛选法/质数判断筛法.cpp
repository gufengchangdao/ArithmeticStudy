����ɸ��
��2��ʼ�������ı���ɸȥ
ȱ�㣺ͬһ���������ܻ����ظ�ɸȥ 
const int maxn=1e5;
int prime[maxn];
bool ispri[maxn];//��ɸȥ�ĺ����з� 
void sieve()
{
	int k=0;
	memset(ispri,-1,sizeof(ispri));//��ֵ�������ǰ�ispri��ʼ��Ϊtrue
	ispri[1]=false;
	for(int i=2;i<maxn;i++){
		if(ispri[i]){
			prime[k++]=i;//��¼���� 
			for(int j=i*i;j<maxn;j+=i) ispri[j]=false;//�������ı���ȫ��ɸȥ
				//j��i*i��ʼ,��Ϊ2*i��3*i��...(i-1)*i������ǰ��ɸȥ�ˣ�����maxn̫���ʱ��i*i�ᱬ������ll 
		}
	}	
}

����ɸ(ŷ��ɸ)�� ÿ��������������С�������е����Ͳ��������� 
const int maxn=1e5;
int prime[maxn];
bool ispri[maxn];
void sieve()
{ 
	int k=0,temp;
	memset(ispri,-1,sizeof(ispri));
	ispri[1]=false;
	for(int i=2;i<maxn;i++){
		if(ispri[i]) prime[k++]=i;
		
		for(int j=0;j<k;j++){//j�����Ѿ���õ���������Ϊֻ��k������������i�Ƿ�Ϊ������Ҫ���� 
			temp=i*prime[j];//prime������������Ҫ��ȥ�ĺ�������С�����ӣ���֪i>=prime[j],prime[j]Ϊtemp����С������ 
			if(temp>=maxn) break;//�ж����Ƿ�Խ�� 
			ispri[temp]=false; 
			if(i%prime[j]==0) break;//ȥ�صĹؼ�����ʾi�������к��и�������
										//����ֹ��һ��temp�Ͳ�������С��������ȥ�� 
		}
	}
}
/* 
��֪�κ���
i=p1^a1*p2^a2*p3^a3...*pi^ai;//piΪ��������pi<p(i+1)
j����С������ʼ��������֪i%prime[j]==0ʱprime[j]==p1,��Ϊi����С������
��i%prime[j]==0���˳���i=k*prime[j],  temp=i*prime[j+1]=prime[j]*(k*prime[j+1]),
��ʱ���tempɸȥ������i=k*prime[j+1]ʱ�����ٴ�ɸȥ 
*/ 
