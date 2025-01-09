#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
    int num1, num2, num3, num4 = 0;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    int result = (56 * num1) + (24 * num2) + (14 * num3) + (6 * num4);
    printf("%d", result);
}
