#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int cookie = 0, mod = 0;
		scanf("%d %d", &cookie, &mod);
		if (cookie % mod == 0)
		{
			printf("%d\n", cookie / mod);
		}
		else
		{
			printf("%d\n", cookie / mod + 1);
		}
	}
}