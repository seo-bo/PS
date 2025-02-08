#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<pll>>dp(n + 1, vector<pll>(2, make_pair(0, -1)));
    for (int i = 1; i <= m; ++i)
    {
        int a = 0;
        cin >> a;
        for (int j = 0; j < a; ++j)
        {
            ll b = 0, c = 0;
            cin >> b >> c;
            vector<pll>ddp(2);
            auto [a1, a2] = dp[b][0];
            auto [b1, b2] = dp[b][1];
            ddp[0] = make_pair(max(a1, b1), -1);
            if (a1 + c > b1)
            {
                ddp[1] = make_pair(a1 + c, i);
            }
            else
            {
                ddp[1] = dp[b][1];
            }
            if (b2 + 1 < i)
            {
                if (b1 + c > ddp[1].first)
                {
                    ddp[1] = make_pair(b1 + c, i);
                }
            }
            dp[b] = ddp;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += max(dp[i][0].first, dp[i][1].first);
    }
    cout << ans;
    return 0;
}