#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

char ary[10];
char result[10];

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		int carry = 0, count =0;
		memset(ary, 0, sizeof(ary));
		memset(result, 0, sizeof(result));
		scanf("%s", ary);
		getchar();
		int size = strlen(ary);
		for (int j = 0; j < size; j++)
		{
			int temp = (ary[j] - '0') + (ary[size - 1 - j] - '0') + carry;
			result[j] = (temp % 10) + '0';
			carry = temp / 10;
		}
		if (carry > 0)
		{
			result[size] = carry + '0';
		}
		int newsize = strlen(result);
		int start = 0, end = newsize - 1;
		while (start <= end)
		{
			if (result[start] != result[end])
			{
				count++;
				break;
			}
			else
			{
				start++;
				end--;
			}
		}
		if (count != 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}