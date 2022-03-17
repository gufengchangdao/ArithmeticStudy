
//v[i][j]表示价值 

void FindMax()//动态规划，使用递推的思想与数组结合 
{
    int i,j;	//i，j分别表示物品和此时的背包容量 
    //填表
    for(i=1;i<=number;i++)
    {
        for(j=1;j<=capacity;j++){	//注；v[i][0]和v[0][j]都为初始为0,v[i][j]的值一步步求出并且互不影响 
            if(j<w[i])//w[i]为第i个背包的重量，包装不进
                V[i][j]=V[i-1][j];//第i-1个到第i个，表示第i个物体不包装 
            else//能装
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);//比较装与不装哪个价值大 
                    //V[i][j]=V[i-1][j];不装价值不变 
                    //V[i][j]=V[i-1][j-w[i]]+v[i];装的价值，前i-1个物品的最优解与第i个物品的价值之和更大
        }
    }
}//v[number][capacity]即为最优解 

void FindWhat(int i,int j)//寻找解的组成方式,item[i]装上就为1，不装就为0 
{
    if(i>=0){//递归出口，i由number减少到0，标记的i等于1  
        if(V[i][j]==V[i-1][j]){//相等说明没装
            item[i]=0;//全局变量，标记未被选中
            FindWhat(i-1,j);
        }
        else if( j-w[i]>=0 && V[i][j]==V[i-1][j-w[i]]+v[i] ){
            item[i]=1;//标记已被选中
            FindWhat(i-1,j-w[i]);//回到装包之前的位置
        }
    }
}//输出 item[i]=1对应的i即可 

