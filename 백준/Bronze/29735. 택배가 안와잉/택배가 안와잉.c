#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char start[6];
char end[6];
int main(void)
{
	int inh = 0, inm = 0, outh = 0, outm = 0, temp =0, minus = 0;

	scanf("%s %s", start, end);
	scanf("%d %d", &temp, &minus);

	sscanf(start, "%d:%d", &inh, &inm);
	sscanf(end, "%d:%d", &outh, &outm);

	int time = 0, day = 0, resulth = 0;
	time = ((outh * 60) + outm) - ((inh * 60) + inm);
	day = (time % minus == 0) ? (time / minus - 1) : time / minus;
	resulth = ((temp % day + 1) * minus) + (inh * 60) + inm;

	printf("%d\n", temp /day);
	printf("%02d:%02d", resulth / 60, resulth % 60);
}