#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int compare(const void* num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}


int main(void) 
{
    int num = 0;
    scanf("%d", &num);
    getchar();
    int* ary = malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ary[i]);
    }
    qsort(ary, num, sizeof(int), compare);
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            printf("%d ", ary[i]);
        }
        else if (ary[i-1] != ary[i])
        {
            printf("%d ", ary[i]);
        }
    }
}