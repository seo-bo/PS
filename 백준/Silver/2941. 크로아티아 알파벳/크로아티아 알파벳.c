#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main()
{
	char arr[101] = { 0 };
	scanf("%s", arr);
	int count = 0;
	int size = strlen(arr);
	for (int i = 0; i < size; i++)
	{
		if ('-' <= arr[i])
		{
			count++;
		}
		
		if ((arr[i] == 'l' || arr[i] == 'n') && (arr[i + 1] == 'j'))
		{
			count--;
		}
		
		if (('a' < arr[i] < 'z') && (arr[i + 1] == '-' || arr[i + 1] == '='))
		{
			count--;
		}
		if ((arr[i] == 'd') && (arr[i + 1] == 'z')&&(arr[i+2] == '='))
		{
			count--;
		}
	}
	printf("%d", count);
}