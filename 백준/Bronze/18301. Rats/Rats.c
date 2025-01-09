#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
    int num1, num2, num3 = 0;
    scanf("%d %d %d", &num1, &num2, &num3);
    int result = floor(((num1 + 1) * (num2 + 1)) / (num3 + 1) - 1);
    printf("%d", result);
}
