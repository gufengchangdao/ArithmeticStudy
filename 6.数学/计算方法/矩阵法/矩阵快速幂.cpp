���������������������ʽ�ģ����Ե�һ����Ҫ�г�����ʽ:
��ʱ��仯��n������ÿ�����������ᰴ��һ�����ɱ仯
���ƿ��Դ���������ݷ�Χ̫��һ�㳬�����������Ϊ�ݴ�
���������ɣ�M*a[n-1]=a[n],M����ȫΪ������һ��Ϊmaxn*maxn�׵ģ���aΪmaxn*1�׵� 
[M]*a[n-1]=a[n]
a[n-1]��һ�㺬��f[n-1]��f[n-2]�ͱ�Ҫ�ĳ��� 
[M]һ�㻹��1��0�ͱ�Ҫ�ĳ��� 
struct mat//�þ�������� 
{
	int m[maxn][maxn];
	mat(){	//����������ʱ��ͻ����У��Ծ����ʼ�� 
		memset(m,0,sizoef());
	}
};

 
int res[3][3],M[3][3],ans[3][3];
int temp[3][3];
int len=2;
const int N=2;
const int mod=10000; 
void multi(int a[][N],int b[][N],int x,int y)//aһ�㶼��ΪN*N�׾���Nֻ�Ǿ����С����������Ч���� 
{											//	��Ч���� a[x][len]*b[len][y]														
	memset(temp,0,sizeof(temp));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<len;k++)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<x;i++)	
		for(int j=0;j<y;j++) a[i][j]=temp[i][j];
}

void pow(int a[][N],int n)//���res������Ǵ� 
{
	memset(res,0,sizeof res);
	for(int i=0;i<len;i++) res[i][i]=1;
	while(n){
		if(n&1) multi(res,a,len,len);
		n>>=1;
		multi(a,a,len,len); 
	}	
}
