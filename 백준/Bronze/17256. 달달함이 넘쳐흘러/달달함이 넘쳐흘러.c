#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int a1, a2, a3 = 0;
    int c1, c2, c3 = 0;
    scanf("%d %d %d", &a1, &a2, &a3);
    scanf("%d %d %d", &c1, &c2, &c3);
    printf("%d %d %d", c1 - a3, c2 / a2, c3 - a1);
}
