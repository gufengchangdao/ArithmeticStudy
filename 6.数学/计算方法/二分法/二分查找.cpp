//���ֲ��Һ���
//���ֲ��ҵ�������Ϊlog(n)/log(2)+1��nΪint�͵�
mid���󷨡�whileѭ���Ľ���������s[mid]=goalʱ��ȡ��	
˼·���ȿ���goal�����ڵ����,���һ������[k(l),goal,k+1(r)]��������ڿ���goal���ֵ���� 
	mid=(r+l)>>1;(ÿ�ζ���ȡ���)
	1.����goal�����ڵ������ѭ����[k(l),goal,k+1(r)]��ʱ��	
		(l<=r):mid=l; l+=1;��ʱl==r :mid=l=r; r-=1;--->[k(r),goal,k+1(l)]
		(l<r): --->[k,goal,k+1(l==r)]
	2.����goal��ʱ��
		(l<=r):if(s[mid]==goal) return mid;	�õ��� 
						    	l=mid;	��Ϊ[mid(l),l+1] mid����ȡl,��������ѭ�� 
								r=mid; 	��Ϊ[goal(l==r)],���ж�����Ϊ�棬Ҳ����ѭ�� 
		(l<r):					l=mid; mid==l==goal��������ѭ��,Ҳ������ģ�����r=mid(goal)-1��ʱ�� 
		 						r=mid;	l==r==goal �˳�ѭ�����õ��� 
	mid=(r+l+1)>>1;(ÿ�ζ���ȡ�ұ�)	
	1.����goal�����ڵ����
		(l<=r):r�ȶ���l�󶯣�ͬ����� 
		(l<r): --->[k(l==r),goal,k+1] 
	2.����goal��ʱ��
		(l<=r):if(s[mid]==goal)	 return mid;
								 l=mid; ��Ϊ[mid(l),l+1] mid����ȡr,���mid==l==r,��ѭ�� 
								 r=mid; ��ѭ�� 
		(l<r):					 l=mid;	mid==l==r���˳�ѭ�����õ��� 
								 r=mid; mid==r==goal���������ѭ��
�ܽ᣺midÿ��ȡ��߲��Ҵ���s[mid]==goal��ʱ������l=mid,  ȡ�ұ߲���r=mid;								 
	  while(l<=r)����s[mid]==goal��ʱ��l��r�����ܵ���mid
	  ������з��գ�����ģ����� 
								 	
������ 							
binary_search(s,s+size,goal);//����ĳ��Ԫ���Ƿ���֣��ҵ������棬���򷵻ؼ�
lower_bound�����ҵ�һ�����ڻ����ĳ��Ԫ�ص�λ����first��last�е�ǰ�պ�������ж��ֲ��ң����ش���
	�����val�ĵ�һ��Ԫ��λ�á��������Ԫ�ض�С��val���򷵻�last��λ�ã���last��λ����Խ��ģ�
	int pos1=lower_bound(a,a+6,7)-a;    //���������е�һ�����ڻ���ڱ�������ֵ������a�Ѿ�����С�����ź��� 
upper_bound�����ҵ�һ������ĳ��Ԫ�ص�λ��

//���ֲ��ҿ�� 
int binarySearch(int s[], int goal){
    int l=0,r=nums.length-1;
    while(l<=r){ 
        int mid=(r+l)/2;//mid����ȡ�����޵��е㣬�����������޶�Ӧֵ���е㣬����ҪС��������� 
        if(s[mid]==goal)
            return mid;//�������ޣ�Ҫȡ�ϸ���ڡ�С�ڵ�ʱ������Ҫ�Ķ� 
        else if(s[mid]<goal)
            l=mid+1;
        else 
            r=mid-1;
        }
    return -1;	//ȡ�ϸ���ڻ���С�ڵ�ʱ������ҲҪ�Ķ� 
    //return l; 	���Ҵ��ڵ���goal������λ�ã�������ʱ����[r,left,l] 
    //return r;		����С�ڵ���goal������λ�� 
}

int binarySearch(int s[], int goal){
    int l=0,r=nums.length-1;
    while(l<=r){ 
        int mid=(r+l)/2;
        if(s[mid]<=goal) l=mid+1;	//���Ҫ����r 
        else r=mid-1;
    //    if(s[mid]<goal) l=mid+1;
    //    else r=mid-1;		�����ڵ�ʱ����һ���һ�������ڵ�ʱ��Ҫ����l(goal) 
		}
    return r; //����ֵ��<=goal 

//���ַ������������������֮�͵���Ŀ��ֵ���������
void binarySearch(int s[], int goal){
    int left=0,right=nums.length-1;
    while(left<right){  
        if(s[left]+s[right]==goal)
            ...//ȫ�ֱ����������� 
        else if(s[left]+s[right]<goal)
            left++;
        else
            right--;
        }
}
//���ֲ�����߽����⣺ 
int left_bound(int goal)
{
	int l=0,r=19,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(s[mid]==goal) l=mid;
		else if(s[mid]<goal) l=mid;//���ȥ���Ⱥŵ������l�ͻ��ϸ�С��goal,����Ҳ�п������l=l 
		else r=mid-1;//Ҫ������߽磬����Ҫ����߱ƽ�,�Ǿ���r��"����"һЩ 
	}
	return l;							   
}  										  
//���ֲ��Ҵ��ڵ���Ŀ��ֵ 
int right_bound(int goal)
{
	int l=0,r=len,mid;	//ע�⣬����r������ 
	while(l<r){	//��r=mid����l<r 
		mid=l+(r-l)>>1;	//�ȼ���ӣ���ֹ������ 
		if(s[mid]==goal) return mid;	//�ҵ�Ŀ��ֵ 
		else if(s[mid]>goal) r=mid;
		else l=mid+1;
	}
	return l;	//�ҵ���Ŀ����ֵ����l==len 
}


 
