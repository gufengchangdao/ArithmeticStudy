��̬�滮��
��������Ԫ�صĺ���
�ҳ�����Ԫ��֮��Ĺ�ϵʽ 
�ҳ���ʼֵ 

��λ����dP 
�����˴����Ͻ��ߵ����½ǣ���ֻ�����»����ң������·����
dp[i][j]	�ߵ�[i][j]λ�õ���С·���� 
public static int uniquePaths(int[][] arr) {
      int m = arr.length;
      int n = arr[0].length;
    if (m <= 0 || n <= 0) return 0;
    int[][] dp = new int[m][n]; //��ʼ��
      dp[0][0] = arr[0][0];//��ʼ������ߵ���
      for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + arr[i][0];// ��ʼ�����ϱߵ���
      for(int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + arr[0][i];// ��ʼ������ߵ���
	  
    for (int i = 1; i < m; i++)////�Ƶ��� dp[m-1][n-1]
        for (int j = 1; j < n; j++) dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
    return dp[m-1][n-1];
}


