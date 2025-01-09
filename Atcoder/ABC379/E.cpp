#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    ll n = 0;
    cin >> n;
    string str;
    cin >> str;
    vector<ll> prefix(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] + (ll)(str[i - 1] - '0') * i;
    }
    vector<ll> sum(n + 50, 0);
    for (ll i = 1; i <= n; ++i)
    {
        ll pi = prefix[i], idx = n - i;
        while (pi > 0)
        {
            sum[idx++] += pi % 10;
            pi /= 10;
        }
    }
    for (ll i = 0; i < sum.size(); ++i)
    {
        while (sum[i] >= 10)
        {
            if (i + 1 >= sum.size())
            {
                sum.push_back(0);
            }
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    ll tp = sum.size() - 1;
    while (tp > 0 && !sum[tp])
    {
        tp--;
    }
    for (; tp >= 0; --tp)
    {
        cout << sum[tp];
    }
    return 0;
}
