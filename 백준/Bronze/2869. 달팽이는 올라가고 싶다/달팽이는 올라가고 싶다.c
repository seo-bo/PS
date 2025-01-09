#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int up = 0, down = 0, len = 0, result =0;
	scanf("%d %d %d", &up, &down, &len);
	result = (len - down -1) / (up - down) +1;
	printf("%d", result);
}

