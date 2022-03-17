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
    m=m%n;//先对m取余，很关键，否则答案会错误 
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++)
            printf("%d ", a[i][(j-m+n)%n]);//j-m为向左移动m次，+n是防止有负数，再取余防止超过n 
    	printf("\n");
    }
    return 0;
}


