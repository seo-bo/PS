#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x[3];
    

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &x[i]);
    }
    if (x[0] + x[1] + x[2] == 180)
    {
            if (x[0] == 60 && x[1] == 60 && x[2] == 60)
            {
                printf("Equilateral");
                
            }
            else if (x[0] != x[1] && x[0] !=x[2] && x[1] != x[2])
            {
                printf("Scalene");
            }
            else
            {
                printf("Isosceles");
               
            }
        }
    
    else
    
        printf("Error");
    
   
}