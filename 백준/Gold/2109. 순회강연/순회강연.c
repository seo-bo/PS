#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int visited[10001] = { 0, };

typedef struct Show
{
    int value;
    int day;
}Show;

typedef struct Heap
{
    int size;
    Show heap[10000];
}Heap;

Heap* create()
{
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
    h->size = 0;
}

void insert(Heap* h, Show num)
{
    int i = ++(h->size);
    while ((i != 1) && num.value > h->heap[i / 2].value)
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = num;
}

Show delete(Heap* h)
{
    int parent = 1;
    int child = 2;
    Show num = h->heap[1];
    Show temp = h->heap[(h->size)--];
    while (child <= h->size)
    {
        if ((child < h->size) && h->heap[child].value < h->heap[child + 1].value)
        {
            child++;
        }
        if (temp.value >= h->heap[child].value)
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
    Show* ary = (Show*)malloc(sizeof(Show) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &ary[i].value, &ary[i].day);
        getchar();
        insert(h, ary[i]);
    }
    for (int i = 0; i < num; i++)
    {
        Show temp = delete(h);
        while (temp.day > 0)
        {
            if (visited[temp.day] == 0)
            {
                visited[temp.day] = 1;
                result += temp.value;
                break;
            }
            else
            {
                temp.day--;
            }
        }
    }
    printf("%d", result);
}