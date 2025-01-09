#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char arr[101];
	char brr[101];
	int num1 = 0;
	scanf("%s", arr);
	for (int i = 0; i < (strlen(arr)); i++)
	{
		brr[i] = arr[strlen(arr) - 1 - i];
	}
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == brr[i])
		{
			num1++;
		}
	}
	if (num1 != strlen(arr))
	{
		num1 = 0;
	}
	else
		num1 = 1;
	printf("%d", num1);
}