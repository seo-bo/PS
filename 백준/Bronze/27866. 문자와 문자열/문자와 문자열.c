#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char arr[1000];
	int num1 = 0;
	scanf("%s", arr);
	scanf("%d", &num1);
	printf("%c ", arr[num1 - 1]);
	
}
