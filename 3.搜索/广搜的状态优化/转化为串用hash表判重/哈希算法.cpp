//��ӡn������ǰm����� 

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
int a[MAXN];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));//��������� 
		for(int i=0;i<n;i++){
			int tem;
			scanf("%d",&tem);
			a[500000+tem]++;//����tΪ����������Ҫ���м俪ʼ��t+500000 
		}
		for(int i=MAXN-1;m>0;i--)//�Ӵ�С����m>0��Ϊѭ�����ڣ�ȷ��ֻ���m�� 
			for(int j=1;j<=a[i]&&m>0;j++){
				printf("%d%c",i-500000,m>1?' ':'\n'); 
				m--;
			}
//			while(a[i]--){	//a[i]Ϊ0��ʱ��Ͳ������ѭ�� 
//				if(m>1) printf("%d ",i-500000);
//				else printf("%d\n",i-500000);
//				m--;
//			} 
	}
	return 0;
}
 
