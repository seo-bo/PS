#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char arr[4];
	scanf("%s", arr);
	char temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;
	for (int i = 0; i < 3; i++)
	{
		printf("%c", arr[i]);
	}
}