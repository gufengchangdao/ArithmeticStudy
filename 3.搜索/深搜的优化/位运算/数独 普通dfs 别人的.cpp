//����
/*
���⣺9*9�� 
	��ͨdfs 

Ԥ���� 
	Ԥ�������������м���������ѡcnt[i] 
	Ԥ�����nλΪ1������1��9�е�n,sum[i]=n
����һ������s
��ʼ��:
	�ö�ά���鴢��s������
 	������row��������col�����оŹ���g��Ϊȫ1
	����ÿһ���㣬���С��С��Ź����й�������һλ��Ϊ0����ͳ�ƿ�λ�ĸ���t
dfs������
	����ÿ�С�ÿ���ҵ�������������ٵĵ�(x,y)���Ըõ�����޸ġ�����������
	�ҵ��������˳�
*/
#include<iostream>
using namespace std;
int row[10],col[10],g[10],num[512],cnt[512],t;
char str[10][10];

int gc(int x,int y){//����ά������һά�����飬��9��9*9�ĸ���״̬��Ϊ1��0��8��һά�����ʾ 
    return ((x/3)*3+y/3);//������ǵڼ�������
}

void wei(int x,int y,int z){
    row[x]^=1<<z;//�����꣬��ǣ���ʾ��x����z+1�Ѿ��У�row[x]��zλ��Ϊ0 
    col[y]^=1<<z;//�����꣬��λ���ʹ�ø�Ϊ0��1��1��0 
    g[gc(x,y)]^=1<<z;//�Ź����е�����
}

int lowbit(int x)//Ѱ�Ҷ����������һ��1 ��λ��
{
   return x&(-x); 
}

int dfs(int n)
{
    if(n==0)//����û�п���������˾ͷ���1
    	return 1;
    	
    int temp=10,x,y;
    for(int i=0;i<=8;i++)//ͨ�������ҳ�����������С����һ��
    	for(int j=0;j<=8;j++){
        	if(str[i][j]!='.') continue;
        	int val=row[i]&col[j]&g[gc(i,j)];//�õ������ּ�Ϊ�����������
        	if(!val) return 0; //û���������� 
        	if(cnt[val]<temp){
            	temp=cnt[val];
            	x=i,y=j;//�ҵ���С�ģ�����x,y��¼λ��
        	}
    	}
    //ÿ�δ�������������ٵ�һ��(x,y) 
    int val=row[x]&col[y]&g[gc(x,y)];
    for(;val;val-=lowbit(val)){//�ȱ���������д�����֣�����С�Ŀ�ʼ 
        int z=num[lowbit(val)];
        
		str[x][y]='1'+z;//��ΪzΪ0��8 
        wei(x,y,z);
        if(dfs(n-1)) return 1;//���ϱ�����ֱ���ҵ�һ����󣬳������ 
    
		wei(x,y,z);//���� 
        str[x][y]='.';
    }
    return 0;//�޽� 
}

int main()
{
  	for(int i=0;i<(1<<9);i++)
  		for(int j=i;j;j-=lowbit(j))//i��ʾ��������������У�Ԥ��������i���ж��ٸ�1 
  			cnt[i]++;
  	for(int i=0;i<=8;i++) //num[i]��ʾi���б�ʾ������ȥ1��Ĵ�С 
  		num[1<<i]=i;
  		
  	char s[100];
  	while(~scanf("%s",s)&&s[0]!='e'){
     	for(int i=0;i<=8;i++)
      		for(int j=0;j<=8;j++)
      			str[i][j]=s[i*9+j];//�Զ�ά��ʽ��ʾ 
      	for(int i=0;i<=8;i++)
      		row[i]=col[i]=g[i]=(1<<9)-1;//���ݵĳ�ʼ����Ϊ9��1 
      	t=0;
      	for(int i=0;i<=8;i++)
      		for(int j=0;j<=8;j++)
        		if(str[i][j]!='.')
          			wei(i,j,str[i][j]-'1');//�Ը������������� 
        		else
          			t++;//ͳ���ж��ٿ�����д��λ��
          			
        dfs(t);
        for(int i=0;i<=8;i++)
          	for(int j=0;j<=8;j++)
          		s[i*9+j]=str[i][j];//��ά��һά 
        puts(s);  
  }
}

