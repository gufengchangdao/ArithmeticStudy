#include<stdio.h>
#include<math.h>
int main(){ 
	printf("%f\n",log(10)); //��eΪ�׵Ķ������� 
	printf("%f\n",log10(100)); //log()��log2()��log10()�ǹ��к��� 
	printf("%f\n",log2(8));
	printf("%f\n",log(8)/log(2)); //����log2^8,���û��׹�ʽ
	printf("%f\n",exp(1)); //������Ȼ����e,exp��n��ֵΪe^n�η�
	printf("%f\n",log(exp(5)));
	return 0;
}

��������Ϊdouble�ͣ�Ҳ����ǿ������ת��Ϊint��
���ã�����sum�ж���λ��(int)log10(sum) 
