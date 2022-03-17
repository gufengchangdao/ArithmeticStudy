//快速排序用了二分、递归的思想
//二分：不断交换两边的数，再把基准值移动到“中间”使得左边的数小于基准值，右边的数大于基准值 
//递归：基准值归为一次，一个分成两个，再对两个基准值归为，再分，再......
 
#include <stdio.h>
int a[101],n;	//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)//left和right分别指向序列最左边和最右边 
{
 	int i,j,swap,temp;
 	
 	if(left>=right) return;//细分到只有一个数为递归出口 
 	
 	temp=a[left]; //temp中存的就是基准数
 	i=left;
 	j=right;
 	while(i!=j){//左右点相遇是出口 
 	//一定要先从右边开始找，从右边找比基点小的，从左边找比基点大的，交换再在中间插入基点 
 		while(a[j]>=temp && i<j)//要么找到满足条件的点要么相遇是出口 
 			j--;
 		//再从左边开始找 
 		while(a[i]<=temp && i<j)
 			i++;
 		//倘若两下标未相遇，代表存在两点，交换两个数在数组中的位置
 		if(i<j){
 			swap=a[i];
 			a[i]=a[j];
 			a[j]=swap;
 		}
 	}
 	
 	//最终将基准数归位：基准值与相遇点交换 
 	a[left]=a[i];
 	a[i]=temp; 	
 	quicksort(left,i-1);//继续处理左边的
 	quicksort(i+1,right);//继续处理右边的
//快速排序的每一轮处理其实就是将这一轮的基准数归位，直到所有的数都归位为止，排序就结束了

}	
int main()
{
	int i,j;
	//读入数据
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 	quicksort(1,n); //快速排序调用
 	//输出排序后的结果
 	for(i=1;i<=n;i++)
 		printf("%d ",a[i]);
 	return 0;
}
