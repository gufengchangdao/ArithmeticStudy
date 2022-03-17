引入delta数组 delta[i]表示区间 [i, n] 的共同增量，
于是修改区间 [l, r] 时修改 delta[l] 和 delta[r + 1] 即可
查询区间 [l, r] 的和 即sum[r] - sum[l - 1]
求sum[i]：
  
tree[i]=a[i]-a[i-1];
a[i]=tree[1]+tree[2]+tree[3]+...+tree[i];
sum[i]=tree[1]*i+tree[2]*(i-1)+...+tree[i]*1
	  =tree[1]*i+tree[2]*i+...+tree[i]*i-(tree[1]*0+tree[2]*1+...+tree[i]*(i-1))
	  =i*sum(1,i,tree)-sum(1,i,treei);	//treei[i]为tree[i]*(i-1) 

a[i]//原数组 
tr[i]//为tree[i]的树状数组
trr[i]//为tree[i]*(i-1)的树状数组， 
//动态调整树状数组 
inline void add(int i,ll k,ll tree[])//
{
	
}
//求tree中[1,i]的和，即前缀和 
inline ll sum(int i,ll tree[])
{
	
}
//输入a[i]和初始化 
	scanf("%d",&a[i]); 
	add(i,a[i]-a[i-1],tr);//先建立差的树状数组用于求i*(tree[1]*i+tree[2]*i+...+tree[i]) 
	add(i,(i-1)*(a[i]-a[i-1]),trr);//用于求tree[1]*0+tree[2]*1+...+tree[i]*(i-1) 
//在[l,r]区间中a[i]修改为a[i]+k 
	add(l,k,tr);//只用修改与a[l]和a[r+l]有关的tr和trr就可以 
	add(r+1,-k,tr);
	add(l,k*(l-1),trr);//差分数组 
	add(r+1,-k*r,trr);
//求a中[l,r]区间的和 ,sum[r]-sum[l-1]
	r*sum(r,tr)-sum(r,trr) - (l*sum(l,tr)-sum(l,trr));
	
