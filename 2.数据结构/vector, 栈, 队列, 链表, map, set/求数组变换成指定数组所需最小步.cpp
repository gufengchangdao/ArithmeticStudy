//题意：给定两个数组，问至少多少次操作才能是前一个数组变为后一个数组
//两个操作：1、删除第一个，在最后面添加任何一个数；2、改变数组任意一个位置的数据 
/*
题解：
	读取数据后，用另外两个数组记录其位次，对于每个数的先后次序之差便得到了前后位次的变化量
	取变化量出现次数最多的一组数作为主体，其余的数配合主体作出改变形成目标数组，则n-不变的(主体) 
*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int a[maxn], b[maxn], pa[maxn], pb[maxn];//pa与pb存储两个数组的位次 
int main(){
    ios::sync_with_stdio(false);//关闭流同步 
    cin.tie(nullptr);//cin与cout是默认绑定的,这样增加了IO的负担，通过tie(nullptr)来解除 
	//cin和std :: cout之间的绑定，进一步加快执行效率, tie是将两个stream绑定的函数
	//在c++中，nullptr是空指针，NULL是整数0 
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], pa[a[i]] = i;
    for(int i = 1; i <= n; ++i) cin >> b[i], pb[b[i]] = i;
    map<int, int>mp;//这里用map存储可以避免无用的空间浪费和遍历时不需要数据的干扰，并且键可以为负数 
    for(int i = 1; i <= n; ++i){
        mp[pa[i] - pb[i]]++;//同一个数先后次序的差表示相对位置 
    }
    int ans = 0;
    for(auto i : mp){//范围for，这里配合cin.tie(nullptr)使用,mp是一个可遍历的容器或流，比如vector
	//、map类型，i就用来在遍历过程中获得容器里的每一个元素 
        if(i.first >= 0)//排除位次降低的，因为相对不变的一组数位次只会向前不会向后 
            ans = max(ans, i.second);
    }
    cout << n - ans << '\n';//总数-不变的 
    return 0;
}
