#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[51] = { 0, };
char word1[51] = { 0, };
char word2[51] = { 0, };
char word3[51] = { 0, };
char result[51] = { 0, };

int reverse(char* ary, int size)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		char temp = ary[end];
		ary[end] = ary[start];
		ary[start] = temp;
		start++;
		end--;
	}
}

int main(void)
{
	scanf("%s", word);
	int size = strlen(word);
	for (int i = 1; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			char compare[51] = { 0, };
			strncpy(word1, word, i);
			word1[i] = '\0';
			strncpy(word2, word + i, j - i);
			word2[j - i] = '\0';
			strcpy(word3, word + j);
			int size1 = strlen(word1);
			int size2 = strlen(word2);
			int size3 = strlen(word3);
			reverse(word1, size1);
			reverse(word2, size2);
			reverse(word3, size3);
			strncat(compare, word1, size1);
			strncat(compare, word2, size2);
			strncat(compare, word3, size3);
			if (i == 1 && j == 2)
			{
				strcpy(result, compare);
			}
			else
			{
				if (strcmp(compare, result) < 0)
				{
					strcpy(result, compare);
				}
			}
		}
	}
	printf("%s\n", result);
}