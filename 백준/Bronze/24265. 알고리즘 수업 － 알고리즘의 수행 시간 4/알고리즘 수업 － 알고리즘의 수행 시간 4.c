#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	long long num = 0;
	scanf("%lld", &num);
	printf("%lld\n%d",((num-1)*num)/2,2);
}

