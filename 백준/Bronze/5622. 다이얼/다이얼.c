#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char arr[26];
	int result = 0;
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}
	scanf("%s", arr);
	
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] - 'A' == 0 || arr[i] - 'A' == 1 || arr[i] - 'A'== 2)
			arr[i] = 2;
		if (arr[i] - 'D' == 0 || arr[i] - 'D' == 1 || arr[i] - 'D' == 2)
			arr[i] = 3;
		if (arr[i] - 'G' == 0 || arr[i] - 'G' == 1 || arr[i] - 'G' == 2)
			arr[i] = 4;
		if (arr[i] - 'J' == 0 || arr[i] - 'J' == 1 || arr[i] - 'J' == 2)
			arr[i] = 5;
		if (arr[i] - 'M' == 0 || arr[i] - 'M' == 1 || arr[i] - 'M' == 2)
			arr[i] = 6;
		if (arr[i] - 'P' == 0 || arr[i] - 'P' == 1 || arr[i] - 'P' == 2|| arr[i] - 'P' == 3)
			arr[i] = 7;
		if (arr[i] - 'T' == 0 || arr[i] - 'T' == 1 || arr[i] - 'T' == 2)
			arr[i] = 8;
		if (arr[i] - 'W' == 0 || arr[i] - 'W' == 1 || arr[i] - 'W' == 2|| arr[i] - 'W' == 3)
			arr[i] = 9;
		if (arr[i] == '\n')
			arr[i] = 0;
	}
	for (int i = 0; i < 26; i++)
	{
		result += arr[i];
	}
	printf("%d", result + strlen(arr));


}