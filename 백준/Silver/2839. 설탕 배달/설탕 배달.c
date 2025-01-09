#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() 
{
    int num = 0;
    int count = 0;
    scanf("%d", &num);
    while (1)
    {
        if (num < 0)
        {
            count = -1;
            break;
        }
        else if (num == 0)
        {
            break;
        }
        if (num % 5 == 0)
        {
                count += num / 5;
                num = 0;
                break;
        }
        if (num % 3 == 0 && num % 5 != 0)
        {
            count++;
            num -= 3;
        }
        if (num % 3 != 0 && num % 5 != 0)
        {
            count++;
            num -= 5;
        }
    }
    printf("%d", count);
}

