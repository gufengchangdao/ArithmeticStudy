//https://www.nitacm.com/problem_show.php?pid=602
//1~n的集合，q==1，删除w，q==2，查询w现在排在多少位，N<=100000000，1<=M<=100000
//题解：原数组把已经删除的数设为1，其他为0，1~i有多少那么i之前就删除了多少 
/*
e结构体存储每组的q和w 
b[i]存储每组的w，排好序
用s[b[i]]=i,记录w组中不同的数的前后顺序 
a[i]作为s[i]的树状数组 
对于每次操作：
删除：先判断，将要删除的数用mp[w]=1标记，更新a[i]数据，这里的改变值为1，即s[w]从0变成1并改变其a[i] 
查询：先判断，排名==w-w之前减去的数的数组s[i]总和 
*/ 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>mp,s;
//unordered_map<int,int>mp,s;//创建无序map，无序map比map更快一些
//这里用map存储是因为对于一些大的数maxn,用a[maxn]=1标记比mp[maxn]=1更占内存，a数组要开的很大，而
//map只需要用一个开一个 
const int maxn=1e5+5;
int a[maxn],b[maxn],n,m;//a为树状数组 
struct op{
    int q,w;
}e[maxn];

int lowbit(int x){
    return x&(-x);
}

void update(int i,int k){ //单点更新
    while(i<=m){
        a[i]+=k;
        i+=lowbit(i);
    }
}

int getsum(int i){ //区间查询
    int res=0;
    while(i>0){
        res+=a[i];
        i-=lowbit(i);
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int q,w;
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d",&e[i].q,&e[i].w);
            b[i]=e[i].w;
        }
        //离散化处理 
        //对b数组排序，用s数组以w为ID，值为数组对应的次序，次序值无关紧要，重要的是这几个数的分布 
        sort(b+1,b+1+m); 
        for (int i = 1; i <= m; ++i)
            s[b[i]]=i;
    //    也可以用m=unique(b+1,b+m+1)-b-1; 直接对b数组去重
	//		再用s[i]=lower_bound(b+1,b+m+1)-b-1，二分查找找到ID    
        for (int i = 1; i <= m; ++i) {
            q=e[i].q;w=e[i].w;
            if(q==1){//删除操作 
                if(!mp[w]){
                    mp[w]=1;//对已经删除的点标记 
                    update(s[w],1);
                }
                else{
                    printf("mdzzwinter0\n");
                }
            }
            else{//访问操作 
                if(!mp[w])
                    printf("%d\n",w-getsum(s[w]));//排名==w - w前面删除的数个数的和 
                else
                    printf("mdzzwinter1\n");
            }
        }
        mp.clear();
        s.clear();
        memset(a,0,sizeof(a));
    }
    return 0;
}
