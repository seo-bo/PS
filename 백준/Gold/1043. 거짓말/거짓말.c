#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

int parent[MAX];
int count[MAX];
int know[MAX];
int party[MAX][MAX];

int find(int num) 
{
    if (num == parent[num])
    {
        return num;
    }
    return parent[num] = find(parent[num]);
}

void Union(int temp1, int temp2) 
{
    int root1 = find(temp1);
    int root2 = find(temp2);
    if (temp1 != temp2)
    {
        parent[root1] = root2;
    }
}

int main(void) 
{
    int human = 0, contest = 0, truth = 0;
    scanf("%d %d", &human, &contest);
    getchar();
    for (int i = 1; i <= human; i++) 
    {
        parent[i] = i;
    }
    scanf("%d", &truth);
    getchar();
    for (int i = 0; i < truth; i++) 
    {
        scanf("%d", &know[i]);
        getchar();
    }

    for (int i = 0; i < contest; i++)
    {
        scanf("%d", &count[i]);
        getchar();
        for (int j = 0; j < count[i]; j++)
        {
            scanf("%d", &party[i][j]);
            getchar();
            if (j > 0)
            {
                Union(party[i][0], party[i][j]);
            }
        }
    }
    for (int i = 0; i < truth; i++) 
    {
        Union(0, know[i]);
    }
    int result = 0;
    for (int i = 0; i < contest; i++) 
    {
        if (find(0) != find(party[i][0]))
        {
            result++;
        }
    }

    printf("%d", result);
    return 0;
}
