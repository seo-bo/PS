#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> v(r, vector<int>(c, -1));
    vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < r; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; ++j)
        {
            if (str[j] == 'O')
            {
                v[i][j] = 3;
            }
        }
    }
    for (int k = 2; k <= n; ++k)
    {
        if (k % 2 == 0)
        {
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (v[i][j] == -1)
                    {
                        v[i][j] = k + 3;
                    }
                }
            }
        }
        else
        {
            vector<vector<int>> temp = v;
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (v[i][j] == k)
                    {
                        temp[i][j] = -1;
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = i + dir[z][0];
                            int ny = j + dir[z][1];
                            if (nx >= 0 && ny >= 0 && nx < r && ny < c)
                            {
                                temp[nx][ny] = -1;
                            }
                        }
                    }
                }
            }
            v = temp;
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (v[i][j] == -1)
            {
                cout << '.';
            }
            else
            {
                cout << 'O';
            }
        }
        cout << '\n';
    }
    return 0;
}