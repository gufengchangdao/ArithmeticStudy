#include <stdio.h>
int main()
{
    int a[10][10];
    int i, j, n, m;
    scanf("%d%d",&m,&n);
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++)
            scanf("%d", &a[i][j]);
    }
    m=m%n;//�ȶ�mȡ�࣬�ܹؼ�������𰸻���� 
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++)
            printf("%d ", a[i][(j-m+n)%n]);//j-mΪ�����ƶ�m�Σ�+n�Ƿ�ֹ�и�������ȡ���ֹ����n 
    	printf("\n");
    }
    return 0;
}


