//Radar Installation
/*
���⣺��x���Ϸ��Ǻ����·��ǰ���������n�������״�ֻ�ܽ��ڰ��ϣ���Ч�뾶Ϊd���󸲸����е�������Ҫ��
	�ٸ��״���ڸ��ǲ��������ʱ���-1 
���ݴ�������ÿ����Ϊ���ģ��뾶Ϊd��Բ��x��Ľ��㣬�õ�������[l,r]�����״�Ŀɷ����� 
	̰����⣺�����ݰ�r��С�������򣬶��������ص��ĵ����ùܣ����ص�������� 
*/
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d,ans,t=0;
struct node{
	double l,r;
	bool operator <(const node &a)const {
		//if(r==a.r) return l<a.l;�ò��� 
		return r<a.r;
	}
}e[maxn];

int main()
{
	while(~scanf("%d%d",&n,&d)&&(n||d)){
		bool can=1;
		
		double x,y;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			double tem=sqrt(fabs(1.0*d*d-y*y));
			e[i].l=x-tem,e[i].r=x+tem;	//���㽻������� 
			if(y>d) can=0;	//����û�н����� 
		}
		if(!can){
			printf("Case %d: -1\n",++t);
			continue;
		}
		sort(e,e+n);
		ans=1;
		double r=e[0].r;
		for(int i=1;i<n;i++){
			if(e[i].l>r) r=e[i].r,ans++;	//Ѱ�����䲻�ظ���������� 	
		}
		printf("Case %d: %d\n",++t,ans);
	}
}
