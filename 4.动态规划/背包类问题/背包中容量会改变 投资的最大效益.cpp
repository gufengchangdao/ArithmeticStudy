���⣺ 
�ñ���ȥͶ�ʣ���������Ͷ��ÿ���õ���Ϣ�ֿ���ѡ����������Ͷ����Ŀ����n����õ�������� 
�£���Ϊ����ÿ������ı䣬���ø�forѭ���Ϳ���ÿ��ģ�Ⲣ���±��� 
#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1e7;
int f[maxn];
struct node
{
	int w,v;	
}bond[15];
int main()
{
	long long V;
	int n,d,temp;
	scanf("%lld%d%d",&V,&n,&d);
	for(ri i=1;i<=d;i++){
		scanf("%d%d",&temp,&bond[i].v);
		bond[i].w=temp/1000;//����Ͷ��������Ϊ1000�ı��� 
	}
	while(n--){
		for(ri i=1;i<=d;i++){
			temp=bond[i].w*1000;
			for(ri j=temp;j<=V;j++)
				f[j]=max(f[j],f[j-temp]+bond[i].v);
		}
		V+=f[V];//ԭ�������Ͷ�ʻ�õ���Ϣ 

	}
	printf("%lld\n",V);
} 
