int 10^9	//������32λ����(��������) 
unsigned int 10^9
long long 10^18
unsigned long long 10^19
double //������׼ȷ��ǰ17λ����ȷ��С�����6λ���������� 

//ע�⣺
int a,b;
long long sum;
sum=a*b;//a��b����int�͵ģ�����Ժ�ת��Ϊint�͵��ٴ���sum������a*b����10^9�ͻᱬ�� 
sum=1ll*a*b;//��1ll*a��aת��Ϊlong long �;Ϳ�����
 
//����int��
#include<climits>
//������������
	INT_MAX=2147483647 
	INT_MIN=-2147483648
//��limits.h�������¶���
	#define INT_MAX 2147483647
	#define INT_MIN (-INT_MAX - 1)
INT_MAX+1=INT_MIN //������ȡ��һ�� 
INT_MAX+INT_MAX=-2
 
