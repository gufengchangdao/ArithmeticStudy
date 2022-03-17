//递归打印路径很重要，path[x2][y2].x1 path[x2][y2].y2   x1,y1,x2,y2分别为前一个点和后一个点
//通过递归不断追溯到第一次不断返回的的时候打印状态	
//dfs(x2,y2){
//	判断起点 
//	dfs(x1,y1);
//	打印x2,y2;
//}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std; 
const int maxn = 1e2 + 5;
struct pot{
	int k1;//桶A 
	int k2;//桶B 
	int op;//路径长 
};
struct path{
	int x;//桶A
	int y;//桶B 
//	int op;// 
	int step;
}path[maxn][maxn];
char str[][10] = { "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",  "POUR(2,1)", "POUR(1,2)"};
int A, B, C;
bool judge[maxn][maxn];

void my_clear(){//全部清空 
	struct path h = {0, 0, 0};
	memset(judge, 0, sizeof(judge));
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
		path[i][j]= h; 
}

// 递归打印路径 
void dfs(int x, int y){
	int a = path[x][y].x;
	int b = path[x][y].y;
	if (path[x][y].step == 0) { //递归出口，输出第一次操作，即充满A或者B 
		if (a == A)
			cout << str[0] << endl;
		else if (b == B) 
			cout << str[1] << endl; 
		return;
	}
	dfs(a, b);
	cout << str[path[x][y].op]<<  endl;//输出操作名 
}
void BFS(int v1, int v2, int L) {
	queue <pot> wat;
	pot start = {0, 0, 0};//初始 
	judge[0][0] = true;//标记 
	wat.push(start);//存入
	 
	while (!wat.empty()) {
		pot tep = wat.front();
		wat.pop();
		
		if (tep.k1 == L || tep.k2 == L) {//判断是否满足条件 
			cout << path[tep.k1][tep.k2].step << endl;//输出结果并打印路径 
			dfs(tep.k1, tep.k2);
			return ;
		}
		int temp;
		for (int i = 0; i < 6; i++) {
			switch(i) {
				/*6种状态*/ 
				case 0 : start.k1 = v1, start.k2 = tep.k2; break;  	//A fill
				case 1 : start.k1 = tep.k1; start.k2 = v2; break;	//B fill
				case 2 : start.k1 = 0, start.k2 = tep.k2; break;	//A empty
				case 3 : start.k1 = tep.k1; start.k2 = 0; break;	//B empty
				case 4 : temp = tep.k1 + tep.k2 - v1;				// B -> A
			     	if (temp > 0) {//大于0表示溢出 
						start.k2 = temp;
						start.k1 = v1; 
						}
					else {//小于等于0表示可以倒完 
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
			if (!judge[start.k1][start.k2]) {//未访问过 
				path[start.k1][start.k2].x = tep.k1;
				path[start.k1][start.k2].y = tep.k2;//记录前驱结点 
				path[start.k1][start.k2].op = i;//存入执行的操作序号 
				path[start.k1][start.k2].step = path[tep.k1][tep.k2].step + 1;//路径加一				
				judge[start.k1][start.k2] = true;//标记 
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

