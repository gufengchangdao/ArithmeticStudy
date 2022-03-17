归并排序：
	核心是合并 
原理：不断把数列二分，直到分的只有两个数，可知不用排序，每一步有左右两部分，两部分在上一步已经
	分别排好序，不断进行比较，把小数装入临时数组temp即可完成排序，类似交换排序的升级版，复杂度和
	快排一样

void mergesort(int l, int r, int *A){
	//递归二分部分 
	if (l >= r) return;
	int mid = (l + r) >> 1;
	mergesort(l, mid, A); 
	mergesort(mid + 1, r, A);
	//合并部分	
	int i = l, j = mid + 1, cnt= 0;
	while(i<=mid&&j<= r){	
		if (A[i] <= A[j]) temp[cnt++] = A[i++];
		else{
			temp[cnt++] = A[j++];
		//	ans+=mid-i+1;	//ans用来求逆序数个数 
		}
	}
	while(i <= mid) temp[cnt++] = A[i++];//比较完一个子数列，把剩下的子数列的数放入 
	while(j<= r) temp[cnt++] = A[j++];
	for (i=0;i<cnt;i++) A[i+l] = temp[i];//赋给原数组 
} 
 
