//Flip Game
/*	
题意：4*4的方格放有黑白棋，每对一个棋子颜色翻转，上下左右也要翻转，问至少多少步可以达到全黑或全白 
	深度搜索 
	注意dfs中的if判断写法 和变与不变的先后次序 
*/
#include<stdio.h>
int a,step;
int goal1=(1<<16)-1,goal2=0; //全黑或全白 
bool flag=0;

bool check(int x,int y){
	return x>=0&&x<4&&y>=0&&y<4;
}
//变换一次 
void shift(int x,int y)
{
	a^=(1<<(x*4+y)); 
	if(x>0) a^=(1<<((x-1)*4+y)); 
	if(x<3) a^=(1<<((x+1)*4+y)); 
	if(y>0) a^=(1<<(x*4+y-1));
	if(y<3) a^=(1<<(x*4+y+1));  
}
//深搜 
void dfs(int x,int y,int depth)
{
	if(depth==step){	//达到深度再判断 
		if(a==goal1||a==goal2) flag=1;
		return;
	}
	if(flag||x==4) return;	//这里的flag一定要判断，因为找到答案返回后depth!=step 
		
	shift(x,y);	//一定要先判断变换的情况，再判断不变化的情况，否则会因为a是全局变量而出错 
	if(y<3) dfs(x,y+1,depth+1);	//一行一行搜索 
	else dfs(x+1,0,depth+1);
	
	shift(x,y);
	if(y<3) dfs(x,y+1,depth);
	else dfs(x+1,0,depth);	
	return;
}

int main()
{
	char c;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			scanf(" %c",&c);
			if(c=='b') a|=(1<<(i*4+j));	//状态压缩 
		}
	for(step=0;step<=16;step++){	//深度搜索 
		dfs(0,0,0);	//注意每次从depth=0开始 
		if(flag) break;
	}
	if(flag) printf("%d\n",step);
	else printf("Impossible\n");
}
