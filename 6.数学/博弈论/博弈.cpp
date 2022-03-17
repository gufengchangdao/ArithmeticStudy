//	巴什博弈（Bash Game）
//  只有一堆n个物品，两个人从轮流中取出（1~m）个；最后取光者胜。
int Bash_Game(int n,int m)//是否先手有必赢策略
{
	if(m==1){
		if(m%2==0) return 0;
		else return 1;
	} 
	if(m>=n) return 1;//可以一次取完 
    if (n%(m+1)!=0) return 1;//如果n不是m+1的倍数，那么第一个人必赢 
    return 0;//否则第一个人必输 
}

