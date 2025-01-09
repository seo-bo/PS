#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    cin >> n;
    vector<vector<int>>graph(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int e1 = 0, e2 = 0;
        cin >> e1 >> e2;
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }
    vector<int>ans(n + 1);
    vector<bool>visited(n + 1,false);
    visited[1] = true;
    function<void(int)> dfs = [&](int start) ->void
        {
            for (auto& i : graph[start])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    ans[i] = start;
                    dfs(i);
                }
            }
        };
    dfs(1);
    for (int i = 2; i <= n; ++i)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}