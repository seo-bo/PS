#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {

	int arr[26];
	char brr[100];
	scanf("%s", brr);
	

	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	for (int i = 97; i <= 122; i++)
	{

		for (int j = 0; j < strlen(brr); j++)
		{
			if (brr[j] == i)
			{
				arr[brr[j] - 'a'] = j;
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {

		printf("%d ", arr[i]);

	}

	return 0;

}