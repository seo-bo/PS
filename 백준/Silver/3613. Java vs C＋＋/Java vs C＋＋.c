#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char o_o[150];
char x_x[150];

int main(void)
{
	int java = 0, cpp = 0;
	fgets(o_o, 110, stdin);
	o_o[strcspn(o_o, "\n")] = '\0';
	int size = strlen(o_o);
	if (o_o[0] == '_' || o_o[size - 1] == '_' || isupper(o_o[0])) {
		printf("Error!");
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (isupper(o_o[i]))
		{
			java = 1;
		}
		if (o_o[i] == '_')
		{
			if (o_o[i + 1] == '_' || i + 1 == size) {
				printf("Error!");
				return 0;
			}
			cpp = 1;
		}
	}
	if (java && cpp)
	{
		printf("Error!");
		return 0;
	}
	int k = 0;
	if (java)
	{
		for (int i = 0; i < size; i++)
		{
			if (isupper(o_o[i]))
			{
				x_x[k++] = '_';
				x_x[k++] = tolower(o_o[i]);
			}
			else
			{
				x_x[k++] = o_o[i];
			}
		}
	}
	else if (cpp)
	{
		for (int i = 0; i < size; i++)
		{
			if (o_o[i] == '_')
			{
				i++;
				x_x[k++] = toupper(o_o[i]);
			}
			else
			{
				x_x[k++] = o_o[i];
			}
		}
	}
	else
	{
		printf("%s", o_o);
		return 0;
	}
	x_x[k] = '\0';
	printf("%s", x_x);
	return 0;
}
