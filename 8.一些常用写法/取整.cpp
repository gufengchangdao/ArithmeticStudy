#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

    double a = 77.001;
    double b = ceil(a);����ȡ�� 

    printf("b = %.3f\n",b);

    double c = 77.999;
    double d = floor(c);	����ȡ�� 
    printf("d = %.3f\n",d);
    return 0;
}

ǿ������ת��

printf("%.0f",a-0.5); 
 
