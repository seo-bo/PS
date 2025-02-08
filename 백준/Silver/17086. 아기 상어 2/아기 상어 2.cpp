#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
    int n = 0, m = 0, ans =0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pii> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
            if (v[i][j])
            {
                q.push(make_pair(i, j));
                visited[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == -1)
            {
                visited[nx][ny] = visited[cur.first][cur.second] + 1;
                ans = max(ans, visited[nx][ny]);
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << ans;
    return 0;
}