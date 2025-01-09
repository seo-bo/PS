#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
    long long A, B = 0;
    scanf("%lld %lld", &A, &B);
    long long result = (A + B) * (A - B);
    printf("%lld", result);
}
