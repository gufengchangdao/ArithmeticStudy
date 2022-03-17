//Flip Game
/*	
���⣺4*4�ķ�����кڰ��壬ÿ��һ��������ɫ��ת����������ҲҪ��ת�������ٶ��ٲ����Դﵽȫ�ڻ�ȫ�� 
	������� 
	ע��dfs�е�if�ж�д�� �ͱ��벻����Ⱥ���� 
*/
#include<stdio.h>
int a,step;
int goal1=(1<<16)-1,goal2=0; //ȫ�ڻ�ȫ�� 
bool flag=0;

bool check(int x,int y){
	return x>=0&&x<4&&y>=0&&y<4;
}
//�任һ�� 
void shift(int x,int y)
{
	a^=(1<<(x*4+y)); 
	if(x>0) a^=(1<<((x-1)*4+y)); 
	if(x<3) a^=(1<<((x+1)*4+y)); 
	if(y>0) a^=(1<<(x*4+y-1));
	if(y<3) a^=(1<<(x*4+y+1));  
}
//���� 
void dfs(int x,int y,int depth)
{
	if(depth==step){	//�ﵽ������ж� 
		if(a==goal1||a==goal2) flag=1;
		return;
	}
	if(flag||x==4) return;	//�����flagһ��Ҫ�жϣ���Ϊ�ҵ��𰸷��غ�depth!=step 
		
	shift(x,y);	//һ��Ҫ���жϱ任����������жϲ��仯��������������Ϊa��ȫ�ֱ��������� 
	if(y<3) dfs(x,y+1,depth+1);	//һ��һ������ 
	else dfs(x+1,0,depth+1);
	
	shift(x,y);
	if(y<3) dfs(x,y+1,depth);
	else dfs(x+1,0,depth);	
	return;
}

int main()
{
	char c;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			scanf(" %c",&c);
			if(c=='b') a|=(1<<(i*4+j));	//״̬ѹ�� 
		}
	for(step=0;step<=16;step++){	//������� 
		dfs(0,0,0);	//ע��ÿ�δ�depth=0��ʼ 
		if(flag) break;
	}
	if(flag) printf("%d\n",step);
	else printf("Impossible\n");
}
