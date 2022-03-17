//��ŭ��С�� 
/*
���⣺������(0,0)����С�񣬸���n�����λ�ã���Ĺ켣Ϊy=a*x*x+b*x������a<0�������ٶ���ֻС��
	���Դ��������(m�����) 
	��̬�滮��״̬ѹ��
	�����ߵ�ѡ��ֻ��x��ͬ��ʱ��ֻ��һͷ������ֻ�ܹ�һͷ�����������������ߣ�ÿ������ͷ���ԭ��
		ȷ�������ߣ���Ҫ����������Ƿ��������������
	�Ż���û��lowbit[i]��ʱ��Ҫforѭ��һ�����״̬iû�й��ĵ��йص��ߣ�����кܶ��ظ��Ĳ�����ÿ��
		ֻ����û�й��ĵ����С��ţ��ͻ�úܶ� 
	״̬ѹ�����̣��������е�״̬����Ϊi����С��������i|(1<<(j-1))��i|lines[j][k]���Ǵ��ڵ���i�ģ�
		����ÿһ����dp������ǰ���dp״̬����ģ�ÿ��ֻҪ����lowbit[i]��ص��߼��ϾͿ���	 
	
*/
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
int lowbit[1<<20],line[20][20],dp[1<<20];//dp�����Ӧλ�õ����������ĵ��� 
double x[20],y[20];

void init()
{
	int len=1<<18;
	for(int i=0;i<len;i++){
		int j=1;
		while(j<=18 && i&(1<<(j-1))) j++;
		lowbit[i]=j;//����i&(1<<(j-1))=0����С������j������i��չ��ת�Ƶ�������(���н�)���Ҫ����j����� 
				//��׻����ǻ�δ����������С��ţ��ں��������У�ÿ�δ��������С��ţ��õ������� 
	}		
}

void equation(double &x,double &y,double a1,double b1,double c1,double a2,double b2,double c2)
{	//�ⷽ��
	y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	x=(c1-b1*y)/a1;
}

int main()
{
	init();
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		memset(dp,0x3f,sizeof(dp));//Ҫ�붯̬�滮�ã���ʼ��һ��ҪƯ�� 
		dp[0]=0;	
		memset(line,0,sizeof(line));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf%lf",x+i,y+i);//x��yΪ���飬������ǵ�ַ������&
	
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){//�������е������� 
				if(fabs(x[i]-x[j])<eps) continue;//���ں�������ȵ����㣬û��ͬһ�������ߣ�ֻ��һ����������߲���¼ 
				double a,b;
				equation(a,b,x[i]*x[i],x[i],y[i],x[j]*x[j],x[j],y[j]);//����a,b 
				if(a>-eps) continue; //a>=0���������� 
				for(int k=1;k<=n;k++)//������ȷ�������ߺ��ж��������Ƿ����������� 
					if(abs(a*x[k]*x[k]+b*x[k]-y[k])<eps) line[i][j]|=(1<<(k-1));
				line[j][i]=line[i][j];	//����������ͬ��j�Ͳ�������ô���� 
			}

		int len=1<<n;	
		for(int i=0;i<len;i++){	//i��С��󣬲��ϵõ������⣬����ÿ��״̬i����ֻ���ǹ�lowbit[i]��������С���� 
			int j=lowbit[i];	
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1);//����ת�ƣ�Ҫ���ǲ����������ϵĵ� 
			for(int k=1;k<=n;k++)
				dp[i|line[j][k]]=min(dp[i|line[j][k]],dp[i]+1);//���ת�ƣ����о���lowunbit��������
		}			
		printf("%d\n",dp[(1<<n)-1]);	
	}
	
}
