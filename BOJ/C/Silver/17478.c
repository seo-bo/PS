
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	int len = 0;
	scanf("%d", &num);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	while (1)
	{
		if (num == -1)
		{
			break;
		}
		else if (num > 0)
		{
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("\"재귀함수가 뭔가요?\"\n");
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
			len += 4;
		}
		else if (num == 0)
		{
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("\"재귀함수가 뭔가요?\"\n");
			for (int j = 0; j < len; j++)
			{
				printf("_");
			}
			printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
			
				while (len>=0)
				{
					for (int j = 0; j < len; j++)
					{
						printf("_");
					}
					printf("라고 답변하였지.\n");
					len -= 4;
				}
			}
				num--;
		}
		
	}

