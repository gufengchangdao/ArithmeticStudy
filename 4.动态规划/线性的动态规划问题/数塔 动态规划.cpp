#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;//Ϊ���㷨д�����򵥣����ﶨ��һ���㹻����������洢����(Ϊ�˱�����������ж�̬����ռ䣬�����Ļ��㷨�������Ƚ��鷳������ֻ��Ϊ���㷨��������)
int data[N][N];//�洢����ԭʼ����
int dp[N][N];//�洢��̬�滮�����е�����,ֻ���������Բ��ã�����Ҫ��ѯ·���Ļ�Ҫ�� 
int n;//���Ĳ���
/*��̬�滮ʵ���������*/
void tower_walk()
{
    for (int i = 0; i < n; ++i)// �������ϼ��� 
        dp[n - 1][i] = data[n - 1][i];//dp�������һ�� 
        //�������� 
    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)// ʹ�õ��ƹ�ʽ����dp��ֵ
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + data[i][j];
}
/*��ӡ���ս��*/
void print_result()
{
    cout << "���·���ͣ�" << dp[0][0] << '\n';
    int node_value;
    cout << "���·����" << data[0][0];// �����������Ԫ�أ�Ȼ��������µ��������� 
    int j = 0;
    	//���϶��� 
    for (int i = 1; i < n; ++i){
        /* ���node_value == dp[i][j]��˵����һ��Ӧ����data[i][j]�����node_value == dp[i][j + 1]��˵����һ��Ӧ����data[i][j + 1]*/
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
//�Զ����µķ������Ե����ϵļ��� 
