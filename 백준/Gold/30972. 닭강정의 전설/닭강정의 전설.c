#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[5001][5001] = { 0, };
int sum[5001][5001] = { 0, };
int calc(int num1, int num2, int num3, int num4)
{
    int result1 = (sum[num3][num4] - sum[num1 - 1][num4] - sum[num3][num2 - 1] + sum[num1 - 1][num2 - 1]) * (-1);
    int result2 = sum[num3 - 1][num4 - 1] - sum[num1][num4 - 1] - sum[num3 - 1][num2] + sum[num1][num2];
    return (result1 + result2 + result2);
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            scanf("%d", &ary[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ary[i][j];
        }
    }
    int get = 0;
    scanf("%d", &get);
    for (int i = 0; i < get; i++)
    {
        int a = 0, b = 0, c = 0, d = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int drunk = calc(a, b, c, d);
        printf("%d\n", drunk);
    }
}