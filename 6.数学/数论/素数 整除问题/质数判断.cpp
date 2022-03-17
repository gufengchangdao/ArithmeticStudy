bool isPrime( int num )
{
	//num小于5时另外处理 
	if(n<5){
	    if(n==2||n==3) return true;
	    return false;
	}
	//不在6的倍数两侧的数一定不是质数 
	if(num%6!=1&&num%6!= 5)
	    return false;
	    
	int temp=sqrt(num);
	//判断6的倍数两侧的数是否为质数 
	for(int i=5;i<=temp;i+=6)
	    if(num %i== 0||num %(i+ 2)==0 )
	        return false;
	//是质数 
	return true ;
}
//质数分布规律：大于等于5的质数一定和6的倍数相邻，即6n-1,6n+1;
//对于循环中的6i-1	6i	6i+1 6i+2 6i+3 6i+4 ,	
//6i,6i+2,6i+4为偶数，但6n-1,6n+1明显为奇数
//6i+3明显为3的倍数，6n为3的倍数，6n-1,6n+1明显不是 
//所以只用判断6i-1和6i+1，即  i从5开始步长为6的循环中判断n取余i和i+2的情况 
