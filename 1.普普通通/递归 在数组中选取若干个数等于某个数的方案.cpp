	int goal/= 4;
  	int a[6]={ 4, 3, 2, 2, 1, 1 };
  	stack<int> s;
//ѡ���һ���� 
void Calc(){
	int len=strlen(a);
    for(int i=0;i<len;i++){
     	if (a[i] == goal){
          //��������+ 
      	}
      	else if (a[i] < goal){
      		//ʣ�� iArr[i]<a
      		stack.Clear();//��ʼ�� 
      		stack.Push(a[i]); 
      		Func(i,goal-a[i]);
  		}
  		else{
  			break;//��������Ѿ����򣬺�������Ѿ������ܣ��˳����ɣ����δ���򣬲���Ҫ��һ�� 
		}
   	}
}
//ѡ������� 
void Func(int i, int remain)
{
	int len=strlen(a);
    for (int j=i+1;j<len;j++){//j>=len�㲻������ 
        if (remain==a[j]){
           	stack.Push(a[j]);
           	//���stack ��һ����..
           	stack.Pop();//�ص�����a[j]֮ǰ������������ϣ�һ������ȵ���ʱ��Ҫ������û�еĻ�������ֱ���˳��ͺ� 
        }
        else if(remain>a[j]){
           	stack.Push(a[j]);
          	Func(j,goal-a[j]);
        	stack.Pop();//j==strlen(a)ʱ�����Ҳ���У��ص�����a[j]֮ǰ 
        }
        else break;//�ܺʹ�����Ҫֵ������ 
    }
}
