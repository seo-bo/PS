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
    int T = 0;
    cin >> T;
    while (T--)
    {
        int n = 0;
        cin >> n;
        string a,b,c;
        cin >> a >> b >> c;
        bool check = false;
        for (int i = 0; i < c.length(); ++i)
        {
            if (a[i] != c[i] && b[i] != c[i])
            {
                check = true;
                break;
            }
        }
        if(!check) 
        {
            cout << "NO" <<'\n';
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
