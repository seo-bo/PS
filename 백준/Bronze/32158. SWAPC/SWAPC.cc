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
    int n = 0;
    cin >> n;
    string str;
    cin >> str;
    vector<int>c;
    vector<int>p;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'C')
        {
            c.push_back(i);
        }
        else if(str[i] == 'P')
        {
            p.push_back(i);
        }
    }
    for (int i = 0; i < c.size() && i < p.size(); ++i)
    {
        swap(str[c[i]], str[p[i]]);
    }
    cout << str;
    return 0;
}