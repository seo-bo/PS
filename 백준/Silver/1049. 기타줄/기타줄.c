#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int main(void)
{
	int need = 0, type = 0;
	scanf("%d %d", &need, &type);
	int* bundle = (int*)malloc(sizeof(int) * type);
	int* piece = (int*)malloc(sizeof(int) * type);
	int* case_ = (int*)malloc(sizeof(int) * 3);
	for (int i = 0; i < type; i++)
	{
		scanf("%d %d", &bundle[i], &piece[i]);
	}
	qsort(bundle, type, sizeof(int), compare);
	qsort(piece, type, sizeof(int), compare);
	case_[0] = ((need / 6) * bundle[0]) + ((need % 6) * piece[0]);
	case_[1] = ceil(((double)need / 6)) * bundle[0];
	case_[2] = need * piece[0];
	qsort(case_, 3, sizeof(int), compare);
	printf("%d", case_[0]);
	free(bundle);
	free(piece);
	free(case_);
}
