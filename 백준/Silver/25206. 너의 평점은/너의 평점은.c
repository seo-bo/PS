#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	float sresult = 0;
	float sum = 0;
	for (int i = 0; i < 20; i++)
	{
		char title[50] = { '/0', };
		char credit[4] = { '/0', };
		char score[3] = { '/0', };;
		scanf("%s %s %s", title, credit, score);
		float ncredit = (float)credit[0] - 48;
		sum += ncredit;
		float nscore;
		if (score[0] == 'A')
		{
			nscore = 4.0;
		}
		else if (score[0] == 'B')
		{
			nscore = 3.0;
		}
		else if (score[0] == 'C')
		{
			nscore = 2.0;
		}
		else if (score[0] == 'D')
		{
			nscore = 1.0;
		}
		else if (score[0] == 'F')
		{
			nscore = 0.0;
		}
		else if (score[0] == 'P')
		{
			nscore = 0.0;
			sum -= ncredit;
		}
		if (score[1] == '0')
		{
			nscore += 0;
		}
		else if (score[1] == '+')
		{
			nscore = nscore + 0.5;
		}

		sresult += ncredit * nscore;
	}
		printf("%f", sresult/sum);
}