#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

string grid[100];
int row = 0, col = 0;
int visited[101][101] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct war
{
    int x;
    int y;
    char mark;
};

int bfs(int start, int end, char mark)
{
    queue<war>q;
    visited[start][end] = 1;
    q.push({ start,end,mark });
    int cnt = 1;
    while (!q.empty())
    {
        war cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + direction[i][0];
            int ny = cur.y + direction[i][1];
            if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && grid[nx][ny] == cur.mark)
            {
                q.push({ nx,ny,mark });
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ll b = 0, w = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> col >> row;
    for (int i = 0; i < row; ++i)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (!visited[i][j])
            {
                int get = bfs(i, j, grid[i][j]);
                if (grid[i][j] == 'B')
                {
                    b += get * get;
                }
                else if (grid[i][j] == 'W')
                {
                    w += get * get;
                }
            }
        }
    }
    cout << w << " " << b;
    return 0;
}