//二分查找函数
//二分查找的最大次数为log(n)/log(2)+1，n为int型的
mid的求法、while循环的结束条件、s[mid]=goal时的取法	
思路：先考虑goal不存在的情况,最后一定出现[k(l),goal,k+1(r)]的情况，在考虑goal出现的情况 
	mid=(r+l)>>1;(每次都是取左边)
	1.考虑goal不存在的情况：循环到[k(l),goal,k+1(r)]的时候	
		(l<=r):mid=l; l+=1;此时l==r :mid=l=r; r-=1;--->[k(r),goal,k+1(l)]
		(l<r): --->[k,goal,k+1(l==r)]
	2.存在goal的时候
		(l<=r):if(s[mid]==goal) return mid;	得到答案 
						    	l=mid;	因为[mid(l),l+1] mid总数取l,所以是死循环 
								r=mid; 	因为[goal(l==r)],该判断总是为真，也是死循环 
		(l<r):					l=mid; mid==l==goal成立，死循环,也有例外的，比如r=mid(goal)-1的时候 
		 						r=mid;	l==r==goal 退出循环，得到答案 
	mid=(r+l+1)>>1;(每次都是取右边)	
	1.考虑goal不存在的情况
		(l<=r):r先动，l后动，同样结果 
		(l<r): --->[k(l==r),goal,k+1] 
	2.存在goal的时候
		(l<=r):if(s[mid]==goal)	 return mid;
								 l=mid; 因为[mid(l),l+1] mid总是取r,最后mid==l==r,死循环 
								 r=mid; 死循环 
		(l<r):					 l=mid;	mid==l==r，退出循环，得到答案 
								 r=mid; mid==r==goal恒成立，死循环
总结：mid每次取左边并且存在s[mid]==goal的时候不能让l=mid,  取右边不能r=mid;								 
	  while(l<=r)并且s[mid]==goal的时候l、r都不能等于mid
	  灵活多变有风险，套用模板最保险 
								 	
函数： 							
binary_search(s,s+size,goal);//查找某个元素是否出现，找到返回真，否则返回假
lower_bound：查找第一个大于或等于某个元素的位置在first和last中的前闭后开区间进行二分查找，返回大于
	或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置，且last的位置是越界的！
	int pos1=lower_bound(a,a+6,7)-a;    //返回数组中第一个大于或等于被查数的值，数组a已经有由小到大排好序 
upper_bound：查找第一个大于某个元素的位置

//二分查找框架 
int binarySearch(int s[], int goal){
    int l=0,r=nums.length-1;
    while(l<=r){ 
        int mid=(r+l)/2;//mid必须取两下限的中点，而不是两下限对应值的中点，这里要小心数据溢出 
        if(s[mid]==goal)
            return mid;//返回下限，要取严格大于、小于的时候这里要改动 
        else if(s[mid]<goal)
            l=mid+1;
        else 
            r=mid-1;
        }
    return -1;	//取严格大于或则小于的时候这里也要改动 
    //return l; 	查找大于等于goal的数的位置，结束的时候有[r,left,l] 
    //return r;		查找小于等于goal的数的位置 
}

int binarySearch(int s[], int goal){
    int l=0,r=nums.length-1;
    while(l<=r){ 
        int mid=(r+l)/2;
        if(s[mid]<=goal) l=mid+1;	//最后要返回r 
        else r=mid-1;
    //    if(s[mid]<goal) l=mid+1;
    //    else r=mid-1;		不存在的时候与一般的一样，存在的时候，要返回l(goal) 
		}
    return r; //返回值是<=goal 

//二分法求从升序数组中两数之和等于目标值满足的两数
void binarySearch(int s[], int goal){
    int left=0,right=nums.length-1;
    while(left<right){  
        if(s[left]+s[right]==goal)
            ...//全局变量保存下限 
        else if(s[left]+s[right]<goal)
            left++;
        else
            right--;
        }
}
//二分查找左边界问题： 
int left_bound(int goal)
{
	int l=0,r=19,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(s[mid]==goal) l=mid;
		else if(s[mid]<goal) l=mid;//如果去掉等号的情况，l就会严格小于goal,不过也有可能最后l=l 
		else r=mid-1;//要查找左边界，所以要向左边逼近,那就让r更"主动"一些 
	}
	return l;							   
}  										  
//二分查找大于等于目标值 
int right_bound(int goal)
{
	int l=0,r=len,mid;	//注意，这里r超界了 
	while(l<r){	//有r=mid就有l<r 
		mid=l+(r-l)>>1;	//先减后加，防止数爆了 
		if(s[mid]==goal) return mid;	//找到目标值 
		else if(s[mid]>goal) r=mid;
		else l=mid+1;
	}
	return l;	//找到比目标大的值或者l==len 
}


 
