#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
    int num1 = 0;
    scanf("%d", &num1);
    int result = pow((num1 + 1) * (2) - num1 - 1 - (num1), num1);
    printf("%d", result);
}
