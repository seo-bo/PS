#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
    char ary[51];
    char bry[51];
    int count = 0;
    scanf("%s %s", ary, bry);
    int alen = strlen(ary);
    int blen = strlen(bry);
    int len = blen - alen;
    for (int i = 0; i < blen - alen; i++)
    {
        ary[alen + i] = '0';
        count++;
    }
    int num = 50;
    for (int i = 0; i <= len; i++)
    {
        count = 0;
        for (int j = 0; j < alen; j++)
        {
            if (ary[j] != bry[i + j])
            {
                count++;
            }   
        }   
        if (count <= num)
        {
            num = count;
        }
    }
    printf("%d", num);
}

