//金明的预算方案 
/*
题意：每件物品的价格与重要度的乘积的总和最大
	物品有主件和附件之分，一个主件可以搭配多个附件(最多两个)，也可以不搭配；但是附件必须搭配主件
有依赖背包： 先把价值算出来；把附件绑定在主件上,在规划的时候考虑主件的时候还要考虑主件和附件一起买情况	 
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
		if(op==0){	//自身是主件 
			mw[i]=pp*vv;	//真实价值 
			mv[i]=vv;	//价格 
		}
		else{	//记录附件 
			c[op]++;	
			fv[op][c[op]]=vv;
			fw[op][c[op]]=pp*vv;
		}
	}
	for(int i=1;i<=n;i++){
		if(!mv[i]) continue;只考虑主件和它对应的附件 
		for(int j=V;j>=mv[i];j--){
			f[j]=max(f[j],f[j-mv[i]]+mw[i]);只考虑主件 
			if(j>=mv[i]+fv[i][1]) 
				f[j]=max(f[j],f[j-mv[i]-fv[i][1]]+mw[i]+fw[i][1]);考虑两件，就算没有附件对应的值也是0，没问题 
			if(j>=mv[i]+fv[i][2]) 
				f[j]=max(f[j],f[j-mv[i]-fv[i][2]]+mw[i]+fw[i][2]); 
			if(j>=mv[i]+fv[i][1]+fv[i][2]) 考虑三件 
				f[j]=max(f[j],f[j-mv[i]-fv[i][1]-fv[i][2]]+mw[i]+fw[i][1]+fw[i][2]);	
		}
	}
	printf("%d\n",f[V]);
}
