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
    ll ans = 0;
    int n = 0, m = 0;
    cin >> n >> m;
    vector<unordered_map<string, vector<ll>>> v(4); // 4사분면, 기울기, 거리
    for (int i = 0; i < n; ++i)
    {
        ll x = 0, y = 0;
        cin >> x >> y;
        ll sum = x * x + y * y;
        if (!x && y > 0) // |(1, inf)
        {
            v[0]["INF"].push_back(sum);
        }
        else if (x < 0 && !y) // ㅡ(2, 0)
        {
            v[1]["0"].push_back(sum);
        }
        else if (!x && y < 0) // |(3, inf)
        {
            v[2]["INF"].push_back(sum);
        }
        else if (x > 0 && !y) // ㅡ(4, 0)
        {
            v[3]["0"].push_back(sum);
        }
        else if (x > 0 && y > 0) // 1사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            v[0][s].push_back(sum);
        }
        else if (x < 0 && y > 0) // 2사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            v[1][s].push_back(sum);
        }
        else if (x < 0 && y < 0) // 3사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            v[2][s].push_back(sum);
        }
        else if (x > 0 && y < 0)// 4분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            v[3][s].push_back(sum);
        }
    }
    for (auto& i : v)
    {
        for (auto& j : i)
        {
            if (!j.second.empty())
            {
                sort(j.second.begin(), j.second.end());
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        ll x = 0, y = 0;
        cin >> x >> y;
        ll sum = x * x + y * y;
        if (!x && y > 0) // |(1, inf)
        {
            if (!v[0]["INF"].empty())
            {
                size_t idx = lower_bound(v[0]["INF"].begin(), v[0]["INF"].end(), sum) - v[0]["INF"].begin();
                ans = max(ans, (ll)(idx + (idx < v[0]["INF"].size() && v[0]["INF"][idx] <= sum)));
            }
        }
        else if (x < 0 && !y) // ㅡ(2, 0)
        {
            if (!v[1]["0"].empty())
            {
                size_t idx = lower_bound(v[1]["0"].begin(), v[1]["0"].end(), sum) - v[1]["0"].begin();
                ans = max(ans, (ll)(idx + (idx < v[1]["0"].size() && v[1]["0"][idx] <= sum)));
            }
        }
        else if (!x && y < 0) // |(3, inf)
        {
            if (!v[2]["INF"].empty())
            {
                size_t idx = lower_bound(v[2]["INF"].begin(), v[2]["INF"].end(), sum) - v[2]["INF"].begin();
                ans = max(ans, (ll)(idx + (idx < v[2]["INF"].size() && v[2]["INF"][idx] <= sum)));
            }
        }
        else if (x > 0 && !y) // ㅡ(4, 0)
        {
            if (!v[3]["0"].empty())
            {
                size_t idx = lower_bound(v[3]["0"].begin(), v[3]["0"].end(), sum) - v[3]["0"].begin();
                ans = max(ans, (ll)(idx + (idx < v[3]["0"].size() && v[3]["0"][idx] <= sum)));
            }
        }
        else if (x > 0 && y > 0) // 1사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            if (!v[0][s].empty())
            {
                size_t idx = lower_bound(v[0][s].begin(), v[0][s].end(), sum) - v[0][s].begin();
                ans = max(ans, (ll)(idx + (idx < v[0][s].size() && v[0][s][idx] <= sum)));
            }
        }
        else if (x < 0 && y > 0) // 2사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            if (!v[1][s].empty())
            {
                size_t idx = lower_bound(v[1][s].begin(), v[1][s].end(), sum) - v[1][s].begin();
                ans = max(ans, (ll)(idx + (idx < v[1][s].size() && v[1][s][idx] <= sum)));
            }
        }
        else if (x < 0 && y < 0) // 3사분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            if (!v[2][s].empty())
            {
                size_t idx = lower_bound(v[2][s].begin(), v[2][s].end(), sum) - v[2][s].begin();
                ans = max(ans, (ll)(idx + (idx < v[2][s].size() && v[2][s][idx] <= sum)));
            }
        }
        else if (x > 0 && y < 0) // 4분면
        {
            ll GCD = gcd(x, y);
            string s = to_string(x / GCD) + "/" + to_string(y / GCD);
            if (!v[3][s].empty())
            {
                size_t idx = lower_bound(v[3][s].begin(), v[3][s].end(), sum) - v[3][s].begin();
                ans = max(ans, (ll)(idx + (idx < v[3][s].size() && v[3][s][idx] <= sum)));
            }
        }
    }
    cout << ans;
    return 0;
}