#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
    int num1, num2 = 0;
    scanf("%d %d", &num1, &num2);
    if (num1 == num2)
    {
        printf("%d", 1);
    }
    else
        printf("%d", 0);
}
