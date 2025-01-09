#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int size;
    long long heap[1000100];
}Heap;

Heap* create()
{
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
    h->size = 0;
}

void insert(Heap* h, long long num)
{
    int i = ++(h->size);
    while ((i != 1) && num < h->heap[i / 2])
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = num;
}

long long delete(Heap* h)
{
    int parent = 1;
    int child = 2;
    long long num = h->heap[1];
    long long temp = h->heap[(h->size)--];
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
    int test = 0;
    scanf("%d", &test);
    getchar();
    for (int k = 0; k < test; k++)
    {
        Heap* h = create();
        init(h);
        int num = 0;
        long long result = 0;
        scanf("%d", &num);
        long long* ary = (long long*)malloc(sizeof(long long) * num);
        for (int i = 0; i < num; i++)
        {
            scanf("%lld", &ary[i]);
            insert(h, ary[i]);
        }
        while (h->size > 1)
        {
            long long sum = 0;
            for (int i = 0; i < 2; i++)
            {
                sum += delete(h);
            }
            insert(h, sum);
            result += sum;
        }
        printf("%lld\n", result);
        free(h);
        free(ary);
    }
}