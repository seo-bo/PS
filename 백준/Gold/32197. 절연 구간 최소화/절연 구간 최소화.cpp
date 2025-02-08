#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    int s = 0, e = 0;
    cin >> s >> e;
    deque<pii> dq;
    vector<vector<ll>> visited(n + 1, vector<ll>(2, LLONG_MAX));
    visited[s][0] = visited[s][1] = 0;
    dq.push_front(make_pair(s, 0));
    dq.push_front(make_pair(s, 1));
    while (!dq.empty())
    {
        auto [c, d] = dq.front();
        dq.pop_front();
        for (auto& [a, b] : graph[c])
        {
            ll dis = visited[c][d] + (d != b);
            if (dis < visited[a][b])
            {
                visited[a][b] = dis;
                if (b == d)
                {
                    dq.push_front(make_pair(a, b));
                }
                else
                {
                    dq.push_back(make_pair(a, b));
                }
            }
        }
    }
    cout << min(visited[e][0], visited[e][1]);
    return 0;
}