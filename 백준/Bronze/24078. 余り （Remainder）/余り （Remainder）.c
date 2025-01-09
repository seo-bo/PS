#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
    int num1 = 0;
    scanf("%d", &num1);
    while (num1 >= 21)
    {
        num1 -= 21;
    }
    printf("%d", num1);
}

