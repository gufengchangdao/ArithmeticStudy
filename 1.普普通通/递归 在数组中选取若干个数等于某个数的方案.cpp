	int goal/= 4;
  	int a[6]={ 4, 3, 2, 2, 1, 1 };
  	stack<int> s;
//选择第一个数 
void Calc(){
	int len=strlen(a);
    for(int i=0;i<len;i++){
     	if (a[i] == goal){
          //输出这个数+ 
      	}
      	else if (a[i] < goal){
      		//剩下 iArr[i]<a
      		stack.Clear();//初始化 
      		stack.Push(a[i]); 
      		Func(i,goal-a[i]);
  		}
  		else{
  			break;//如果数组已经排序，后面的数已经不可能，退出即可；如果未排序，不能要这一步 
		}
   	}
}
//选择后续数 
void Func(int i, int remain)
{
	int len=strlen(a);
    for (int j=i+1;j<len;j++){//j>=len便不在运行 
        if (remain==a[j]){
           	stack.Push(a[j]);
           	//输出stack 这一步略..
           	stack.Pop();//回到增加a[j]之前，尝试其他组合，一般有相等的数时需要这样，没有的话，这里直接退出就好 
        }
        else if(remain>a[j]){
           	stack.Push(a[j]);
          	Func(j,goal-a[j]);
        	stack.Pop();//j==strlen(a)时该组合也不行，回到增加a[j]之前 
        }
        else break;//总和大于需要值，返回 
    }
}
