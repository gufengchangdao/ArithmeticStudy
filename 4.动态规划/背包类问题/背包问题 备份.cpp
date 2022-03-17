f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
/*
存在购买顺序要求时，例如先买w[i]大的
则应该将结构体goods(结构体方便)从小到大排序 
因为dp过程中，dp[1][n]先将第一件物品考虑完，dp[2][n]在第一件物品的情况下考虑第二件物品，所以第二件
物品会更新第一种物品，但第一种物品不会更新第二种物品，相当于先购买第二种物品再购买第一种物品，第二
种物品的购买与否会影响第一种物品的购买
*/

//原始 
for(int i=1;i<=n;i++)
	for(int j=0;j<=v;j++)
		f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
//优化 
//二维变一维，因为每次求f[i][j]会用到f[i-1][j-m]，故比j小的f不能先改变，只能让j从从大到小
//而且i等于1的时候已经初始化了
//j运行到w[i]即可，体积小于w[i]时已经不可能装下了 
for(int i=1;i<=n;i++)
	for(int j=v;j>w[i];j--)
		f[j]=max(f[j],f[j-w[i]]+v[i]);

/*
背包问题：
1.恰好装满背包时价值最大 
	初始化时f[0]=0,f[1~v]=负无穷
	dp都是由前一组dp得到且只有dp[0]=0，求max最大时，若有j-w[i]==0，则dp[j]=0,表示可以达到j值
2.只是问是否能正好装满背包 
	在求是否能够达到num时，f[0]=0,f[1~v]=负无穷
	可以由if (dp[j - w]) dp[j] = true，将可以达到的j标为1，最后检测f[num]==1即可 
3.价格最大，初始化f[1~v]=0
4.价格最小，初始化f[0]=0,f[1~V]=和的最大值，遍历时min查找
	dp[V]=min(dp[V],dp[V-w[i]]+v[i])时，不存在重量之和为V-w[i]的情况，不断递归，可知这时候没有解
5.多组混合背包：
	用f[i][j]表示第i组背包容量为j最大的价值 
	1.至少选择一个：初始化f[0][0~v]=0,f[i][0~v]=负无穷,这里f[i][0]也必须负无穷，因为必须答案要从上一组转移过来 
		f[i][j]=max(max(f[i][j],f[i][j-w[i]]+v[i]),f[i-1][j-w[i]]+v[i]); 
		//f[i-1]是为了把上一次结果转移过来的同时必须选择一个，选择之和就成为了dp[i]，保证至少选择一个 
 	2.最多选择一个：初始化f[i][j]=f[i-1][j],j为[0~V] 
 		f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
		//f[i-1]是不变的，只要f[i][j]取过一次就不会再取了，当然也可以不取
		1维最多选择一个： c[k]第k组拥有的商品数量，cc[k][i]第k组第i个商品 
		for(int k=1;k<=cla;k++)//cla组 
		for(int j=V;j>=0;j--)//将j的循环放在i的外面，达到每组最多选择一个的效果 
			for(int i=1;i<=c[k];i++){//每组的商品 
				if(j>=w[cc[k][i]]) f[j]=max(f[j],f[j-w[cc[k][i]]]+v[cc[k][i]]);
				printf("f[%d]:%d\n",j,f[j]);
			}
*/
 
/*
一个常数的优化 v很大的时候适用 
由于只需要最后f [ j ] f[j]f[j]的值，倒推前一个物品，其实只要知道f[j-w[n]] 即可。
以此类推，对以第j个背包，其实只需要知道到f[j-sum(w[j...n] )]即可
*/
for(int i=1;i<=n;i++){
	scanf("%d",&w[i]);
	s[i]=s[i-1]+w[i];
}
for(int i=1;i<=n;i++){
	int bound=max(w[i],v-(s[n]-s[i]));// 
	for(int j=v;j>=bound;j--)
		f[j]=max(f[j],f[j-w[i]]+v[i]);
}

完全背包问题：每个物品可以无限取

/*
//小优化 
//把w[i]>V的物品排除，v[i]<v[j]但是w[i]>w[j]排除 
结构体储存，sort按v排序，遍历将相同v而w最小的储存进去 
*/

/*
转化为01背包求解：
把每个物品分成V/w[i]份
更高效的:
	把第i个物品分成若干个w[i]*2^k、v[i]*2^k，其中w[i]*2^k<=V，因为不管取多少个该物品，
	都可以用2^0、2^1、2^2表示出来，这里利用二进制的思想 
*/	

//最优：
for(int i=1;i<=n;i++)
	for(int j=w[i];j<=V;j++)//j从小到大遍历，则每次j就会利用在第i个物品中已经更改过的f[]值，即取过还能再取 
		f[j]=max(f[j],f[j-w[i]]+v[i]);	 
	//f[i][j]=max(f[i-1][j],f[i][j-w[i]]+v[i]);//显式给出 

多重背包问题：商品数量不是一个也不是无限
/* 
	可以对每个商品取0~p[i]个操作
	也可以把商品转化为01背包，两者复杂度相同
*/

