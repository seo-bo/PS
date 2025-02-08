#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    vector<int> v(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (v[i] > v[j])
            {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i] << ' ';
    }
    return 0;
}