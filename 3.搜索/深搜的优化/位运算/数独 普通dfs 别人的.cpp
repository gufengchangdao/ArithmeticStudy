//数独
/*
题意：9*9的 
	普通dfs 

预处理 
	预处理所有数列有几个数可以选cnt[i] 
	预处理第n位为1的数是1到9中的n,sum[i]=n
读入一行数据s
初始化:
	用二维数组储存s中数字
 	所有行row、所有列col、所有九宫格g都为全1
	处理每一个点，对行、列、九宫格有过的数那一位变为0；并统计空位的个数t
dfs搜索：
	遍历每行、每列找到可以填的数最少的点(x,y)，对该点进行修改、搜索、回溯
	找到任意解就退出
*/
#include<iostream>
using namespace std;
int row[10],col[10],g[10],num[512],cnt[512],t;
char str[10][10];

int gc(int x,int y){//将二维数组变成一维的数组，把9个9*9的格子状态变为1个0到8的一维数组表示 
    return ((x/3)*3+y/3);//计算的是第几个方格
}

void wei(int x,int y,int z){
    row[x]^=1<<z;//横坐标，标记，表示第x行数z+1已经有，row[x]第z位变为0 
    col[y]^=1<<z;//纵坐标，按位异或，使得该为0变1，1变0 
    g[gc(x,y)]^=1<<z;//九宫格中的数字
}

int lowbit(int x)//寻找二进制中最后一个1 的位置
{
   return x&(-x); 
}

int dfs(int n)
{
    if(n==0)//若果没有可填的数字了就返回1
    	return 1;
    	
    int temp=10,x,y;
    for(int i=0;i<=8;i++)//通过遍历找出可填数字最小的那一个
    	for(int j=0;j<=8;j++){
        	if(str[i][j]!='.') continue;
        	int val=row[i]&col[j]&g[gc(i,j)];//得到的数字即为可以填的数字
        	if(!val) return 0; //没有数可以填 
        	if(cnt[val]<temp){
            	temp=cnt[val];
            	x=i,y=j;//找到最小的，并用x,y记录位置
        	}
    	}
    //每次处理可填数字最少的一个(x,y) 
    int val=row[x]&col[y]&g[gc(x,y)];
    for(;val;val-=lowbit(val)){//先遍历可以填写的数字，从最小的开始 
        int z=num[lowbit(val)];
        
		str[x][y]='1'+z;//因为z为0到8 
        wei(x,y,z);
        if(dfs(n-1)) return 1;//不断遍历，直到找到一个解后，程序结束 
    
		wei(x,y,z);//回溯 
        str[x][y]='.';
    }
    return 0;//无解 
}

int main()
{
  	for(int i=0;i<(1<<9);i++)
  		for(int j=i;j;j-=lowbit(j))//i表示可以填的数的数列，预处理数列i中有多少个1 
  			cnt[i]++;
  	for(int i=0;i<=8;i++) //num[i]表示i数列表示的数减去1后的大小 
  		num[1<<i]=i;
  		
  	char s[100];
  	while(~scanf("%s",s)&&s[0]!='e'){
     	for(int i=0;i<=8;i++)
      		for(int j=0;j<=8;j++)
      			str[i][j]=s[i*9+j];//以二维形式表示 
      	for(int i=0;i<=8;i++)
      		row[i]=col[i]=g[i]=(1<<9)-1;//数据的初始化，为9个1 
      	t=0;
      	for(int i=0;i<=8;i++)
      		for(int j=0;j<=8;j++)
        		if(str[i][j]!='.')
          			wei(i,j,str[i][j]-'1');//对给定的数处理标记 
        		else
          			t++;//统计有多少可以填写的位置
          			
        dfs(t);
        for(int i=0;i<=8;i++)
          	for(int j=0;j<=8;j++)
          		s[i*9+j]=str[i][j];//二维变一维 
        puts(s);  
  }
}

