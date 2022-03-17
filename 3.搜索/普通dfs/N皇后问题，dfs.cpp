//N皇后问题 
#include<bits/stdc++.h>
using namespace std;
int n,tot=0;	//tot记录第n皇后的棋局个数 
int col[12]={0};	//记录皇后位置，col[n]为第n行第col[n]列
//判断是否符合条件 
bool check(int c,int r)	//c为列  r为行 
{
	for(int i=0;i<r;i++)	// 
		if(col[i]==c||(abs(col[i]-c)==abs(i-r)))	//是否在同一行或者处于对角线位置 
			return false;
	return true;
} 

void dfs(int r)	//一行一行递归 
{
	if(r==n){	//递归出口,因为从dfs(0)开始的，故第n行不用for循环 
		tot++;	//记录棋局个数 
		return;
	}
	for(int c=0;c<n;c++)	//寻找，类似上下左右移动 
		if(check(c,r)){
			col[r]=c;	//标记 
			dfs(r+1);
		}
}

int main()
{
	int ans[12]={0};//记录n皇后的棋局个数 
	//先打表，否则会超时 
	for(n=1;n<=10;n++){	//表示1到10皇后 
		memset(col,0,sizeof(col));
		tot=0;
		dfs(0);
		ans[n]=tot;
	}
	while(cin>>n){
		if(n==0) return 0;
		cout<<ans[n]<<endl;
	}
	return 0;
}
