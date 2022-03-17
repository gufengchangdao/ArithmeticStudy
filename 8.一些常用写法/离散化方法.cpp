第一种： 
#include<algorithm> // 头文件 
//n 原数组大小 num 原数组中的元素 lsh 离散化的数组 cnt 离散化后的数组大小 
int lsh[MAXN] , cnt , num[MAXN] , n;
for(int i=1; i<=n; i++){
	scanf("%d",&num[i]);
	lsh[i] = num[i];	
}
sort(lsh+1 , lsh+n+1);
cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;//去重后下标范围为[1,cnt]; 
for(int i=1; i<=n; i++)
	num[i]=lower_bound(lsh+1,lsh+cnt+1,num[i])-lsh;	//num[i]最小为1，num数组指向lsh对应的下标 
//注意 去重和二分后面减去的数的区别，unique返回的是不重复序列的最后一个元素的下一个元素，二分则不同 

第二种： 
#include<algorithm>
struct Node {
	int data , id;
	bool operator < (const Node &a) const {
		if(data==a.data) return id<a.id;	//根据题目需要对id排序 
		return data < a.data;
	}
};
for(int i=1; i<=n; i++) {
	scanf("%d",&num[i].data);
	num[i].id = i;
}
sort(num+1 , num+n+1);	//排序后，连续的下标i就是对原数值的离散化 
for(int i=1; i<=n; i++)	
	rank[num[i].id] = i;


