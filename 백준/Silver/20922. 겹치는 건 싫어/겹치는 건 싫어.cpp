#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& i : v)
    {
        cin >> i;
    }
    unordered_map<int, int> mm;
    int left = 0, right = 0;
    while (right < n)
    {
        mm[v[right]]++;
        while (mm[v[right]] > k)
        {
            mm[v[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    cout << ans;
    return 0;
}