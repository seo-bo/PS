#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() 
{
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = num - i; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}

