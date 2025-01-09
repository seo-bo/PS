#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int Alp[26];
int main()
{
	char arr[1000001];
	scanf("%s", arr);
	
	char result;
	int num = 0;
	int size = strlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 'a')
		{
			Alp[arr[i] - 'a']++;
		}
		else
			Alp[arr[i] - 'A']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (Alp[i] == num)
		{
			result = '?';
		}
		else if (Alp[i] > num)
		{
			num = Alp[i];
			result = 'A' + i;
		}
	}
	printf("%c", result);
}