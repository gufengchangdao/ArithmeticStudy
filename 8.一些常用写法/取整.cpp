#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

    double a = 77.001;
    double b = ceil(a);向上取整 

    printf("b = %.3f\n",b);

    double c = 77.999;
    double d = floor(c);	向下取整 
    printf("d = %.3f\n",d);
    return 0;
}

强制类型转换

printf("%.0f",a-0.5); 
 
