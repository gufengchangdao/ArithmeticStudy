二维数组传入函数
C语言里面对二维数组的存储是按照一维数组来处理的，二维数组按照行展开的方式按顺序存储，例如
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[6] = {1,2,3,4,5,6};	
	两者等同 ，所以在传入时要传入二维数组的列
void foo(int a[][3], int m, int n)
{
	
}	

