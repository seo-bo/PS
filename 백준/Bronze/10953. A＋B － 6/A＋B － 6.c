#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() 
{
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        int num1 = 0;
        int num2 = 0;
        scanf("%d,%d", &num1, &num2);
        printf("%d\n", num1 + num2);
    }
}

