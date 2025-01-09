#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long numa = 0, numb = 0;
	scanf("%lld %lld", &numa, &numb);
	long long chi = 0;
	scanf("%lld", &chi);
	if (((numa + numb) - 2 * chi) >= 0)
	{
		printf("%lld", ((numa + numb) - 2 * chi));
	}
	else
		printf("%lld", numa + numb);
}

