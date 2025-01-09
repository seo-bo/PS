#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 0;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int slen = s.length(), tlen = t.length();
        int j = 0;  
        bool found = false;
        vector<int> os;
        for (int i = 0; i < slen && j < tlen; ++i)
        {
            if (s[i] == t[j] || s[i] == '?')
            {
               os.push_back(i);
                j++;
            }
        }
        if (j == tlen)
        {
            found = true;
            for (int i = 0; i < tlen; ++i)
            {
                s[os[i]] = t[i];
            }
        }
        if (found)
        {
            cout << yes << '\n';
            for (char& c : s)
            {
                if (c == '?')
                {
                    cout << 'a';
                }
                else
                {
                    cout << c;
                }
            }
            cout << '\n';
        }
        else
        {
            cout << no << '\n';
        }
    }
    return 0;
}