/*	
二位进制写法
已知所有数都能用二进制数表示，也是2^0,2^1,2^2,2^3...表示，
用w[i]处理过，再用w[i]*2处理的话，由于w[i]处理过，相当于w[i]*0,w[i]*1,w[i]*2,w[i]*3都处理过了 
*/ 
for(int i=1;i<=n;i++){
    int num=min(p[i],V/w[i]);//找出能买的该商品数量，p[i]为该商品数量，考虑体积能装多少还要考虑有多少个 
    for(int k=1;num>0;k<<=1){//利用二进制，k=1,2,4,8,16,...,2^(k-1),num 
        if(k>num) k=num;//截止条件，k不能大于num，并且能够把1~P[i]都能遍历 
        num-=k; 
        for(int j=V;j>=w[i]*k;j--)//每次操作不同的区间 
            f[j]=max(f[j],f[j-w[i]*k]+v[i]*k);
    }
}
/*
例如：p[i]=17 
[w[i],							V]
	[w[i]*2,					V]
		[w[i]*4,				V]
			[w[i]*8,			V]
	[w[i]*2,					V]最后一个做到正好取到p[i]个 
这样包括了取0个、取1到取p[i]个 
*/	

/*
单调队列优化 最快 不会！ 
p：某类物品数量，w：某类物品花费，v：某类物品价值，V:商品总价值
*/
void MultiPack(int p, int w, int v) {
    for (int j = 0; j < w; j++) { //j为w的所有组
        int head = 1, tail = 0;
        for (int k = j, i = 0; k <= V / 2; k += w, i++) {
            int r = f[k] - i * v;
            while (head <= tail and r >= q[tail].v) tail--;
            q[++tail] = node(i, r);
            while (q[head].id < i - p) head++; //需要的物品数目
            f[k] = q[head].v + i * v;
        }
    }
}

