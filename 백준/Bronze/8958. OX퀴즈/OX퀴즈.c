#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	return *(char*)num1 - *(char*)num2;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int result = 0;
		int score = 0;
		char ary[81] = { 0, };
		scanf("%s", ary);
		int size = sizeof(ary) / sizeof(char);
		for (int j = 0; j < size; j++)
		{
			if (ary[j] == 'O')
			{
				if (ary[j] != ary[j - 1])
				{
					score = 1;
					result += score;
				}
				else if (ary[j] == ary[j - 1])
				{
					score = score + 1;
					result += score;
				}
			}
			else
			{
				score = 0;
			}
		}
		printf("%d\n", result);
	}

}


