#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int row = 0;
    int col = 0;
    int rowresult = 0;
    int colresult = 0;
    scanf("%d %d", &row, &col);
    char** ary = (char**)malloc(sizeof(char*) * (row)+1);
    for (int i = 0; i < row; i++)
    {
        ary[i] = (char*)malloc(sizeof(char) * (col)+1);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf(" %c", &ary[i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        int rowcount = 0;
        for (int j = 0; j < col; j++)
        {
            if (ary[i][j] == 'X')
            {
                rowcount++;
            }
        }
        if (rowcount == 0)
        {
            rowresult += 1;
        }
    }
    for (int i = 0; i < col; i++)
    {
        int colcount = 0;
        for (int j = 0; j < row; j++)
        {
            if (ary[j][i] == 'X')
            {
                colcount++;
            }
        }
        if (colcount == 0)
        {
            colresult += 1;
        }
    }
    if (rowresult > colresult)
    {
        printf("%d", rowresult);
    }
    else if (rowresult < colresult)
    {
        printf("%d", colresult);
    }
    else if (rowresult == colresult)
    {
        printf("%d", colresult);
    }
    for (int i = 0; i < row; i++)
    {
        free(ary[i]);
    }
    free(ary);

}