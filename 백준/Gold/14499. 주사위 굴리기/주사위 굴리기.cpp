#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
    cin.tie(0)->ios::sync_with_stdio(0);
    vector<int> dice(7, 0);
    vector<vector<int>> dir = { {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0} };
    int n = 0, m = 0, x = 0, y = 0, q = 0;
    cin >> n >> m >> x >> y >> q;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto& i : v)
    {
        for (auto& j : i)
        {
            cin >> j;
        }
    }
    while (q--)
    {
        int _ = 0;
        cin >> _;
        int nx = x + dir[_][0];
        int ny = y + dir[_][1];
        if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
        {
            continue;
        }
        int top = dice[1], bot = dice[6], north = dice[2], south = dice[5], east = dice[4], west = dice[3];
        if (_ == 1)
        {
            dice[1] = west, dice[3] = bot, dice[4] = top, dice[6] = east;
        }
        else if (_ == 2)
        {
            dice[1] = east, dice[3] = top, dice[4] = bot, dice[6] = west;
        }
        else if (_ == 3)
        {
            dice[1] = south, dice[2] = top, dice[5] = bot, dice[6] = north;
        }
        else if (_ == 4)
        {
            dice[1] = north, dice[2] = bot, dice[5] = top, dice[6] = south;
        }
        if (v[nx][ny])
        {
            dice[6] = v[nx][ny];
            v[nx][ny] = 0;
        }
        else
        {
            v[nx][ny] = dice[6];
        }
        cout << dice[1] << '\n';
        x = nx;
        y = ny;
    }
    return 0;
}