#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct cmp 
{
    bool operator()(const pii& a, const pii& b) const 
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n >> m >> k;
    set<pii, cmp> s;
    vector<int> v(n + 1);
    vector<pii> match;
    for (int i = 0; i < m; ++i) 
    {
        int t1 = 0, t2 = 0, result = 0;
        cin >> t1 >> t2 >> result;
        switch (result)
        {
        case 0:
        {
            match.push_back(make_pair(t1, t2));
            break;
        }
        case 1:
        {
            v[t1]++;
            break;
        }
        case 2:
        {
            v[t2]++;
            break;
        }
        }
    }
    for (int i = 1; i <= n; ++i) 
    {
        s.insert(make_pair(i, v[i]));
    }
    function<void(int)> dfs = [&](int depth) -> void 
        {
        if (depth == match.size())
        {
            auto it = s.begin();
            it++;
            if ((*s.begin()).first == k && (*s.begin()).second > (*it).second) 
            {
                ans++;
            }
            return;
        }
        int t1 = match[depth].first;
        int t2 = match[depth].second;
        s.erase(make_pair(t1, v[t1]));
        v[t1]++;
        s.insert(make_pair(t1, v[t1]));
        dfs(depth + 1);
        s.erase(make_pair(t1, v[t1]));
        v[t1]--;
        s.insert(make_pair(t1, v[t1]));
        s.erase(make_pair(t2, v[t2]));
        v[t2]++;
        s.insert(make_pair(t2, v[t2]));
        dfs(depth + 1);
        s.erase(make_pair(t2, v[t2]));
        v[t2]--;
        s.insert(make_pair(t2, v[t2]));
        };
    dfs(0);
    cout << ans;
    return 0;
}