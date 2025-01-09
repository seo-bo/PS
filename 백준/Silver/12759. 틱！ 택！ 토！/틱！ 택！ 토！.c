#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int player = 0;
	scanf("%d", &player);
	int player2 = 3 - player;
	int arr[3][3] = { 0, };
	int result = 0;
	int num = 0;
	for (int i = 0; i < 9; i++)
	{
		int put1 = 0;
		int put2 = 0;
		scanf("%d %d", &put1, &put2);
		if (i % 2 == 0)
		{
			arr[put1 - 1][put2 - 1] = player;
		}
		else
		{
			arr[put1 - 1][put2 - 1] = player2;
		}
		if (result == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[j][0] == arr[j][1] && arr[j][2] == arr[j][1] && arr[j][0] == arr[j][2] && arr[j][0] != 0)
				{
					result = arr[j][0];
					break;

				}
				else if (arr[0][j] == arr[1][j] && arr[2][j] == arr[1][j] && arr[0][j] == arr[2][j] && arr[0][j] != 0)
				{
					result = arr[0][j];
					break;
				}
			}
			if (arr[0][0] == arr[1][1] && arr[2][2] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != 0)
			{
				result = arr[0][0];
				break;
			}
			else if (arr[0][2] == arr[1][1] && arr[2][0] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] != 0)
			{
				result = arr[0][2];
				break;
			}
		}
	}
	
	printf("%d", result);
	return 0;
}