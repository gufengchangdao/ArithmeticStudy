#include<bits/stdc++.h>
#define Maxn 10
using namespace std;
int pos[Maxn];//pos[i]  ��i����������ʹ�õڼ���λ��
int T,n;
int deep;//DNA������С����
char c[10] = "ACGT";//ģ�壬���������ƶ����������� 
struct node
{
    char list[Maxn];     //DNA�����
    int len;     //DNA����
}dna[Maxn];//a[i]  ��i��DNA����

int init()//Ԥ������ʣ�೤��
{
    int ans=0;
    for(int i=0;i<n;i++)//�ܳ���-����ʹ�õ�λ��=ʣ�»�û�õ�λ�� ������ʣ�೤��
        ans=max(ans,dna[i].len-pos[i]);
    return ans;
}

int dfs(int step)
{
    if(step+init()>deep)//���ۺ�����Ԥ������ʣ�೤��+��ǰ����>����DNA���е���С����
        return 0;
    if(init()==0)//����Сdeep�´ﵽ���е�DNA���ж��źã��������
        return 1;
        
    int pre[Maxn];//�Ƚ�pos����������һ�����Ҫ�ã�һ��������Ϊȫ�ֱ��� 
	for(int j=0;j<n;j++)//����pos
        pre[j]=pos[j];
        
    for(int i=0;i<4;i++){//�������У���λ�÷ֱ���ΪA��T��G��Cһһ���� 
        int f=0;
        for(int j=0;j<n;j++){//i==0ʱ������A������DNA������֤�Ƿ�ǰλ��ΪA������Aʱ���԰Ѹ�λ������ΪA 
            if(c[i]==dna[j].list[pos[j]]){
                f=1;
                pos[j]++;//�Ѹ�λ����ΪA��Ҫ������һλ 
            }
        }
        if(f){
            if(dfs(step+1))//�з��ϵģ���������������λ��ΪA�󣬳���������һλ 
                return 1;
            for(int j=0;j<n;j++)//����,û���ҵ�����������������pos��ֵ�ı䣬���ݵ�ԭ����ֵ 
                pos[j]=pre[j];
        }
    }
    return 0;//����ʡȥ��û���ҵ���������ֵ0�Ļ���Ĭ��Ϊ�ҵ��� 
}
int main()
{
    cin>>T;
    while(T--){
        deep=0;//�Լ������DNA������С����
        cin>>n;
        	for(int i=0;i<n;i++){//��ֵ
        	    cin>>dna[i].list;//cin>>������  ����ֱ�Ӷ�ȡһ���ַ����������ո� 
        	    dna[i].len=strlen(dna[i].list);
        	    deep=max(deep,dna[i].len);//deep�����һ����ʼ����ʡʱ�� 
        	    pos[i]=0;//�������дӵ�һ���ַ���ʼ���� 
        	}
    	for(deep;;deep++)//һ�����ڴ� 
    	    if(dfs(0)) break;	
    	cout<<deep<<endl;
    }
    return 0;
}
