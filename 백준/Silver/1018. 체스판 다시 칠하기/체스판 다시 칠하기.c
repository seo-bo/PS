#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chess[52][52] = { 0, };
int dp[52][52] = { 0, };

int Min(int num1, int num2) 
{
    return num1 < num2 ? num1 : num2;
}

int main(void)
{
    int row = 0, col = 0, mini = 64;
    scanf("%d %d", &row, &col);

    for (int i = 1; i <= row; i++)
    {
        scanf("%s", chess[i] + 1);
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if ((i + j) % 2 == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (chess[i][j] == 'W');
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (chess[i][j] == 'B');
            }
        }
    }

    for (int i = 8; i <= row; i++)
    {
        for (int j = 8; j <= col; j++)
        {
            int result = dp[i][j] - dp[i - 8][j] - dp[i][j - 8] + dp[i - 8][j - 8];
            mini = Min(mini, Min(result, 64 - result));
        }
    }

    printf("%d", mini);
}
