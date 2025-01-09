#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int visited[1001] = { 0, };

typedef struct Task
{
    int value;
    int day;
}Task;

typedef struct Heap
{
    int size;
    Task heap[10000];
}Heap;

Heap* create()
{
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
    h->size = 0;
}

void insert(Heap* h, Task num)
{
    int i = ++(h->size);
    while ((i != 1) && num.value > h->heap[i / 2].value)
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = num;
}

Task delete(Heap* h)
{
    int parent = 1;
    int child = 2;
    Task num = h->heap[1];
    Task temp = h->heap[(h->size)--];
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
    Task* ary = (Task*)malloc(sizeof(Task) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &ary[i].day, &ary[i].value);
        getchar();
        insert(h, ary[i]);
    }
    for (int i = 0; i < num; i++)
    {
        Task temp = delete(h);
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