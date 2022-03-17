#include<stdio.h>
double jie(double n);
int main(void) 
{
	double n;
	while (scanf("%lf", &n) != EOF) {
		double i;
		double j;
		for (i = 1; i <= n; i++) {
			for (j = 0; j < i; j++) {
				if (i==1) 
					printf("%d\n",1);
				else if ( j == 0) 
					printf("%d ",1);
				else if (j == i - 1)
					printf("%d\n",1);
				else 
					printf("%.0f ", jie(i - 1) / (jie(j) * jie(i - 1 - j)));
			}
		}
		printf("\n");
	}
}
double jie(double n)
{
	if (n <= 1)
		return 1;
	else 
		return n * jie(n - 1);
}
