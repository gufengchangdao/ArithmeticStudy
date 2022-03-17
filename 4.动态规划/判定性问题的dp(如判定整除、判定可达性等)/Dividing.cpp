/*
本题是检测是否存在若干个数之和等于某个数sum
方法1是遍历的时候把小于等于 sum的数，当等于sum的时候退出即可 
方法2更直接：当f[j]遍历到就为true,到最后如果f[sum]存在的话，表示存在若干个数之和正好为sum 
	为false则表示不可能满足条件
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
						if(f[j-i*k]+i*k<=sum)//这里必须包含等于 
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
