//���⣺1���پ������ٴμӻ�����Ա��n�����ԼӼ�֮ǰ�ļ����� 
//IDDFS��ָ���ݹ���ȣ���for()ѭ��ʵ�֣�����һ�����ڽ�����Ͳ�����ֹ����
//���ۺ�������ʹ�����ĵ�����ʽҲ�޷���ʣ�ಽ���ڴﵽn����ʱ�˳�
//�ݹ��ȣ�dfs�ж��˳��ͳ�����������ǰ����֮ǰ���������г��ԣ������ƶ����� 
#include<stdio.h>
#include<stdlib.h> //����abs()��Ҫ�� 
#include<iostream>
using namespace std;
int val[1010];//����ÿһ���ļ����� 
int pos,n;//posΪ�������� 

bool ida(int now,int depth)
{ 
	if(now>depth) return false;//�����趨����ȣ��˳� 
	if(val[pos]<<(depth-now)<n) return false;// ���ۺ��������ı���Ҳ�ﲻ�����˳�
	if(val[pos]==n) return true;//�����ݹ�ĳ��ڣ����������ﵽ��n
	//��ǰ�����֮ǰ����Ӽ�//posͬnow��ͬ�����ǵ�ǰ���	  
	pos++;//����һ�� 
	for(int i=0;i<pos;i++){//pos��ѭ��������ǰ��������ǰ�����е���(��������)��Ӽ��������ƶ����� 
		val[pos]=val[pos-1]+val[i];//�� 
		if(ida(pos,depth)) return true;
		val[pos]=abs(val[pos-1]-val[i]);//�� 
		if(ida(pos,depth)) return true;
	}
	pos--;//û���ҵ���ȡ����β��� 
	return false; 
}

int main()
{
	while(cin>>n&&n){
		int depth;//���� 
		for(depth=0;;depth++){//depth��0��ʼ��nowҲҪ��0��ʼ��Ҫ��֤n�Ƿ�Ϊ1��Ϊ1ʱdepth=0  
			val[pos=0]=1;//��1��ʼ���㣬pos=0,val[0]=1,����val[]��ֵ������ǰ����ó��ģ����Բ���Ҫ���� 
			if(ida(0,depth)) break;//ÿ��ֻdfs�����depth,�ҵ�������˳� 
		}
		cout<<depth<<endl;
	}
	return 0;
}
