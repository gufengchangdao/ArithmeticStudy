//������Ԥ�㷽�� 
/*
���⣺ÿ����Ʒ�ļ۸�����Ҫ�ȵĳ˻����ܺ����
	��Ʒ�������͸���֮�֣�һ���������Դ���������(�������)��Ҳ���Բ����䣻���Ǹ��������������
������������ �ȰѼ�ֵ��������Ѹ�������������,�ڹ滮��ʱ����������ʱ��Ҫ���������͸���һ�������	 
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[64],f[32005],mw[33333],mv[33333],fw[33333][3],fv[33333][3]; 

int main()
{
	int n,V,op,k=0,vv,pp;
	scanf("%d%d",&V,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&vv,&pp,&op);
		if(op==0){	//���������� 
			mw[i]=pp*vv;	//��ʵ��ֵ 
			mv[i]=vv;	//�۸� 
		}
		else{	//��¼���� 
			c[op]++;	
			fv[op][c[op]]=vv;
			fw[op][c[op]]=pp*vv;
		}
	}
	for(int i=1;i<=n;i++){
		if(!mv[i]) continue;ֻ��������������Ӧ�ĸ��� 
		for(int j=V;j>=mv[i];j--){
			f[j]=max(f[j],f[j-mv[i]]+mw[i]);ֻ�������� 
			if(j>=mv[i]+fv[i][1]) 
				f[j]=max(f[j],f[j-mv[i]-fv[i][1]]+mw[i]+fw[i][1]);��������������û�и�����Ӧ��ֵҲ��0��û���� 
			if(j>=mv[i]+fv[i][2]) 
				f[j]=max(f[j],f[j-mv[i]-fv[i][2]]+mw[i]+fw[i][2]); 
			if(j>=mv[i]+fv[i][1]+fv[i][2]) �������� 
				f[j]=max(f[j],f[j-mv[i]-fv[i][1]-fv[i][2]]+mw[i]+fw[i][1]+fw[i][2]);	
		}
	}
	printf("%d\n",f[V]);
}
