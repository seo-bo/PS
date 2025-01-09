#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[500001] = { 0, };
int result[500001] = { 0, };

int compare(const void* num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}

int lower_bound(int* ary, int size, int key)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int cen = (start + end + 1) / 2;
        if (ary[cen] >= key)
        {
            end = cen -1;
        }
        else
        {
            start = cen + 1;
        }
    }
    return end;
}

int upper_bound (int* ary, int size, int key)
{
    int start = 0, end = size - 1, cen =0;
    while (start <= end)
    {
        cen = (start + end + 1) / 2;
        if (ary[cen] > key)
        {
            end = cen -1;
        }
        else
        {
            start = cen + 1;
        }
    }
        return end;
}


int main() 
{
    int num = 0, num2 = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ary[i]);
    }
    scanf("%d", &num2);
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &result[i]);
    }
    qsort(ary, num, sizeof(int), compare);
    for (int i = 0; i < num2; i++)
    {
        int up = upper_bound(ary, num, result[i]);
        int low = lower_bound(ary, num, result[i]);
        int result = up - low;
        printf("%d ", result);
    }
}
