#include<bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
int result[11];
int visited[11];

void dfs(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                result[depth] = i;
                dfs(depth + 1);
                visited[i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dfs(0);
    return 0;
}