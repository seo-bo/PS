#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
    int num1= 0;
    scanf("%d", &num1);
    int result1 = num1 * 0.78;
    int result2 = num1 - (num1 * 0.2) * 0.22;
    printf("%d %d", result1, result2);
}
