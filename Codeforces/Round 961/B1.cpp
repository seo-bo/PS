#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 0;
    cin >> T;
    while (T--)
    {
        ll n = 0, m = 0;
        cin >> n >> m;
        vector<ll> v(n);
        for (auto& i : v)
        {
            cin >> i;
        }
        sort(v.begin(), v.end());
        ll left = 0, right = 0, now = 0, ans = 0;
        while (right < n)
        {
            now += v[right];
            while (now > m)
            {
                now -= v[left];
                left++;
            }
            while (left < right && v[right] - v[left] > 1)
            {
                now -= v[left];
                left++;
            }
            ans = max(ans, now);
            right++;
        }
        cout << ans << '\n';
    }
    return 0;
}
