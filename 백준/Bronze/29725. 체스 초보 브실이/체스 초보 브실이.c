#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char chess[10][10] = { 0, };
int main(void)
{
	int white = 0;
	for (int i =0; i< 8; i++)
	{
		fgets(chess[i], 9, stdin);
		getchar();
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess[i][j] == 'P')
			{
				white += 1;
			}
			else if (chess[i][j] == 'p')
			{
				white -= 1;
			}
			else if (chess[i][j] == 'N')
			{
				white += 3;
			}
			else if (chess[i][j] == 'n')
			{
				white -= 3;
			}
			else if (chess[i][j] == 'B')
			{
				white += 3;
			}
			else if (chess[i][j] == 'b')
			{
				white -= 3;
			}
			else if (chess[i][j] == 'R')
			{
				white += 5;
			}
			else if (chess[i][j] == 'r')
			{
				white -= 5;
			}
			else if (chess[i][j] == 'Q')
			{
				white += 9;
			}
			else if (chess[i][j] == 'q')
			{
				white -= 9;
			}
		}
	}
	printf("%d", white);
}