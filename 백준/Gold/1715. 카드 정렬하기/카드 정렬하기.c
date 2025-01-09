#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int size;
    int heap[100010];
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
    int i = ++(h->size);
    while ((i != 1) && num < h->heap[i / 2])
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
    int num = h->heap[1];
    int temp = h->heap[(h->size)--];
    while (child <= h->size)
    {
        if (child < h->size && h->heap[child] > h->heap[child + 1])
        {
            child++;
        }
        if (temp <= h->heap[child])
        {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return num;
}

int main(void)
{
    Heap* h = create();
    init(h);
    int num = 0, result = 0;
    scanf("%d", &num);
    int* ary = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ary[i]);
        insert(h, ary[i]);
    }
    while (h->size > 1)
    {
        int sum = 0;
        for (int i = 0; i < 2; i++)
        {
            sum += delete(h);
        }
        insert(h, sum);
        result += sum;
    }
    printf("%d", result);
}