混合背包问题：
/*
01和完全背包混合
01背包和完全背包中给代码只有一处不同，只需在对每个物品应用转移方程时，根据物品的类别选用顺序
或逆序的循环即可
*/
/*
因为三种背包的不同只在与对应第i个物品时运行的次数j，w[i]*k则相当于运行k次
p[i]:每个物品的件数，0代表无穷个
*/
for(int i=1;i<=n;i++){
if(p[i]==0)
	for(int j=w[i];j<=V;j++)
		f[j]=max(f[j],f[j-w[i]]+v[i]);
else{
	//for(int k = 1; k <= p[i]; k++)写简单点的话，就让i循环p[i]遍 
	int num=min(p[i],V/w[i]);//去掉多余的商品数量 
	for(int k=1;num>0;k<<=1){
		if(k>num) k=num;
		num-=k;
		for(int j=V;j>=w[i]*k;j--)
			f[j]=max(f[j],f[j-w[i]*k]+v[i]*k);
	}
} 

二维费用背包：每个物品需要两种价格
/*
容量分别为V、T,有时候也会把购买的物品数量限制作为T,此时g[i]都为1 
多一维数组判断即可
*/
//f[i][j][k]=max(f[i-1][j][k],f[i-1][j-w[i]][k-g[i]]+v[i])
for(int i = 1; i <= n; i++)//容量分别为V、T 
    for(int j = V; j >= w[i]; j--)
        for(int k = T; k >= g[i]; k--)
        	f[j][k] = max(f[j][k], f[j - w[i]][k - g[i]] + v[i]);
 
有依赖背包问题：
/*
这种背包问题的物品间存在某种“依赖”的关系。也就是说，i依赖于j，表示若选物品i，则必须选物品j。为
了简化起见，我们先设没有某个物品既依赖于别的物品，又被别的物品所依赖；另外，没有某件物品同时依赖
多件物品。我们可以对主件i的“附件集合”先进行一次01背包，得到费用依次为0... V-c[i]所有这些值时相
应的最大价值f[0... V-c[i]] ,那么这个主件及它的附件集合相当	于V-c[i]+1个物品的物品组，其中费用为
c[i]+k的物品的价值为f[k]+w[i]。也就是说原来指数级的策略中有很多策略都是冗余的，通过一次01背包后，
将主件i转化为V-c[i]+1个物品的物品组，就可以直接应用分组背包的算法解决问题了。
*/
memset(f,-1,sizeof(f));//有依赖关系，要赋初值-1，通过-1排除不可能情况 
memset(f[0],0,sizeof(f[0]));//第0行要赋为0 
for(int k=1;k<=n;k++){//n组物品 
	scanf("%d%d",&fw,&m);//读取主件费用和附件数量 
	//购买主件 
	for(int j=fw;j<=V;j++)
		f[k][j]=f[k-1][j-fw];//为第k组f赋初值，先减去费用，这题主件的价值为0 
	for(int i=1;i<=m;i++){//遍历附件 
		scanf("%d%d",&w,&v); 
		for(int j=V;j>=w;j--)
			if(f[k][j-w]!=-1)//注意依赖背包有不可能的情况，这里即k买不到主件，不能装附件 
				f[k][j]=max(f[k][j],f[k][j-w]+v);
	}
	//够买主件与不购买主件 
	for(int j=0;j<=V;j++) f[k][j]=max(f[k][j],f[k-1][j]);//考虑不选当前组的情况（不是必选） 
}

泛化物品
	问法的不同：
		1.输出方案： 
		从g[n][V]开始,g[i][j]=0表示推出f[i][j]的值时是f[i][j]=f[i-1][j]，未购买i物品 
					  g[i][j]=1表示采用了方程的后一项，购买i物品，并找到g[i-1][j-w[i]]继续判断 
		这两种策略是未选第i个物品及选了第i个物品，
		另外，采用方程的前一项或后一项也可以在输出方案的过程中根据f[i][j]的值实时地求出来，也即
		不须纪录g数组，判断f[i][j]==f[i-1][j]，f[i][j]==f[i-1][j-w[i]]+v[i]即可。
		2.输出字典序最小的最优方案：
		因为，越来后面的物品相当于越先选，所以先把物品逆序排列一下
		从N到1输入时，如果f[i][j]==f[i-1][i-j]及f[i][j]==f[i-1][j-w[i]]+v[i]同时成立，应该按照后者来输出方案
		3.最优方案的总数：
			01背包：g[i][j]=0,用g[i][j]表示f[i][j]的方案总数
			如果F[i][j]=F[i-1][j]且F[i][j]!=F[i-1][j-C[i]]+W[i]说明第i个物品不放,g[i][j]=g[i-1][j] 
			如果F[i][j]!=F[i-1][j]且F[i][j]=F[i-1][j-C[i]]+W[i]说明第i个物品放，g[i][j]=g[i-1][j-w[i]] 
			如果F[i][j]=F[i-1][j]且F[i][j]=F[i-1][j-C[i]]+W[i]说明放与不放都可g[i][j]=g[i-1][j]+g[i-1][j-w[i]]	
			完全背包： g[i][j]=1、g[0][j]=0、g[i][0]=0; 
			如果F[i][j]=F[i-1][j]且F[i][j]!=F[i][j-C[i]]+W[i]说明第i个物品不放,g[i][j]=g[i-1][j]
			如果F[i][j]!=F[i-1][j]且F[i][j]=F[i][j-C[i]]+W[i]说明背包中还有第i个物品，g[i][j]=g[i][j-w[i]] 
			如果F[i][j]=F[i][j-w[i]]+v[i]且F[i][j]=F[i-1][j]说明存在i与不存在i都可以达到最大值,g[i][j]=g[i-1][j]+g[i][j-w[i]]
  			for i ← 1 to N //求f[i][j]的同时求g[i][j]
      		do for j ← 1 to V
          	F[i][j] ← F[i-1][j]//不用max时要先赋值 
          	G[i][j] ← G[i-1][j]//继承结果 
          	if (j >= C[i])
            	if (F[i][j] < F[i][j-C[i]]+W[i])//再次购买i 
                  	then F[i][j] ← F[i][j-C[i]]+W[i] 
                       G[i][j] ← G[i][j-C[i]] 
              	else if (F[i][j] = F[i][j-C[i]]+W[i])//两者方案皆可 
                  then G[i][j] ← G[i-1][j]+G[i][j-C[i]]
  			return F[N][V] and G[N][V]
 		4.求K优解：
			f[i][j]变为f[i][j][k] 可以看作f[i][j]是一个大小为K的数组，将结果的前K项储存到f[i][j][1...K]
			由于是求最优解，所以其它在任何一个策略上达不到最优的方案都被忽略了。如果把每个状态表示
			成一个大小为K的数组，并在这个数组中有序的保存该状态可取到的前K KK个最优值。另外还要注意
			题目对于“第K优解”的定义，将策略不同但权值相同的两个方案是看作同一个解还是不同的解。
			如果是前者，则维护有序队列时要保证队列里的数没有重复的。
int kth(int n, int V, int k){
    for (int i = 1; i <= n; i++){
        for (int j = V; j >= w[i]; j--){
            for (int l = 1; l <= k; l++){//这里保存k个状态值，便于供k个f[i][j]选择 
                a[l] = f[j][l];
                b[l] = f[j - w[i]][l] + v[i];
            }
            a[k + 1] = -1;b[k + 1] = -1;//设边界 
            int x = 1, y = 1, o = 1;
            while (o != k + 1 && (a[x] != -1|| b[y] != -1)){
			//a[x]=-1的时候，b[y]!=-1，这时会有a[x]<b[y],剩下的都判为第i个物品加入的情况 
                if (a[x] > b[y]) f[j][o] = a[x], x++;
                else f[j][o] = b[y], y++;
                if (f[j][o] != f[j][o - 1]) o++;//这里值相同的解就不算，
										//值如果都相同的话第o种以后的解就不会更新 
            }
        }
    }
	return f[V][k];
}
			

