#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int ary[10000] = { 0, };
    int bry[10000] = { 0, };
    int len = 0;
    int num = 0;
    int j = 0;
    scanf("%d %d", &len, &num);
    for (int i = 0; i <len; i++)
    {
        ary[i] = i+1;
        if ((len % ary[i]) == 0)
        {
            bry[j] = ary[i];
            j++;
        }
    }
 
    printf("%d", bry[num-1]);
}