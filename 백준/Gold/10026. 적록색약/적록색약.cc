#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    int ans1 = 0, ans2 = 0;
    vector<vector<bool>> visited1(n, vector<bool>(n, false));
    vector<vector<bool>> visited2(n, vector<bool>(n, false));
    vector<vector<int>> dir = { {-1,0},{1,0},{0,-1},{0,1} };

    auto judge = [&](int x, int y, int nx, int ny, int d) -> bool
        {
            if (d == 1)
            {
                if (!visited1[nx][ny] && grid[x][y] == grid[nx][ny])
                {
                    return true;
                }
            }
            else
            {
                if (!visited2[nx][ny])
                {
                    if (grid[x][y] == grid[nx][ny] || (grid[x][y] == 'R' && grid[nx][ny] == 'G') || (grid[x][y] == 'G' && grid[nx][ny] == 'R'))
                    {
                        return true;
                    }
                }
            }
            return false;
        };

    auto bfs = [&](int x, int y, int d) -> void
        {
            queue<pii> q;
            q.push(make_pair(x, y));
            if (d == 1)
            {
                visited1[x][y] = true;
            }
            else
            {
                visited2[x][y] = true;
            }
            while (!q.empty())
            {
                pii cur = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nx = cur.first + dir[i][0];
                    int ny = cur.second + dir[i][1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                    {
                        if (judge(cur.first, cur.second, nx, ny, d))
                        {
                            q.push(make_pair(nx, ny));
                            if (d == 1)
                            {
                                visited1[nx][ny] = true;
                            }
                            else
                            {
                                visited2[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited1[i][j])
            {
                ans1++;
                bfs(i, j, 1);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited2[i][j])
            {
                ans2++;
                bfs(i, j, 2);
            }
        }
    }
    cout << ans1 << ' ' << ans2 << "\n";
    return 0;
}