#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    ll n = 0;
    cin >> n;
    vector<ll>v(n);
    for (auto& i : v)
    {
        cin >> i;
    }
    vector<ll>table(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        table[i] = table[i / 2] + 1;
    }
    ll m = table[n];
    vector<vector<ll>>mini(m + 1, vector<ll>(n));
    vector<vector<ll>>maxi(m + 1, vector<ll>(n));
    auto min_query = [&](ll left, ll right) -> ll
        {
            ll pivot = table[right - left + 1];
            return min(mini[pivot][left], mini[pivot][right - (1 << pivot) + 1]);
        };
    auto max_query = [&](ll left, ll right) -> ll
        {
            ll pivot = table[right - left + 1];
            return max(maxi[pivot][left], maxi[pivot][right - (1 << pivot) + 1]);
        };
    vector<ll> div;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (i < n)
            {
                div.push_back(i);
            }
            if (n / i != i && n / i < n)
            {
                div.push_back(n / i);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        mini[0][i] = maxi[0][i] = v[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; (j + (1 << i)) <= n; ++j) 
        {
            mini[i][j] = min(mini[i - 1][j], mini[i - 1][j + (1 << (i - 1))]);
            maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][j + (1 << (i - 1))]);
        }
    }
    sort(div.begin(), div.end());
    for (auto& i : div)
    {
        ll maxx = max_query(0, i - 1), minn = min_query(0, i - 1);
        ll sum = maxx + minn;
        bool check = true;
        for (int j = 1; j < n / i; ++j)
        {
            ll left = j * i, right = left + i - 1;
            ll tmx = max_query(left, right), tmn = min_query(left, right);
            if (tmx + tmn != sum)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
