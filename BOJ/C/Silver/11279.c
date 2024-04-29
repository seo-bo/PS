
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int size;
	int heap[100000];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, int num)
{
	int i = ++(h->size);//만약에 이놈이 첫놈이면 인덱스 1, 즉 루트에 들어가겠지??
	while ((i != 1) && num > h->heap[i / 2]) // 왜냐면 최후방으로 들어가니까 당연히 적당히 노드가 있으면, 이새끼 그냥 자식이잖아 근데 얘 부모랑 비교하는거지?
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	int root = h->heap[1];
	int temp = h->heap[h->size--];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child] < h->heap[child + 1]) // 여기서 child+1이 더 작은 값을 갖는다는 사실을 알 수 있지?
		{
			child++;
		}
		if (temp >= h->heap[child])
		{
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return root;
}

int main(void)
{
	Heap* h = create();
	init(h);
	int test = 0;
	scanf("%d", &test);
	while (test--)
	{
		int get = 0;
		scanf("%d", &get);
		switch (get)
		{
			case 0:
			{
				if (h->size == 0)
				{
					printf("0\n");
				}
				else
				{
					printf("%d\n", delete(h));
				}
				break;
			}
			default:
			{
				insert(h, get);
				break;
			}
		}
	}
}
