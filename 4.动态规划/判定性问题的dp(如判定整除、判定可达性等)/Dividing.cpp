/*
�����Ǽ���Ƿ�������ɸ���֮�͵���ĳ����sum
����1�Ǳ�����ʱ���С�ڵ��� sum������������sum��ʱ���˳����� 
����2��ֱ�ӣ���f[j]��������Ϊtrue,��������f[sum]���ڵĻ�����ʾ�������ɸ���֮������Ϊsum 
	Ϊfalse���ʾ��������������
*/ 
#include<bits/stdc++.h> 
using namespace std;
#define ri register int
int f[120005];

int main()
{
	int v[10],sum,dig=0;
	while(~scanf("%d%d%d%d%d%d",&v[1],&v[2],&v[3],&v[4],&v[5],&v[6])&&(v[1]||v[2]||v[3]||v[4]||v[5]||v[6])){
		dig++;
		int good=1;
		memset(f,0,sizeof(f));
		sum=v[1]+v[2]*2+v[3]*3+v[4]*4+v[5]*5+v[6]*6;
		if(sum&1) good=1;
		else{
			sum/=2;
			for(ri i=1;i<=6&&good;i++){
				int num=min(v[i],sum/i);
				for(ri k=1;num>0&&good;k<<=2){	
					if(k>num) k=num;
					num-=k;
					for(ri j=sum;j>=i*k&&good;j--){
						if(f[j-i*k]+i*k<=sum)//�������������� 
						f[j]=max(f[j],f[j-i*k]+i*k);
			printf("f[%d]:%d\n",j,f[j]);			
			
						if(f[j]==sum) good=0;
					}
				}
			}
		}
		if(good) printf("Collection #%d:\nCan't be divided.\n\n",dig);
		else printf("Collection #%d:\nCan be divided.\n\n",dig);
	}
 } 
