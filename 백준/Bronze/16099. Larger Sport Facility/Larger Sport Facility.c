#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    int num1 = 0;
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++)
    {
        long long n1, n2, n3, n4 = 0;
        scanf("%lld %lld %lld %lld", &n1, &n2, &n3, &n4);
        long long p1 = n1 * n2;
        long long p2 = n3 * n4;
        if (p1 > p2)
        {
            printf("TelecomParisTech\n");
        }
        else if (p1 < p2)
        {
            printf("Eurecom\n");
        }
        else
            printf("Tie\n");
    }
}
