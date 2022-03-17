//�ݹ��ӡ·������Ҫ��path[x2][y2].x1 path[x2][y2].y2   x1,y1,x2,y2�ֱ�Ϊǰһ����ͺ�һ����
//ͨ���ݹ鲻��׷�ݵ���һ�β��Ϸ��صĵ�ʱ���ӡ״̬	
//dfs(x2,y2){
//	�ж���� 
//	dfs(x1,y1);
//	��ӡx2,y2;
//}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std; 
const int maxn = 1e2 + 5;
struct pot{
	int k1;//ͰA 
	int k2;//ͰB 
	int op;//·���� 
};
struct path{
	int x;//ͰA
	int y;//ͰB 
//	int op;// 
	int step;
}path[maxn][maxn];
char str[][10] = { "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",  "POUR(2,1)", "POUR(1,2)"};
int A, B, C;
bool judge[maxn][maxn];

void my_clear(){//ȫ����� 
	struct path h = {0, 0, 0};
	memset(judge, 0, sizeof(judge));
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
		path[i][j]= h; 
}

// �ݹ��ӡ·�� 
void dfs(int x, int y){
	int a = path[x][y].x;
	int b = path[x][y].y;
	if (path[x][y].step == 0) { //�ݹ���ڣ������һ�β�����������A����B 
		if (a == A)
			cout << str[0] << endl;
		else if (b == B) 
			cout << str[1] << endl; 
		return;
	}
	dfs(a, b);
	cout << str[path[x][y].op]<<  endl;//��������� 
}
void BFS(int v1, int v2, int L) {
	queue <pot> wat;
	pot start = {0, 0, 0};//��ʼ 
	judge[0][0] = true;//��� 
	wat.push(start);//����
	 
	while (!wat.empty()) {
		pot tep = wat.front();
		wat.pop();
		
		if (tep.k1 == L || tep.k2 == L) {//�ж��Ƿ��������� 
			cout << path[tep.k1][tep.k2].step << endl;//����������ӡ·�� 
			dfs(tep.k1, tep.k2);
			return ;
		}
		int temp;
		for (int i = 0; i < 6; i++) {
			switch(i) {
				/*6��״̬*/ 
				case 0 : start.k1 = v1, start.k2 = tep.k2; break;  	//A fill
				case 1 : start.k1 = tep.k1; start.k2 = v2; break;	//B fill
				case 2 : start.k1 = 0, start.k2 = tep.k2; break;	//A empty
				case 3 : start.k1 = tep.k1; start.k2 = 0; break;	//B empty
				case 4 : temp = tep.k1 + tep.k2 - v1;				// B -> A
			     	if (temp > 0) {//����0��ʾ��� 
						start.k2 = temp;
						start.k1 = v1; 
						}
					else {//С�ڵ���0��ʾ���Ե��� 
						start.k2 = 0;
						start.k1 = tep.k1 + tep.k2;
						}
				break;
				case 5 : temp = tep.k1 + tep.k2 - v2;				//A -> B
				 	if (temp > 0) {
				 		start.k1 = temp;
				 		start.k2 = v2;
				 	}
				 	else{
				 		start.k1 = 0;
				 		start.k2 = tep.k1 + tep.k2;
				 	}
				break;
			}
			if (!judge[start.k1][start.k2]) {//δ���ʹ� 
				path[start.k1][start.k2].x = tep.k1;
				path[start.k1][start.k2].y = tep.k2;//��¼ǰ����� 
				path[start.k1][start.k2].op = i;//����ִ�еĲ������ 
				path[start.k1][start.k2].step = path[tep.k1][tep.k2].step + 1;//·����һ				
				judge[start.k1][start.k2] = true;//��� 
				wat.push(start);
			}
		}
	}
	cout << "impossible" << endl;
}
int main()
{
	while (cin >> A >> B >> C) {
		BFS(A, B, C);
		my_clear();
	}
	return 0;
}

