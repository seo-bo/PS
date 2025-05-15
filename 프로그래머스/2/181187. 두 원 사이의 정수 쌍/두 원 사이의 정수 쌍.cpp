#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long solution(int r11, int r22) {
    ll r1 = r11, r2 = r22;
    ll ans = 0;
    for (ll i = 0; i <= r2; ++i) 
    {
        ll a = floor(sqrt(double(r2 * r2 - i * i)));
        ll cnt = 0;
        if (i < r1) 
        {
            ll t = r1 * r1 - i * i - 1;
            if (t >= 0) 
            {
                ll b = floor(sqrt((double)t));
                cnt = 2 * b + 1;
            }
        }
        ll b = 2 * a + 1 - cnt;
        if (!i) 
        {
            ans += b;
        } 
        else 
        {
            ans += 2 * b;
        }
    }
    return ans;
}