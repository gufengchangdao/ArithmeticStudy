动态规划：
定义数组元素的含义
找出数组元素之间的关系式 
找出初始值 

二位数组dP 
机器人从左上角走到右下角，且只能向下或向右，求最短路径和
dp[i][j]	走到[i][j]位置的最小路径和 
public static int uniquePaths(int[][] arr) {
      int m = arr.length;
      int n = arr[0].length;
    if (m <= 0 || n <= 0) return 0;
    int[][] dp = new int[m][n]; //初始化
      dp[0][0] = arr[0][0];//初始化最左边的列
      for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + arr[i][0];// 初始化最上边的行
      for(int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + arr[0][i];// 初始化最左边的行
	  
    for (int i = 1; i < m; i++)////推导出 dp[m-1][n-1]
        for (int j = 1; j < n; j++) dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
    return dp[m-1][n-1];
}


