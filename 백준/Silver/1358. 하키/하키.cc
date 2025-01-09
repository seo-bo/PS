#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w = 0, h = 0, x = 0, y = 0, p = 0, r = 0, ans = 0;
    cin >> w >> h >> x >> y >> p;
    r = h / 2;
    vector<pii> c = { {x, y + r}, {x + w, y + r} };
    for (int i = 0; i < p; ++i)
    {
        int nx = 0, ny = 0;
        cin >> nx >> ny;
        bool check = false;
        for (int j = 0; j < 2; ++j)
        {
            int dx = nx - c[j].first;
            int dy = ny - c[j].second;
            if (dx * dx + dy * dy <= r * r)
            {
                check = true;
            }
        }
        if (x <= nx && nx <= x + w && y <= ny && ny <= y + h)
        {
            check = true;
        }
        if (check)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}