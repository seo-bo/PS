#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* num1, const void* num2)
{
	return *(char*)num1 - *(char*)num2;
}

int rcompare(const void* num1, const void* num2)
{
	return *(char*)num2 - *(char*)num1;
}
char sound[9];
char upsound[9];
char downsound[9];

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		scanf("%s", &sound[i]);
	}
	strcpy(upsound, sound);
	strcpy(downsound, sound);
	qsort(upsound, 8, sizeof(char), compare);
	qsort(downsound, 8, sizeof(char),rcompare);

	if (strcmp(sound, upsound) == 0)
	{
		printf("ascending");
	}
	else if (strcmp(sound, downsound) == 0)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}

}


