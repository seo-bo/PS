#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int ary[2];

    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            scanf("%d", &ary[i]);
        }
        if (ary[0] == 0 && ary[1] == 0)
        {
            return 0;
        }
        else if (ary[0] % ary[1] == 0 || ary[1] % ary[0] == 0)
        {
            if (ary[0] > ary[1])
            {
                printf("multiple\n");
            }
            else if (ary[0] < ary[1])
            {
                printf("factor\n");
            }
        }
        else
        {
            printf("neither\n");
        }

        
    }
}