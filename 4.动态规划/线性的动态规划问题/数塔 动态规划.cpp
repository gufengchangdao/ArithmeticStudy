#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;//为了算法写起来简单，这里定义一个足够大的数用来存储数据(为了避免运算过程中动态申请空间，这样的话算法看起来比较麻烦，这里只是为了算法看起来简单)
int data[N][N];//存储数塔原始数据
int dp[N][N];//存储动态规划过程中的数据,只计算结果可以不用，但还要查询路径的话要用 
int n;//塔的层数
/*动态规划实现数塔求解*/
void tower_walk()
{
    for (int i = 0; i < n; ++i)// 从下向上计算 
        dp[n - 1][i] = data[n - 1][i];//dp复制最后一行 
        //从下自上 
    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)// 使用递推公式计算dp的值
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + data[i][j];
}
/*打印最终结果*/
void print_result()
{
    cout << "最大路径和：" << dp[0][0] << '\n';
    int node_value;
    cout << "最大路径：" << data[0][0];// 首先输出塔顶元素，然后从上往下倒回来计算 
    int j = 0;
    	//自上而下 
    for (int i = 1; i < n; ++i){
        /* 如果node_value == dp[i][j]则说明下一步应该是data[i][j]；如果node_value == dp[i][j + 1]则说明下一步应该是data[i][j + 1]*/
        if (dp[i][j + 1] == dp[i - 1][j] - data[i - 1][j]) ++j;
        cout << "->" << data[i][j];
    }
    cout << endl;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--){
    	cin >> n;
    	for (int i = 0; i < n; ++i)
    	    for (int j = 0; j <= i; ++j)
    	        cin >> data[i][j];
    	tower_walk();
    	print_result(); 
	}
}
//自顶向下的分析；自底向上的计算 
