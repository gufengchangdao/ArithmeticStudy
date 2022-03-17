带权并查集：
	一般是给出多个x,y,v，v是x与y的相对关系，最后查询任意两个数的相对关系 
	比一般并查集多一个sum[i],为从结点i到根结点的边权值的和，也可以说sum[x]=(x,s[x]]的结点值的和 
	类似于多个集合，每个集合的元素都有自己元素的前缀和sum 
	可以比较(同一个根结点)比较：sum[x]-sum[y]
	不可以比较(根结点不同)合并：sum[xx]=-sum[x]+val+sum[y]
	对于有循环的关系的并查集需要在更新sum的时候取模 
	
int findset(int x)
{
	if(x!=s[x]){
		int tem=s[x];
		s[x]=findset(s[x]);
		sum[x]+=sum[tem];//递归求由根结点开始的前缀和，tem就是x的父节点 
	}
	return s[x];
}

void unionset(int x,int y,int val)
{
	int xx=findset(x);
	int yy=findset(y);
	if(xx==yy)//两结点的根结点相同，可以推出(x,y]的区间和了 
		if((sum[x]-sum[y])!=val) ans++;
	else{	//根结点不同，不能推出，接受给的区间和 
		s[xx]=yy;
		sum[xx]=-sum[x]+val+sum[y];//求出xx到yy的边权值
	}//我们规定只要s[i]连接到根结点，就要更新sum[i],因为就算在findset里面由于x==s[x]而不会更新sum 
}


