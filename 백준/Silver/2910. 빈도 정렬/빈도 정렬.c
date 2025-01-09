#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Sort
{
    int number;
    int count;
    int idx;
}Sort;

int sorted[1001] = { 0, };

int Min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int compare(const void* num1, const void* num2)
{
    if (((Sort*)num1)->number == ((Sort*)num2)->number)
    {
        return ((Sort*)num1)->idx - ((Sort*)num2)->idx;
    }
    else
    {
        return ((Sort*)num1)->number - ((Sort*)num2)->number;
    }
}

int resultcompare(const void* num1, const void* num2)
{
    if (((Sort*)num1)->count == ((Sort*)num2)->count)
    {
        return ((Sort*)num1)->idx - ((Sort*)num2)->idx;
    }
    else
    {
        return ((Sort*)num2)->count - ((Sort*)num1)->count;
    }
}

int main(void)
{
    int num = 0, num2 = 0, k = 0;
    scanf("%d %d", &num, &num2);
    getchar();
    Sort* ary = (Sort*)calloc(num, sizeof(Sort));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ary[i].number);
        ary[i].idx = i;
    }
    qsort(ary, num, sizeof(Sort), compare);
    ary[0].count++;
    for (int i = 1; i < num; i++)
    {
        if (ary[i].number == ary[k].number)
        {
            ary[k].count++;
            ary[k].idx = Min(ary[k].idx, ary[i].idx);
        }
        else
        {
            k++;
            ary[k].number = ary[i].number;
            ary[k].idx = ary[i].idx;
            ary[k].count++;
        }
    }
    qsort(ary, k + 1, sizeof(Sort), resultcompare);
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < ary[i].count; j++)
        {
            printf("%d ", ary[i].number);
        }
    }
}
