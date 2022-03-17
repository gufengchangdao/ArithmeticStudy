
树状数组
	解决大部分基于区间上的更新以及求和问题
	树状数组可以解决的问题都可以用线段树解决，但比线段树好写
	每个节点储存一个数组数值 c[i]为节点值，A[i]为数组值
int a[1005],c[1005]; //对应原数组和树状数组
C[1] = A[1];
C[2] = A[1] + A[2];
C[3] = A[3];
C[4] = A[1] + A[2] + A[3] + A[4];
C[5] = A[5];
C[6] = A[5] + A[6];
C[7] = A[7];
C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];
规律： 
C[i] = A[i - 2^k+1] + A[i - 2^k+2] + ... + A[i];   //k为i的二进制中从最低位到高位连续零的长度 
即为c[i]有2^k个数相加

求前n项和：
SUMi = C[i] + C[i-2^k1] + C[i-2^k1-2^k2] + .....;
int getsum(int i){        //求A[i]中1~i的和
    int res = 0;
    while(i > 0){//i减小到0不再改变，故如果a[i]从0开始，a[0]任何时候都不会加进去 
        res += c[i];//从c[i]开始累加，i不断减小 
        i -= lowbit(i);
    }
    return res;
}

求lowbit=2^k;
规律：2^k=x&(-x)
int lowbit(int x){
    return x&(-x);
}

x为0时结果为0
x为奇数时结果为1(最后一位为1，取反加1没有进位，故x和-x除了最后一位相同其他的都相反，按位与结果为0，最后结果为1) 
x为偶数时结果为x中2的最大次方的因子(8&(-8)==8、12&(-12)==4)

改变A[i]的时候，同样要变的是 C[i + 2^k]、C[(i + 2^k) + 2^k]...；
void updata(int i,int k){    //在i位置加上k，要从从c[j]改到c[n] 
    while(i <= n){//与a[i]有关的c[j]，其中j>=i; 
        c[i] += k;//这里允许c[i]可以小于0 
        i += lowbit(i);
    }
} 
