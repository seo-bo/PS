#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Road
{
    int start;
    int end;
    int dis;
}Road;

typedef struct Heap
{
    int size;
    Road heap[100010];
}Heap;

Heap* create()
{
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap*h)
{
    h->size = 0;
}

void insert(Heap* h, Road num)
{
    int i = ++(h->size);
    while ((i != 1) && num.start < h->heap[i / 2].start)
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = num;
}

Road delete(Heap* h)
{
    int parent = 1;
    int child = 2;
    Road num = h->heap[1];
    Road temp = h->heap[(h->size)--];
    while (child <= h->size)
    {
        if (child < h->size && h->heap[child].start > h->heap[child + 1].start)
        {
            child++;
        }
        if (temp.start <= h->heap[child].start)
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

int Max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int Min(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}

int compare(const void* num1, const void* num2)
{
    if (((Road*)num1)->end == ((Road*)num2)->end)
    {
        return ((Road*)num1)->start - ((Road*)num2)->start;
    }
    else
    {
        return ((Road*)num1)->end - ((Road*)num2)->end;
    }
}

int main(void) 
{
    Heap* h = create();
    init(h);
    int num = 0, len = 0, result = 0;
    scanf("%d", &num);
    Road* ary = (Road*)malloc(sizeof(Road) * num);
    for (int i = 0; i < num; i++)
    {
        int temp1 = 0, temp2 = 0;
        scanf("%d %d", &temp1, &temp2);
        ary[i].start = Min(temp1, temp2);
        ary[i].end = Max(temp1, temp2);
        ary[i].dis = abs(temp1 - temp2);
    }
    scanf("%d", &len);
    qsort(ary, num, sizeof(Road), compare);
    for (int k = 0; k < num; k++)
    {
        if (ary[k].dis <= len)
        {
            insert(h, ary[k]);
            while (h->size > 0 && h->heap[1].start < ary[k].end - len)
            {
                delete(h);
            }
            result = Max(result, h->size);
        }
    }
    printf("%d", result);
}